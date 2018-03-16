#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
    public:
        virtual ~Player();
        Player();
        void move();
        bool shoot(sf::RectangleShape bullet);
        sf::RectangleShape getPlayerShape();
        sf::Vector2f getPlayerPosition();

    protected:
        sf::RectangleShape  player;
        sf::Texture         playerTexture;
        int                 width;
        int                 height;
        int                 shortShoot;
        int                 life;

    private:
};

#endif // PLAYER_H
