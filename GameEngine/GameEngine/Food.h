#pragma once
#include <iostream>

class Skill;

class Food {

public:

	std::string creature;

	struct effects {
		int strength;
		int dexterity;

		bool hasSkill;

		Skill* skill;
	};
	effects amount[3];

};