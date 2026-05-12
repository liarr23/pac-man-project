#include "PlayingState.h"
#include "../map/MapManager.h"
#include "../entities/Pacman.h"
#include "../entities/Ghost.h"
#include "../ui/UIManager.h"
#include "../managers/ScoreManager.h"
#include "../core/Config.h"

using namespace std;
PlayingState::PlayingState() {
    m_map = new MapManager(Config::MAP_WIDTH, Config::MAP_HEIGHT);
    m_pacman = new Pacman(m_map->getPacmanStartPos().x,m_map->getPacmanStartPos().y,Config::INITIAL_LIVES,Config::PACMAN_SPEED,Direction::None,m_map);
    m_uiManager = new UIManager();
    m_scoreManager = new ScoreManager();
    for(int i=0; i < 4; i++) {
        m_ghosts.push_back(new Ghost(m_map->getGhostStartPos().x,m_map->getGhostStartPos().y,Config::GHOST_SPEED,Direction::None,m_map));
    }
}