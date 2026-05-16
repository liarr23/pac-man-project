#include "Pacman.h"
#include "../map/MapManager.h"
#include <cmath>

Pacman::Pacman() {
}

Pacman::Pacman(int x, int y, int lives, double speed, Direction d, MapManager* map) {
    m_position = Point(x, y);
    this->map = map;
    this->lives = lives;
    this->speed = speed;
    this->dir = d;
    spawnPoint = Point(x, y);
    nextdir = Direction::None;
    moveCooldown = 0.0;
    animTimer = 0.0;
}

Pacman::~Pacman() = default;

void Pacman::setDirection(Direction d) {
    if (d == Direction::None) return;
    nextdir = d;
}

void Pacman::update(float deltaTime) {
    if (!m_active) return;

    moveCooldown -= deltaTime * speed;
    animTimer += deltaTime;

    if (moveCooldown > 0.0) return;
    moveCooldown = 1.0;
    if (nextdir != Direction::None) {
        Point next = m_position;
        switch (nextdir) {
            case Direction::Up:    next.y--; break;
            case Direction::Down:  next.y++; break;
            case Direction::Left:  next.x--; break;
            case Direction::Right: next.x++; break;
            default: break;
        }
        if (canWalkTo(next)) {
            dir = nextdir;
            nextdir = Direction::None;
        }
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

void Pacman::render(sf::RenderWindow& window) {
    static constexpr float TILE_SIZE = 32.0f;
    static constexpr float RADIUS = 14.0f;
    static constexpr int SEGMENTS = 30;

    float px = m_position.x * TILE_SIZE + TILE_SIZE / 2.0f;
    float py = m_position.y * TILE_SIZE + TILE_SIZE / 2.0f;

    // Mouth angle: oscillates between 0 (closed) and ~45 degrees (open)
    float mouthAngle = 0.0f;
    if (dir != Direction::None) {
        mouthAngle = std::abs(std::sin(animTimer * 10.0f)) * 45.0f;
    }

    // Build Pac-Man as a convex shape (circle with wedge cut out)
    float startAngle = mouthAngle * 0.5f * 3.14159265f / 180.0f;
    float endAngle = (360.0f - mouthAngle * 0.5f) * 3.14159265f / 180.0f;

    sf::ConvexShape shape;
    shape.setPointCount(SEGMENTS + 2);
    shape.setPoint(0, sf::Vector2f(0.f, 0.f)); // center

    for (int i = 0; i <= SEGMENTS; i++) {
        float angle = startAngle + (endAngle - startAngle) * i / SEGMENTS;
        shape.setPoint(i + 1, sf::Vector2f(
            std::cos(angle) * RADIUS,
            std::sin(angle) * RADIUS
        ));
    }

    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(0.f, 0.f);
    shape.setPosition(px, py);

    // Rotate based on direction
    switch (dir) {
        case Direction::Right: shape.setRotation(0.f); break;
        case Direction::Down:  shape.setRotation(90.f); break;
        case Direction::Left:  shape.setRotation(180.f); break;
        case Direction::Up:    shape.setRotation(270.f); break;
        default:               shape.setRotation(0.f); break;
    }

    window.draw(shape);
}

sf::FloatRect Pacman::getBounds() const {
    return sf::FloatRect(
        m_position.x * 32.0f, m_position.y * 32.0f,
        32.0f, 32.0f
    );
}

void Pacman::reset() {
    m_position = spawnPoint;
    dir = Direction::None;
    nextdir = Direction::None;
    moveCooldown = 0.0;
}

void Pacman::die() {
    lives--;
    reset();
}
