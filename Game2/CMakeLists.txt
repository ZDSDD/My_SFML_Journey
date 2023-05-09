cmake_minimum_required(VERSION 3.25)
project(Game2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game2 main.cpp Game.cpp Game.h Player.cpp Player.h SwagBall.cpp SwagBall.h)

SET(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
target_link_libraries(Game2 sfml-system sfml-window sfml-graphics sfml-audio)