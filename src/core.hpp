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

    enum Rule {
        Standard,
        NoRepeat,
        NoNeighbor,
        NoSecondNeighbor
    };

    /*** Constants ***/
    const int WIDTH = 1920;
    const int HEIGHT = 1080;

    const int ANCHOR_R = 4;
    const int MARKER_R = 3;
    const int POINT_R = 2;

    unsigned int TPS = 0;
    unsigned int BASE_TPS = 10;
    const int MAX_TPS = 80;
    bool TICKLIM_DISABLED = true;

    const int NUMRULES = 4;
    Rule GameRule;

    /*** Running ***/
    void displayStatics();
    void displayText();
    void displayAnchors();
    void displayMarker();
    void display();

    /*** Action Handling ***/
    void handleEvent();
    void handleKeypress(sf::Event &event);
    void handleClick(sf::Event &event);

    /*** Tick handling ***/
    void tick();
    void chooseAnchor();
    sf::Vector2f choosePoint();
    void drawStaticCircle(sf::Vector2f &position);

    /*** Members ***/
    sf::RenderWindow Window;
    std::vector<sf::Vector2f> Anchors;
    sf::Vector2f Marker;

    sf::Image StaticImage;
    sf::Texture StaticTexture;
    sf::Sprite StaticSprite;

    sf::Text TPSIndicator;
    sf::Text GameRuleIndicator;
    sf::Font DisplayFont;

    int LastAnchor = 0;

public:

    ChaosSimulator();
    ~ChaosSimulator();

    void runApp();

};


#endif