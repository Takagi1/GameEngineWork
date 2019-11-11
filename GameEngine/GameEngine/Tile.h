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

	void Draw(sf::RenderWindow& r_Window);

	bool isMoveable = true; //Is this tile movable

};