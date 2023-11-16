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

sf::Vector2f GameObject::getPosition()
{
	sf::Vector2f positions;
	positions.x = xPosition;
	positions.y = yPosition;

	return positions;
}
sf::FloatRect GameObject::getRectangleRect()
{
	sf::FloatRect shapeRect;

	shapeRect.width = width;
	shapeRect.height = height;

	shapeRect.left = rShape.getPosition().x - rShape.getOrigin().x;
	shapeRect.top = rShape.getPosition().y - rShape.getOrigin().y;

	return shapeRect;
}


int GameObject::OnCollisionEnter(sf::FloatRect shapeBall, sf::FloatRect shapeBrick, int life)
{
	bool isX = false;
	bool isY = false;

	float overlapX = 0.0f;
	float overlapY = 0.0f;

	if (life > 0)
	{
		// Test de collision sur l'axe X
		if (shapeBall.left + shapeBall.width > shapeBrick.left &&
			shapeBall.left < shapeBrick.left + shapeBrick.width)
		{
			isX = true;

			// Calcul de la quantité de chevauchement sur l'axe X
			overlapX = std::min(shapeBall.left + shapeBall.width - shapeBrick.left, shapeBrick.left + shapeBrick.width - shapeBall.left);
		}

		// Test de collision sur l'axe Y
		if (shapeBall.top + shapeBall.height > shapeBrick.top &&
			shapeBall.top < shapeBrick.top + shapeBrick.height)
		{
			isY = true;

			// Calcul de la quantité de chevauchement sur l'axe Y
			overlapY = std::min(shapeBall.top + shapeBall.height - shapeBrick.top, shapeBrick.top + shapeBrick.height - shapeBall.top);
		}

		// Détermination de la face de collision
		if (isX && isY)
		{
			if (overlapX < overlapY)
			{
				// Collision sur l'axe X, déterminez si c'est à gauche ou à droite
				if (shapeBall.left <= shapeBrick.left)
				{
					// Collision sur le côté gauche de la brique
					std::cout << "Collision sur le côté gauche de la brique" << std::endl;
					return 1;
				}
				else
				{
					// Collision sur le côté droit de la brique
					std::cout << "Collision sur le côté droit de la brique" << std::endl;
					return 1;
				}
			}
			else
			{
				// Collision sur l'axe Y, déterminez si c'est en haut ou en bas
				if (shapeBall.top <= shapeBrick.top)
				{
					// Collision en haut de la brique
					std::cout << "Collision en haut de la brique" << std::endl;
					return 2;
				}
				else
				{
					// Collision en bas de la brique
					std::cout << "Collision en bas de la brique" << std::endl;
					return 2;
				}
			}

			// Vous pouvez également renvoyer un code ou une valeur spécifique pour indiquer la face de collision
			return true;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}



