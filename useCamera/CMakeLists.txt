cmake_minimum_required(VERSION 3.0)
project( cameraRelated )
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})


add_executable(K-matrix K-matrix.cpp )
target_link_libraries( K-matrix ${OpenCV_LIBS} )
