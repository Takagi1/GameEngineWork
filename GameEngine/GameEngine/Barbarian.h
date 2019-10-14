#pragma once
#include "Champion.h"


class Barbarian : public Champion
{
private:
	sf::Texture characterTexture;
	sf::Sprite characterSprite;
public:

	//Constructor
	Barbarian();

	virtual void turnStart(int turn) override;

	virtual void BasicAction(class Monster& monster) override;

	virtual void Guard() override;

	//for drawing character
	virtual sf::Sprite getSprite() override;
	
	virtual void setSpritePos(int x, int y) override;
};

