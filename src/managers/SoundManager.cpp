#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
    m_chomp.setBuffer(m_chompBuffer);
    m_powerPellet.setBuffer(m_powerPelletBuffer);
    m_ghostEaten.setBuffer(m_ghostEatenBuffer);
    m_death.setBuffer(m_deathBuffer);
    m_gameStart.setBuffer(m_gameStartBuffer);
    m_gameOver.setBuffer(m_gameOverWinBuffer);
}

bool SoundManager::loadAll() {
    bool ok = true;

    auto tryLoad = [&](const std::string& path, sf::SoundBuffer& buf) {
        if (!buf.loadFromFile(path)) {
            std::cerr << "[SoundManager] Failed to load: " << path << std::endl;
            ok = false;
        }
    };

    tryLoad("assets/sounds/chomp.wav", m_chompBuffer);
    tryLoad("assets/sounds/power_pellet.wav", m_powerPelletBuffer);
    tryLoad("assets/sounds/ghost_eaten.wav", m_ghostEatenBuffer);
    tryLoad("assets/sounds/death.wav", m_deathBuffer);
    tryLoad("assets/sounds/game_start.wav", m_gameStartBuffer);
    tryLoad("assets/sounds/game_over_win.wav", m_gameOverWinBuffer);
    tryLoad("assets/sounds/game_over_lose.wav", m_gameOverLoseBuffer);

    if (!m_bgm.openFromFile("assets/sounds/bgm.ogg")) {
        // BGM is optional, don't fail
    }

    m_loaded = ok;
    return ok;
}

void SoundManager::playChomp()          { if (m_loaded) { m_chomp.stop(); m_chomp.play(); } }
void SoundManager::playPowerPellet()    { if (m_loaded) { m_powerPellet.stop(); m_powerPellet.play(); } }
void SoundManager::playGhostEaten()     { if (m_loaded) { m_ghostEaten.stop(); m_ghostEaten.play(); } }
void SoundManager::playDeath()          { if (m_loaded) { m_death.stop(); m_death.play(); } }
void SoundManager::playGameStart()      { if (m_loaded) { m_gameStart.stop(); m_gameStart.play(); } }

void SoundManager::playGameOver(bool won) {
    if (!m_loaded) return;
    m_gameOver.stop();
    m_gameOver.setBuffer(won ? m_gameOverWinBuffer : m_gameOverLoseBuffer);
    m_gameOver.play();
}

void SoundManager::playBGM() {
    m_bgm.setLoop(true);
    m_bgm.play();
}

void SoundManager::stopBGM() {
    m_bgm.stop();
}

void SoundManager::pauseBGM(bool paused) {
    if (paused)
        m_bgm.pause();
    else
        m_bgm.play();
}
