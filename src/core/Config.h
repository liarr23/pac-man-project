#pragma once

#include "Types.h"

// core
#include "InputHandler.h"
#include "GameEngine.h"
#include "GameObject.h"

// entities
#include "../entities/Character.h"
#include "../entities/Ghost.h"
#include "../entities/Blinky.h"
#include "../entities/Pinky.h"
#include "../entities/Inky.h"
#include "../entities/Clyde.h"
#include "../entities/Pacman.h"

// items
#include "../items/Item.h"
#include "../items/Dot.h"
#include "../items/PowerPellet.h"
#include "../items/Fruit.h"

// managers
#include "../managers/ScoreManager.h"
#include "../managers/SoundManager.h"

// map
#include "../map/MapManager.h"
#include "../map/Wall.h"

// states
#include "../states/GameState.h"
#include "../states/MenuState.h"
#include "../states/PlayingState.h"
#include "../states/PausedState.h"
#include "../states/GameOverState.h"

// ui
#include "../ui/UIManager.h"

namespace Config {//游戏配置常量
    constexpr int TILE_SIZE = 32;
    constexpr int MAP_WIDTH = 28;
    constexpr int MAP_HEIGHT = 31;
    constexpr float PACMAN_SPEED = 100.f;
    constexpr float GHOST_SPEED = 80.f;
    constexpr int INITIAL_LIVES = 3;
    const std::string HIGHSCORE_PATH = "save/highscore.txt";
}
