#pragma once
#include "Guide.h"
#include "Barbarian.h"

using namespace std;

class Party
{
public:
	array<Character*, 2> party;

	Party() {
		party[1] = new Guide();
		party[0] = new Barbarian();

	};
private:

};