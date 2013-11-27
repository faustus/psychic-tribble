set(EXE test_suite)


add_definitions(-D_VERBOSE)
include_directories(../src/)
include_directories(${GTEST_SRC_DIR})

add_executable(${EXE}
               main_test.cpp
              )

target_link_libraries(${EXE} pthread gtest gtest_main)

add_test(NAME int_test COMMAND ${EXE})
