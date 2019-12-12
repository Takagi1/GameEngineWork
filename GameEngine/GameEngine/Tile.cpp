#include "pch.h"
#include "Tile.h"
#include "SceneManager.h"

Tile::Tile(Effect eff)
{
	effect = eff;
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

void Tile::CalledEffect(SceneManager** manager)
{
	//This might be a bad way of doing this
	SceneManager* man = *manager;
	if (effect == Transition) {
		man->BuildScene(man->IntToScene(scene_number), x, y);
	}
}

void Tile::TickEffect()
{
}

void Tile::SetChangeScene(int scene_number_, int x_, int y_)
{
	scene_number = scene_number_;
	x = x_;
	y = y_;
	effect = Transition;
	isMoveable = true;
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}
