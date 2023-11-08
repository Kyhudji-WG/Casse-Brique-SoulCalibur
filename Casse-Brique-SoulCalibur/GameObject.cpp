#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>


GameObject::GameObject(float x, float y, float radius)
{
	this->xPosition = x;
	this->yPosition = y;
	//width = width;
	//height = height;
	this->radius = radius;
	xDirection = 0;
	yDirection = -1;
	

	shape.setPosition(sf::Vector2f(xPosition, yPosition));
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::Green);
	
	
}

GameObject::~GameObject()//destructeur
{
	
}

sf::CircleShape GameObject::getShape()
{
	return shape;
}

void GameObject::draw(sf::RenderWindow& window) 
{
	window.draw(shape);
}

void GameObject::setDirection(sf::Vector2f const& direction)
{
	xDirection = direction.x;
	yDirection = direction.y;
}

void GameObject::getDirection()
{
	sf::Vector2f(xDirection, yDirection);
}

void GameObject::move(float time)
{
	xPosition += xDirection * time * 100.f;
	yPosition += yDirection * time * 100.f;

	shape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void GameObject::setRotation(float angle)
{
	shape.rotate(angle);
}

bool GameObject::isColliderect(sf::FloatRect col2)
{
	sf::FloatRect col = shape.getGlobalBounds();
	
	if (col.intersects(col2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameObject::isOutScreen(int width_screen)
{
	sf::FloatRect col = shape.getGlobalBounds();

	if (col.left < 0 || (col.left + col.width) >= width_screen || col.top < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}