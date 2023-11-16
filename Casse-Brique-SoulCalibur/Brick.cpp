#include <SFML/Graphics.hpp>
#include <iostream>
#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, sf::Color couleur, int life): GameObject( x,  y, width, height,  couleur) //Constructeur 
{
	this->life = 3;
}

Brick::~Brick() //destructeur
{

}


void Brick::TakeDamage()
{
	sf::Clock oClock;
	float deltaTime = 0;
	bool isHit = false;
	
	if (life == 3 && isHit == false)
	{
		life = life - 1;
		rShape.setFillColor(sf::Color::Cyan);
		isHit = true;
	}
	else if (life == 2 && isHit == false)
	{
		life = life - 1;
		rShape.setFillColor(sf::Color::Magenta);
		isHit = true;
	}
	else if (life == 1 && isHit == false)
	{
		life = life - 1;
		isHit = true;
	}
	
	if (deltaTime > 5 && isHit == true)
	{
		isHit = false;
	}
	
	deltaTime = oClock.restart().asSeconds();
}

int Brick::getLife()
{
	return life;
}