cmake_minimum_required(VERSION 3.0)
project(usePangolin)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

SET(CMAKE_BUILD_TYPE Debug)

find_package(Glog REQUIRED)
INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})

find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})
 
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(main main.cpp)
target_link_libraries(main 
    ${Pangolin_LIBRARIES}
    ${GLOG_LIBRARY}
    ${OpenCV_LIBS}
    )

add_executable( slam14 slam14.cpp)
target_link_libraries(slam14 ${Pangolin_LIBRARIES})
