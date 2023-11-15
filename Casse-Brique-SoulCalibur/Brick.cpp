
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, sf::Color couleur, int life) : GameObject( x, y, width, height, couleur) //Constructeur 
{
    life = 3;
}

Brick::~Brick() //destructeur
{

}


void Brick::TakeDamage()
{
    life = life - 1;
    if (life == 3)
    {
        rShape.setFillColor(sf::Color::Red);
    }
    else if (life == 2)
    {
        rShape.setFillColor(sf::Color::Magenta);
    }
    else if (life == 1)
    {
        rShape.setFillColor(sf::Color::Yellow);
    }
    else if (life <= 0)
    {
        std::cout << "plus de vie" << std::endl;
    }
}
