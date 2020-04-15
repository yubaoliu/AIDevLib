#include <Eigen/Geometry>
#include <iostream>
// Camera coordinate to ROS world or map coordinate
int main()
{
    Eigen::Matrix<double, 3, 3> rotationMat;
    rotationMat << 0, 0, 1, -1, 0, 0, 0, -1, 0;
    Eigen::Quaterniond Q(rotationMat);
    std::cout << Q.x() << ","
              << Q.y() << ","
              << Q.z() << ","
              << Q.w() << std::endl;
}
