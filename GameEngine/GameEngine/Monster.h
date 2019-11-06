#pragma once
#include "Character.h"

class Food;

class Monster : public Character
{
public:
	virtual void MonsterAction(Character& blob_) = 0;  //Basic ai

	virtual Food GetFood() = 0;
};