#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>
#include <iostream>

#include "sophus/so3.hpp"
#include "sophus/se3.hpp"

using namespace std;

int main(int argc, char** argv)
{
    // z: 90 degree
    Eigen::Matrix<double, 3, 3> R = Eigen::AngleAxis<double>(M_PI / 2, Eigen::Vector3d(0, 0, 1)).toRotationMatrix();
    // using Transformation = Matrix<Scalar, N, N>
    Sophus::SO3<double> SO3_R(R); 
    // Sophus::SO3<double> SO3_v(0, 0, M_PI/2);


}
