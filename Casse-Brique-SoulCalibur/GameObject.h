#pragma once

class GameObject
{
private:
	float xPosition;
	float yPosition;

	float weight;
	float height;

public:

	GameObject(); //constructeur

	~GameObject(); //destructeur

	void move(float time);
};

