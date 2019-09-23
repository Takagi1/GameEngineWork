#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class MapCharacter
{

private:

	// Is left button pressed
	bool m_LeftPressed;

	// Is right button pressed
	bool m_RightPressed;

	// Is up button pressed
	bool m_UpPressed;

	// Is down button pressed
	bool m_DownPressed;

	//speed in pixels per second
	float speed;

public:

	//Constructor
	MapCharacter();

	//Object position
	Vector2f position;

	//send copy of the sprite to main 
	Sprite getSprite();

	
	Texture texture;
	Sprite sprite;

	// Player movement 

	// Move player left
	void moveLeft();

	// Move player right
	void moveRight();

	// Move player up
	void moveUp();

	// Move player down
	void moveDown();

	// Stop movement left
	void stopLeft();

	// Stop movement right
	void stopRight();

	// Stop movement up
	void stopUp();

	// Stop movement down
	void stopDown();

	//Update
	void update(float deltaTime);
};