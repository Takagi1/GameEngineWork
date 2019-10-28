#pragma once
#include <string>

//Forward declare

class Character;

class Skill {

public:

	Skill() {

	} //Constructor

	Character* character; //Reference if needed to effect self
	std::string name; //Name of ability

	virtual void Effect(Character& character) = 0;
};