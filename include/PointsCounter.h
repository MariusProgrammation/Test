#ifndef POINTSCOUNTER_H
#define POINTSCOUNTER_H

#include <SFML/Graphics.hpp>


class PointsCounter
{
    public:
        PointsCounter(int countDownMain);
        virtual ~PointsCounter();
        sf::Text getText();
        void changeScore(sf::RectangleShape bullet, sf::RectangleShape enemy);

    protected:
        sf::Font font;
        sf::Text text;
        int countDown;

    private:
};

#endif // POINTSCOUNTER_H
