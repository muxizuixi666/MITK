SET(CPP_FILES 
  Algorithms/vtkPointSetSlicer.cxx
  Algorithms/mitkCoreExtObjectFactory.cpp
  Algorithms/mitkAngleCorrectByPointFilter.cpp
  Algorithms/mitkAutoCropImageFilter.cpp
  Algorithms/mitkBoundingObjectCutter.cpp
  Algorithms/mitkBSplineRegistration.cpp
  Algorithms/mitkCalculateSegmentationVolume.cpp
  Algorithms/mitkCallbackFromGUIThread.cpp
  Algorithms/mitkContourSetToPointSetFilter.cpp
  Algorithms/mitkContourUtils.cpp
  Algorithms/mitkCorrectorAlgorithm.cpp
  Algorithms/mitkCylindricToCartesianFilter.cpp
  #Algorithms/mitkDICOMFileIOFactory.cpp
  Algorithms/mitkDemonsRegistration.cpp
  Algorithms/mitkDiffImageApplier.cpp
  Algorithms/mitkDopplerToStrainRateFilter.cpp
  Algorithms/mitkExtractDirectedPlaneImageFilter.cpp
  Algorithms/mitkExtractImageFilter.cpp
  Algorithms/mitkGeometryClipImageFilter.cpp
  Algorithms/mitkGeometryDataSource.cpp
  Algorithms/mitkHistogramMatching.cpp
  Algorithms/mitkImageRegistrationMethod.cpp
  Algorithms/mitkImageToLookupTableFilter.cpp
  Algorithms/mitkImageToSurfaceFilter.cpp
  Algorithms/mitkInterpolateLinesFilter.cpp
  Algorithms/mitkLabeledImageToSurfaceFilter.cpp
  Algorithms/mitkLookupTableSource.cpp
  Algorithms/mitkManualSegmentationToSurfaceFilter.cpp
  Algorithms/mitkMaskImageFilter.cpp
  Algorithms/mitkMeshSource.cpp
  Algorithms/mitkMetricParameters.cpp
  Algorithms/mitkNonBlockingAlgorithm.cpp
  Algorithms/mitkOptimizerFactory.cpp
  Algorithms/mitkOptimizerParameters.cpp
  Algorithms/mitkOverwriteSliceImageFilter.cpp
  Algorithms/mitkPadImageFilter.cpp
  Algorithms/mitkPlaneCutFilter.cpp
  Algorithms/mitkPlaneFit.cpp
  Algorithms/mitkPlanesPerpendicularToLinesFilter.cpp
  Algorithms/mitkPointLocator.cpp
  Algorithms/mitkPointSetToCurvedGeometryFilter.cpp
  Algorithms/mitkPointSetToGeometryDataFilter.cpp
  Algorithms/mitkPolygonToRingFilter.cpp
  Algorithms/mitkProbeFilter.cpp
  Algorithms/mitkRegistrationBase.cpp
  Algorithms/mitkRigidRegistrationObserver.cpp
  Algorithms/mitkRigidRegistrationPreset.cpp
  Algorithms/mitkSegmentationSink.cpp
  Algorithms/mitkShapeBasedInterpolationAlgorithm.cpp
  Algorithms/mitkShowSegmentationAsSurface.cpp
  Algorithms/mitkSurfaceToImageFilter.cpp
  Algorithms/mitkSymmetricForcesDemonsRegistration.cpp
  Algorithms/mitkTransformParameters.cpp
  Algorithms/mitkUnstructuredGridHistogram.cpp
  Algorithms/mitkUnstructuredGridSource.cpp
  Controllers/mitkMovieGenerator.cpp
  Controllers/mitkMultiStepper.cpp
  Controllers/mitkProgressBar.cpp
  Controllers/mitkReportGenerator.cpp
  Controllers/mitkSegmentationInterpolationController.cpp
  Controllers/mitkStatusBar.cpp
  Controllers/mitkToolManager.cpp
  DataManagement/itkConfidenceDiffusionTensor3D.cpp
  DataManagement/mitkAffineTransformationOperation.cpp
  DataManagement/mitkApplyDiffImageOperation.cpp
  DataManagement/mitkBoundingObject.cpp
  DataManagement/mitkBoundingObjectGroup.cpp
  DataManagement/mitkCellOperation.cpp
#DataManagement/mitkClosedSpline.cpp
  DataManagement/mitkColorConversions.cpp
  DataManagement/mitkColorSequence.cpp
  DataManagement/mitkColorSequenceCycleH.cpp
  DataManagement/mitkColorSequenceHalfTones.cpp
  DataManagement/mitkColorSequenceRainbow.cpp
  DataManagement/mitkCompressedImageContainer.cpp
  DataManagement/mitkCone.cpp
  DataManagement/mitkContour.cpp
  DataManagement/mitkContourSet.cpp
  DataManagement/mitkCuboid.cpp
  DataManagement/mitkCylinder.cpp
  DataManagement/mitkDataTreeFilter.cpp
  DataManagement/mitkDataTreeFilterFunctions.cpp
  DataManagement/mitkDataTreeHelper.cpp
  DataManagement/mitkDelegateManager.cpp
  DataManagement/mitkDelegateProperty.cpp
  DataManagement/mitkDrawOperation.cpp
  DataManagement/mitkEllipsoid.cpp
  DataManagement/mitkExternAbstractTransformGeometry.cpp
  DataManagement/mitkExtrudedContour.cpp
  DataManagement/mitkFrameOfReferenceUIDManager.cpp
  DataManagement/mitkGridRepresentationProperty.cpp
  DataManagement/mitkGridVolumeMapperProperty.cpp
  DataManagement/mitkItkBaseDataAdapter.cpp
  DataManagement/mitkLabeledImageLookupTable.cpp
  DataManagement/mitkLineOperation.cpp
  DataManagement/mitkMesh.cpp
  DataManagement/mitkOrganTypeProperty.cpp
  DataManagement/mitkPlaneLandmarkProjector.cpp
  DataManagement/mitkPointData.cpp
  DataManagement/mitkPropertyManager.cpp
  DataManagement/mitkPropertyObserver.cpp
#DataManagement/mitkRingSpline.cpp
  DataManagement/mitkSeedsImage.cpp
  DataManagement/mitkSeedsImageLookupTableSource.cpp
  DataManagement/mitkSphereLandmarkProjector.cpp
#DataManagement/mitkUSLookupTableSource.cpp
  DataManagement/mitkUnstructuredGrid.cpp
  DataManagement/mitkVideoSource.cpp
  IO/mitkObjFileIOFactory.cpp
  IO/mitkObjFileReader.cpp
  IO/mitkPACSPlugin.cpp
  IO/mitkParRecFileIOFactory.cpp
  IO/mitkParRecFileReader.cpp
  IO/mitkStlVolumeTimeSeriesIOFactory.cpp
  IO/mitkStlVolumeTimeSeriesReader.cpp
  IO/mitkUnstructuredGridVtkWriter.cpp
  IO/mitkUnstructuredGridVtkWriterFactory.cpp
  IO/mitkVtkUnstructuredGridIOFactory.cpp
  IO/mitkVtkUnstructuredGridReader.cpp
  IO/mitkVtkVolumeTimeSeriesIOFactory.cpp
  IO/mitkVtkVolumeTimeSeriesReader.cpp
  Interactions/mitkAutoSegmentationTool.cpp
  Interactions/mitkConferenceEventMapper.cpp
  Interactions/mitkConnectPointsInteractor.cpp
  Interactions/mitkContourInteractor.cpp
  Interactions/mitkContourTool.cpp
  #Interactions/mitkCoordinateSupplier.cpp
  #Interactions/mitkDisplayCoordinateOperation.cpp
  #Interactions/mitkDisplayInteractor.cpp
  Interactions/mitkDisplayPointSetInteractor.cpp
  #Interactions/mitkDisplayVectorInteractor.cpp
  Interactions/mitkExtrudedContourInteractor.cpp
  Interactions/mitkFeedbackContourTool.cpp
  Interactions/mitkInteractionDebug.cpp
  Interactions/mitkInteractionDebugger.cpp
  Interactions/mitkPaintbrushTool.cpp
  Interactions/mitkPointInteractor.cpp
  Interactions/mitkPointSelectorInteractor.cpp
  #Interactions/mitkPositionTracker.cpp
  Interactions/mitkSeedsInteractor.cpp
  Interactions/mitkSegTool2D.cpp
  Interactions/mitkSegmentationsProcessingTool.cpp
  Interactions/mitkSetRegionTool.cpp
  Interactions/mitkSocketClient.cpp
  Interactions/mitkSurfaceInteractor.cpp
  Interactions/mitkTool.cpp
  Rendering/mitkContourMapper2D.cpp
  Rendering/mitkContourSetMapper2D.cpp
  Rendering/mitkContourSetVtkMapper3D.cpp
  Rendering/mitkContourVtkMapper3D.cpp
  Rendering/mitkEnhancedPointSetVtkMapper3D.cpp
  Rendering/mitkImageBackground2D.cpp
  Rendering/mitkLineMapper2D.cpp
#Rendering/mitkLineVtkMapper3D.cpp
  Rendering/mitkMeshMapper2D.cpp
  Rendering/mitkMeshVtkMapper3D.cpp
  Rendering/mitkNativeRenderWindowInteractor.cpp
  Rendering/mitkPointDataVtkMapper3D.cpp
  Rendering/mitkSplineMapper2D.cpp
  Rendering/mitkSplineVtkMapper3D.cpp
  Rendering/mitkUnstructuredGridMapper2D.cpp
  Rendering/mitkUnstructuredGridVtkMapper3D.cpp
  Rendering/vtkUnstructuredGridMapper.cpp
)

