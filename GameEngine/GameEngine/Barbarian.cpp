#include "pch.h"
#include "Monster.h"



Barbarian::Barbarian() {

	name = "Barbarian";

	power = 5;

	defense = 5;
	 
	maxHealth = 100;
	health = maxHealth;



	AddSkill("ORA");
}

void Barbarian::turnStart(int turn)
{
}

void Barbarian::BasicAction(Monster& monster) {
	int damage = power * 2;
	monster.takeDamage(damage);
}

void Barbarian::Guard()
{
	guard1 = true;
}

void Barbarian::CallSkill(Monster & monster, int skill_number)
{
	skills[skill_number]->Effect(monster);
}

sf::Sprite Barbarian::getSprite() {
	return sprite;
}

void Barbarian::setSpritePos(int x, int y) {
	sprite.setPosition(x, y);
}

class ORA : public Barbarian::Skill {
public:
	ORA(Guide * guide_, Champion * champion_) {
		guide = guide_;
		champion = champion_;
		range = 1;
		isRanged = true;
		name = "ORA";
	};

	virtual void Effect(Monster& monster) {
		guide->party[guide->currentChampion]->health += 10;

		//if health is greater then max reduce to max
		if (guide->party[guide->currentChampion]->health > guide->party[guide->currentChampion]->maxHealth) {
			guide->party[guide->currentChampion]->health = guide->party[guide->currentChampion]->maxHealth;
		}
	}
};

//Always put new skills above this line

void Barbarian::AddSkill(std::string skill_name)
{
	int check = 0;
	bool doesHave = false;
	for (std::vector<Champion::Skill*>::iterator it = skills.begin(); it != skills.end(); ++it) {
		if (skills[check]->name == skill_name) doesHave = true;
	}

	if (!doesHave)
	{
		if (skill_name == "ORA") {
			skills.push_back(new ORA(guideRef, this));
		}
	}
	else {
		
		//error. character already has skill_name
		//put error here
	}

}

