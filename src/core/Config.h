#pragma once

#include "Types.h"

// core
#include "InputHandler.h"
#include "GameEngine.h"

// entities
#include "../entities/GameObject.h"
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
