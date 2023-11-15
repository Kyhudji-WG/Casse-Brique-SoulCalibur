#include "Ball.h"


Ball::Ball(float x, float y, float radius, sf::Color couleur) : GameObject(x, y, radius, couleur) //Constructeur 
{
	speed = 1;
}

Ball::~Ball() //destructeur
{

}

void Ball::moveBall(float time)
{
	cShape.getPosition();
	xPosition += direction.x * time * 100.f;
	yPosition += direction.y * time * 100.f;

	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
}
