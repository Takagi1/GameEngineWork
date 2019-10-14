#pragma once
#include "Monster.h"

class Bob : public Monster
{
private:

	sf::Texture characterTexture;
	sf::Sprite characterSprite;

public:

	//Constructor
	Bob();

	//virtual void BasicAction(Character& target) override;

	virtual sf::Sprite getSprite() override;

	virtual void setSpritePos(int x, int y) override;
};
