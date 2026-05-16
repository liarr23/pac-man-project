#include "PlayingState.h"
#include "../core/Config.h"
#include "../map/MapManager.h"
#include "../map/Wall.h"
#include "../entities/Pacman.h"
#include "../entities/Blinky.h"
#include "../entities/Pinky.h"
#include "../entities/Inky.h"
#include "../entities/Clyde.h"
#include "../items/Dot.h"
#include "../items/PowerPellet.h"
#include "../items/Fruit.h"
#include "../ui/UIManager.h"
#include "../managers/ScoreManager.h"
#include "../core/Config.h"
#include "PausedState.h"
#include "GameOverState.h"
#include "../core/Types.h"

using namespace std;
PlayingState::PlayingState() 
{
    m_map = new MapManager(Config::MAP_WIDTH, Config::MAP_HEIGHT);
    m_map->LoadFromFile("assets/maps/map2.txt");
    m_pacman = new Pacman(m_map->getPacmanStartPos().x,m_map->getPacmanStartPos().y,Config::INITIAL_LIVES,Config::PACMAN_SPEED,Direction::None,m_map);
    m_uiManager = new UIManager();
    m_scoreManager = new ScoreManager();
    m_scoreManager->loadHighScore("highscore.txt");
    m_soundManager = new SoundManager();
    m_soundManager->playBackgroundMusic();
    m_ghosts.push_back(new Blinky(m_map->getBlinkyStartPos().x,m_map->getBlinkyStartPos().y,Config::GHOST_SPEED,Direction::None,m_map));
    m_ghosts.push_back(new Pinky(m_map->getPinkyStartPos().x,m_map->getPinkyStartPos().y,Config::GHOST_SPEED,Direction::None,m_map));
    m_ghosts.push_back(new Inky(m_map->getInkyStartPos().x,m_map->getInkyStartPos().y,Config::GHOST_SPEED,Direction::None,m_map));
    m_ghosts.push_back(new Clyde(m_map->getClydeStartPos().x,m_map->getClydeStartPos().y,Config::GHOST_SPEED,Direction::None,m_map));
    for (auto ghost : m_ghosts) {
        ghost->setPacman(m_pacman);
        ghost->setBlinky(m_ghosts[0]);
    }
    for(int i = 0; i < m_map->getWidth(); i++) {
        for(int j = 0; j < m_map->getHeight(); j++) {
            char tile = m_map->getWord(i, j);
            if (tile == '.') {
                m_items.push_back(new Dot(i, j));
            } else if (tile == 'O') {
                m_items.push_back(new PowerPellet(i, j));
            } else if (tile == '#') {
                m_walls.push_back(new Wall(i, j));
            } else if (tile == 'F') {
                m_items.push_back(new Fruit(i, j));
            } else if (tile == 'E'){
                revivePoint = Point(i, j);
            }
        }
    }
}

PlayingState::~PlayingState() 
{
    delete m_pacman;
    for (auto ghost : m_ghosts) {
        delete ghost;
    }
    for (auto item : m_items) {
        delete item;
    }
    for (auto wall : m_walls) {
        delete wall;
    }
    delete m_map;
    delete m_uiManager;
    delete m_scoreManager;
    delete m_soundManager;
}


void PlayingState::handleInput(GameEngine& engine, sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
            case sf::Keyboard::W:
                m_pacman->setDirection(Direction::Up); break;
            case sf::Keyboard::Down:
            case sf::Keyboard::S:
                m_pacman->setDirection(Direction::Down); break;
            case sf::Keyboard::Left:
            case sf::Keyboard::A:
                m_pacman->setDirection(Direction::Left); break;
            case sf::Keyboard::Right:
            case sf::Keyboard::D:
                m_pacman->setDirection(Direction::Right); break;
            case sf::Keyboard::P:
            case sf::Keyboard::Escape:
                m_soundManager->stopBackgroundMusic();
                engine.pushState(new PausedState()); break;
            default: break;
        }
    }
}

void PlayingState::update(GameEngine& engine, float deltaTime)
{
    m_pacman->update(deltaTime);
    for (auto ghost : m_ghosts) {
        ghost->update(deltaTime);
    }
    if(!m_soundManager->isBackgroundMusicPlaying()) {
        m_soundManager->playBackgroundMusic();
    }
    // Pacman vs Items
    for (auto it = m_items.begin(); it != m_items.end();) {
        Item* item = *it;
        if (item->isActive() && m_pacman->getBounds().intersects(item->getBounds())) {
            ItemType type = item->onCollect();
            m_scoreManager->addScore(item->getScore());

            if (type == ItemType::PowerPellet) {
                m_soundManager->playEatPowerPellet();
                for (auto ghost : m_ghosts) {
                    ghost->setFrightened();
                }
            }
            if (type == ItemType::Dot) {
                m_soundManager->playEatDot();
            }
            delete item;
            it = m_items.erase(it);
        } else {
            ++it;
        }
    }

    // Pacman vs Ghosts
    for (auto ghost : m_ghosts) {
        if (!ghost->isAlive) continue;
        if (!m_pacman->getBounds().intersects(ghost->getBounds())) continue;

        if (ghost->state == State::Frightened) {
            ghost->eaten();
            m_scoreManager->addScore(200);
            m_soundManager->playEatGhost();
        } else if (ghost->state != State::Eaten) {
            m_soundManager->playHurt();
            m_pacman->die();
            if (m_pacman->lives <= 0) {
                m_soundManager->stopBackgroundMusic();
                m_soundManager->playGameOver();
                m_scoreManager->saveHighScore("highscore.txt");
                engine.changeState(new GameOverState(false, m_scoreManager->getScore()));
                return;
            }
            for (auto g : m_ghosts) {
                g->reset();
            }
        }
    }

    // Count remaining dots
    int dotsRemaining = 0;
    for (auto item : m_items) {
        if (item->onCollect() == ItemType::Dot || item->onCollect() == ItemType::PowerPellet) {
            dotsRemaining++;
        }
    }
    if (dotsRemaining == 0) {
        m_soundManager->stopBackgroundMusic();
        m_soundManager->playVictory();
        m_scoreManager->saveHighScore("highscore.txt");
        engine.changeState(new GameOverState(true, m_scoreManager->getScore()));
        return;
    }
    // Power pellet timer
    float powerTimeRatio = 0.f;
    for (auto ghost : m_ghosts) {
        if (ghost->state == State::Frightened) {
            float remaining = static_cast<float>(Ghost::FRIGHTENED_DURATION - ghost->scarytime);
            float ratio = remaining / static_cast<float>(Ghost::FRIGHTENED_DURATION);
            if (ratio > powerTimeRatio) powerTimeRatio = ratio;
        }
    }
    m_uiManager->update(m_scoreManager->getScore(), m_scoreManager->getHighScore(), m_pacman->lives, dotsRemaining, powerTimeRatio);
}
 
void PlayingState::render(sf::RenderWindow& window) 
{
    for (auto wall : m_walls) {
        wall->render(window);
    }
    for (auto item : m_items) {
        item->render(window);
    }
    m_pacman->render(window);
    for (auto ghost : m_ghosts) {
        ghost->render(window);
    }
    m_uiManager->render(window);
}
