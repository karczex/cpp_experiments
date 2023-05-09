cmake_minimum_required(VERSION 3.3)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

#find_package(package_name REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
#target_link_libraries(${CMAKE_PROJECT_NAME} package_name)

