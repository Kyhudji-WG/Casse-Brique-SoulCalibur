#pragma once
#include <SFML/Graphics.hpp>


class GameObject
{
private:

	float xPosition;
	float yPosition;
	float weight;
	float height;
	float radius;
	int xDirection;
	int yDirection;

	sf::CircleShape shape;

public:

	GameObject(float x, float y, float radius); //constructeur

	~GameObject(); //destructeur

	void draw(sf::RenderWindow& window);

	void move(float time);
};
