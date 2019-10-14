#include "pch.h"
#include "Bob.h"

Bob::Bob()
{
	//Set attributes 

	defense = 1;

	//calculate max health
	maxHealth = 28;

	//set health to max
	health = maxHealth;

	speed = 1;

	//set exp value 
	exp = 5;

	//get background texture
	if (!characterTexture.loadFromFile("Choas.png")) {
		//put error here 
	}


	// Associate the sprite with the texture
	characterSprite.setTexture(characterTexture);
}

sf::Sprite Bob::getSprite() {
	return characterSprite;
}

void Bob::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}