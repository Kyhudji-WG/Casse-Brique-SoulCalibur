#pragma once

class GameObject
{
private:
	float xPosition;
	float yPosition;

	float weight;
	float height;

	float xdirection;
	float ydirection;

public:

	GameObject(); //constructeur

	~GameObject(); //destructeur

	void move(float time);
};

