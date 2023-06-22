cmake_minimum_required(VERSION 3.25)
project(Game4)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game4 main.cpp stdafx.h SourceFiles/Game.cpp Headers/Game.h SourceFiles/Player.cpp Headers/Player.h SourceFiles/TileMap.cpp Headers/TileMap.h SourceFiles/Tile.cpp Headers/Tile.h)

set(PRECOMPILED_HEADERS stdafx.h)
target_precompile_headers(Game4 PRIVATE ${PRECOMPILED_HEADERS})


set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
file(COPY "Textures" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Fonts" DESTINATION "${CMAKE_BINARY_DIR}")
target_link_libraries(Game4 sfml-system sfml-window sfml-graphics sfml-audio)