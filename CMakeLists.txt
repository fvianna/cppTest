cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(cppTest VERSION 1.1.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Makes version major and minor available in the source code
configure_file(./src/in/config.hpp.in ./include/config.hpp)

# add executables to the project
add_executable(cppTest ./src/main.cpp)

# adds the binary directory as a path to be serched for include files
target_include_directories(cppTest PUBLIC "${PROJECT_BINARY_DIR}/include")
