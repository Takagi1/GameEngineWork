#pragma once
#include "Bob.h"

class Encounter {
public:
	Monster* encounter[1];

	Encounter() {
		encounter[0] = new Bob();
	}

};