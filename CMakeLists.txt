cmake_minimum_required(VERSION 3.16)
project(GreenVoid)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED CONFIG)
find_package(SDL2_image REQUIRED CONFIG)

add_executable(GreenVoid 
    src/main.cpp 
    src/Game.cpp
    src/Renderable.cpp
    src/TextureManager.cpp
)

target_include_directories(GreenVoid PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GreenVoid PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_image::SDL2_image
)