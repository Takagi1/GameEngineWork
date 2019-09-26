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

	//calculate max health
	maxHealth = vitality * 3;

	//set health to max

	health = maxHealth;
}
