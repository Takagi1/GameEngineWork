#include "pch.h"
#include "Bob.h"

Bob::Bob()
{
	//Set attributes 
	strength = 5;
	dexterity = 5;
	vitality = 5;
	inteligence = 5;
	wisdom = 5;

	defense = 1;

	//calculate max health
	maxHealth = vitality * 3;

	//set health to max
	health = maxHealth;

	//set exp value 
	exp = 5;

	isMonster = true;

	//get background texture
	if (!characterTexture.loadFromFile("Choas.png")) {
		//put error here 
	}


	// Associate the sprite with the texture
	characterSprite.setTexture(characterTexture);
}

int Bob::BasicAttack(Character* target) {
	int damage = ceil(strength * 1.5) + ceil(dexterity * 0.5);

	return damage;
}

sf::Sprite Bob::getSprite() {
	return characterSprite;
}

int Bob::GetExp() {
	return exp;
}

void Bob::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}