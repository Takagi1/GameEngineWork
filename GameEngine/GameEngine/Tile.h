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

	void CalledEffect(); //Player interact

	void TickEffect(); //What happens every tick

	sf::Sprite getSprite(); //send copy of the sprite to main 

	bool isMoveable = true; //Is this tile movable

};