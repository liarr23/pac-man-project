#include"Dot.h"
ItemType Dot::onCollect() {
    return ItemType::Dot;
}
int Dot::getScore() const {
    return m_score;
}
