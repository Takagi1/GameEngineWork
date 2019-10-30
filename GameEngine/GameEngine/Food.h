#pragma once
#include <iostream>

class Skill;

class Food {

public:

	Food();

	std::string creature;
	int number; //Used to determine what stage of food this is

	int strength;
	int dexterity;

	bool hasSkill;
	
	Skill* skill;

};