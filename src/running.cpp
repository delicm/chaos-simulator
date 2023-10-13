#include "running.hpp"




void display_anchors(App &app) {

    for (auto &position : app.Anchors) {
        sf::CircleShape circle(ANCHOR_R);
        circle.setFillColor(sf::Color::Magenta);
        circle.setPosition(position);

        app.Window.draw(circle);
    }

}



void runApp(App &app) {
    while (app.Window.isOpen()) {

        app.Window.clear();

        handle_event(app);

        display_anchors(app);

        app.Window.display();

    }
}