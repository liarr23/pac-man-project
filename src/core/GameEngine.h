#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class GameState;

class GameEngine {
public:
    GameEngine();
    ~GameEngine();
    void run();

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    std::vector<GameState*> m_states;
};
