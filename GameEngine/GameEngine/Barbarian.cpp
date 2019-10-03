#include "pch.h"
#include "Barbarian.h"

Barbarian::Barbarian() {

	strength = 20;

	speed = 10;

	maxHealth = 100;
	health = maxHealth;
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