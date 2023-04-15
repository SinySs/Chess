cmake_minimum_required(VERSION 3.23)
project(sf)

set(CMAKE_CXX_STANDARD 14)


add_executable(sf main.cpp src/AssetManager.cpp)


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(include) #full way
include_directories("${PROJECT_SOURCE_DIR}/include")


target_link_libraries(sf sfml-system sfml-window sfml-graphics sfml-audio)
