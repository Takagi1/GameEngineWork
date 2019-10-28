#include "pch.h"
#include "Bob.h"
#include "Blob.h"

Bob::Bob()
{
	//Set attributes 

	strength = 1;

	defense = 1;

	//calculate max health
	maxHealth = 28;

	//set health to max
	health = maxHealth;

	speed = 1;

	//set exp value 
	exp = 5;

	//get background texture
	setTexture("Choas.png");

	// Associate the sprite with the texture
	setSprite();
}

void Bob::Attack(Character & target)
{
}

void Bob::MonsterAction(Character & blob_)
{
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