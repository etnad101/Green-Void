cmake_minimum_required(VERSION 3.16)
project(GreenVoid)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 CONFIG REQUIRED )
find_package(SDL2_image CONFIG REQUIRED )

add_executable(GreenVoid
    src/main.cpp
    src/Engine.cpp
    src/Renderable.cpp
    src/Tile.cpp
    src/TextureManager.cpp
    src/Player.cpp
    src/World.cpp
    src/Game.cpp
)

target_include_directories(GreenVoid PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GreenVoid PRIVATE
    SDL2::SDL2
    SDL2::SDL2main
    SDL2_image::SDL2_image-static
)
