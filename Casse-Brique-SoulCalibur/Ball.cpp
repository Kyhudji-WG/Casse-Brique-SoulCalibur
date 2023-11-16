#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ball.h"


Ball::Ball(float x, float y, float radius, sf::Color couleur, float speed) : GameObject(x, y, radius, couleur) //Constructeur 
{
	this->speed = 1;
}

Ball::~Ball() //destructeur
{

}

sf::FloatRect Ball::getBallRect()
{
	sf::FloatRect shapeRect;

	shapeRect.left = cShape.getPosition().x - cShape.getOrigin().x;
	shapeRect.top = cShape.getPosition().y - cShape.getOrigin().y;
	shapeRect.width = radius;
	shapeRect.height = radius;

	return shapeRect;
}

void Ball::setBallPosition(float fX, float fY)
{
	xPosition = fX;
	yPosition = fY;
}

void Ball::moveBall(float time)
{
	cShape.getPosition();
	xPosition += speed * direction.x * time * 100.f;
	yPosition += speed * direction.y * time * 100.f;

	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
}


void Ball::rebondWithScreen()
{
	// Si la balle atteint le bord gauche ou droit de la fenêtre, inversez la direction horizontale
	if (xPosition < radius || xPosition > 800.f - radius)
	{
		direction.x = -direction.x;
	}

	// Si la balle atteint le bord supérieur de la fenêtre, inversez la direction verticale
	if (yPosition < radius)
	{
		direction.y = -direction.y;
	}
}

void Ball::rebondWithObj(Ball oBall, int collisionCode)
{
	switch (collisionCode)
	{
	case 1: // Collision sur le côté gauche de la brique
		direction.x = -direction.x;
		break;

	case 2: // Collision en haut de la brique
		direction.y = -direction.y;
		break;

	default:
		break;
	}
}
