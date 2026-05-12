#include "GameEngine.h"
#include "../states/GameState.h"

GameEngine::GameEngine()
    : m_window(sf::VideoMode(800, 800), "Pacman Game", sf::Style::Resize | sf::Style::Close) {
    m_window.setFramerateLimit(60);
    m_texture.loadFromFile("assets/textures/pacman.jpg");
    m_sprite.setTexture(m_texture);
}

GameEngine::~GameEngine() {
    for (auto* state : m_states) {
        delete state;
    }
}

void GameEngine::run() {
    while (m_window.isOpen()) {
        processEvents();
        update(m_clock.restart().asSeconds());
        render();
    }
}

void GameEngine::pushState(GameState* state) {
    m_states.push_back(state);
}

void GameEngine::popState() {
    if (!m_states.empty()) {
        delete m_states.back();
        m_states.pop_back();
    }
}

void GameEngine::changeState(GameState* state) {
    if (!m_states.empty()) {
        delete m_states.back();
        m_states.pop_back();
    }
    m_states.push_back(state);
}

void GameEngine::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
            m_window.close();
        }
        if (!m_states.empty()) {
            m_states.back()->handleInput(*this, event);
        }
    }
}

void GameEngine::update(float deltaTime) {
    if (!m_states.empty()) {
        m_states.back()->update(*this, deltaTime);
    }
}

void GameEngine::render() {
    m_window.clear(sf::Color::Black);
    m_window.draw(m_sprite);
    for (auto* state : m_states) {
        state->render(m_window);
    }
    m_window.display();
}
