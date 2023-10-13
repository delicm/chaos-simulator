#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include <vector>




#ifdef DEBUG
#define LOG(x) printf("%s\n", x)
#else
#define LOG(x)
#endif




class ChaosSimulator {

private:

    /*** Constants ***/
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    const int ANCHOR_R = 4;
    const int MARKER_R = 3;
    const int POINT_R = 2;

    unsigned int TPS = 0;

    /*** Running ***/
    void displayStatics();
    void displayAnchors();
    void displayMarker();
    void display();

    /*** Action Handling ***/
    void handleEvent();
    void handleKeypress(sf::Event &event);
    void handleClick(sf::Event &event);

    /*** Tick handling ***/
    void tick();
    void drawStaticCircle(sf::Vector2f &position); // TODO

    /*** Members ***/
    sf::RenderWindow Window;
    std::vector<sf::Vector2f> Anchors;
    sf::Vector2f Marker;

    sf::Image StaticImage;
    sf::Texture StaticTexture;
    sf::Sprite StaticSprite;

public:

    ChaosSimulator();
    ~ChaosSimulator();

    void runApp();

};


#endif