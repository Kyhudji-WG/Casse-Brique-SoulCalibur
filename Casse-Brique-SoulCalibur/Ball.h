#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball : public GameObject
{
private:
	int speed;
public:

	Ball(float x, float y, float radius, sf::Color couleur); //constructeur
	~Ball(); //destructeur

	void moveBall(float time);
};