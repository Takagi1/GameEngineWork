#include "pch.h"
#include "Barbarian.h"
#include "Guide.h"
#include "Monster.h"

Barbarian::Barbarian() {

	name = "Barbarian";

	power = 5;

	maxHealth = 100;
	health = maxHealth;

	//get background texture
	characterTexture.loadFromFile("Robo.png");

	// Associate the sprite with the texture
	characterSprite.setTexture(characterTexture);
}

void Barbarian::turnStart(int turn)
{
}

void Barbarian::BasicAction(Monster& monster) {
	int damage = power * 2;
	monster.takeDamage(damage);
}

void Barbarian::Guard()
{
	guard1 = true;
}

sf::Sprite Barbarian::getSprite() {
	return characterSprite;
}

void Barbarian::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}


