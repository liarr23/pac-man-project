#include"ScoreManager.h"
void ScoreManager::addScore(int points) {
    m_score += points;
}
int ScoreManager::getScore() const {
    return m_score;
}