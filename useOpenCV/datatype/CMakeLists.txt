cmake_minimum_required(VERSION 3.0)
project( datatype )
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})


add_executable(cv_mat cv_mat.cpp )
target_link_libraries( cv_mat ${OpenCV_LIBS} )
