#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    // 3D rotation, use Matrix3d or Matrix3f
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix<double, 3, 3>::Identity();

    // Aixi angle
    Eigen::AngleAxisd rotation_vector(M_PI / 4, Eigen::Vector3d(0, 0, 1));
    cout.precision(3);
    cout << "Rotation matrix of AngleAxis = \n"
         << rotation_vector.matrix() << endl;
    cout << "------------------------------------" << endl;
    // Aixi-angle to rotation matrix
    rotation_matrix = rotation_vector.toRotationMatrix();

    cout << "Rotation matrix = \n"
         << rotation_matrix << endl;
    cout << "------------------------------------" << endl;
    // rotate using AngleAxis
    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_vector * v;
    cout << "Point: " << v.transpose() << endl
         << "after rotation use AngleAxis: " << v_rotated.transpose() << endl;
    cout << "------------------------------------" << endl;

    // rotate using rotation matrix
    v_rotated = rotation_matrix * v;
    cout << "Point: " << v.transpose() << endl
         << "after rotation use rotation matrix: " << v_rotated.transpose() << endl;
    cout << "------------------------------------" << endl;
    // Eular angle
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // XYX, yaw, pitch, roll
    cout << "yaw, pitch, roll: " << euler_angles.transpose() << endl;

    cout << "------------------------------------" << endl;
    // Eigen::Isometry
    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Eigen::Vector3d(1, 3, 4));
    cout << "Transform matrix = \n"
         << T.matrix() << endl;
    cout << "------------------------------------" << endl;
    // transform
    Eigen::Vector3d v_transformed = T * v;
    cout << "v transformed = " << v_transformed.transpose() << endl;
    cout << "------------------------------------" << endl;
    // Quaternion
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    cout << "quaternon: "
         << q.coeffs().transpose() << endl; // coeffs: (x, y, z, w)

    q = Eigen::Quaterniond(rotation_matrix);
    cout << "quaternon: "
         << q.coeffs().transpose() << endl; // coeffs: (x, y, z, w)

    v_rotated = q * v; // In math: qvq^{-1}

    cout << "Point: " << v.transpose() << endl
         << "after rotation use Quaternion: " << v_rotated.transpose() << endl;
}
