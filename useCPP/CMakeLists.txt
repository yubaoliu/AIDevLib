cmake_minimum_required(VERSION 3.0)
project(useCPP)

find_package(Threads)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(sort_example sort_fun.cpp)

add_executable(unordered_map_example unordered_map_example.cpp)

add_executable(thread_in_class thread_in_class.cpp)
target_link_libraries( thread_in_class 
    Threads::Threads
    )

add_executable(callback_in_class callback_in_class.cpp)
target_link_libraries( callback_in_class
    Threads::Threads
    )


# target_link_libraries(useSophus Sophus::Sophus)
