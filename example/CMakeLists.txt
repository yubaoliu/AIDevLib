# executable 
add_executable(rot2quad rot_mat_2_quaterniond.cpp)
target_link_libraries(rot2quad ${PROJECT_NAME})

# Generate point cloud
add_executable (generate_pointcloud generatePointCloud.cpp)
target_link_libraries (
generate_pointcloud 
    ${PCL_LIBRARIES}
    ${OpenCV_LIBS}
)
