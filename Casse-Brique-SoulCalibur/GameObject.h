#pragma once
#include <SFML/Graphics.hpp>


class GameObject
{
protected:

	float xPosition;
	float yPosition;
	float width;
	float height;
	float radius;
	sf::Vector2f direction;

	sf::CircleShape cShape; 
	sf::RectangleShape rShape;

public:

	GameObject(float x, float y, float radius, sf::Color couleur); //constructeur CircleShape

	GameObject(float x, float y, float width, float height, sf::Color couleur); //constructeur RectangleShape

	~GameObject(); //destructeur

	const sf::Vector2f getOrigin();

	void drawCircle(sf::RenderWindow& window);

	void drawRect(sf::RenderWindow& window);

	void setDirection(float y, float x);

	sf::Vector2f getDirection();

	void setRectPosition(float fX, float fY);

	sf::Vector2f getPosition();

	sf::FloatRect getRectangleRect();

	int OnCollisionEnter(sf::FloatRect shapeRect1, sf::FloatRect shapeRect2);
};

