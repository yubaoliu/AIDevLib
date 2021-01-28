#include <Eigen/Core>
#include <Eigen/Dense>
#include <ctime>
#include <iostream>

#define MATRIX_SIXE 50

using Eigen::MatrixXd;
int main()
{
    // Construct matrix
    // typedef Matrix<Scalar, RowsAtCompileTime, ColsAtCompileTime, Options> MyMatrixType;
    // Options can be ColMajor or RowMajor, default is ColMajor. (see class Matrix for more options)
    Eigen::Matrix<float, 2, 3> matrix_23;
    matrix_23 << 1, 2, 3, 4, 5, 6;
    std::cout << "matrix_23: " << std::endl
              << matrix_23 << std::endl;
    // Access every elements
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            std::cout << "(" << i << "," << j << ") " << matrix_23(i, j) << std::endl;

    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << "Construct matrix: " << std::endl
              << m << std::endl;

    std::cout << "innerStride: " << m.innerStride() << std::endl;
    std::cout << "outerStride: " << m.outerStride() << std::endl;
    std::cout << "transpose: " << m.transpose() << std::endl;
    std::cout << "sum: " << m.sum() << std::endl;
    std::cout << "trace: " << m.trace() << std::endl;
    std::cout << "inverse: " << m.inverse() << std::endl;
    std::cout << "determinant: " << m.determinant() << std::endl;
    std::cout << "10*matrix: " << 10 * m << std::endl;

    // cast
    Eigen::Vector3d v_3d;
    v_3d << 3, 2, 1;
    Eigen::Matrix<double, 2, 1> cast_mul = matrix_23.cast<double>() * v_3d;
    std::cout << "cast and multiply: " << cast_mul << std::endl;

    // Reductions
    int i, j;
    int s = m.minCoeff(&i, &j);
    std::cout << "min value: "
              << "(" << i << "," << j << "):" << s << std::endl;
    s = m.maxCoeff(&i, &j);
    std::cout << "max value: "
              << "(" << i << "," << j << "):" << s << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
    // Eigen
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
    matrix_33 = Eigen::Matrix3d::Random();
    std::cout << "(random matrix) matrix_33:" << std::endl
              << matrix_33 << std::endl;

    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_33.transpose() * matrix_33);
    std::cout << "Eigen values = " << eigen_solver.eigenvalues() << std::endl;
    std::cout << "Eigen vectors = " << eigen_solver.eigenvectors() << std::endl;

    // solve matrix_NN * x = v_Nd
    std::cout << "-------------------------------------------" << std::endl;
    Eigen::Matrix<double, MATRIX_SIXE, MATRIX_SIXE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIXE, MATRIX_SIXE);
    Eigen::Matrix<double, MATRIX_SIXE, 1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIXE, 1);

    clock_t time_start = clock();
    Eigen::Matrix<double, MATRIX_SIXE, 1> x = matrix_NN.inverse() * v_Nd;
    std::cout << "Time used in normal inverse is " << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

    // use QR
    time_start = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    std::cout << "Time used in QR decomposition inverse is " << 1000 * (clock() - time_start) / (double)CLOCKS_PER_SEC << "ms" << std::endl;

    std::cout << "-------------------------------------------" << std::endl;
}
