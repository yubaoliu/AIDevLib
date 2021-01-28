cmake_minimum_required(VERSION 3.0)
project( delaunay_triangulation )
find_package( OpenCV REQUIRED )

INCLUDE_DIRECTORIES(
    ${GLOG_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS}
    )


add_executable(delaunay_triangulation delaunay_triangulation.cpp )
target_link_libraries( delaunay_triangulation ${OpenCV_LIBS} )
