#include "Ghost.h"
#include "Pacman.h"
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>

void Ghost::update(float deltaTime) {
    if (!m_active) return;
    statetime += deltaTime;

    // Eaten ghost: move back to ghost house, then respawn
    if (state == State::Eaten) {
        moveCooldown -= deltaTime * speed * 3.0; // faster when returning
        if (moveCooldown > 0.0) return;
        moveCooldown = 1.0;

        // Navigate towards spawnPoint
        int dx = spawnPoint.x - m_position.x;
        int dy = spawnPoint.y - m_position.y;
        if (dx == 0 && dy == 0) {
            // Reached ghost house, respawn
            state = State::Chase;
            isAlive = true;
            scarytime = 0;
            statetime = 0;
            return;
        }
        // Move one step towards spawn
        Point next = m_position;
        if (std::abs(dx) >= std::abs(dy)) {
            next.x += (dx > 0) ? 1 : -1;
        } else {
            next.y += (dy > 0) ? 1 : -1;
        }
        m_position = next;
        return;
    }

    if (state == State::Frightened) {
        scarytime += deltaTime;
        if (scarytime >= FRIGHTENED_DURATION) {
            state = State::Chase;
            scarytime = 0;
            statetime = 0;
        }
    }

    moveCooldown -= deltaTime * speed;
    if (moveCooldown > 0.0) return;
    moveCooldown = 1.0;

    Point pacmanPos;
    Point blinkyPos;
    Direction pacmanDir = Direction::None;
    if (m_pacman) {
        sf::FloatRect b = m_pacman->getBounds();
        pacmanPos = Point(static_cast<int>(b.left / 32.0f), static_cast<int>(b.top / 32.0f));
        pacmanDir = m_pacman->dir;
    }
    if (m_blinky) {
        blinkyPos = m_blinky->getPosition();
    }
    Direction nextDir = getDirection(pacmanPos, blinkyPos, pacmanDir);
    if (nextDir != Direction::None) {
        dir = nextDir;
    }
    if (dir != Direction::None) {
        Point next = m_position;
        switch (dir) {
            case Direction::Up:    next.y--; break;
            case Direction::Down:  next.y++; break;
            case Direction::Left:  next.x--; break;
            case Direction::Right: next.x++; break;
            default: break;
        }
        if (canWalkTo(next)) {
            m_position = next;
            if (map) {
                if (m_position.x < 0) m_position.x = map->getWidth() - 1;
                if (m_position.x >= map->getWidth()) m_position.x = 0;
            }
        }
    }
}
namespace {

constexpr float TILE = 32.0f;
constexpr float HALF = 16.0f;
constexpr float HEAD_RADIUS = 13.0f;
constexpr float BODY_HEIGHT = 13.0f;
constexpr float BUMP_RADIUS = 4.0f;
constexpr float EYE_WHITE_RADIUS = 4.5f;
constexpr float PUPIL_RADIUS = 2.0f;
constexpr float PUPIL_OFFSET = 1.5f;
const sf::Color FRIGHTENED_BLUE(33, 33, 255);
const sf::Color PUPIL_COLOR(0, 0, 200);

void drawGhostBody(sf::RenderWindow& window, float px, float py,
                   const sf::Color& color)
{
    sf::CircleShape head(HEAD_RADIUS);
    head.setFillColor(color);
    head.setOrigin(HEAD_RADIUS, HEAD_RADIUS);
    head.setPosition(px, py - 3.0f);
    window.draw(head);

    sf::RectangleShape body(sf::Vector2f(HEAD_RADIUS * 2.0f, BODY_HEIGHT));
    body.setFillColor(color);
    body.setPosition(px - HEAD_RADIUS, py - 3.0f);
    window.draw(body);

    for (float offset = -8.0f; offset <= 8.0f; offset += 8.0f) {
        sf::CircleShape bump(BUMP_RADIUS);
        bump.setFillColor(color);
        bump.setOrigin(BUMP_RADIUS, BUMP_RADIUS);
        bump.setPosition(px + offset, py - 3.0f + BODY_HEIGHT);
        window.draw(bump);
    }
}

void drawNormalEyes(sf::RenderWindow& window, float px, float py, Direction dir)
{
    float offX = 0.0f, offY = 0.0f;
    switch (dir) {
        case Direction::Up:    offY = -PUPIL_OFFSET; break;
        case Direction::Down:  offY =  PUPIL_OFFSET; break;
        case Direction::Left:  offX = -PUPIL_OFFSET; break;
        case Direction::Right: offX =  PUPIL_OFFSET; break;
        default: break;
    }

    for (float eyeX : {px - 5.0f, px + 5.0f}) {
        sf::CircleShape white(EYE_WHITE_RADIUS);
        white.setFillColor(sf::Color::White);
        white.setOrigin(EYE_WHITE_RADIUS, EYE_WHITE_RADIUS);
        white.setPosition(eyeX, py - 4.0f);
        window.draw(white);

        sf::CircleShape pupil(PUPIL_RADIUS);
        pupil.setFillColor(PUPIL_COLOR);
        pupil.setOrigin(PUPIL_RADIUS, PUPIL_RADIUS);
        pupil.setPosition(eyeX + offX, py - 4.0f + offY);
        window.draw(pupil);
    }
}

void drawFrightenedFace(sf::RenderWindow& window, float px, float py)
{
    for (float eyeX : {px - 4.0f, px + 4.0f}) {
        sf::CircleShape dot(1.5f);
        dot.setFillColor(sf::Color::White);
        dot.setOrigin(1.5f, 1.5f);
        dot.setPosition(eyeX, py - 4.0f);
        window.draw(dot);
    }

    sf::VertexArray mouth(sf::LineStrip, 5);
    mouth[0].position = sf::Vector2f(px - 7.0f, py + 2.0f);
    mouth[1].position = sf::Vector2f(px - 4.0f, py - 1.0f);
    mouth[2].position = sf::Vector2f(px,        py + 2.0f);
    mouth[3].position = sf::Vector2f(px + 4.0f, py - 1.0f);
    mouth[4].position = sf::Vector2f(px + 7.0f, py + 2.0f);
    for (int i = 0; i < 5; ++i)
        mouth[i].color = sf::Color::White;
    window.draw(mouth);
}

} // anonymous namespace

