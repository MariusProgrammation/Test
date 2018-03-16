#include "Bullet.h"

Bullet::Bullet()
{
    bullet.setSize(sf::Vector2f(10, 50));
    bullet.setPosition(100, 700);
    bullet.setFillColor(sf::Color::Yellow);
    bulletFired = 0;
}

Bullet::~Bullet()
{
    //dtor
}

sf::RectangleShape Bullet::getBulletShape()
{
    return(bullet);
}

void Bullet::move()
{
    if(bulletFired == 1 && bullet.getPosition().y >= 0 - bullet.getSize().y)
        bullet.move(0, -1);
    else
        bullet.setPosition(0, -500);
}

void Bullet::setBulletPosition(int xPosition, int yPosition)
{
    bullet.setPosition(xPosition, yPosition);
}

void Bullet::setBulletFired()
{
    bulletFired = 1;
}

void Bullet::removeBullet()
{
    bulletFired = 0;
    bullet.setPosition(-100, -100);
}



















