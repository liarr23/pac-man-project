#include "UIManager.h"

UIManager::UIManager(int score, int highScore, int lives, int dotsRemaining)
    : m_score(score), m_highScore(highScore), m_lives(lives), m_dotsRemaining(dotsRemaining), m_powerTimeRatio(0.f) {
}

UIManager::~UIManager() {
}

void UIManager::update(int score, int highScore, int lives, int dotsRemaining, float powerTimeRatio) {
    m_score = score;
    m_highScore = highScore;
    m_lives = lives;
    m_dotsRemaining = dotsRemaining;
    m_powerTimeRatio = powerTimeRatio;
}

static void drawHeart(sf::RenderWindow& window, float cx, float cy, float size, sf::Color color) {
    // Main heart body
    sf::ConvexShape heart;
    heart.setPointCount(7);
    heart.setPoint(0, sf::Vector2f(0.f, size * 0.35f));
    heart.setPoint(1, sf::Vector2f(-size * 0.5f, -size * 0.05f));
    heart.setPoint(2, sf::Vector2f(-size * 0.35f, -size * 0.45f));
    heart.setPoint(3, sf::Vector2f(0.f, -size * 0.15f));
    heart.setPoint(4, sf::Vector2f(size * 0.35f, -size * 0.45f));
    heart.setPoint(5, sf::Vector2f(size * 0.5f, -size * 0.05f));
    heart.setPoint(6, sf::Vector2f(0.f, size * 0.35f));
    heart.setFillColor(color);
    heart.setPosition(cx, cy);
    window.draw(heart);

    // Dark outline
    heart.setFillColor(sf::Color(120, 0, 0));
    heart.setScale(1.12f, 1.12f);
    heart.setPosition(cx, cy);
    // Draw outline first by drawing bigger dark heart behind
    sf::ConvexShape outline = heart;
    outline.setFillColor(sf::Color(80, 0, 0));
    outline.setScale(1.15f, 1.15f);
    outline.setPosition(cx, cy);
    window.draw(outline);

    // Redraw the colored heart on top
    sf::ConvexShape main = heart;
    main.setScale(1.f, 1.f);
    main.setFillColor(color);
    main.setPosition(cx, cy);
    window.draw(main);

    // Highlight / gloss (top-left shine)
    sf::ConvexShape shine;
    shine.setPointCount(4);
    shine.setPoint(0, sf::Vector2f(-size * 0.3f, -size * 0.4f));
    shine.setPoint(1, sf::Vector2f(-size * 0.1f, -size * 0.4f));
    shine.setPoint(2, sf::Vector2f(-size * 0.15f, -size * 0.15f));
    shine.setPoint(3, sf::Vector2f(-size * 0.35f, -size * 0.2f));
    shine.setFillColor(sf::Color(255, 255, 255, 100));
    shine.setPosition(cx, cy);
    window.draw(shine);

    // Small bright dot highlight
    sf::CircleShape dot(size * 0.06f);
    dot.setFillColor(sf::Color(255, 255, 255, 160));
    dot.setOrigin(size * 0.06f, size * 0.06f);
    dot.setPosition(cx - size * 0.2f, cy - size * 0.3f);
    window.draw(dot);
}

void UIManager::render(sf::RenderWindow& window)
{
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/MiSans-Bold.ttf")) {
        return;
    }

    // Lives - Minecraft-style hearts
    for (int i = 0; i < m_lives; i++) {
        drawHeart(window, 22.f + i * 38.f, 22.f, 18.f, sf::Color(220, 0, 0));
    }

    // Score
    sf::Text scoreText("Score: " + std::to_string(m_score), font, 24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 40);
    window.draw(scoreText);

    // High Score
    sf::Text highScoreText("High Score: " + std::to_string(m_highScore), font, 24);
    highScoreText.setFillColor(sf::Color::Green);
    highScoreText.setPosition(10, 65);
    window.draw(highScoreText);

    // Dots remaining
    sf::Text dotsText("Dots: " + std::to_string(m_dotsRemaining), font, 24);
    dotsText.setFillColor(sf::Color(255, 183, 174));
    dotsText.setPosition(10, 90);
    window.draw(dotsText);

    // Power pellet timer bar
    if (m_powerTimeRatio > 0.f) {
        float winW = static_cast<float>(window.getSize().x);
        float barW = 200.f;
        float barH = 12.f;
        float barX = (winW - barW) / 2.f;
        float barY = static_cast<float>(window.getSize().y) - 30.f;

        // Background
        sf::RectangleShape bg(sf::Vector2f(barW, barH));
        bg.setFillColor(sf::Color(50, 50, 50));
        bg.setOutlineThickness(1.f);
        bg.setOutlineColor(sf::Color(100, 100, 100));
        bg.setPosition(barX, barY);
        window.draw(bg);

        // Fill
        float fillW = barW * m_powerTimeRatio;
        sf::RectangleShape fill(sf::Vector2f(fillW, barH));
        fill.setFillColor(sf::Color(50, 50, 255));
        fill.setPosition(barX, barY);
        window.draw(fill);

        // Highlight (gloss)
        sf::RectangleShape gloss(sf::Vector2f(fillW, barH * 0.4f));
        gloss.setFillColor(sf::Color(255, 255, 255, 60));
        gloss.setPosition(barX, barY);
        window.draw(gloss);

        // Label
        sf::Text powerText("POWER", font, 14);
        powerText.setFillColor(sf::Color(150, 150, 255));
        auto pwBounds = powerText.getLocalBounds();
        powerText.setPosition((winW - pwBounds.width) / 2.f, barY - 18.f);
        window.draw(powerText);
    }
}
