#pragma once
#include "AnimationController.h"

using namespace sf;

//Forward Decleration

class Monster;

class MapCharacter
{

public:
	enum Direction
	{
		Right,
		Down,
		Left,
		Up
	};

	AnimationController animationController;

	Direction dir = Down;//What direction is the character facing also the default 

	//is this the player
	bool isPlayer;

	//Object position
	Vector2f position;

	//send copy of the sprite to main 
	Sprite getSprite();

	RectangleShape getRect();
	
	Monster* monster;

	Texture texture;
	Sprite sprite;
//Movement 

	std::pair<int, int> location;

	void Move(int x, int y);


	//Update
	void update(float deltaTime);
};