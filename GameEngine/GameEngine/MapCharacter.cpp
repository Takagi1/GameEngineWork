#include "pch.h"
#include "MapCharacter.h"
MapCharacter::MapCharacter()
{
	
	//Associate texture with sprite
	//texture.loadFromFile("bob.png");


	//sprite.setTexture(texture);
	rec.setSize(Vector2f(25, 25));
	rec.setFillColor(sf::Color::Green);
	rec.setOutlineThickness(3);
	rec.setOutlineColor(sf::Color::Black);
	rec.setPosition(0, 0);
}

//TODO add in connection between player and map movement (will most likely need to simplify the system overall)

//make the private sprite available to the draw() function
Sprite MapCharacter::getSprite()
{
	
	return sprite;
}

void MapCharacter::Move(int x, int y)
{
	location.first += x;
	location.second += y;
}


void MapCharacter::update(float deltaTime) {

	//Now move sprite to its new position
	position = Vector2f(-600 + ((location.first * 100) + 50), -200 + ((location.second * 100) + 50));
	rec.setPosition(position);
	
} 