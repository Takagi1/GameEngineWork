#pragma once
#include "AnimationController.h"
#include <forward_list>

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

	RectangleShape rectangle;

	Monster* monster = nullptr;

	Texture texture;
	Sprite sprite;

	std::forward_list<std::string> sentence;

	bool isPerson = false;
//Movement 

	std::pair<int, int> location;

	void Move(int x, int y);

	sf::FloatRect collision();

	virtual Monster* CallMonster() = 0;
	//Update
	void update(float deltaTime, sf::RenderWindow& r_Window);
};