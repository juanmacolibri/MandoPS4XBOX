cmake_minimum_required(VERSION 3.15)
project(MandoPS4XBOX)

set(CMAKE_CXX_STANDARD 17)

add_executable(MandoPS4XBOX main.cpp)

target_link_libraries(MandoPS4XBOX -lglfw -lGL -lGLEW -lX11 -lpthread -lXrandr -lXi)