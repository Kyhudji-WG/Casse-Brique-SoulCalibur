#include "GameObject.h"
#include <SFML/Graphics.hpp>

/*
GameObject::GameObject(float x, float y, float weight, float height) //constructeur
{
	xPosition = x;
	yPosition = y;
	weight = weight;
	height = height;


	// Initialise la position et la taille de l'objet
	// par défaut, vous pouvez également ajouter d'autres paramètres, comme la couleur, la texture, etc.
	shape.setPosition(x, y);

}
*/
GameObject::GameObject(float x, float y, float radius)
{
	/*
	xPosition = x;
	yPosition = y;
	weight = weight;
	height = height;
	radius = radius;
	*/

	shape.setPosition(sf::Vector2f(x, y));
	shape.setRadius(radius);
	shape.setFillColor(sf::Color::Red);
}

GameObject::~GameObject()//destructeur
{
	
}

void GameObject::draw(sf::RenderWindow& window) {
	window.draw(shape);
}

/*
void GameObject::setPosition(float x, float y) {
	shape.setPosition(x, y);
}

void GameObject::setRadius(float radius) {
	shape.setRadius(radius);
}


*/