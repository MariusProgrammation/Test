#ifndef INVADOR_H
#define INVADOR_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "PointsCounter.h"

class Invador
{
    public:
        Invador();
        virtual ~Invador();
        void move(sf::RectangleShape bullet, float moveDifficulty);
        sf::RectangleShape getEnemyShape();
        sf::RectangleShape getGameOverShape();
        bool getEndGame();
        void resetInvador();

    protected:
        sf::RectangleShape enemy;
        sf::RectangleShape gameOver;
        int                randomNumberTexture;
        sf::Texture        enemyTextureChoosen;
        sf::Texture        enemyTexture1;
        sf::Texture        enemyTexture2;
        sf::Texture        enemyTexture3;
        sf::Texture        enemyTexture4;
        sf::Texture        gameOverTexture;
        bool               inLife;
        bool               endGame;

    private:
};

#endif // INVADOR_H
