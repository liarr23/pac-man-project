#include "MapManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
MapManager::MapManager(int width, int height) {
MapManager::width = width;
    MapManager::height = height;
}
MapManager::~MapManager() = default;
bool MapManager::LoadFromFile(const string &fileName) {
    ifstream file(fileName);
    if(!file.is_open()) {
        cerr<<"Error opening file"<<fileName<<endl;
        return false;
    }
    if (width <= 0 || height <= 0) {
        cerr<<"Error map 规格"<<fileName<<endl;
        return false;
    }
    for (int row=0; row<height; row++) {
        for (int col=0; col<width; col++) {
            char val;
            if (!file>>val) {
                cerr<<"Error reading file"<<fileName<<"on"<<row<<" "<<col<<endl;
                return false;
            }
                world.insert({Point(col,row),val});
            if (val=='P') {
                PacmanStartPos=Point(col,row);

            }
            else if (val=='G') {
                GhostStartPos=Point(col,row);
            }
            else if (val=='E') {
                GhostDoor=Point(col,row);
            }
        }
    }
file.close();
    return true;
}
bool MapManager::isWalkable(const Point& p) const {
if (p.x<0||p.x>width-1||p.y<0||p.y>height-1) return false;
char val=world.at(Point(p.x,p.y));
if (val=='W') {
    return false;
}
else {
    return true;
}}
Point MapManager::getPacmanStartPos() const {
    return PacmanPos;
}
Point MapManager::getGhostStartPos() const {
    return GhostPos;
}
bool MapManager::isWalkable(int x,int y) const {
    if (x<0||x>width-1||y<0||y>height-1) return false;
    char val=world.at(Point(x,y));
    if (val=='W') {
        return false;
    }
    else {
        return true;
    }
}

char MapManager::getWord(int x, int y) const {
    return world.at(Point(x,y));
}
char MapManager::getWord(Point& p) const {
    return world.at(p);
}
int MapManager::getWidth() const {
    return width;
}
int MapManager::getHeight() const {
    return height;
}
Point MapManager::getBlinkyStartPos() {
    return BlinkyStartPos;
}

Point MapManager::getClydeStartPos() {
    return ClydeStartPos;
}

Point MapManager::getInkyStartPos() {
    return InkyStartPos;
}

Point MapManager::getPinkyStartPos() {
    return PinkyStartPos;
}
