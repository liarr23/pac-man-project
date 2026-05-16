#include"PausedState.h"
#include "../core/GameEngine.h"
void PausedState::handleInput(GameEngine& engine, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {

        engine.popState(); // Return to PlayingState
    }
    if ((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
    {
        engine.popState(); // Close the game
    }
}
void PausedState::update(GameEngine& engine, float deltaTime)
{
}
void PausedState::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }
    float winW = static_cast<float>(window.getSize().x);
    float winH = static_cast<float>(window.getSize().y);

    sf::Text titleText("Game Paused", font, 60);
    titleText.setFillColor(sf::Color::Red);
    auto titleBounds = titleText.getLocalBounds();
    titleText.setPosition((winW - titleBounds.width) / 2, winH * 0.3f);
    window.draw(titleText);

    sf::Text hintText("Press P to Resume\nPress Escape to Quit", font, 30);
    hintText.setFillColor(sf::Color::White);
    auto hintBounds = hintText.getLocalBounds();
    hintText.setPosition((winW - hintBounds.width) / 2, winH * 0.5f);
    window.draw(hintText);
}
