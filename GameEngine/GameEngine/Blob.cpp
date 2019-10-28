#include "pch.h"
#include "Blob.h"


Blob::Blob() {
	stomach.resize(3); //Set inital stomach size

	name = "Blob";

	speed = 10;

	
	setTexture("Robo.png");

	setSprite();
}

void Blob::Attack(Character & target)
{
	//Put attack here
}

void Blob::Run()
{
	//Run from battle comand
}

//Always put new skills above this line


void Blob::AddSkill(Skill* skill) {
	int check = 0;
	bool doesHave = false;
	for (std::vector<Skill*>::iterator its = skills.begin(); its != skills.end(); ++its){
		
		if (skills[check]->name == skill->name) doesHave = true;
	}
		
	if (!doesHave)
	{
		if (skill->name == "Fire1") {
			skills.push_back(skill);
		}
	}
	else {
		//error. character already has skill_name
		//put error here
	}
	
}

size_t Blob::GetSkillSize()
{
	return skills.size();
}




