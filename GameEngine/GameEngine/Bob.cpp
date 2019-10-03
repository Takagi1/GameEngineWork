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
}

int Bob::BasicAttack(Character* target) {
	int damage = ceil(strength * 1.5) + ceil(dexterity * 0.5);

	return damage;
}

void Bob::Draw() {

}

int Bob::GetExp() {
	return exp;
}

