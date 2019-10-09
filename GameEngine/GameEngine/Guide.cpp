#include "pch.h"
#include "Guide.h"

Guide::Guide() {

	name = "Guide";

	strength = 20;

	speed = 10;

	maxHealth = 100;
	health = maxHealth;
}

int Guide::BasicAttack(Character* target) {
	int damage = ceil(strength * 1.5) + ceil(dexterity * 0.5);

	return damage;
}

sf::Sprite Guide::getSprite() {
	return characterSprite;
}

void Guide::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}