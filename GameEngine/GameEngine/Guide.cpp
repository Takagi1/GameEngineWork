#include "pch.h"
#include "Guide.h"
#include "Barbarian.h"
#include "Monster.h"
#include "StatusEffect.h"



Guide::Guide() {
	party[0] = new Barbarian();

	name = "Guide";

	speed = 10;

	AddSkill("Heal");
}

void Guide::TurnStart()
{
	for (itCondition = conditions.begin(); itCondition != conditions.end(); ++itCondition) {
		itCondition->StatusTick();
		conditions.remove_if(itCondition->timeLeft == 0);
	}
}

void Guide::InflictStatus(StatusEffect effect)
{
	conditions.push_front(effect);
}

void Guide::Move(int direction) {
	//increase or decrease location
	location += direction;
}

void Guide::Charge()
{
	energy += 10;
	if (energy > maxEnergy) {
		energy = maxEnergy;
	}
}

void Guide::CallSkill(Monster & monster, int skill_number)
{
	skills[skill_number]->Effect(monster);
}

void Guide::ChampionAttack(Monster & monster)
{
	party[currentChampion]->BasicAction(monster);
}

void Guide::callGuard()
{
	party[currentChampion]->Guard();
}

void Guide::ChampionSkills(Monster & monster, int skill_number)
{
	party[currentChampion]->CallSkill(monster, skill_number);
}

sf::Sprite Guide::getSprite() 
{ 
	return characterSprite; 
}

sf::Sprite Guide::getChampionSprite()
{
	return party[currentChampion]->getSprite();
}

void Guide::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}

void Guide::setChampionSpritePos(int x, int y)
{
	party[currentChampion]->setSpritePos(x, y);
}

std::string Guide::getChampionName()
{
	return party[currentChampion]->name;
}

int Guide::getChampionHealth()
{
	return party[currentChampion]->health;
}

int Guide::getChampionMaxHealth()
{
	return party[currentChampion]->maxHealth;
}

int Guide::GetBasicRange()
{
	return party[currentChampion]->basicRange;
}

int Guide::GetSkillRange(int skill_number) {
	return party[currentChampion]->skills[skill_number]->range;
}

std::string Guide::GetSkillName(int skill_number)
{
	return party[currentChampion]->skills[skill_number]->name;
}

void Guide::takeDamage(int damage)
{
	party[currentChampion]->takeDamage(damage);
}

class Heal : public Guide::Skill {
public:
	Heal(Guide * guide_) {
		guide = guide_;
		range = 0;
		ranged = false;
		name = "Heal";
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


void Guide::AddSkill(std::string skill_name) {
	int check = 0;
	bool doesHave = false;
	for (std::vector<Skill*>::iterator its = skills.begin(); its != skills.end(); ++its){
		
		if (skills[check]->name == skill_name) doesHave = true;
	}
		
	if (!doesHave)
	{
		if (skill_name == "Heal") {
			skills.push_back(new Heal(this));
		}
	}
	else {
		//error. character already has skill_name
		//put error here
	}
	
}

size_t Guide::GetSkillSize()
{
	return skills.size();
}

