#pragma once
#include "Monster.h"

//Forward delcarations

class Bob : public Monster
{
public:

	//Constructor
	Bob();


	virtual void Attack(Character& target) override;
	virtual void MonsterAction(Character& blob_) override;  //Basic ai

	virtual void AddSkill(Skill* skill) override; //Add a skill to the blob

	virtual size_t GetSkillSize() override; //Get the number of skill the blob has

	virtual void Run() override; //Run from battle

	virtual Food GetFood1() override;

	virtual Food GetFood2() override;

	virtual Food GetFood3() override;

};
