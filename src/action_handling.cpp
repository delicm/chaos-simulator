#include "core.hpp"




void ChaosSimulator::handleKeypress(sf::Event &event) {

    sf::Keyboard::Key key = event.key.code;

    switch (key)
    {
    case sf::Keyboard::Backspace:
        if (Anchors.size()) Anchors.pop_back();
        LOG("Last anchor deleted");
        break;


    case sf::Keyboard::Space:
        TPS = BASE_TPS - TPS;
        LOG("Toggled ticking");
        break;


    case sf::Keyboard::C:
        StaticImage.create(WIDTH, HEIGHT, sf::Color::Transparent);
        StaticTexture.loadFromImage(StaticImage);
        StaticSprite.setTexture(StaticTexture);
        LOG("Cleared statics");
        break;


    case sf::Keyboard::Up:
        BASE_TPS = 10 + BASE_TPS % MAX_TPS;
        TPS = TPS == 0 ? 0 : BASE_TPS;
        TPSIndicator.setString("TPS: " + std::to_string(BASE_TPS));
        LOG("Increased base tickspeed");
        break;

    case sf::Keyboard::Down:
        BASE_TPS = 10 + (BASE_TPS + MAX_TPS - 20) % MAX_TPS;
        TPS = TPS == 0 ? 0 : BASE_TPS;
        TPSIndicator.setString("TPS: " + std::to_string(BASE_TPS));
        LOG("Decreased base tickspeed");
        break;

    default:
        break;
    }

}





void ChaosSimulator::handleClick(sf::Event &event) {

    sf::Vector2i mousePos = {
        event.mouseButton.x,
        event.mouseButton.y
    };

    switch (event.mouseButton.button)
    {
    case sf::Mouse::Left:
        Anchors.push_back(
            static_cast<sf::Vector2f>(
                mousePos
            ) - sf::Vector2f(ANCHOR_R, ANCHOR_R)
        );
        LOG("Left mouse button pressed");
        break;
    
    default:
        break;
    }
}





void ChaosSimulator::handleEvent() {

    static sf::Event event;
    if (!Window.pollEvent(event)) return;

    switch (event.type)
    {

    case sf::Event::Closed:
        Window.close();
        LOG("Window closed");
        break;

    case sf::Event::KeyPressed:
        handleKeypress(event);
        break;

    case sf::Event::MouseButtonPressed:
        handleClick(event);
        break;


    default:
        break;
    }
}