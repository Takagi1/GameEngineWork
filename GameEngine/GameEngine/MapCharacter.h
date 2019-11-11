#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class MapCharacter
{

public:

	//Constructor
	MapCharacter();

	//Object position
	Vector2f position;

	//send copy of the sprite to main 
	Sprite getSprite();

	Texture texture;
	Sprite sprite;

//Movement 

	std::pair<int, int> location;

	void Move(int x, int y);

	//Update
	void update(float deltaTime);
};