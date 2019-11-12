#include "pch.h"
#include "Tile.h"

Tile::Tile()
{
}

void Tile::SetTexture(std::string name)
{

	if (!texture.loadFromFile(name)) {
		//put error here 
	}
}

void Tile::SetSprite()
{
	sprite.setTexture(texture);
}

void Tile::SetLocation(int x, int y)
{
	sprite.setPosition(x, y);
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}
