#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Bullet.h"
#include "Invador.h"
#include "PointsCounter.h"
#include "Background.h"
#include "MenuSpaceInv.h"
#include <vector>
using namespace std;
using namespace sf;

#define ENEMYNUMBER 100

int main()
{

    RenderWindow window(sf::VideoMode(1000, 800), "SPACE INVADERS");

    int                 enemyNumber = 100;
    srand (time(NULL));

    std::vector<Invador *> test;
    Player              p1;
    Player              p2;

    Player              player;
    Invador             enemy[enemyNumber];
    for (int i = 0; i < 100; ++i) {
        test.push_back(new Invador());
    }
    std::cout << test.size() << std::endl;
    Bullet              bullet;
    PointsCounter       pointsCounter(enemyNumber);
    MenuSpaceInv        menuSI;

    sf::RectangleShape winLaser;
    winLaser.setSize(sf::Vector2f(1000, 10));
    winLaser.setFillColor(sf::Color::Green);
    winLaser.setPosition(0, -10000);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(menuSI.getGameStarted() == true)
        {
            player.move();
            player.shoot(bullet.getBulletShape());

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                bullet.setBulletFired();
                bullet.setBulletPosition(player.getPlayerPosition().x + 45, player.getPlayerPosition().y);
            }
            bullet.move();

            for (int i = 0; i <= enemyNumber - 1; ++i)
            {
                pointsCounter.changeScore(bullet.getBulletShape(), enemy[i].getEnemyShape());
                enemy[i].move(bullet.getBulletShape(), menuSI.getDifficulty());
                if(enemy[i].getEndGame() == true)
                    menuSI.setEndGame();
            }

            winLaser.move(0, 0.1);

            window.clear();
            window.draw(player.getPlayerShape());
            window.draw(bullet.getBulletShape());
            for (int i = 0; i <= enemyNumber - 1; ++i)
            {
                window.draw(enemy[i].getEnemyShape());
            }
            window.draw(pointsCounter.getText());
            window.draw(winLaser);
            window.display();
        }
        if(menuSI.getGameStarted() == false)
        {
            window.clear();
            menuSI.checkChoice(window);
            window.draw(menuSI.getMenuShape());
            //menuSI.getMenuShape().setPosition(-100, -100);
            window.display();
        }
    }
    return 0;
}


