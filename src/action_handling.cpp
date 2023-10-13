#include "action_handling.hpp"




void handle_keypress(App &app, sf::Event event) {

    sf::Keyboard::Key key = event.key.code;

    switch (key)
    {
    case sf::Keyboard::Backspace:
        if (app.Anchors.size()) app.Anchors.pop_back();
        LOG("Key Backspace pressed");
        break;
    
    default:
        break;
    }

}





void handle_mouse(App &app, sf::Event &event) {

    sf::Vector2i mousePos = {
        event.mouseButton.x,
        event.mouseButton.y
    };

    switch (event.mouseButton.button)
    {
    case sf::Mouse::Left:
        app.Anchors.push_back(
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





void handle_event(App &app) {

    static sf::Event event;
    if (!app.Window.pollEvent(event)) return;

    switch (event.type)
    {

    case sf::Event::Closed:
        app.Window.close();
        LOG("Window closed");
        break;

    case sf::Event::KeyPressed:
        handle_keypress(app, event);
        break;

    case sf::Event::MouseButtonPressed:
        handle_mouse(app, event);
        break;


    default:
        break;
    }
}