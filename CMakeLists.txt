cmake_minimum_required(VERSION 3.17)
project(demo_1)
#set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS " CMAKE_SIZEOF_VOID_P")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
set(OpenCV_DIR "E:/jelly/ubuntu/opencv3.4.10/mingw_build/install")
#set(OpenCV_DIR "D:/software/opencv_3.4.14/opencv/build")
#set(OpenCV_DIR "E:\\jelly\\ubuntu\\opencv3.4.10\\opencv-3.4.10")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)

#
message(${OpenCV_LIBS})
#if (OpenCV_FOUND)
include_directories(${OpenCV_INCLUDE_DIRS})
#include_directories(
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\include"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\include\\opencv"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\include\\opencv2")
#    message(${OpenCV_LIBS})
#endif()

#add_executable(demo_1 haha.cpp face_detect.cpp detect.cpp)
#add_executable(demo_1 haha.cpp face_detect.cpp detect.cpp)
add_executable(demo_1 detect.cpp)
#
#add_executable(demo_1 face_detect.cpp)


set(OpenCV_LIBS
        opencv_core
        opencv_imgproc
        opencv_highgui
        opencv_imgcodecs
        opencv_xphoto
        opencv_imgproc
        opencv_objdetect
        opencv_face
        opencv_xobjdetect)


target_link_libraries(demo_1 ${OpenCV_LIBS})
#set(TARGET_LIBS
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_aruco3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_bgsegm3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_bioinspired3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_calib3d3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_ccalib3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_core3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_datasets3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_dnn3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_dnn_objdetect3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_dpm3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_face3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_features2d3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_flann3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_fuzzy3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_hfs3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_highgui3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_img_hash3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_imgcodecs3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_imgproc3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_line_descriptor3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_ml3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_objdetect3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_optflow3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_phase_unwrapping3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_photo3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_plot3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_reg3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_rgbd3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_saliency3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_shape3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_stereo3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_stitching3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_structured_light3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_superres3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_surface_matching3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_text3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_tracking3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_video3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_videoio3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_videostab3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_xfeatures2d3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_ximgproc3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_xobjdetect3410.dll.a"
#        "E:\\jelly\\ubuntu\\opencv3.4.10\\mingw_build\\install\\x64\\mingw\\lib\\libopencv_xphoto3410.dll.a"
#
#        )

#target_link_libraries(demo_1 ${OpenCV_LIBS})