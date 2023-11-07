#include "GameObject.h"
#include <SFML/Graphics.hpp>


GameObject::GameObject() //constructeur
{
	xPosition = 100.f;
	yPosition = 100.f;
	weight = 10.f;
	height = 10.f;

}

GameObject::~GameObject() //destructeur
{

}

void GameObject::move(float time)
{
	
}
