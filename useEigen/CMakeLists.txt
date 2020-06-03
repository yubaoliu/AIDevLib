cmake_minimum_required(VERSION 3.10)

# set the project name
project(useEigen)

find_package(OpenCV 3)
find_package(Eigen3 REQUIRED)

# header files include_directories(include ${EIGEN3_INCLUDE_DIR})

# add the executable
add_executable(eigen_example eigen_example.cpp)
target_link_libraries(eigen_example Eigen3::Eigen)

add_executable(eigenMatrix eigenMatrix.cpp)
target_link_libraries(eigenMatrix Eigen3::Eigen)

add_executable(eigenGeometry eigenGeometry.cpp)
target_link_libraries(eigenGeometry Eigen3::Eigen)
