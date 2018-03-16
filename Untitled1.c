#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define STEP 1.0


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Image dirigeable");
    bool vie = true;
    if(vie=true)
    {
        sf::RectangleShape rectangle(sf::Vector2f(50, 50));
        rectangle.setPosition(300,200);
        sf::RectangleShape laser(sf::Vector2f(150, 25));
        laser.setPosition(650,200);
        laser.setFillColor(sf::Color::Red);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && rectangle.getPosition().y > 0)
        {
        rectangle.move(0,-STEP);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && rectangle.getPosition().y < 550)
        {
        rectangle.move(0,STEP);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && rectangle.getPosition().x < 750)
        {
        rectangle.move(STEP,0);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left ) && rectangle.getPosition().x > 0)
        {
        rectangle.move(-STEP,0);
        }



        window.clear();
        window.draw(rectangle);
        window.draw(laser);
        window.display();
}



while (window.isOpen())
{
   sf::Event event;
while (window.pollEvent(event))
{
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
            break;

        default:
            break;
        }
}
   while (window.pollEvent(event))
   {
       if (event.type == sf::Event::Closed)
           window.close();
   }

    return 0;
