cmake_minimum_required(VERSION 3.14)

project(
  Breeze
  VERSION 0.1
  LANGUAGES CXX
  )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
add_subdirectory(app)

