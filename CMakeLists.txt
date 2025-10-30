cmake_minimum_required(VERSION 3.5)

project(memory_arena VERSION 1.0.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE release)

set(SRC src/arena.c src/arena.h)

add_library(${PROJECT_NAME} STATIC ${SRC})

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 11)

target_compile_options(${PROJECT_NAME} PUBLIC "-Wall")
