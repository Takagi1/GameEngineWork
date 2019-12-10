#pragma once
#include <string>

//Forward declare

class Character;


//Elemental type
enum class Element
{
	Physical,
	Fire,
	Ice,
	Poison
};

class Skill {

public:

	std::string name; //Name of ability
	Element element; //Element of ability
	bool pierce; //Ignore defense?

	bool isBuff = false; //Does the skill target yourself?

	//Use caster to get there stats
	virtual void Effect(Character* target, Character* caster) = 0;
};