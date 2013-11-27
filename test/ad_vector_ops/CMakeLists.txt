set(ADD test_add)
set(SUB test_sub)
set(MUL test_mul)
#set(DIV test_div)

#add_definitions(-D_VERBOSE)
include_directories(../)
include_directories(../../src/)
include_directories(${GTEST_SRC_DIR})

#ADDITION
add_executable(${ADD}
               ad_vector_add_test.cpp
              )

target_link_libraries(${ADD} pthread gtest gtest_main)

add_test(NAME addition_test COMMAND ${ADD})

#SUBTRACTION
add_executable(${SUB}
               ad_vector_sub_test.cpp
              )

target_link_libraries(${SUB} pthread gtest gtest_main)

add_test(NAME subtraction_test COMMAND ${SUB})

#MULTIPLICATION
add_executable(${MUL}
               ad_vector_mul_test.cpp
              )

target_link_libraries(${MUL} pthread gtest gtest_main)

add_test(NAME multiplication_test COMMAND ${MUL})

