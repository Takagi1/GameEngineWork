#include "pch.h"
#include "Guide.h"

Guide::Guide() {

	strength = 20;

	speed = 10;

	maxHealth = 100;
	health = maxHealth;
}

int Guide::BasicAttack(Character* target) {
	int damage = ceil(strength * 1.5) + ceil(dexterity * 0.5);

	return damage;
}

void Guide::Draw() {

}