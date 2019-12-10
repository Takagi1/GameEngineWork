#pragma once
#include "MapCharacter.h"

class BlobSprite : public MapCharacter {
public:
	BlobSprite();

	virtual Monster* CallMonster() override;
};