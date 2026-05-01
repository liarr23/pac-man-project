#include "GameEngine.h"
GameEngine::GameEngine() : window(sf::VideoMode(800, 800), "Pacman Game", sf::Style::Resize | sf::Style::Close) {
    window.setFramerateLimit(60);
}
GameEngine::~GameEngine() {
}
void GameEngine::run()
{
    sf::Clock clock;
    while(window.isOpen())
    {
        processEvents();
        update(clock.restart());
        render();
    }
}
void GameEngine::processEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if((event.type == sf::Event::Closed)||(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
        }
        m_inputHandler.handleEvents(event);
    }
}
void GameEngine::update(sf::Time deltaTime)
{

}
void GameEngine::render()
{
    window.clear(sf::Color(144, 238, 144));
    // 在这里画你的图形
    window.display();
}