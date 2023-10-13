#include "core.hpp"




void ChaosSimulator::display() {

    displayStatics();

    displayAnchors();

    displayMarker();

    Window.display();

}



void ChaosSimulator::displayStatics() {

    StaticTexture.update(StaticImage);
    Window.draw(StaticSprite);

}



void ChaosSimulator::displayAnchors() {

    for (auto &position : Anchors) {
        sf::CircleShape circle(ANCHOR_R);
        circle.setFillColor(sf::Color::Magenta);
        circle.setPosition(position);

        Window.draw(circle);
    }

}



void ChaosSimulator::displayMarker() {

    sf::CircleShape circle(MARKER_R);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(Marker);

    Window.draw(circle);    

}



void ChaosSimulator::runApp() {

    while (Window.isOpen()) {

        Window.clear();

        handleEvent();
        tick();

        display();

    }
}