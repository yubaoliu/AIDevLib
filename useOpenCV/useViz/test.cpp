#include <iostream>
#include <opencv2/calib3d.hpp>
#include <opencv2/viz/types.hpp>
#include <opencv2/viz/vizcore.hpp>

using namespace cv;
using namespace std;

int main()
{
    // visualization
    cv::viz::Viz3d vis("Visual Odometry");
    cv::viz::WCoordinateSystem world_coor(1.0), camera_coor(0.5);
    cv::Point3d cam_pos(0, -1.0, -1.0), cam_focal_point(0, 0, 0), cam_y_dir(0, 1, 0);
    // cv::Point3d cam_pos(1, -2.0 -2.0), cam_focal_point(1, 1, 1), cam_y_dir(0, 1, 0);
    cv::Affine3d cam_pose = cv::viz::makeCameraPose(cam_pos, cam_focal_point, cam_y_dir);
    vis.setViewerPose(cam_pose);

    world_coor.setRenderingProperty(cv::viz::LINE_WIDTH, 2.0);
    camera_coor.setRenderingProperty(cv::viz::LINE_WIDTH, 1.0);

    viz::WCameraPosition cpw(0.5);                               // Coordinate axes
    viz::WCameraPosition cpw_frustum(Vec2f(0.889484, 0.523599)); // Camera frustum

    // vis.showWidget("World", world_coor);
    // vis.showWidget("Camera", camera_coor);

    vis.showWidget("CPW", cpw, cam_pose);
    vis.showWidget("CPW_FRUSTUM", cpw_frustum, cam_pose);

    vis.spin();

    cout << "end" <<endl;
    return 0;
}
