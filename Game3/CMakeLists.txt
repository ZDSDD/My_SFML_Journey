cmake_minimum_required(VERSION 3.25)
project(Game3)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game3 main.cpp Game.cpp Game.h Player.cpp Player.h Bullet.cpp Bullet.h Enemy.cpp Enemy.h)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
file(COPY "Textures" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "Fonts" DESTINATION "${CMAKE_BINARY_DIR}")
target_link_libraries(Game3 sfml-system sfml-window sfml-graphics sfml-audio)
