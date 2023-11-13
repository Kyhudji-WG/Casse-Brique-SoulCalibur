#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>


GameObject::GameObject(float x, float y, float radius) //constructeur CircleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->radius = radius;
	direction.x = 1;
	direction.y = 0;

	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
	cShape.setRadius(radius);
	cShape.setFillColor(sf::Color::Green);
}

GameObject::GameObject(float x, float y, float width, float height, sf::Color couleur) //constructeur RectangleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->width = width;
	this->height = height;
	direction.x = 1;
	direction.y = 0;

	rShape.setOrigin( 0.5 * width, 0.5 * height);
	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
	rShape.setSize(sf::Vector2f(width, height));
	rShape.setFillColor(couleur);
}

GameObject::~GameObject()//destructeur
{
	
}

/* inutile (pour l'instant ) 

sf::CircleShape GameObject::getCShape()
{
	return cShape;
}

sf::RectangleShape GameObject::getRShape()
{
	return rShape;
}

*/
void GameObject::drawCircle(sf::RenderWindow& window) 
{
	window.draw(cShape);
}

void GameObject::drawRect(sf::RenderWindow& window)
{
	window.draw(rShape);
}

void GameObject::setDirection(sf::Vector2f const& direction)
{
	xPosition = direction.x;
	yPosition = direction.y;
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

bool GameObject::isOutScreen(sf::FloatRect shapeRect1, int width_screen)
{

	if (shapeRect1.left < 0 || (shapeRect1.left + shapeRect1.width) >= width_screen || shapeRect1.top < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameObject::rebond(GameObject shape_ball)
{
	sf::Vector2f dir(shape_ball.getDirection()); 
	sf::Vector2f N();//Xposition balle - Xposition barre, Yposition balle - Yposition barre ) vecteur normal à normer

}