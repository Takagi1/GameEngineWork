#pragma once
#include <iostream>

class Skill;

class Food {

public:

	std::string creature;

	struct effects {
		int strength = 0;
		int dexterity = 0;
		int magic = 0;
		int defense = 0;
		int speed = 0;

		//Add in elemental resistance

		std::map<Element, int> res;

		bool hasSkill = false;

		Skill* skill = NULL;
	};
	effects amount[3];

};