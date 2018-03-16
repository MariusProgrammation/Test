#ifndef MENUSPACEINV_H
#define MENUSPACEINV_H

#include <iostream>
#include <SFML/Graphics.hpp>

class MenuSpaceInv
{
    public:
        MenuSpaceInv();
        virtual ~MenuSpaceInv();
        sf::RectangleShape getMenuShape();
        void checkChoice(sf::RenderWindow &window);
        float getDifficulty();
        bool getGameStarted();
        void setEndGame();

    protected:
        sf::RectangleShape menuSpaceInv;
        sf::Texture        menuTexture;
        bool               gameStarted;
        float                difficulty;

    private:
};

#endif // MENUSPACEINV_H
