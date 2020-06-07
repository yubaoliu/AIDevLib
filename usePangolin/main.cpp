#include <glog/logging.h>

#include "pangolinBase.h"

// void SampleMethod();
// void setup();
// void guiInit();
// void guiHandler();
// void run();

int main(int argc, char** argv)
{
    google::InitGoogleLogging(argv[0]);

    std::cout<<"Pangolin Example"<<std::endl;

    PangolinBase::Ptr instance(new  PangolinBase);

    // use the context in a separate rendering thread

    // pangolin::SaveWindowOnRender("window");
    //
    // // create a frame buffer object with colour and depth buffer
    // pangolin::GlTexture color_buffer(w, h);
    // pangolin::GlRenderBuffer depth_buffer(w, h);
    // pangolin::GlFramebuffer fbo_buffer(color_buffer, depth_buffer);
    // fbo_buffer.Bind();
    //
    // fbo_buffer.Unbind();
    // color_buffer.Save("fbo.png", false);
    // pangolin::QuitAll();
    return 0;
}
