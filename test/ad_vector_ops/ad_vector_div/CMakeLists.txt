set(DIV test_div)

#add_definitions(-D_VERBOSE)
include_directories(../)
include_directories(../../)
include_directories(../../../src/)
include_directories(${GTEST_SRC_DIR})

#DIVISION
add_executable(${DIV}
               ad_vector_div_test.cpp
              )

target_link_libraries(${DIV} pthread gtest gtest_main)

add_test(NAME division_test COMMAND ${DIV})

