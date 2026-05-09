#include"GameOverState.h"
#include "../core/GameEngine.h"
#include "MenuState.h"
#include "PlayingState.h"

GameOverState::GameOverState(bool won, int finalScore) : m_won(won), m_finalScore(finalScore) {
}
void GameOverState::handleInput(GameEngine& engine, sf::Event& event) 
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        engine.changeState(new MenuState()); // Return to menu
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
    {
        engine.popState(); // Close the game
    }
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R)
    {
        engine.changeState(new PlayingState()); // Restart the game
    }
}
void GameOverState::render(sf::RenderWindow& window) 
{
    // Render the game over screen (you can add a "Game Over" text here)
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        // Handle error
        return;
    }
    sf::Text resultText(m_won ? "You Win!, Final Score: " + std::to_string(m_finalScore) : "You Lose!, Final Score: " + std::to_string(m_finalScore), font, 70);
    if (m_won) {
        resultText.setFillColor(sf::Color::Green);
    } 
    else {
        resultText.setFillColor(sf::Color::Red);
    }
    resultText.setPosition(100, 100);
    window.draw(resultText);
    sf::Text gameOverText("Game Over : Press Enter to Return to Menu \n Press Escape to Quit \n Press R to Restart", font, 50);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(100, 200);
    window.draw(gameOverText);
}