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
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        // Handle error
        return;
    }
    sf::Text titleText("Pacman Game", font, 70);
    titleText.setFillColor(sf::Color::Yellow);
    auto titleBounds = titleText.getLocalBounds();
    titleText.setPosition((800 - titleBounds.width) / 2, 150);
    window.draw(titleText);

    sf::Text highScoreText("High Score: " + std::to_string(highScore), font, 40);
    highScoreText.setFillColor(sf::Color::Green);
    auto hsBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition((800 - hsBounds.width) / 2, 300);
    window.draw(highScoreText);

    sf::Text instructionText("Press Enter to Start\nPress Escape to Quit", font, 30);
    instructionText.setFillColor(sf::Color::White);
    auto instBounds = instructionText.getLocalBounds();
    instructionText.setPosition((800 - instBounds.width) / 2, 450);
    window.draw(instructionText);
}