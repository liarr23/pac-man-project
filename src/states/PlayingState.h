#pragma once
#include "GameState.h"
#include <vector>

class Pacman;
class Ghost;
class Item;
class MapManager;
class UIManager;
class ScoreManager;

class PlayingState : public GameState {
public:
    PlayingState();
    ~PlayingState();
    void handleInput(GameEngine& engine, sf::Event& event) override;
    void update(GameEngine& engine, float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    Pacman* m_pacman;
    std::vector<Ghost*> m_ghosts;
    std::vector<Item*> m_items;
    MapManager* m_map;
    UIManager* m_uiManager;
    ScoreManager* m_scoreManager;
};
