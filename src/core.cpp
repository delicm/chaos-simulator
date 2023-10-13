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
}

ChaosSimulator::~ChaosSimulator() {}

