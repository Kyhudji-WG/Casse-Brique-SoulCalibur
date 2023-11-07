#include "GameObject.h"
#include <SFML/Graphics.hpp>


GameObject::GameObject() //constructeur
{
	xPosition = 100.f;
	yPosition = 100.f;
	weight = 10.f;
	height = 10.f;
	xdirection = 0;
	ydirection = 0;

}

GameObject::~GameObject() //destructeur
{

}

void GameObject::move(float time)
{
	xPosition += time * xdirection;
	yPosition += time * ydirection;
}