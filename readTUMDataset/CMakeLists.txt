cmake_minimum_required(VERSION 3.0)
project(TUMDataset)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable( read_tum read_tum.cpp)

# add_executable(read_tum unordered_map_example.cpp)

# target_link_libraries(useSophus Sophus::Sophus)
