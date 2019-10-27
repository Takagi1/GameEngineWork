#pragma once
#include "Monster.h"

//Forward delcarations

class Guide;

class Bob : public Monster
{
private:

	sf::Texture characterTexture;
	sf::Sprite characterSprite;

public:

	//Constructor
	Bob();


	virtual void MonsterAction(Guide& guide_) override;
	virtual void BasicAction(Guide& guide_) override;  //Basic attack
	virtual void Move(int direction) override;

	class Skill : public Monster::Skill {

	public:
		virtual void Effect(Guide& guide_) = 0;
	};


	virtual sf::Sprite getSprite() override;

	virtual void setSpritePos(int x, int y) override;
};
