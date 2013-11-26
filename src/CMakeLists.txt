set(EXE main)

add_executable(${EXE}
               main.cpp)

install(TARGETS ${EXE} DESTINATION bin/)
