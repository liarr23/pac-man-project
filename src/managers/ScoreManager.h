#pragma once

class ScoreManager {
    public:
    ScoreManager() = default;
    ~ScoreManager() = default;
    void addScore(int points);
    int getScore() const;
    private:
    int m_score = 0;
};