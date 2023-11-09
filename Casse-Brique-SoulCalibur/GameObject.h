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
	sf::Vector2f direction;

	sf::CircleShape cShape; 
	sf::RectangleShape rShape;

public:

	GameObject(float x, float y, float radius); //constructeur CircleShape

	GameObject(float x, float y, float width, float height); //constructeur RectangleShape

	~GameObject(); //destructeur

	sf::CircleShape getCShape();

	sf::RectangleShape getRShape();

	void drawCircle(sf::RenderWindow& window);

	void drawRect(sf::RenderWindow& window);

	void setDirection(sf::Vector2f const& direction);

	sf::Vector2f getDirection();

	void moveBall(float time);

	void moveRect(float time);

	void setRotation(float angle);

	sf::FloatRect getBallRect();

	sf::FloatRect getRectangleRect();

	bool OnCollisionEnter(sf::FloatRect shapeRect1, sf::FloatRect shapeRect2);

	bool isOutScreen(int width_screen);

	void rebond(GameObject shape_ball);
};

