#pragma once
#include"Item.h"
class Dot : public Item {
    private:
    int m_score = 10; // 普通豆的分数
    public:
    Dot() = default;
    ~Dot() = default;
    ItemType onCollect() override;
    int getScore() const override;
};