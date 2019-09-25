#include "pch.h"
#include "MapCharacter.h"
MapCharacter::MapCharacter()
{
	
	//Associate texture with sprite
	texture.loadFromFile("bob.png");
	sprite.setTexture(texture);

	//Set speed
	speed = 400;

	//Set Starting position
	position.x = 700;
	position.y = 700;
	
}

//TODO add in connection between player and map movement (will most likely need to simplify the system overall)

//make the private sprite available to the draw() function
Sprite MapCharacter::getSprite()
{
	return sprite;
}


void MapCharacter::moveLeft()
{
	m_LeftPressed = true;
}

void MapCharacter::moveRight()
{
	m_RightPressed = true;
}

void MapCharacter::moveUp()
{
	m_UpPressed = true;
}

void MapCharacter::moveDown()
{
	m_DownPressed = true;
}

void MapCharacter::stopLeft()
{
	m_LeftPressed = false;
}

void MapCharacter::stopRight()
{
	m_RightPressed = false;
}

void MapCharacter::stopUp()
{
	m_UpPressed = false;
}

void MapCharacter::stopDown()
{
	m_DownPressed = false;
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed.
void MapCharacter::update(float deltaTime) {
	if (m_RightPressed)
	{
		position.x += speed * deltaTime;
	}

	if (m_LeftPressed)
	{
		position.x -= speed * deltaTime;
	}

	if (m_UpPressed)
	{
		position.y -= speed * deltaTime;
	}

	if (m_DownPressed)
	{
		position.y += speed * deltaTime;
	}
	

	//Now move sprite to its new position
	sprite.setPosition(position);
	
} 