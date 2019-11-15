#pragma once
#include <string>

//Forward declare

class Character;


//Elemental type
enum class Element
{
	Normal,
	Fire,
	Water
};

class Skill {

public:

	Skill() {

	} //Constructor

	Character* character; //Reference if needed to effect self
	std::string name; //Name of ability
	Element element; //Element of ability

	virtual void Effect(Character& character) = 0;
};