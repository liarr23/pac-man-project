#include"InputHandler.h"
InputHandler::InputHandler() {
}
InputHandler::~InputHandler() {
}
void InputHandler::handleEvents(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
                m_direction = Direction::Up;
                break;
            case sf::Keyboard::Down:
                m_direction = Direction::Down;
                break;
            case sf::Keyboard::Left:
                m_direction = Direction::Left;
                break;
            case sf::Keyboard::Right:
                m_direction = Direction::Right;
                break;
            case sf::Keyboard::W:
                m_direction = Direction::Up;
                break;
            case sf::Keyboard::S:
                m_direction = Direction::Down;
                break;
            case sf::Keyboard::A:
                m_direction = Direction::Left;
                break;
            case sf::Keyboard::D:
                m_direction = Direction::Right;
                break;
            default:
                m_direction = Direction::None;
                break;
        }
    }
}
    Direction InputHandler::getDirection() const {
    return m_direction;
}
bool InputHandler::isActionTriggered() const {
    // 这里可以根据需要实现特殊状态的触发逻辑
    return false; // 默认返回false，表示没有特殊状态被触发
}