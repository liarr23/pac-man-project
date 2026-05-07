cmake_minimum_required(VERSION 3.15)

project(SFMLProject VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_ROOT "C:/Users/liar/Downloads/SFML-2.6.1-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.1")

set(SOURCES
    src/main.cpp
    src/core/GameObject.cpp
    src/core/GameEngine.cpp
    src/core/InputHandler.cpp
    src/entities/Character.cpp
    src/entities/Pacman.cpp
    src/entities/Ghost.cpp
    src/entities/Blinky.cpp
    src/entities/Pinky.cpp
    src/entities/Inky.cpp
    src/entities/Clyde.cpp
    src/items/Item.cpp
    src/items/Dot.cpp
    src/items/PowerPellet.cpp
    src/items/Fruit.cpp
    src/map/MapManager.cpp
    src/map/Wall.cpp
    src/states/GameState.cpp
    src/states/MenuState.cpp
    src/states/PlayingState.cpp
    src/states/PausedState.cpp
    src/states/GameOverState.cpp
    src/managers/ScoreManager.cpp
    src/managers/SoundManager.cpp
    src/ui/UIManager.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_ROOT}/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_ROOT}/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)