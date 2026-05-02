#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Window", sf::Style::Resize | sf::Style::Close);
    sf::Color backgroundColor(144, 238, 144);
    sf::Texture texture; //图片对象ni
    if (!texture.loadFromFile("../Image_1765179663459_461.jpg")) // 判断加载失败，报错
       {
     std::cerr << "false" << std::endl;
     return -1;
            }
       sf::Sprite sprite(texture); //创建精灵对象
        sprite.setPosition(sf::Vector2f(0, -5)); //位置
        sprite.scale(0.75f, 0.75f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(backgroundColor);
        // 在这里画你的图形
       
        window.draw(sprite); //画图
        window.display();
    }
    return 0;
}