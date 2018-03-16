#include "Background.h"

Background::Background()
{
    //if (!backgroundTexture.loadFromFile("backgroundTexture.png"))
    //    std::cerr << "Error loading image :" << "ennemieTexture.png" << std::endl;
    //background.setTexture(&backgroundTexture);
    background.setSize(sf::Vector2f(1000, 800));
    background.setFillColor(sf::Color::Blue);
}

Background::~Background()
{
    //dtor
}

sf::RectangleShape Background::getBackgroundShape()
{
    return(background);
}
