/*!
  @file   drishti/hci/FaceFinderPainter.h
  @author David Hirvonen
  @brief  Face tracking class with OpenGL texture drawing

  \copyright Copyright 2014-2016 Elucideye, Inc. All rights reserved.
  \license{This project is released under the 3 Clause BSD License.}

*/

#ifndef __drishti_hci_FaceFinderPainter_h__
#define __drishti_hci_FaceFinderPainter_h__

#include "drishti/hci/drishti_hci.h"
#include "drishti/hci/FaceFinder.h"

#include <memory>

// *INDENT-OFF*
namespace ogles_gpgpu
{
    class FacePainter;
    class TransformProc;
}
// *INDENT-ON*

DRISHTI_HCI_NAMESPACE_BEGIN

class FaceFinderPainter : public FaceFinder
{
public:
    
    class Impl;

    FaceFinderPainter(FaceDetectorFactoryPtr &factory, Config &config, void *glContext = nullptr);
    ~FaceFinderPainter();
    virtual void init(const FrameInput &frame);
    void drawIris(bool flag) { m_drawIris = flag; }

protected:
    
    virtual void initPainter(const cv::Size &inputSizeUp);    
    virtual GLuint paint(const ScenePrimitives &scene, GLuint inputTexture);    

    bool m_drawIris = false;
    std::shared_ptr<ogles_gpgpu::TransformProc> m_rotater;
    std::shared_ptr<ogles_gpgpu::FacePainter> m_painter;
    
    std::unique_ptr<Impl> m_pImpl;
};

DRISHTI_HCI_NAMESPACE_END

#endif // __drishti_hci_FaceFinderPainter_h__