cmake_minimum_required(VERSION 3.0)
project( features )
find_package( OpenCV REQUIRED )
INCLUDE_DIRECTORIES(
    ${GLOG_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS}
    )

find_package(VTK)

include(${VTK_USE_FILE})


add_executable(orb_cv  orb_cv.cpp )
target_link_libraries( orb_cv ${OpenCV_LIBS} )

