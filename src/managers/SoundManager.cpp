#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
    if (m_backgroundMusic.openFromFile("assets/sounds/background.flac")) {
        m_musicLoaded = true;
        m_backgroundMusic.setLoop(true);
        m_backgroundMusic.setVolume(30.f);
    }
    if (m_eatDotBuffer.loadFromFile("assets/sounds/eat1.ogg")) {
        m_eatDotSound.setBuffer(m_eatDotBuffer);
    }
    if (m_eatPowerPelletBuffer.loadFromFile("assets/sounds/eat1.ogg")) {
        m_eatPowerPelletSound.setBuffer(m_eatPowerPelletBuffer);
    }
    if (m_eatGhostBuffer.loadFromFile("assets/sounds/burp.ogg")) {
        m_eatGhostSound.setBuffer(m_eatGhostBuffer);
    }
    if (m_deathBuffer.loadFromFile("assets/sounds/hit2.ogg")) {
        m_deathSound.setBuffer(m_deathBuffer);
    }
    if (m_hurtBuffer.loadFromFile("assets/sounds/hurt.ogg")) {
        m_hurtSound.setBuffer(m_hurtBuffer);
    }
    if (m_gameOverBuffer.loadFromFile("assets/sounds/hit2.ogg")) {
        m_gameOverSound.setBuffer(m_gameOverBuffer);
    }
    if (m_victoryBuffer.loadFromFile("assets/sounds/eat1.ogg")) {
        m_victorySound.setBuffer(m_victoryBuffer);
    }
}

void SoundManager::playBackgroundMusic() {
    if (m_musicLoaded) {
        m_backgroundMusic.play();
    }
}

void SoundManager::stopBackgroundMusic() {
    if (m_musicLoaded) {
        m_backgroundMusic.stop();
    }
}

void SoundManager::playEatDot() {
    if (m_eatDotBuffer.getSampleCount() > 0) {
        m_eatDotSound.play();
    }
}

void SoundManager::playEatPowerPellet() {
    if (m_eatPowerPelletBuffer.getSampleCount() > 0) {
        m_eatPowerPelletSound.play();
    }
}

void SoundManager::playEatGhost() {
    if (m_eatGhostBuffer.getSampleCount() > 0) {
        m_eatGhostSound.play();
    }
}

void SoundManager::playDeath() {
    if (m_deathBuffer.getSampleCount() > 0) {
        m_deathSound.play();
    }
}

void SoundManager::playHurt() {
    if (m_hurtBuffer.getSampleCount() > 0) {
        m_hurtSound.play();
    }
}

void SoundManager::playGameOver() {
    if (m_gameOverBuffer.getSampleCount() > 0) {
        m_gameOverSound.play();
    }
}

void SoundManager::playVictory() {
    if (m_victoryBuffer.getSampleCount() > 0) {
        m_victorySound.play();
    }
}

void SoundManager::setMusicVolume(float volume) {
    if (m_musicLoaded) {
        m_backgroundMusic.setVolume(volume);
    }
}

void SoundManager::setSoundVolume(float volume) {
    m_eatDotSound.setVolume(volume);
    m_eatPowerPelletSound.setVolume(volume);
    m_eatGhostSound.setVolume(volume);
    m_deathSound.setVolume(volume);
    m_hurtSound.setVolume(volume);
    m_gameOverSound.setVolume(volume);
    m_victorySound.setVolume(volume);
}

bool SoundManager::isBackgroundMusicPlaying() const {
    return m_musicLoaded && m_backgroundMusic.getStatus() == sf::Music::Playing;
}