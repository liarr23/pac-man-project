#include "PlayingState.h"
#include "../core/Config.h"
#include "../map/MapManager.h"
#include "../map/Wall.h"
#include "../entities/Pacman.h"
#include "../entities/Blinky.h"
#include "../entities/Pinky.h"
#include "../entities/Inky.h"
#include "../entities/Clyde.h"
#include "../items/Dot.h"
#include "../items/PowerPellet.h"
#include "../items/Fruit.h"
#include "../ui/UIManager.h"
#include "../managers/ScoreManager.h"
#include "../core/Config.h"

using namespace std;
PlayingState::PlayingState() {
    m_map = new MapManager(Config::MAP_WIDTH, Config::MAP_HEIGHT);
    m_pacman = new Pacman(m_map->getPacmanStartPos().x,m_map->getPacmanStartPos().y,Config::INITIAL_LIVES,Config::PACMAN_SPEED,Direction::None,m_map);
    m_uiManager = new UIManager();
    m_scoreManager = new ScoreManager();
    m_ghosts.push_back(new Blinky(m_map->getBlinkyStartPos().x, m_map->getBlinkyStartPos().y, Config::GHOST_SPEED, Direction::None, m_map));
    m_ghosts.push_back(new Pinky(m_map->getPinkyStartPos().x, m_map->getPinkyStartPos().y, Config::GHOST_SPEED, Direction::None, m_map));
    m_ghosts.push_back(new Inky(m_map->getInkyStartPos().x, m_map->getInkyStartPos().y, Config::GHOST_SPEED, Direction::None, m_map));
    m_ghosts.push_back(new Clyde(m_map->getClydeStartPos().x, m_map->getClydeStartPos().y, Config::GHOST_SPEED, Direction::None, m_map));
    for(int i = 0; i < m_map->getWidth(); i++) {
        for(int j = 0; j < m_map->getHeight(); j++) {
            char tile = m_map->getWord(i, j);
            if (tile == '.') {
                m_items.push_back(new Dot(i, j));
            } else if (tile == 'O') {
                m_items.push_back(new PowerPellet(i, j));
            } else if (tile == '#') {
                m_walls.push_back(new Wall(i, j));
            } else if (tile == 'F') {
                m_items.push_back(new Fruit(i, j));
            }
        }
    }
}