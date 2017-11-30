/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/


#include <berryISelectionService.h>
#include <berryIWorkbenchWindow.h>

#include "QmitkTractometryView.h"

#include <mitkNodePredicateDataType.h>
#include <mitkNodePredicateDimension.h>
#include <mitkNodePredicateAnd.h>
#include <mitkImageCast.h>
#include <mitkImageAccessByItk.h>
#include <mitkImage.h>
#include <mitkFiberBundle.h>
#include <mitkDiffusionPropertyHelper.h>
#include <mitkITKImageImport.h>
#include <QmitkChartWidget.h>
#include <mitkPixelTypeMultiplex.h>
#include <mitkImagePixelReadAccessor.h>
#include <berryIPreferences.h>
#include <berryWorkbenchPlugin.h>
#include <berryQtPreferences.h>
#include <vtkLookupTable.h>

const std::string QmitkTractometryView::VIEW_ID = "org.mitk.views.tractometry";
using namespace mitk;

QmitkTractometryView::QmitkTractometryView()
  : QmitkAbstractView()
  , m_Controls( nullptr )
{

}

// Destructor
QmitkTractometryView::~QmitkTractometryView()
{

}

void QmitkTractometryView::CreateQtPartControl( QWidget *parent )
{
  // build up qt view, unless already done
  if ( !m_Controls )
  {
    // create GUI widgets from the Qt Designer's .ui file
    m_Controls = new Ui::QmitkTractometryViewControls;
    m_Controls->setupUi( parent );

    mitk::TNodePredicateDataType<mitk::Image>::Pointer imageP = mitk::TNodePredicateDataType<mitk::Image>::New();
    mitk::NodePredicateDimension::Pointer dimP = mitk::NodePredicateDimension::New(3);

    m_Controls->m_ImageBox->SetDataStorage(this->GetDataStorage());
    m_Controls->m_ImageBox->SetPredicate(mitk::NodePredicateAnd::New(imageP, dimP));

    this->m_Controls->m_ChartWidget->SetXAxisLabel("Tract position");
    this->m_Controls->m_ChartWidget->SetYAxisLabel("Image Value");
  }
}

void QmitkTractometryView::OnPageSuccessfullyLoaded()
{
  berry::IPreferencesService* prefService = berry::WorkbenchPlugin::GetDefault()->GetPreferencesService();
  berry::IPreferences::Pointer m_StylePref = prefService->GetSystemPreferences()->Node(berry::QtPreferences::QT_STYLES_NODE);

  QString styleName = m_StylePref->Get(berry::QtPreferences::QT_STYLE_NAME, "");

  if (styleName == ":/org.blueberry.ui.qt/darkstyle.qss")
  {
    this->m_Controls->m_ChartWidget->SetTheme(QmitkChartWidget::ChartStyle::darkstyle);
  }
  else
  {
    this->m_Controls->m_ChartWidget->SetTheme(QmitkChartWidget::ChartStyle::lightstyle);
  }
}

void QmitkTractometryView::SetFocus()
{
}

bool QmitkTractometryView::Flip(vtkSmartPointer< vtkPolyData > polydata1, int i, vtkSmartPointer< vtkPolyData > ref_poly)
{
  float d_direct = 0;
  float d_flipped = 0;

  vtkCell* cell1 = polydata1->GetCell(0);
  if (ref_poly!=nullptr)
    cell1 = ref_poly->GetCell(0);
  int numPoints1 = cell1->GetNumberOfPoints();
  vtkPoints* points1 = cell1->GetPoints();

  vtkCell* cell2 = polydata1->GetCell(i);
  vtkPoints* points2 = cell2->GetPoints();

  for (int j=0; j<numPoints1; ++j)
  {
    double* p1 = points1->GetPoint(j);
    double* p2 = points2->GetPoint(j);
    d_direct = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]) + (p1[2]-p2[2])*(p1[2]-p2[2]);

    double* p3 = points2->GetPoint(numPoints1-j-1);
    d_flipped = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]) + (p1[2]-p3[2])*(p1[2]-p3[2]);
  }

  if (d_direct>d_flipped)
    return true;
  return false;
}

