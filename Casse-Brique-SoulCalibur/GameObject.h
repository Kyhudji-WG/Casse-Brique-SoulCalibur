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
	float minAngle;
	float maxAngle;
	sf::CircleShape cShape;
	sf::RectangleShape rShape;
	    std::vector<GameObject> bullets;



public:

	GameObject(float x, float y, float radius, sf::Color couleur); //constructeur CircleShape

	GameObject(float x, float y, float width, float height); //constructeur RectangleShape

	~GameObject(); //destructeur

	//sf::CircleShape getCShape(); inutile pour l'instant

	//sf::RectangleShape getRShape(); inutile pour l'instant

	void drawCircle(sf::RenderWindow& window);

	void drawRect(sf::RenderWindow& window);

	void setDirection(sf::Vector2f const& direction);

	sf::Vector2f getDirection();

	sf::Vector2f getPosition();

	void moveBall(float time);

	void moveRect(float time);

	void setRotation(float angle);

	sf::FloatRect getBallRect();

	sf::FloatRect getRectangleRect();

	bool OnCollisionEnter(sf::FloatRect shapeRect1, sf::FloatRect shapeRect2);

	bool isOutScreen(sf::FloatRect shapeRect1, int width_screen);

	void rebond();

	float getRadius() const;

	void setDirection(float y, float x);
};