#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public:
    UIManager(int score = 0, int highScore = 0, int lives = 3, int dotsRemaining = 0);
    ~UIManager();
    void update(int score, int highScore, int lives, int dotsRemaining, float powerTimeRatio = 0.f);
    void render(sf::RenderWindow& window);
private:
    int m_score;
    int m_highScore;
    int m_lives;
    int m_dotsRemaining;
    float m_powerTimeRatio;
};
