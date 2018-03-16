#include "Player.h"
#include <iostream>
#include "Bullet.h"

#define MOVESPEED 0.5

Player::~Player()
{
    //dtor
}

Player::Player()
{
    if (!playerTexture.loadFromFile("playerTexture.png"))
        std::cerr << "Error loading image :" << "playerTexture.png" << std::endl;
    player.setSize(sf::Vector2f(100, 50));
    player.setTexture(&playerTexture);
    player.setPosition(500 - player.getSize().x / 2, 800 - player.getSize().y);
    life = 3;
    shortShoot = 1;
}

sf::RectangleShape Player::getPlayerShape()
{
    return(player);
}

void Player::move()
{
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) && player.getPosition().x > 0)
    {
        player.move(-MOVESPEED, 0);
    }
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && player.getPosition().x + player.getSize().x < 1000)
    {
        player.move(MOVESPEED, 0);
    }
}

bool Player::shoot(sf::RectangleShape bullet)
{
    if((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && shortShoot == 1)
    {
        std::cout << "shoot!" << std::endl;
        bullet.setPosition(player.getPosition().x + player.getSize().x / 2, player.getPosition().y - player.getSize().y / 2);

        shortShoot = shortShoot * -1;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shortShoot == -1)
            shortShoot = shortShoot * -1;

    return(0);
}

sf::Vector2f Player::getPlayerPosition()
{
    return(player.getPosition());
}









