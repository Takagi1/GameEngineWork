#pragma once
#include "MapCharacter.h"
class DodgerSprite : public MapCharacter {

public:
	DodgerSprite();

	virtual Monster* CallMonster() override;
};