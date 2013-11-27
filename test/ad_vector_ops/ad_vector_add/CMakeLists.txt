set(ADD test_add)

#add_definitions(-D_VERBOSE)
include_directories(../)
include_directories(../../)
include_directories(../../../src/)
include_directories(${GTEST_SRC_DIR})

#ADDITION
add_executable(${ADD}
               ad_vector_add_test.cpp
              )

target_link_libraries(${ADD} pthread gtest gtest_main)

add_test(NAME addition_test COMMAND ${ADD})

