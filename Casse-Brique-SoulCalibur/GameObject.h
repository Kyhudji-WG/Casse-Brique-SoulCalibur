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

	GameObject(float x, float y, float radius, sf::Color couleur); //constructeur CircleShape

	GameObject(float x, float y, float width, float height, sf::Color couleur); //constructeur RectangleShape

	~GameObject(); //destructeur

	const sf::Vector2f getOrigin();

	//sf::CircleShape getCShape(); inutile pour l'instant

	//sf::RectangleShape getRShape(); inutile pour l'instant

	void drawCircle(sf::RenderWindow& window);

	void drawRect(sf::RenderWindow& window);

	void setDirection(float y, float x);

	sf::Vector2f getDirection();

	void setRectPosition(float fX, float fY);

	void setBallPosition(float fX, float fY);

	sf::Vector2f getPosition();

	void moveBall(float time);

	void moveRect(float time);

	void setRotation(float angle);

	sf::FloatRect getBallRect();

	sf::FloatRect getRectangleRect();

	bool OnCollisionEnter(sf::FloatRect shapeRect1, sf::FloatRect shapeRect2);

	bool isOutScreen(sf::FloatRect shapeRect1, int width_screen);

	void rebond(GameObject shape_ball);
};

