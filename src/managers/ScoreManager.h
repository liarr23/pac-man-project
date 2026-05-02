#pragma once
#include <string>

class ScoreManager {
public:
    ScoreManager();
    ~ScoreManager() = default;

    void addScore(int points);
    int getScore() const;
    int getHighScore() const;//记录最高分数
    bool isNewHighScore() const;
    void reset();

    void loadHighScore(const std::string& filepath);//从文件加载最高分数
    void saveHighScore(const std::string& filepath);//保存最高分数到文件

private:
    int m_score = 0;
    int m_highScore = 0;
    std::string m_filepath;//保存最高分数的文件路径
};
