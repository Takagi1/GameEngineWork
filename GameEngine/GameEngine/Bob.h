#pragma once
#include "Monster.h"

//Forward delcarations

class Bob : public Monster
{
public:

	//Constructor
	Bob();

	virtual void MonsterAction(Character* blob_) override;  //Basic ai

	virtual Food* GetFood() override;
};
