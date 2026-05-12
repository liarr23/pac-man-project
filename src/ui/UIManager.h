#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public:
    UIManager(int score = 0, int highScore = 0, int lives = 3);
    ~UIManager();
    void render(sf::RenderWindow& window);
private:
    int m_score;
    int m_highScore;
    int m_lives;
};
