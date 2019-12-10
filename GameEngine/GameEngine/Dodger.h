#pragma once
#include "Monster.h"

//Forward delcarations

class Dodger : public Monster
{
public:

	//Constructor
	Dodger();

	virtual void MonsterAction(Character* blob_) override;  //Basic ai

	virtual Food* GetFood() override;
};