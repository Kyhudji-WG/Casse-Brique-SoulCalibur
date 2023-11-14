
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>


GameObject::GameObject(float x, float y, float radius, sf::Color couleur) //constructeur CircleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->radius = radius;
	direction.x = 2;
	direction.y = -1;
	
	cShape.setOrigin(0.5 * radius, 0.5 * radius);
	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
	cShape.setRadius(radius);
	cShape.setFillColor(couleur);

}

GameObject::GameObject(float x, float y, float width, float height) //constructeur RectangleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->width = width;
	this->height = height;
	direction.x = 1;
	direction.y = 0;
	rShape.setOrigin(0.5 * width, 0.5 * height);
	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
	rShape.setSize(sf::Vector2f(width, height));
	rShape.setFillColor(sf::Color::Red);
}

GameObject::~GameObject()//destructeur
{

}

/* inutile (pourl'instant ?)

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
	this->direction.x = direction.x;
	this->direction.y = direction.y;
}

sf::Vector2f GameObject::getDirection()
{
	return direction;
}
sf::Vector2f GameObject::getPosition()
{
	sf::Vector2f position;
	position.x = xPosition;
	position.y = yPosition;

	return position;
}

void GameObject::moveBall(float time)
{
	xPosition += direction.x * time * 100.f;
	yPosition += direction.y * time * 100.f;

	

	cShape.setPosition(sf::Vector2f(xPosition, yPosition));
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

	shapeRect.left = cShape.getPosition().x;
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
	if ((shapeRectMin.left >= shapeRectMax.left) && (shapeRectMin.left <= (shapeRectMax.left + shapeRectMax.width))) //test xmin1 entre xmin2 et xmax2
	{
		isX = true;
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

float GameObject::getRadius() const
{
	return radius;
}
