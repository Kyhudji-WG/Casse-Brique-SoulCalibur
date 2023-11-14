#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Brick : public GameObject
{
private:
	int life;
	float xPosition;
	float yPosition;
	float width;
	float height;

	sf::RectangleShape rShape;

public:
	Brick(float x, float y, float width, float height, sf::Color couleur, int life); //constructeur
	~Brick();// Destructeur

	void TakeDamage();
};
