#include"PowerPellet.h"
ItemType PowerPellet::onCollect() {
    return ItemType::PowerPellet;
}
int PowerPellet::getScore() const {
    return m_score;
}