# Segmentation (or related) tools for interactive segmentation view
#
# Tool classes, which do not appear in this list but in the CPP_FILES
# list, do not need a factory. The list below contains only "end-user"
# tools, which should be instantiated during runtime
SET( TOOL_FILES
  Interactions/mitkAddContourTool.cpp
  Interactions/mitkAutoCropTool.cpp
  Interactions/mitkBinaryThresholdTool.cpp
  Interactions/mitkCalculateGrayValueStatisticsTool.cpp
  Interactions/mitkCalculateVolumetryTool.cpp
  Interactions/mitkCorrectorTool2D.cpp
  Interactions/mitkCreateSurfaceTool.cpp
  Interactions/mitkEraseRegionTool.cpp
  Interactions/mitkFillRegionTool.cpp
  Interactions/mitkRegionGrowingTool.cpp
  Interactions/mitkSubtractContourTool.cpp
  Interactions/mitkDrawPaintbrushTool.cpp
  Interactions/mitkErasePaintbrushTool.cpp
)

IF(WIN32)
  SET(CPP_FILES 
    Controllers/mitkMovieGeneratorWin32.cpp
    ${CPP_FILES}
  )
ENDIF(WIN32)

IF(MITK_USE_TD_MOUSE)
  SET(CPP_FILES 
      Controllers/mitkTDMouseVtkCameraController.cpp
      Interactions/mitkSpaceNavigatorDriver.cpp
      Interactions/mitkTDMouseEvent.cpp
      Interactions/mitkTDMouseEventThrower.cpp
      ${CPP_FILES}  
     )
ENDIF(MITK_USE_TD_MOUSE)

MITK_MULTIPLEX_PICTYPE( Algorithms/mitkImageRegistrationMethod-TYPE.cpp ) 
