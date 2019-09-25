#pragma once
#include "Barbarian.h"

class Party
{
public:
	Character* party[1];

	Party() {
		party[0] = new Barbarian();
	};
private:

};