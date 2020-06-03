// https://docs.opencv.org/3.4/d9/df8/tutorial_root.html
// https://docs.opencv.org/2.4/doc/tutorials/viz/launching_viz/launching_viz.html
#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/viz/types.hpp>
#include <opencv2/viz/vizcore.hpp>

using namespace cv;
using namespace std;

void help()
{
    cout << "Axis:" << std::endl
         << "Red -> x axis: (1, 0, 0)" << std::endl
         << "Green -> y axis: (0, 1, 0) "
         << "Blue -> z axis: (0, 0, 1)"
         << std::endl;
}

/**
* @function main
*/
int main()
{
    help();

    // Create a window
    viz::Viz3d myWindow("Viz Demo");

    // add widget
    myWindow.showWidget("world", viz::WCoordinateSystem());

    // add plane
    // Method 1:
    // viz::WPlane plane;
    // myWindow.showWidget("Plane", plane);
    // Method 2
    // myWindow.showWidget("Plane", viz::WPlane());

    // Draw line
    viz::WLine axis(Point3f(0.f, 0.f, 0.f), Point3f(2.f, 2.f, 2.f), viz::Color::yellow());
    axis.setRenderingProperty(viz::LINE_WIDTH, 1.0);
    myWindow.showWidget("Line Widget", axis);

    // Construct a cube widget
    // viz::WCube cube_widget(Point3f(0.5, 0.5, 0.0), Point3f(0.0, 0.0, -0.5), true, viz::Color::blue());
    // cube_widget.setRenderingProperty(viz::LINE_WIDTH, 4.0);
    // myWindow.showWidget("Cube Widget", cube_widget);

    // Camera coordinate
    Vec3f cam_pos(2.0f, 2.0f, 2.0f), cam_focal_point(3.0f, 3.0f, 3.0f), cam_y_dir(-0.f, 0.0f, -1.0f);
    Affine3f cam_pose = viz::makeCameraPose(cam_pos, cam_focal_point, cam_y_dir);
    // Affine3f transform = viz::makeTransformToGlobal(Vec3f(0.0f, -1.0f, 0.0f), Vec3f(-1.0f, 0.0f, 0.0f), Vec3f(0.0f, 0.0f, -1.0f), cam_pos);

    viz::WCameraPosition cpw(1);                               // Coordinate axes
    viz::WCameraPosition cpw_frustum(Vec2f(0.889484, 0.523599)); // Camera frustum
    myWindow.showWidget("CPW", cpw, cam_pose);
    myWindow.showWidget("CPW_FRUSTUM", cpw_frustum, cam_pose);

    // // Rotation
    // Mat rot_vec = Mat::zeros(1, 3, CV_32F);
    // float translation_phase = 0.0, translation = 0.0;
    // while (!myWindow.wasStopped()) {
    //     /* Rotation using rodrigues */
    //     rot_vec.at<float>(0, 0) += (float)CV_PI * 0.01f;
    //     rot_vec.at<float>(0, 1) += (float)CV_PI * 0.01f;
    //     rot_vec.at<float>(0, 2) += (float)CV_PI * 0.01f;
    //     translation_phase += (float)CV_PI * 0.01f;
    //     translation = sin(translation_phase);
    //     Mat rot_mat;
    //     Rodrigues(rot_vec, rot_mat);
    //     Affine3f pose(rot_mat, Vec3f(translation, translation, translation));
    //     myWindow.setWidgetPose("Cube Widget", pose);
    //     myWindow.spinOnce(1, true);
    // }

    // Start event loop
    myWindow.spin();

    // Event loop is over when pressed q, Q, e, E
    cout << "Event loop is over" << endl;

    return 0;
}
