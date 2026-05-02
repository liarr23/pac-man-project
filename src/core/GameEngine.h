#pragma once
#include <SFML/Graphics.hpp>
#include "InputHandler.h"
class GameEngine {

public:
    GameEngine();
    ~GameEngine();
    void run();// 游戏主循环
    private:
    InputHandler m_inputHandler;// 输入处理器
    void processEvents();// 处理输入事件
    void update(sf::Time deltaTime);// 更新游戏状态
    void render();// 渲染游戏
    sf ::RenderWindow window;// 游戏窗口
    sf ::Clock clock;// 游戏时钟
};