void Ghost::render(sf::RenderWindow& window)
{
    if (!m_active) return;

    float px = m_position.x * TILE + HALF;
    float py = m_position.y * TILE + HALF;

    if (state == State::Eaten) {
        drawNormalEyes(window, px, py, dir);
        return;
    }

    sf::Color bodyColor;
    if (state == State::Frightened) {
        float remaining = FRIGHTENED_DURATION - scarytime;
        if (remaining <= 2.0f &&
            static_cast<int>(scarytime * 10) % 2 == 0) {
            bodyColor = sf::Color::White;
        } else {
            bodyColor = FRIGHTENED_BLUE;
        }
    } else {
        bodyColor = getColor();
    }

    drawGhostBody(window, px, py, bodyColor);

    if (state == State::Frightened) {
        drawFrightenedFace(window, px, py);
    } else {
        drawNormalEyes(window, px, py, dir);
    }
}

void Ghost::setFrightened() {
    if (state == State::Eaten) return;
    state = State::Frightened;
    scarytime = 0;
}

void Ghost::eaten() {
    state = State::Eaten;
    isAlive = false;
}

sf::FloatRect Ghost::getBounds() const {
    return sf::FloatRect(
        m_position.x * 32.0f, m_position.y * 32.0f,
        32.0f, 32.0f
    );
}

Point Ghost::getPosition() const {
    return m_position;
}
Ghost::Ghost(int x, int y, double speed, Direction dir,MapManager* map) {
    m_position.x = x;
    m_position.y = y;
    spawnPoint = map->GhostDoor;
    this->dir = dir;
    nextdir = Direction::None;
    scarytime = 0;
    this->speed = speed;
    isAlive = true;
    statetime = 0;
    state = State::Scatter;
    this->map = map;
}
void Ghost::reset() {
    m_position = spawnPoint;
    dir = Direction::None;
    nextdir = Direction::None;
    scarytime = 0;
    isAlive = true;
    statetime = 0;
}

Direction Ghost::getDirection(const Point& pacmanPos, const Point& blinkyPos, Direction pacmanDir) {
    Point current = this->m_position;
    Direction currentDir = this->dir;
    Direction oppo_direction = opposite(currentDir);
    std::vector<std::pair<Direction, Point>> candidates = {
            {Direction::Up,    {current.x, current.y - 1}},
            {Direction::Down,  {current.x, current.y + 1}},
            {Direction::Left,  {current.x - 1, current.y}},
            {Direction::Right, {current.x + 1, current.y}}
    };

    if (state == State::Frightened) {
        std::vector<Direction> validDirs;
        for (const auto& cand : candidates) {
            if (cand.first != oppo_direction && canWalkTo(cand.second)) {
                validDirs.push_back(cand.first);
            }
        }
        if (!validDirs.empty()) {
            return validDirs[std::rand() % validDirs.size()];
        }
        for (const auto& cand : candidates) {
            if (canWalkTo(cand.second)) {
                return cand.first;
            }
        }
        return Direction::None;
    }

    Point target = chase(pacmanPos, blinkyPos, pacmanDir);
    Direction best = Direction::None;
    int bestDist = 999999;

        for (const auto& cand : candidates) {
            Direction d = cand.first;
            Point next = cand.second;
            if (d == oppo_direction && currentDir != Direction::None) continue;
            if (!canWalkTo(next)) continue;
            int dist = std::abs(next.x - target.x) + std::abs(next.y - target.y);
            if (dist < bestDist) {
                bestDist = dist;
                best = d;
            }
        }
        if (best == Direction::None) {
            for (const auto& cand : candidates) {
                if (canWalkTo(cand.second)) {
                    return cand.first;
                }
            }
        }
        return best;
    }
