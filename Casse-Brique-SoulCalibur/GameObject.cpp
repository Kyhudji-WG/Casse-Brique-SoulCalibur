#include "GameObject.h"
#include <SFML/Graphics.hpp>


GameObject::GameObject(float x, float y, float radius)
{
	this->xPosition = x;
	this->yPosition = y;
	//weight = weight;
	//height = height;
	this->radius = radius;
	xDirection = -1;
	yDirection = -1;


	shape.setPosition(sf::Vector2f(xPosition, yPosition));
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::Green);

}

GameObject::~GameObject()//destructeur
{

}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void GameObject::move(float time)
{
	xPosition += xDirection * time * 100.f;
	yPosition += yDirection * time * 100.f;

	shape.setPosition(sf::Vector2f(xPosition, yPosition));
}

void GameObject::setRotation(float angle) 
{
	shape.setRotation(angle);

}