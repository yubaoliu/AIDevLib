cmake_minimum_required(VERSION 3.10)

# set the project name
project(useCmake)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

# Glog
find_package(Glog REQUIRED)
INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})
# thread 
find_package(Threads)
# OpenCV
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# add the executable
add_executable(main main.cpp)

target_link_libraries(main 
    ${GLOG_LIBRARY}
    ${OpenCV_LIBS}
    Threads::Threads
    )
