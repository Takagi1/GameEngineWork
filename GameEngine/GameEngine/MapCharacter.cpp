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
	return animationController.GetRectangle();
}

void MapCharacter::Move(int x, int y)
{
	location.first += x;
	location.second += y;
}

FloatRect MapCharacter::collision()
{
	FloatRect rec(0,0,50,50);
	if (dir == Up) {
		rec.left = position.x;
		rec.top = position.y - 100;
	}
	else if (dir == Right) {
		rec.left = position.x + 100;
		rec.top = position.y;
	}
	else if (dir == Down) {
		rec.left = position.x;
		rec.top = position.y + 100;
	}
	else if (dir == Left) {
		rec.left = position.x - 100;
		rec.top = position.y;
	}
	return rec;
}


void MapCharacter::update(float deltaTime,sf::RenderWindow& r_Window) {

	//Now move sprite to its new position

	rectangle = getRect();
	position = Vector2f((r_Window.getSize().x / 2 - rectangle.getLocalBounds().width / 2) + location.first * 100, (r_Window.getSize().y / 2 - rectangle.getLocalBounds().height / 2) + location.second * 100);

	rectangle.setPosition(position);
} 