#pragma once
#include <SFML/Audio.hpp>
#include <string>

class SoundManager {
public:
    SoundManager();
    ~SoundManager() = default;

    void playBackgroundMusic();
    void stopBackgroundMusic();
    void playEatDot();
    void playEatPowerPellet();
    void playEatGhost();
    void playDeath();
    void playHurt();
    void playGameOver();
    void playVictory();
    void setMusicVolume(float volume);
    void setSoundVolume(float volume);

private:
    sf::Music m_backgroundMusic;
    sf::SoundBuffer m_eatDotBuffer;
    sf::SoundBuffer m_eatPowerPelletBuffer;
    sf::SoundBuffer m_eatGhostBuffer;
    sf::SoundBuffer m_deathBuffer;
    sf::SoundBuffer m_hurtBuffer;
    sf::SoundBuffer m_gameOverBuffer;
    sf::SoundBuffer m_victoryBuffer;
    sf::Sound m_eatDotSound;
    sf::Sound m_eatPowerPelletSound;
    sf::Sound m_eatGhostSound;
    sf::Sound m_deathSound;
    sf::Sound m_hurtSound;
    sf::Sound m_gameOverSound;
    sf::Sound m_victorySound;
    bool m_musicLoaded = false;
};
