#include "core.hpp"

App::App()
: Window(sf::VideoMode(WIDTH, HEIGHT), "Chaos Simulator", sf::Style::Fullscreen)
{
    Window.setFramerateLimit(0);
    Window.setKeyRepeatEnabled(false);
    LOG("Window loaded");
}

App::~App() {}

