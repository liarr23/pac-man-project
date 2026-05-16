#include "MenuState.h"
#include "../core/GameEngine.h"
#include "PlayingState.h"
#include <fstream>
MenuState::MenuState(int highScore): highScore(highScore)
{
    std::ifstream file("highscore.txt");
    if (file.is_open()) {
        file >> this->highScore;
    }
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
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }
    float winW = static_cast<float>(window.getSize().x);
    float winH = static_cast<float>(window.getSize().y);

    sf::Text titleText("Pacman Game", font, 70);
    titleText.setFillColor(sf::Color::Yellow);
    auto titleBounds = titleText.getLocalBounds();
    titleText.setPosition((winW - titleBounds.width) / 2, winH * 0.18f);
    window.draw(titleText);

    sf::Text highScoreText("High Score: " + std::to_string(highScore), font, 40);
    highScoreText.setFillColor(sf::Color::Green);
    auto hsBounds = highScoreText.getLocalBounds();
    highScoreText.setPosition((winW - hsBounds.width) / 2, winH * 0.38f);
    window.draw(highScoreText);

    sf::Text instructionText("Press Enter to Start\nPress Escape to Quit", font, 30);
    instructionText.setFillColor(sf::Color::White);
    auto instBounds = instructionText.getLocalBounds();
    instructionText.setPosition((winW - instBounds.width) / 2, winH * 0.55f);
    window.draw(instructionText);
}
