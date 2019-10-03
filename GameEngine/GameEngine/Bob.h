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

	//References

	int& maxHealth = Character::maxHealth;

	int& health = Character::health;

	int& strength = Character::strength;
	int& dexterity = Character::dexterity;
	int& vitality = Character::vitality;
	int& inteligence = Character::inteligence;
	int& wisdom = Character::wisdom;
	int& defense = Character::defense;
	int& speed = Character::speed;

	int& exp = Monster::exp;

	bool& mons = Character::isMonster;

	virtual int BasicAttack(Character* target) override;

	virtual sf::Sprite getSprite() override;

	int GetExp() override;

	virtual void setSpritePos(int x, int y) override;
};
