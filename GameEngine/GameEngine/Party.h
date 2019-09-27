#pragma once
#include "Barbarian.h"
using namespace std;

class Party
{
public:
	array<Character*, 1> party;

	Party() {
		party[0] = new Barbarian();
	};

	int getSize() {
		return party.size();
	}
private:

};