cmake_minimum_required(VERSION 3.21)
project(svg_creator)

set(CMAKE_CXX_STANDARD 17)

add_executable(svg_creator main.cpp src/shape.cpp src/shape.h src/shapes/rectangle.cpp src/shapes/rectangle.h src/helpers/Prompter.cpp src/helpers/Prompter.h src/shapes/circle.cpp src/shapes/circle.h src/shapes/polygon.cpp src/shapes/polygon.h src/shapes/segment.cpp src/shapes/segment.h)
