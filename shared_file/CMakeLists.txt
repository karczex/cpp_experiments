cmake_minimum_required(VERSION 3.10)

# set the project name
project(SMExperiment)
set(CMAKE_CXX_STANDARD 17)

# add the executable
add_executable(producer producer.cpp)

add_executable(consumer consumer.cpp)


