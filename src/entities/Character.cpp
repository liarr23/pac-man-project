//
// Created by MrX on 2026/4/29.
//

#include "Character.h"
#include "../map/MapManager.h"

bool Character::canWalkTo(int x, int y) const {
    return map && map->isWalkable(x, y);
}

bool Character::canWalkTo(const Point &p) const {
    return map && map->isWalkable(p.x, p.y);
}

Direction Character::opposite(Direction dir) {
    if (dir == Direction::None) return Direction::None;
    else if (dir == Direction::Up) return Direction::Down;
    else if (dir == Direction::Down) return Direction::Up;
    else if (dir == Direction::Left) return Direction::Right;
    else if (dir == Direction::Right) return Direction::Left;
    else return Direction::None;
}
