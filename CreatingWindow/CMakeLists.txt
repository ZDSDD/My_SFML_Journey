cmake_minimum_required(VERSION 3.25)
project(CreatingWindow)

set(CMAKE_CXX_STANDARD 17)

add_executable(CreatingWindow main.cpp "Source Files/Game.cpp" "Source Files/Game.h")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

target_link_libraries(CreatingWindow sfml-system sfml-window sfml-graphics sfml-audio)