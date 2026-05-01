#include "ScoreManager.h"
#include <fstream>

ScoreManager::ScoreManager() : m_score(0), m_highScore(0) {}

void ScoreManager::addScore(int points) {
    m_score += points;
}

int ScoreManager::getScore() const {
    return m_score;
}

int ScoreManager::getHighScore() const {
    return m_highScore;
}

bool ScoreManager::isNewHighScore() const {
    return m_score > m_highScore;
}

void ScoreManager::reset() {
    m_score = 0;
}

void ScoreManager::loadHighScore(const std::string& filepath) {
    m_filepath = filepath;
    std::ifstream file(filepath);
    if (file.is_open()) {
        file >> m_highScore;
    }
}

void ScoreManager::saveHighScore(const std::string& filepath) {
    if (m_score > m_highScore) {
        m_highScore = m_score;
        std::ofstream file(filepath);
        if (file.is_open()) {
            file << m_highScore;
        }
    }
}
