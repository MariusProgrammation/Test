#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>


class Background
{
    public:
        Background();
        virtual ~Background();
        sf::RectangleShape getBackgroundShape();

    protected:
        sf::RectangleShape background;
        sf::Texture        backgroundTexture;

    private:
};

#endif // BACKGROUND_H
