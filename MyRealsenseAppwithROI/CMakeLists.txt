cmake_minimum_required(VERSION 3.15)
project(MyRealsenseAppwithROI)

find_package(realsense2 CONFIG REQUIRED)

add_executable(MyRealsenseAppwithROI main.cpp)
target_link_libraries(MyRealsenseAppwithROI PRIVATE realsense2::realsense2)
