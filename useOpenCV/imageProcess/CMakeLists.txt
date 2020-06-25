cmake_minimum_required(VERSION 3.0)
project( imageProcess )
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})


add_executable(readImage readImage.cpp )
target_link_libraries( readImage ${OpenCV_LIBS} )
