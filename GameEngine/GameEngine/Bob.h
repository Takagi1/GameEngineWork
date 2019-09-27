#pragma once
#include "Monster.h"
class Bob : public Monster
{
private:

public:

	//Constructor
	Bob();

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

	virtual void Draw() override;
};
