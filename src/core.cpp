#include "core.hpp"

ChaosSimulator::ChaosSimulator()
: Window(sf::VideoMode(WIDTH, HEIGHT), "Chaos Simulator", sf::Style::Fullscreen),
  Marker(WIDTH/2, HEIGHT/2)
{
    Window.setFramerateLimit(0);
    Window.setKeyRepeatEnabled(false);
    LOG("Window loaded");

    StaticImage.create(WIDTH, HEIGHT, sf::Color::Transparent);
    StaticTexture.loadFromImage(StaticImage);
    StaticSprite.setTexture(StaticTexture);
    LOG("Statics intialized");

    if (DisplayFont.loadFromFile("../assets/Ubuntu-Regular.ttf")) LOG("Font loaded");
    else LOG("Failed to load font");  

    TPSIndicator.setFont(DisplayFont);
    TPSIndicator.setCharacterSize(24);
    TPSIndicator.setFillColor(sf::Color::White);
    TPSIndicator.setPosition(WIDTH - 150, HEIGHT - 50);
    TPSIndicator.setString("TPS: " + std::to_string(BASE_TPS));
    LOG("TPS Indicator loaded");

    GameRuleIndicator.setFont(DisplayFont);
    GameRuleIndicator.setCharacterSize(24);
    GameRuleIndicator.setFillColor(sf::Color::White);
    GameRuleIndicator.setPosition(20, HEIGHT - 50);
    GameRuleIndicator.setString("GameRule: Standard");
    LOG("Game Rule Indicator loaded");
}

ChaosSimulator::~ChaosSimulator() {}

