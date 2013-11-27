set(EXE setup)


#add_definitions(-D_VERBOSE)
include_directories(../)
include_directories(../../src/)
include_directories(${GTEST_SRC_DIR})

add_executable(${EXE}
               ad_vector_setup.cpp
              )

target_link_libraries(${EXE} pthread gtest gtest_main)

add_test(NAME test_setup COMMAND ${EXE})
