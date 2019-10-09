#include "pch.h"
#include "Barbarian.h"

Barbarian::Barbarian() {

	name = "Barbarian";

	strength = 20;

	speed = 10;

	maxHealth = 100;
	health = maxHealth;

	//get background texture
	characterTexture.loadFromFile("Robo.png");

	// Associate the sprite with the texture
	characterSprite.setTexture(characterTexture);
}

int Barbarian::BasicAttack(Character* target) {
	int damage = ceil(strength * 1.5) + ceil(dexterity * 0.5);

	return damage;
}

sf::Sprite Barbarian::getSprite() {
	return characterSprite;
}

void Barbarian::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}

