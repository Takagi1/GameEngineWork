#include "pch.h"
#include "Bob.h"
#include "Blob.h"
#include "Food.h"

Bob::Bob()
{
	//Setup attributes
	strength = 3;
	dexterity = 3;
	magic = 3;
	vitality = 3;
	defense = 3;
	speed = 3;

	//Set elemental resistance
	elementMod[Element::Normal] = 0;
	elementMod[Element::Fire] = 0;
	elementMod[Element::Water] = 0;

	//Set health, maxhealth, energy, and maxenergy
	maxHealth = vitality * 5;
	health = maxHealth;

	maxEnergy = 100;
	energy = maxEnergy;

	//set exp value 
	exp = 5;

	//get background texture
	setTexture("Choas.png");

	// Associate the sprite with the texture
	setSprite();
}

void Bob::Attack(Character & target)
{
	int damage = 5;
	target.takeDamage(5, Element::Normal);
}

void Bob::MonsterAction(Character&  blob_)
{
	Attack(blob_);
}

void Bob::AddSkill(Skill * skill)
{
}

size_t Bob::GetSkillSize()
{
	return size_t();
}

void Bob::Run()
{
}

Food Bob::GetFood()
{
	Food food;

	food.creature = "Bob";

	food.amount[0].strength = 2;

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