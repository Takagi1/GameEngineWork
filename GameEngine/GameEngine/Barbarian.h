#pragma once
#include "Champion.h"


class Barbarian : public Champion
{
private:

public:

	//Constructor
	Barbarian();

	//References

	int& maxHealth = Character::maxHealth;

	int& health = Character::health;

	int& strength = Character::strength;
	int& dexterity = Character::dexterity;
	int& vitality = Character::vitality;
	int& inteligence = Character::inteligence;
	int& wisdom = Character::wisdom;
	int& defense = Character::defense;
	int& speed = Character::speed;
};

