cmake_minimum_required(VERSION 3.16)
project(PacMan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_ROOT "C:/Users/MrX/Downloads/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2.6 COMPONENTS system window graphics audio network REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
        opengl32
        winmm
        gdi32
)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})