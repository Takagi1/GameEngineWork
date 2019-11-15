#include "pch.h"
#include "Character.h"

void Character::TurnStart()
{
	for (std::forward_list<StatusEffect>::iterator itCondition = conditions.begin(); itCondition != conditions.end(); ++itCondition) {
		itCondition->StatusTick();
		//conditions.remove_if(itCondition->timeLeft == 0);
	}
}

void Character::InflictStatus(StatusEffect effect)
{
	conditions.push_front(effect);
}

void Character::CallSkill(Character& target, int skill_number)
{
	skills[skill_number]->Effect(target);
}

void Character::setTexture(std::string name)
{
	if (!texture.loadFromFile(name)) {
		//put error here 
	}
}

void Character::setSprite()
{
	sprite.setTexture(texture);
}

sf::Sprite Character::getSprite()
{
	return sprite;
}

void Character::setSpritePos(int x, int y) {
	sprite.setPosition(x, y);
}

void Character::takeDamage(double damage, Element element_)
{
	damage = damage - defense;

	if (damage <= 0) {
		damage = 0;
	}

	std::map<Element, int>::iterator its;
	
	//get random
	int random = rand() % 51 + 50;

	float randomFloat = random / 100.0f;

	//Get characters elemental resistance
	its = elementMod.find(element_);

//Element resistance modifications

	if (its->second == 2) {
		//Immunity Message?
	}
	else {
		randomFloat -= its->second * 50;
		if (randomFloat <= 0) {
			health -= 1;
		}
		else {
			health -= ceil(damage * randomFloat);
		}
	}

	//Handles character death
	if (health <= 0) {
		health = 0;
		isDead = true;
	}
}