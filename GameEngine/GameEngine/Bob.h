#pragma once
#include "Monster.h"

//Forward delcarations

class Bob : public Monster
{
private: 
	virtual void AddSkill(Skill* skill) override; //Add a skill to the blob
	virtual size_t GetSkillSize() override; //Get the number of skill the blob has
	virtual void Run() override; //Run from battle
public:

	//Constructor
	Bob();

	virtual void Attack(Character* target) override;

	virtual void MonsterAction(Character* blob_) override;  //Basic ai

	virtual Food* GetFood() override;
};
