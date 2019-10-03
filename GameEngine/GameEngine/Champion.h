#pragma once
#include "Character.h"

class Champion : public Character
{
private:

public:
	//Constructer
	Champion() {};

	//Champions current level
	int level = 0;

	//current exp
	int exp;

	//current position for distance calc
	//change to enum as there is set distance
	int distance = 0;

	//resource for champion
	int resource = 0;
};