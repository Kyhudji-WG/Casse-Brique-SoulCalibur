#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball : public GameObject
{
private:
	float speed;
public:

	Ball(float x, float y, float radius, sf::Color couleur, float speed); //constructeur
	~Ball(); //destructeur

	sf::FloatRect getBallRect();

	void setBallPosition(float fX, float fY);

	void moveBall(float time);

	void rebondWithScreen();

	void rebondWithBrick(Ball oBall, int collisionCode);
};