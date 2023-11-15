#include <SFML/Graphics.hpp>
#include <iostream>
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


void Ball::rebond()
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

bool Ball::OnCollisionEnter(sf::FloatRect shapeRect1, sf::FloatRect shapeRect2) //compare la collision entre 2 objets
{
	sf::FloatRect shapeRectMin = shapeRect1;
	sf::FloatRect shapeRectMax = shapeRect2;
	bool isX = false;
	bool isY = false;

	if (shapeRectMin.width * shapeRectMin.height > shapeRectMax.width * shapeRectMax.height) //on cherche le rectangle le plus petit
	{
		shapeRectMin = shapeRect2;
		shapeRectMax = shapeRect1;
	}
	if ((shapeRectMin.left > shapeRectMax.left) && (shapeRectMin.left < (shapeRectMax.left + shapeRectMax.width))) //test xmin1 entre xmin2 et xmax2
	{
		isX = true;
	}
	if (((shapeRectMin.left + shapeRectMin.width) > shapeRectMax.left) && ((shapeRectMin.left + shapeRectMin.width) < (shapeRectMax.left + shapeRectMax.width))) //test xmax1 entre xmin2 et xmax2
	{
		isX = true;
	}
	if ((shapeRectMin.top > shapeRectMax.top) && (shapeRectMin.top < (shapeRectMax.top + shapeRectMax.height))) //test ymin1 entre ymin2 et ymax2
	{
		isY = true;
	}
	if (((shapeRectMin.top + shapeRectMin.height) > shapeRectMax.top) && ((shapeRectMin.top + shapeRectMin.height) < (shapeRectMax.top + shapeRectMax.height))) //test ymax1 entre ymin2 et ymax2
	{
		isY = true;
	}
	if (isX && isY)
	{
		std::cout << "coision";
		return true;
	}
	else
	{
		return false;
	}
}
