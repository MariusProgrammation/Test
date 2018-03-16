#include "PointsCounter.h"
#include <iostream>

PointsCounter::PointsCounter(int countDownMain)
{
    countDown = countDownMain;
    font.loadFromFile("FunSized.ttf");
    if(!font.loadFromFile("FunSized.ttf"))
    {
        std::cout << "Font didnt loaded" << std::endl;
    };
    text.setString(std::to_string(countDown));
    text.setFont(font);
    text.setCharacterSize(50);
    text.setPosition(sf::Vector2f(100, 50));
}

PointsCounter::~PointsCounter()
{
    //dtor
}

sf::Text PointsCounter::getText()
{
    return(text);
}

void PointsCounter::changeScore(sf::RectangleShape bullet, sf::RectangleShape enemy)
{
    if(enemy.getPosition().y  + enemy.getSize().y > bullet.getPosition().y                       &&
       enemy.getPosition().y                       < bullet.getPosition().y + bullet.getSize().y &&
       enemy.getPosition().x  + enemy.getSize().x  > bullet.getPosition().x                      &&
       enemy.getPosition().x                       < bullet.getPosition().x + bullet.getSize().x)
    {
        countDown = countDown - 1;
        text.setString(std::to_string(countDown));
        //std::cout << "Score changed" << std::endl;
    }
}
