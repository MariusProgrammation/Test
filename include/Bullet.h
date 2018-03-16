#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();
        sf::RectangleShape getBulletShape();
        void move();
        void setBulletPosition(int xPosition, int yPosition);
        void setBulletFired();
        void removeBullet();

    protected:
        sf::RectangleShape bullet;
        int                bulletFired;

    private:
};

#endif // BULLET_H
