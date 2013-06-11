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

#ifndef TEXTOVERLAY2D_H
#define TEXTOVERLAY2D_H

#include "mitkVtkOverlay2D.h"
#include <mitkLocalStorageHandler.h>
#include <vtkSmartPointer.h>
#include <vtkTextActor.h>


namespace mitk {

class MITK_CORE_EXPORT TextOverlay2D : public mitk::VtkOverlay2D {
public:

  /** \brief Internal class holding the mapper, actor, etc. for each of the 3 2D render windows */
  /**
     * To render transveral, coronal, and sagittal, the mapper is called three times.
     * For performance reasons, the corresponding data for each view is saved in the
     * internal helper class LocalStorage. This allows rendering n views with just
     * 1 mitkMapper using n vtkMapper.
     * */
  class MITK_CORE_EXPORT LocalStorage : public mitk::Overlay::BaseLocalStorage
  {
  public:
    /** \brief Actor of a 2D render window. */
    vtkSmartPointer<vtkTextActor> m_textActor;

    /** \brief Timestamp of last update of stored data. */
    itk::TimeStamp m_LastUpdateTime;

    /** \brief Default constructor of the local storage. */
    LocalStorage();
    /** \brief Default deconstructor of the local storage. */
    ~LocalStorage();
  };

  /** \brief The LocalStorageHandler holds all (three) LocalStorages for the three 2D render windows. */
  mitk::LocalStorageHandler<LocalStorage> m_LSH;

  mitkClassMacro(TextOverlay2D, mitk::VtkOverlay2D);
  itkNewMacro(TextOverlay2D);

  void SetPosition(Point3D position3D);

  void SetText(std::string text);

  void SetPosition(Point3D position3D, mitk::BaseRenderer* renderer);

  Point3D GetPosition();

  std::string GetText();

  Point3D GetPosition(mitk::BaseRenderer* renderer);

protected:

  virtual vtkSmartPointer<vtkActor2D> GetVtkActor2D(BaseRenderer *renderer);
  void UpdateVtkOverlay2D(mitk::BaseRenderer *renderer);

  /** \brief explicit constructor which disallows implicit conversions */
  explicit TextOverlay2D();

  /** \brief virtual destructor in order to derive from this class */
  virtual ~TextOverlay2D();

private:

  /** \brief copy constructor */
  TextOverlay2D( const TextOverlay2D &);

  /** \brief assignment operator */
  TextOverlay2D &operator=(const TextOverlay2D &);

};

} // namespace mitk
#endif // TEXTOVERLAY2D_H


