#include "pch.h"
#include "Dodger.h"
#include "Blob.h"
#include "Food.h"
#include "Fire1.h"

Dodger::Dodger()
{
	name = "Dodger";

	//Setup attributes
	strength = 1;
	dexterity = 1;
	magic = 1;

	vitality = 1;
	defense = 0;
	speed = 1;

	//Set elemental resistance
	elementMod[Element::Physical] = 0;
	elementMod[Element::Fire] = 0;
	elementMod[Element::Ice] = 0;
	elementMod[Element::Poison] = 0;

	//Set health, maxhealth, energy, and maxenergy
	maxHealth = vitality * 3;
	health = maxHealth;

	maxEnergy = 100;
	energy = maxEnergy;

	//get background texture
	setTexture("Choas.png");

	// Associate the sprite with the texture
	setSprite();
}

void Dodger::MonsterAction(Character *  blob_)
{
	//Perform test attack
	blob_->takeDamage(5, Element::Physical, false);
}

Food* Dodger::GetFood()
{
	Food* food = new Food();

	food->creature = "Dodger";

	food->amount[0].strength = 1;
	food->amount[0].dexterity = 1;
	food->amount[0].magic = 1;

	return food;
}
/*AI should figure out what it is going to do. for now make it simple
BasicAction(guide_);
if (guide_.location > location) {
	Move(1);
}
else if (guide_.location < location) {
	Move(-1);
}
actionsLeft -= 1;
*/