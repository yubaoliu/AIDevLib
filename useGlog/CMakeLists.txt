cmake_minimum_required(VERSION 3.10)

# set the project name
project(useGlog)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)

find_package(Glog REQUIRED)

INCLUDE_DIRECTORIES(${GLOG_INCLUDE_DIR})

# add the executable
add_executable(example example.cpp)

target_link_libraries(example ${GLOG_LIBRARY})
