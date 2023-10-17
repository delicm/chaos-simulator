#include "core.hpp"




void ChaosSimulator::display() {

    displayStatics();

    displayText();

    displayAnchors();

    displayMarker();

    Window.display();

}



void ChaosSimulator::displayStatics() {

    StaticTexture.update(StaticImage);
    Window.draw(StaticSprite);

}



void ChaosSimulator::displayText() {

    std::string gamerule;

    switch (GameRule)
    {
    case Standard:
        gamerule = "Standard";
        break;
    
    case NoRepeat:
        gamerule = "No Repeat";
        break;

    case NoNeighbor:
        gamerule = "No Neighbor";
        break;

    case NoSecondNeighbor:
        gamerule = "No Second Neighbor";
        break;

    default:
        gamerule = "Error";
        break;
    }

    GameRuleIndicator.setString("Game rule: " + gamerule);

    Window.draw(GameRuleIndicator);
    Window.draw(TPSIndicator);

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