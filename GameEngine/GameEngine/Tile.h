#pragma once
#include "SFML/Graphics.hpp"

class Tile {

private:
	sf::Sprite sprite;

	sf::Texture texture;

public:
	Tile();

	void SetTexture(std::string name);

	void SetSprite();

	void SetLocation(int x, int y);

	//send copy of the sprite to main 
	sf::Sprite getSprite();

	bool isMoveable = true; //Is this tile movable

};