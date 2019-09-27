#pragma once
#include "Bob.h"

class Encounter {
public:
	std::array<Character*, 1> encounter;

	Encounter() {
		encounter[0] = new Bob();
	}

	int getSize() {
		return encounter.size();
	}
private:

};