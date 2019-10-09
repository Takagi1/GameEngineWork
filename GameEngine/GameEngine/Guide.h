#pragma once
#include "Champion.h"


class Guide: public Champion
{
private:
	sf::Texture characterTexture;
	sf::Sprite characterSprite;

public:

	//Constructor
	Guide();

	//References

	//name
	//std::string& name = Character::name;

	//max health
	int& maxHealth = Character::maxHealth;

	//current health
	int& health = Character::health;

	int& strength = Character::strength;
	int& dexterity = Character::dexterity;
	int& vitality = Character::vitality;
	int& inteligence = Character::inteligence;
	int& wisdom = Character::wisdom;
	int& defense = Character::defense;
	int& speed = Character::speed;

	int& rage = Champion::resource;

	virtual int BasicAttack(Character* target) override;

	//for drawing character
	virtual sf::Sprite getSprite() override;

	virtual void setSpritePos(int x, int y) override;
};

