#pragma once
#include <SFML/Graphics.hpp>
#include "Types.h"
class InputHandler 
{
   public:
   InputHandler();
    ~InputHandler();
    void handleEvents(const sf::Event& event);
    Direction getDirection() const;
    bool isActionTriggered() const;
    private:
    Direction m_direction = Direction::None;
};