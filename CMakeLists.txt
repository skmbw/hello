cmake_minimum_required(VERSION 3.7)
project(hello)
find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(hello ${SOURCE_FILES})
target_link_libraries(hello ${OpenCV_LIBS})