#pragma once
#include "Champion.h"

class Ranger : public Champion
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:

	Ranger(); //Constructor

	virtual void turnStart(int turn) override;

	//Barbarian Options

	virtual void BasicAction(class Monster& monster) override;

	virtual void Guard() override;

	virtual void CallSkill(Monster& monster, int skill_number) override;

	//Drawing Functions

	virtual sf::Sprite getSprite() override; //Get sprite

	virtual void setSpritePos(int x, int y) override; //Set sprite position

//Skills

	class Skill : public Champion::Skill {

	public:
		virtual void Effect(Monster& monster) = 0;
	};

	virtual void AddSkill(std::string skill_name) override; //Add a skill to the barbarian
};