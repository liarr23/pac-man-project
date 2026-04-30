#pragma once
#include "Item.h"
class PowerPellet : public Item {
    private:
    int m_score = 50; // 能量豆的分数
    public:
    PowerPellet() = default;
    ~PowerPellet() = default;
     ItemType onCollect() override ;
     int getScore() const override;
};