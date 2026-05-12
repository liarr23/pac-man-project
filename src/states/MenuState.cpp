#include "MenuState.h"
#include "../core/GameEngine.h"
#include "PlayingState.h"
MenuState::MenuState(int highScore): highScore(highScore) 
{
} 
void MenuState::handleInput(GameEngine& engine, sf::Event& event) 
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
        engine.changeState(new PlayingState()); // Start the game
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
    {
        engine.popState(); // Close the game
    }
}
void MenuState::update(GameEngine& engine, float deltaTime) 
{
}
void MenuState::render(sf::RenderWindow& window) 
{
    // Render the menu screen (you can add a "Press Enter to Start" text here)
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        // Handle error
        return;
    }
    sf::Text titleText("Pacman Game", font, 70);
    titleText.setFillColor(sf::Color::Yellow);
    titleText.setPosition(200, 100);
    window.draw(titleText);
    sf::Text highScoreText("High Score: " + std::to_string(highScore), font, 50);
    highScoreText.setFillColor(sf::Color::Green);
    highScoreText.setPosition(200, 200);
    window.draw(highScoreText);
    sf::Text instructionText("Press Enter to Start\nPress Escape to Quit", font, 40);
    instructionText.setFillColor(sf::Color::White);
    instructionText.setPosition(200, 300);
    window.draw(instructionText);
}