#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <forward_list>
#include "Character.h"

//Forward decleration

class Monster;
class Skill;

class Blob : public Character
{
public:

	Blob(); //Constructor

	virtual void AddSkill(Skill* skill) override; //Add a skill to the blob

	virtual size_t GetSkillSize() override; //Get the number of skill the blob has

	virtual void Attack(Character& target) override; //Characters basic attack

	virtual void Run() override; //Run from battle
};


