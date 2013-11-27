set(MUL test_mul)

#add_definitions(-D_VERBOSE)
include_directories(../)
include_directories(../../)
include_directories(../../../src/)
include_directories(${GTEST_SRC_DIR})

#MULTIPLICATION
add_executable(${MUL}
               ad_vector_mul_test.cpp
              )

target_link_libraries(${MUL} pthread gtest gtest_main)

add_test(NAME multiplication_test COMMAND ${MUL})
