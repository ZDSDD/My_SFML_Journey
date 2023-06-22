cmake_minimum_required(VERSION 3.25)
project(Snake)

set(CMAKE_CXX_STANDARD 17)

add_executable(Snake main.cpp Game.cpp Game.h predefined.h predefined.h)

set(PRECOMPILED_HEADERS ../../Flappy/predefined.h)
target_precompile_headers(Snake PRIVATE ${PRECOMPILED_HEADERS})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
file(COPY "Textures" DESTINATION "${CMAKE_BINARY_DIR}")
#file(COPY "Fonts" DESTINATION "${CMAKE_BINARY_DIR}")
target_link_libraries(Snake sfml-system sfml-window sfml-graphics sfml-audio)