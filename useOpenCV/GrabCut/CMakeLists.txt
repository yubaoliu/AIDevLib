cmake_minimum_required(VERSION 3.0)
project(GrabCut)
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})


add_executable(grabcut main.cpp )
target_link_libraries( grabcut ${OpenCV_LIBS} )
