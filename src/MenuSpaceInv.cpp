#include "MenuSpaceInv.h"

MenuSpaceInv::MenuSpaceInv()
{
    if (!menuTexture.loadFromFile("menuSpace-Inv.png"))
        std::cerr << "Error loading image :" << "menuSpace-Inv.png" << std::endl;
    menuSpaceInv.setTexture(&menuTexture);
    menuSpaceInv.setSize(sf::Vector2f(1000, 800));
    menuSpaceInv.setPosition(0, 0);
    gameStarted = false;
    difficulty = 50;
}

MenuSpaceInv::~MenuSpaceInv()
{
    //dtor
}

sf::RectangleShape MenuSpaceInv::getMenuShape()
{
    return(menuSpaceInv);
}

void MenuSpaceInv::setEndGame()
{
    gameStarted = false;
}

void MenuSpaceInv::checkChoice(sf::RenderWindow &window)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)               &&
       sf::Mouse::getPosition().x > 0   + window.getPosition().x &&
       sf::Mouse::getPosition().x < 500 + window.getPosition().x   )
    {
        std::cout << "PLAY" << std::endl;
        gameStarted = true;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       sf::Mouse::getPosition().y < 500 + window.getPosition().y &&
       sf::Mouse::getPosition().y > 200 + window.getPosition().y &&
       sf::Mouse::getPosition().x > 500 + window.getPosition().x &&
       sf::Mouse::getPosition().x < 1000 + window.getPosition().x  )
    {
        difficulty = 0.07;
        std::cout << "EASY" << std::endl;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       sf::Mouse::getPosition().y < 700 + window.getPosition().y &&
       sf::Mouse::getPosition().y > 500 + window.getPosition().y &&
       sf::Mouse::getPosition().x > 500 + window.getPosition().x &&
       sf::Mouse::getPosition().x < 1000 + window.getPosition().x  )
    {
        difficulty = 0.16;
        std::cout << "MEDIUM" << std::endl;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
       sf::Mouse::getPosition().y < 800 + window.getPosition().y &&
       sf::Mouse::getPosition().y > 700 + window.getPosition().y &&
       sf::Mouse::getPosition().x > 500 + window.getPosition().x &&
       sf::Mouse::getPosition().x < 1000 + window.getPosition().x  )
    {
        difficulty = 0.23;
        std::cout << "HARD" << std::endl;
    }

}

float MenuSpaceInv::getDifficulty()
{
    return(difficulty);
}

bool MenuSpaceInv::getGameStarted()
{
    return(gameStarted);
}










