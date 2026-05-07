#include"PlayingState.h"

using namespace std;
PlayingState::PlayingState() {
    m_map = new MapManager();
    m_pacman = new Pacman(m_map->getPacmanStartPos());
    m_uiManager = new UIManager();
    m_scoreManager = new ScoreManager();
    for(int i=0; i < 4; i++) {
        m_ghosts.push_back(new Ghost(m_map->getGhostStartPos(i)));
    }
}