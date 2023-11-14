#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Canon : public GameObject
{
private :

public :
	Canon(float x, float y, float width, float height, sf::Color couleur); //constructeur
	~Canon();// Destructeur

};