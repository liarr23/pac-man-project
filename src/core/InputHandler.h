#pragma once
#include <SFML/Graphics.hpp>
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