#pragma once
#include "Character.h"

class Monster : public Character
{
private:

public:
	//Constructer
	Monster() {};

	int Health = 5;

	int exp = 5;

	virtual int GetExp() = 0;

};