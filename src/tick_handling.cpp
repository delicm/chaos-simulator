#include "core.hpp"

void ChaosSimulator::tick() {

    static sf::Clock tickLimiter;

    if (
        TPS == 0 ||
        (tickLimiter.getElapsedTime() < sf::seconds(1.0f / TPS) && TICKLIM_DISABLED)
    ) return;


    if (Anchors.size() == 0) return;

    int anchor = rand() % Anchors.size();

    sf::Vector2f middle = Anchors[anchor] + Marker;
    middle.x /= 2;
    middle.y /= 2;

    drawStaticCircle(middle);

    Marker = middle;

    tickLimiter.restart();

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