#include "core.hpp"




void ChaosSimulator::tick() {

    static sf::Clock tickLimiter;

    if (
        TPS == 0 ||
        (tickLimiter.getElapsedTime() < sf::seconds(1.0f / TPS) && TICKLIM_DISABLED)
    ) return;


    if (Anchors.size() <= 2) return;

    chooseAnchor();

    sf::Vector2f middle = choosePoint();

    drawStaticCircle(middle);

    Marker = middle;

    tickLimiter.restart();

}



void ChaosSimulator::chooseAnchor() {

    if (GameRule == Standard) {
        LastAnchor = rand() % Anchors.size();
        return;
    }

    if (GameRule == NoRepeat) {
        int anchor = rand() % Anchors.size();
        while (anchor == LastAnchor) {
            anchor = rand() % Anchors.size();
        }
        LastAnchor = anchor;
        return;
    }

    if (GameRule == NoNeighbor) {
        int anchor = rand() % Anchors.size();
        while (anchor - LastAnchor == 1 || anchor - LastAnchor == -1) {
            anchor = rand() % Anchors.size();
        }
        LastAnchor = anchor;
        return;
    }

    if (GameRule == NoSecondNeighbor) {
        int anchor = rand() % Anchors.size();
        while (anchor - LastAnchor == 2 || anchor - LastAnchor == -2) {
            anchor = rand() % Anchors.size();
        }
        LastAnchor = anchor;
        return;
    }

}


sf::Vector2f ChaosSimulator::choosePoint() {

    sf::Vector2f middle = Anchors[LastAnchor] + Marker;
    middle.x /= 2;
    middle.y /= 2;

    return middle;

}



void ChaosSimulator::drawStaticCircle(sf::Vector2f &position) {

    sf::Vector2i centerPixel = static_cast<sf::Vector2i>(position);

    for (int x = -POINT_R; x <= POINT_R; x++) {
        for (int y = -POINT_R; y <+ POINT_R; y++) {
            if (x*x + y*y > POINT_R*POINT_R) continue;
            int pixelX = centerPixel.x + x;
            int pixelY = centerPixel.y + y;

            if(pixelX < 0 || pixelX >= WIDTH) continue;
            if(pixelY < 0 || pixelY >= HEIGHT) continue;
            StaticImage.setPixel(pixelX, pixelY, sf::Color::White);
        }
    }

}