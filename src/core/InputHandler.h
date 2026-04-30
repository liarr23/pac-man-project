#pragma once
#include <SFML/Graphics.hpp>
#include "Types.h"
class InputHandler 
{
   public:
   InputHandler();
    ~InputHandler();
    void handleEvents(const sf::Event& event);// 处理输入事件
    Direction getDirection() const;// 获取当前输入的方向
    bool isActionTriggered() const;// 例如，吃豆人吃到能量豆后触发的特殊状态
    private:
    Direction m_direction = Direction::None;// 当前输入的方向
};