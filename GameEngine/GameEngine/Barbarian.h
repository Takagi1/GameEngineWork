#pragma once
#include "Champion.h"


class Barbarian : public Champion
{
private:

public:

	//Constructor
	Barbarian();

	//References

	//max health
	int& maxHealth = Character::maxHealth;

	//current health
	int& health = Character::health;

	int& strength = Character::strength;
	int& dexterity = Character::dexterity;
	int& vitality = Character::vitality;
	int& inteligence = Character::inteligence;
	int& wisdom = Character::wisdom;
	int& defense = Character::defense;
	int& speed = Character::speed;

	int& rage = Champion::resource;

	//for drawing character
	virtual void Draw() override;
};

