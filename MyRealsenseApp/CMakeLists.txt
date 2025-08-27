cmake_minimum_required(VERSION 3.15)
project(MyRealsenseApp)

find_package(realsense2 CONFIG REQUIRED)

add_executable(MyRealsenseApp main.cpp)
target_link_libraries(MyRealsenseApp PRIVATE realsense2::realsense2)
