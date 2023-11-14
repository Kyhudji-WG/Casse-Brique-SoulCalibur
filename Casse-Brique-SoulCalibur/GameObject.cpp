#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cmath>


GameObject::GameObject(float x, float y, float radius, sf::Color couleur) //constructeur CircleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->radius = radius;

	cShape.setOrigin(0.5 * radius, 0.5 * radius);
	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
	cShape.setRadius(radius);
	cShape.setFillColor(couleur);
	direction.x = 1;
	direction.y = 0;
}

GameObject::GameObject(float x, float y, float width, float height, sf::Color couleur) //constructeur RectangleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->width = width;
	this->height = height;

	rShape.setOrigin( 0.5 * width, 0.5 * height);
	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
	rShape.setSize(sf::Vector2f(width, height));
	rShape.setFillColor(couleur);
}

GameObject::~GameObject()//destructeur
{
	
}


const sf::Vector2f GameObject::getOrigin()
{
	return cShape.getOrigin();
}
void GameObject::drawCircle(sf::RenderWindow& window) 
{
	window.draw(cShape);
}

void GameObject::drawRect(sf::RenderWindow& window)
{
	window.draw(rShape);
}

void GameObject::setDirection(float y, float x)
{
	direction.x = x;

	direction.y = y;


	float norme = sqrt(pow(direction.x, 2) + pow(direction.y, 2));

	direction.x = direction.x / norme; //direction X normée
	direction.y = -direction.y / norme; //direction Y normée
	//vecteur direction : creer 2 points => position cannon et position ball
}

sf::Vector2f GameObject::getDirection()
{
	return direction;
}


void GameObject::setRectPosition(float fX, float fY)
{
	xPosition = fX;
	yPosition = fY;
}

void GameObject::setBallPosition(float fX, float fY)
{
	xPosition = fX;
	yPosition = fY;
}

sf::Vector2f GameObject::getPosition()
{
	sf::Vector2f positions;
	positions.x = xPosition;
	positions.y = yPosition;

	return positions;
}

void GameObject::moveBall(float time)
{
	cShape.getPosition();
	xPosition += direction.x * time * 100.f;
	yPosition += direction.y * time * 100.f;

	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void GameObject::moveRect(float time)
{
	xPosition += direction.x * time * 100.f;
	yPosition += direction.y * time * 100.f;

	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void GameObject::setRotation(float angle)
{
	rShape.setRotation(angle);
}


sf::FloatRect GameObject::getBallRect()
{
	sf::FloatRect shapeRect;

	shapeRect.left =  cShape.getPosition().x;
	shapeRect.top = cShape.getPosition().y;

	return shapeRect;
}

sf::FloatRect GameObject::getRectangleRect()
{
	sf::FloatRect shapeRect;

	shapeRect.left = rShape.getPosition().x;
	shapeRect.top = rShape.getPosition().y;
	shapeRect.width = width;
	shapeRect.height = height;

	return shapeRect;
}

bool GameObject::OnCollisionEnter(sf::FloatRect shapeRect1, sf::FloatRect shapeRect2) //compare la collision entre 2 objets
{
	sf::FloatRect shapeRectMin = shapeRect2;
	sf::FloatRect shapeRectMax = shapeRect1;
	bool isX = false;
	bool isY = false;

	if (shapeRect1.width * shapeRect1.height < shapeRect2.width * shapeRect2.height) //on cherche le rectangle le plus petit
	{
		shapeRectMin = shapeRect1;
		shapeRectMax = shapeRect2;
	}
	if ((shapeRectMin.left >= shapeRectMax.left) && (shapeRectMin.left <= (shapeRectMax.left + shapeRectMax.width)) ) //test xmin1 entre xmin2 et xmax2
	{
		isX= true;
	}
	if (((shapeRectMin.left + shapeRectMin.width) >= shapeRectMax.left) && ((shapeRectMin.left + shapeRectMin.width) <= (shapeRectMax.left + shapeRectMax.width))) //test xmax1 entre xmin2 et xmax2
	{
		isX = true;
	}
	if ((shapeRectMin.top >= shapeRectMax.top) && (shapeRectMin.top <= (shapeRectMax.top + shapeRectMax.height))) //test ymin1 entre ymin2 et ymax2
	{
		isY = true;
	}
	if (((shapeRectMin.top + shapeRectMin.height) >= shapeRectMax.top) && ((shapeRectMin.top + shapeRectMin.height) <= (shapeRectMax.top + shapeRectMax.height))) //test ymax1 entre ymin2 et ymax2
	{
		isY = true;
	}
	if (isX && isY)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void GameObject::rebond()
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