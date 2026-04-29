#include<vector>
#include<SFML/Graphics.hpp>

#include "Character.h"
#include "GameObject.h"
using namespace std;
enum Direction {UP, DOWN, LEFT, RIGHT,NONE};
enum class State { Chase, Scatter, Frightened, Eaten };//散开，追赶，恐惧，死亡
class Ghost: public Character {
private:
    Point position;
    Point spawnPoint;//出生点
    Direction dir;//移动方向
    Direction nextdir;//下一次移动目标方向
    int scarytime;//恐惧时间长度
    double speed;//速度
    bool isAlive;//是否存活
    double statetime;//处在某一状态的时间
protected:
    virtual void chase(const Point& pacmanPos, const Point& blinkyPos) = 0;//重写寻路逻辑
    State state = State::Scatter;
public:
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void setFrightened();  
    void eaten();
    Ghost (int x,int y,double speed,Direction) {
        position.x = x;
        position.y = y;
        spawnPoint.x = x;
        spawnPoint.y = y;
        dir=Direction::NONE;
        nextdir=Direction::NONE;
        scarytime=0;
        speed=speed;
        isAlive=true;
        statetime=0;
    }
    void reset() {
        position.x = spawnPoint.x;
        position.y = spawnPoint.y;
        dir=Direction::NONE;
        nextdir=Direction::NONE;
        scarytime=0;
        speed=speed;
        isAlive=true;
        statetime=0;
    }
};
class Bilnky : public Ghost {
protected:
    void chase(const Point &pacmanPos, const Point &blinkyPos) override {
        
    }
};