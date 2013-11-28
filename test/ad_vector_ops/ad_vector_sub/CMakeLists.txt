set(SUB test_sub)

include_directories(../)
include_directories(../../)
include_directories(../../../src/)
include_directories(${GTEST_SRC_DIR})

#SUBITION
add_executable(${SUB}
               ad_vector_sub_test.cpp
              )

target_link_libraries(${SUB} pthread gtest gtest_main)

add_test(NAME subtraction_test COMMAND ${SUB})

