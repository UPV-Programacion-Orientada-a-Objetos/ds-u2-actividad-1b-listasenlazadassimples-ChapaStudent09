cmake_minimum_required(VERSION 3.10)
project(SistemaIoTSensores)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(sensores
    src/main.cpp
)

install(TARGETS sensores DESTINATION bin)
