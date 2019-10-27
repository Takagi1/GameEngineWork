#include "pch.h"
#include "Bob.h"
#include "Guide.h"

Bob::Bob()
{
	//Set attributes 

	power = 1;

	defense = 1;

	//calculate max health
	maxHealth = 28;

	//set health to max
	health = maxHealth;

	speed = 1;

	actions = 1;
	actionsLeft = actions;

	//set exp value 
	exp = 5;

	//get background texture
	if (!characterTexture.loadFromFile("Choas.png")) {
		//put error here 
	}

	// Associate the sprite with the texture
	characterSprite.setTexture(characterTexture);
}

void Bob::MonsterAction(Guide & guide_)
{
	//AI should figure out what it is going to do. for now make it simple
	BasicAction(guide_);
	if (guide_.location > location) {
		Move(1);
	}
	else if (guide_.location < location) {
		Move(-1);
	}
	actionsLeft -= 1;
}

void Bob::BasicAction(Guide & guide_)
{
	int damage = power * 2;
	guide_.takeDamage(damage);
}

void Bob::Move(int direction)
{
	location += direction;
}

sf::Sprite Bob::getSprite() {
	return characterSprite;
}

void Bob::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}