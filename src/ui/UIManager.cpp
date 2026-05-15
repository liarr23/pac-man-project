#include "UIManager.h"

UIManager::UIManager(int score, int highScore, int lives): m_score(score), m_highScore(highScore), m_lives(lives) {
}

UIManager::~UIManager() {
}
void UIManager::update(int score, int highScore, int lives) {
    m_score = score;
    m_highScore = highScore;
    m_lives = lives;
}
void UIManager::render(sf::RenderWindow& window) 
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        // Handle error
        return;
    }
    sf::Text scoreText("Score: " + std::to_string(m_score), font, 30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 90);
    window.draw(scoreText);
    sf::Text highScoreText("High Score: " + std::to_string(m_highScore), font, 30);
    highScoreText.setFillColor(sf::Color::Green);
    highScoreText.setPosition(10, 50);
    window.draw(highScoreText);
    sf::Text livesText("Lives: " + std::to_string(m_lives), font, 30);
    livesText.setFillColor(sf::Color::Red);
    livesText.setPosition(10, 10);
    window.draw(livesText);    
}