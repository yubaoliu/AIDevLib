# https://cmake.org/cmake/help/v3.10/module/FindOpenGL.html
cmake_minimum_required(VERSION 3.0)
project(useOpenGL)

# OpenGL
# find_package(OpenGL REQUIRED)

# GLUT
# find_package(GLUT REQUIRED)

# GLM 
# find_package(GLM REQUIRED)
# message(STATUS "GLM included at ${GLM_INCLUDE_DIR}")

# GLFW
find_package(glfw3 REQUIRED)
message(STATUS "Found GLFW3 in ${GLFW3_INCLUDE_DIR}")

# ASSIMP
# find_package(ASSIMP REQUIRED)
# message(STATUS "Found ASSIMP in ${ASSIMP_INCLUDE_DIR}")

include_directories(
    include
    ../3rdparties/stb
    )

add_executable(mytest test.cpp glad.c)
target_link_libraries(mytest
    glfw 
    ${CMAKE_DL_LIBS}
    )


add_executable(basics basics.cpp glad.c)
target_link_libraries(basics
    glfw 
    # OpenGL::GL 
    # ${OPENGL_LIBRARY}
    ${CMAKE_DL_LIBS}
    )

add_executable(geometry geometry.cpp glad.c)
target_link_libraries( geometry
    glfw 
    ${CMAKE_DL_LIBS}
    )


# add_executable( hello_window hello_window_clear.cpp glad.c)
# target_link_libraries(hello_window
#     glfw 
#     ${CMAKE_DL_LIBS}
#     )
# 
# add_executable( hello_window_clear hello_window_clear.cpp glad.c)
# target_link_libraries(hello_window_clear
#     glfw 
#     ${CMAKE_DL_LIBS}
#     )
# 
# add_executable( hello_triangle hello_triangle.cpp glad.c)
# target_link_libraries(hello_triangle
#     glfw 
#     ${CMAKE_DL_LIBS}
#     )
# 
# add_executable( hello_triangle_indexed hello_triangle_indexed.cpp glad.c)
# target_link_libraries(hello_triangle_indexed
#     glfw 
#     ${CMAKE_DL_LIBS}
#     )





