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

	std::string name; //Name of ability
	Element element; //Element of ability

	bool isBuff = false; //Does the skill target yourself?

	virtual void Effect(Character* character) = 0;
};