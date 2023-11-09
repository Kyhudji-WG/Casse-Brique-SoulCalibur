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

GameObject::GameObject(float x, float y, float width, float height) //constructeur RectangleShape
{
	this->xPosition = x;
	this->yPosition = y;
	this->width = width;
	this->height = height;
	direction.x = 1;
	direction.y = 0;

	rShape.setPosition(sf::Vector2f(xPosition, yPosition));
	rShape.setSize(sf::Vector2f(width, height));
	rShape.setFillColor(sf::Color::Red);
}

GameObject::~GameObject()//destructeur
{
	
}

sf::CircleShape GameObject::getCShape()
{
	return cShape;
}

sf::RectangleShape GameObject::getRShape()
{
	return rShape;
}

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

void GameObject::moveBall(float time)
{
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
	cShape.rotate(angle);
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
	if ((shapeRect1.left > shapeRect2.left) && (shapeRect1.left < (shapeRect2.left + shapeRect2.width)) ) //test xmin1 entre xmin2 et xmax2
	{
		std::cout << "1" << std::endl;
		return true;
	}
	else if (((shapeRect1.left + shapeRect1.width) > shapeRect2.left) && ((shapeRect1.left + shapeRect1.width) < (shapeRect2.left + shapeRect2.width))) //test xmax1 entre xmin2 et xmax2
	{
		std::cout << "2" << std::endl;
		return true;
	}
	else if ((shapeRect1.top > shapeRect2.top) && (shapeRect1.top < (shapeRect2.top + shapeRect2.width))) //test ymin1 entre ymin2 et ymax2
	{
		std::cout << "3" << std::endl;
		return true;
	}
	else if (((shapeRect1.top + shapeRect1.width) > shapeRect2.top) && ((shapeRect1.top + shapeRect1.width) < (shapeRect2.top + shapeRect2.width))) //test ymax1 entre ymin2 et ymax2
	{
		std::cout << "4" << std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool GameObject::isOutScreen(int width_screen)
{
	sf::FloatRect col = cShape.getGlobalBounds();

	if (col.left < 0 || (col.left + col.width) >= width_screen || col.top < 0)
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

}