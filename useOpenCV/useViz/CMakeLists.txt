cmake_minimum_required(VERSION 3.0)
project( launching_viz )
find_package( OpenCV REQUIRED )

find_package(VTK)

include(${VTK_USE_FILE})

add_executable( launching_viz launching_viz.cpp )
target_link_libraries( launching_viz ${OpenCV_LIBS} )

add_executable( widget_pose widget_pose.cpp )
target_link_libraries( widget_pose ${OpenCV_LIBS} )

add_executable( transformations transformations.cpp )
target_link_libraries( transformations  ${OpenCV_LIBS} )

add_executable( example example.cpp )
target_link_libraries( example ${OpenCV_LIBS} )

add_executable(mytest test.cpp )
target_link_libraries( mytest ${OpenCV_LIBS} )

add_executable(creating_widgets creating_widgets.cpp )
target_link_libraries( creating_widgets
    ${OpenCV_LIBS}
    ${VTK_LIBRARIES}
    )


add_executable(histo3D histo3D.cpp )
target_link_libraries( histo3D ${OpenCV_LIBS} )
