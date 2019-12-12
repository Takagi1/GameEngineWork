#pragma once
#include "MapCharacter.h"
class Person : public MapCharacter {

public:
	Person();

	virtual Monster* CallMonster() override;
};