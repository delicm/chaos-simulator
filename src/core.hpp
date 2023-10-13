#ifndef CORE_H
#define CORE_H

#include <SFML/Graphics.hpp>
#include <vector>




#ifdef DEBUG
#define LOG(x) printf("%s\n", x)
#else
#define LOG(x)
#endif



const int WIDTH = 1920;
const int HEIGHT = 1080;




class App {

public:

    sf::RenderWindow Window;
    std::vector<sf::Vector2f> Anchors;

    App();
    ~App();

};









#endif