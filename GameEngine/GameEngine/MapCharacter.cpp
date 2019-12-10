#include "pch.h"
#include "MapCharacter.h"


//TODO add in connection between player and map movement (will most likely need to simplify the system overall)

//make the private sprite available to the draw() function
Sprite MapCharacter::getSprite()
{
	return sprite;
}

RectangleShape MapCharacter::getRect()
{
	sf::RectangleShape rec = animationController.GetRectangle();
	rec.setPosition(position);
	return rec;
}

void MapCharacter::Move(int x, int y)
{
	location.first += x;
	location.second += y;
}


void MapCharacter::update(float deltaTime) {

	//Now move sprite to its new position
	position = Vector2f(-575 + ((location.first * 100) + 50), -175 + ((location.second * 100) + 50));
	//rec.setPosition(position);
	
} 