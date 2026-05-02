#pragma once
#include"Item.h"
class Fruit : public Item {
    private:
    int m_score = 100; // 水果的分数
    public:
    Fruit() = default;
    ~Fruit() = default;
    ItemType onCollect() override;
    int getScore() const override;
};