template <typename TPixel>
void QmitkTractometryView::ImageValuesAlongTract(const mitk::PixelType, mitk::Image::Pointer image, mitk::FiberBundle::Pointer fib, std::vector<std::vector<double> > &data)
{
  int num_points = 100;
  mitk::ImagePixelReadAccessor<TPixel,3> readimage(image, image->GetVolumeData(0));
  mitk::FiberBundle::Pointer working_fib = fib->GetDeepCopy();
  working_fib->ResampleToNumPoints(num_points);
  vtkSmartPointer< vtkPolyData > polydata = working_fib->GetFiberPolyData();

  std::vector<std::vector<double> > all_values;
  std::vector< double > mean_values;
  for (int i=0; i<num_points; ++i)
    mean_values.push_back(0);

  double min = 100000;
  double max = 0;
  double mean = 0;
  for (int i=0; i<working_fib->GetNumFibers(); ++i)
  {
    vtkCell* cell = polydata->GetCell(i);
    int numPoints = cell->GetNumberOfPoints();
    vtkPoints* points = cell->GetPoints();

    std::vector< double > fib_vals;

    bool flip = false;
    if (i>0)
      flip = Flip(polydata, i);
    else if (m_ReferencePolyData!=nullptr)
      flip = Flip(polydata, 0, m_ReferencePolyData);

    for (int j=0; j<numPoints; j++)
    {
      double* p;
      if (flip)
        p = points->GetPoint(numPoints - j - 1);
      else
        p = points->GetPoint(j);

      Point3D px;
      px[0] = p[0];
      px[1] = p[1];
      px[2] = p[2];
      double pixelValue = readimage.GetPixelByWorldCoordinates(px);
      fib_vals.push_back(pixelValue);
      mean += pixelValue;
      if (pixelValue<min)
        min = pixelValue;
      else if (pixelValue>max)
        max = pixelValue;

      mean_values.at(j) += pixelValue;
    }

    all_values.push_back(fib_vals);
  }

  if (m_ReferencePolyData==nullptr)
    m_ReferencePolyData = polydata;

  std::vector< double > std_values1;
  std::vector< double > std_values2;
  for (int i=0; i<num_points; ++i)
  {
    mean_values.at(i) /= working_fib->GetNumFibers();
    double stdev = 0;

    for (unsigned int j=0; j<all_values.size(); ++j)
    {
      double diff = mean_values.at(i) - all_values.at(j).at(i);
      diff *= diff;
      stdev += diff;
    }
    stdev /= all_values.size();
    stdev = std::sqrt(stdev);
    std_values1.push_back(mean_values.at(i) + stdev/2);
    std_values2.push_back(mean_values.at(i) - stdev/2);
  }

  data.push_back(mean_values);
  data.push_back(std_values1);
  data.push_back(std_values2);

  MITK_INFO << "Min: " << min;
  MITK_INFO << "Max: " << max;
  MITK_INFO << "Mean: " << mean/working_fib->GetNumberOfPoints();
}

std::string QmitkTractometryView::RGBToHexString(double *rgb)
{
  std::ostringstream os;
  for (int i = 0; i < 3; ++i)
    {
    os << std::setw(2) << std::setfill('0') << std::hex
       << static_cast<int>(rgb[i] * 255);
    }
  return os.str();
}

void QmitkTractometryView::OnSelectionChanged(berry::IWorkbenchPart::Pointer /*part*/, const QList<mitk::DataNode::Pointer>& nodes)
{
  if(m_Controls->m_ImageBox->GetSelectedNode().IsNull())
    return;

  m_ReferencePolyData = nullptr;
  mitk::Image::Pointer image = dynamic_cast<mitk::Image*>(m_Controls->m_ImageBox->GetSelectedNode()->GetData());

  vtkSmartPointer<vtkLookupTable> lookupTable = vtkSmartPointer<vtkLookupTable>::New();
  lookupTable->SetTableRange(0.0, 1.0);
  lookupTable->Build();

  int num_tracts = 0;
  for (auto node: nodes)
    if ( dynamic_cast<mitk::FiberBundle*>(node->GetData()) )
      num_tracts++;

  int c = 1;
  this->m_Controls->m_ChartWidget->Clear();
  for (auto node: nodes)
  {
    if ( dynamic_cast<mitk::FiberBundle*>(node->GetData()) )
    {
      mitk::FiberBundle::Pointer fib = dynamic_cast<mitk::FiberBundle*>(node->GetData());

      std::vector< std::vector< double > > data;
      mitkPixelTypeMultiplex3( ImageValuesAlongTract, image->GetPixelType(), image, fib, data );

      m_Controls->m_ChartWidget->AddData1D(data.at(0), node->GetName() + " Mean", QmitkChartWidget::ChartType::line);
      if (m_Controls->m_StDevBox->isChecked())
      {
        this->m_Controls->m_ChartWidget->AddData1D(data.at(1), node->GetName() + " +STDEV", QmitkChartWidget::ChartType::line);
        this->m_Controls->m_ChartWidget->AddData1D(data.at(2), node->GetName() + " -STDEV", QmitkChartWidget::ChartType::line);
      }

      double color[3];
      if (num_tracts>1)
      {
        float scalar_color = ( (float)c/num_tracts - 1.0/num_tracts )/(1.0-1.0/num_tracts);
        lookupTable->GetColor(1.0 - scalar_color, color);
      }
      else
        lookupTable->GetColor(0, color);

      this->m_Controls->m_ChartWidget->SetColor(node->GetName() + " Mean", RGBToHexString(color));

      if (m_Controls->m_StDevBox->isChecked())
      {
        color[0] *= 0.8;
        color[1] *= 0.8;
        color[2] *= 0.8;
        this->m_Controls->m_ChartWidget->SetColor(node->GetName() + " +STDEV", RGBToHexString(color));
        this->m_Controls->m_ChartWidget->SetColor(node->GetName() + " -STDEV", RGBToHexString(color));
      }

      this->m_Controls->m_ChartWidget->Show(true);
      this->m_Controls->m_ChartWidget->SetShowDataPoints(false);
      ++c;
    }
  }

  MITK_INFO << "OnSelectionChanged DONE";
}
