cmake_minimum_required(VERSION 2.6)
project(AutoDiffTypeLib)

enable_testing()
set(CMAKE_CXX_FLAGS "-O3 -std=c++11")
set(CMAKE_INSTALL_PREFIX /home/wes/Desktop/surreal_grammar/)

if(_VERBOSE)
   add_definitions(-D_VERBOSE)
endif(_VERBOSE)
add_subdirectory(src/)

#TODO add option for turning off tests

add_subdirectory(gtest-1.7.0)
set(GTEST_DIR /home/wes/Desktop/surreal_grammar/gtest-1.7.0)
set(GTEST_SRC_DIR /home/wes/Desktop/surreal_grammar/gtest-1.7.0/include/)
add_subdirectory(test/)
