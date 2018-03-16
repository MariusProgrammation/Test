#include "Invador.h"

#include <iostream>

Invador::Invador()
{
    randomNumberTexture = rand() % 3;
    if(randomNumberTexture == 0) {
        enemyTextureChoosen = enemyTexture1;
        if (!enemyTextureChoosen.loadFromFile("ennemieTexture1.png"))
            std::cerr << "Error loading image :" << "ennemieTexture1.png" << std::endl;
    }
    if(randomNumberTexture == 1) {
        enemyTextureChoosen = enemyTexture1;
        if (!enemyTextureChoosen.loadFromFile("ennemieTexture2.png"))
            std::cerr << "Error loading image :" << "ennemieTexture2.png" << std::endl;
    }
    if(randomNumberTexture == 2) {
        enemyTextureChoosen = enemyTexture1;
        if (!enemyTextureChoosen.loadFromFile("ennemieTexture3.png"))
            std::cerr << "Error loading image :" << "ennemieTexture3.png" << std::endl;
    }
    if(randomNumberTexture == 3) {
        enemyTextureChoosen = enemyTexture1;
        if (!enemyTextureChoosen.loadFromFile("ennemieTexture4.png"))
            std::cerr << "Error loading image :" << "ennemieTexture4.png" << std::endl;
    }

    enemy.setTexture(&enemyTextureChoosen);
    enemy.setSize(sf::Vector2f(50, 50));
    enemy.setPosition(rand() % /*(1000 - enemy.getSize().x)*/950, rand() % 10000 - 10000);
    inLife = true;

    if (!gameOverTexture.loadFromFile("gameOver.png"))
            std::cerr << "Error loading image :" << "gameOver.png" << std::endl;
    gameOver.setTexture(&gameOverTexture);
    gameOver.setSize(sf::Vector2f(1000, 800));
    gameOver.setPosition(1000, 800);
    endGame = false;
}

Invador::~Invador()
{
    //dtor
}

sf::RectangleShape Invador::getEnemyShape()
{
    return(enemy);
}
sf::RectangleShape Invador::getGameOverShape()
{
    return(gameOver);
}

bool Invador::getEndGame()
{
    return(endGame);
}

void Invador::move(sf::RectangleShape bullet, float moveDifficulty)
{
    if(inLife == true)
    {
        enemy.move(0, moveDifficulty);
        if (enemy.getPosition().y  + enemy.getSize().y  > bullet.getPosition().y                      &&
            enemy.getPosition().y                       < bullet.getPosition().y + bullet.getSize().y &&
            enemy.getPosition().x  + enemy.getSize().x  > bullet.getPosition().x                      &&
            enemy.getPosition().x                       < bullet.getPosition().x + bullet.getSize().x   )
        {
            std::cout << "Enemy destroyed!" << std::endl;
            enemy.setPosition(-100, -100);
            inLife = false;
//            pointsCounter.changeScore();
        }
        if(enemy.getPosition().y > 800 - enemy.getSize().y)
        {
            std::cout << "Lose!" << std::endl;
            endGame = true;
            gameOver.setPosition(0, 0);
        }
    }
}

void Invador::resetInvador()
{

}















