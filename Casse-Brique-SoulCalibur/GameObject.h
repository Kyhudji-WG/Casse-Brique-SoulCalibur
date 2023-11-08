#pragma once
#include <SFML/Graphics.hpp>


class GameObject
{
private:

	float xPosition;
	float yPosition;
	float width;
	float height;
	float radius;
	int xDirection;
	int yDirection;

	sf::CircleShape shape; 

public:

	GameObject(float x, float y, float radius); //constructeur

	~GameObject(); //destructeur

	sf::CircleShape getShape();

	void draw(sf::RenderWindow& window);

	void setDirection(sf::Vector2f const& direction);

	void getDirection();

	void move(float time);

	void setRotation(float angle);

	bool isColliderect(sf::FloatRect col2);

	bool isOutScreen(int width_screen);
};

