cmake_minimum_required(VERSION 3.7)
project(hello)
#find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Test.cpp Test.h Sales_item.h avg_price.h Sales_Data.hpp)
add_executable(hello ${SOURCE_FILES})
target_link_libraries(hello ${OpenCV_LIBS})