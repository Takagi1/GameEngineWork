#include "pch.h"
#include "Character.h"

void Character::TurnStart()
{
	//Tick down a turn
	for (std::forward_list<StatusEffect*>::iterator itCondition = conditions.begin(); itCondition != conditions.end(); ++itCondition) {
		if (itCondition._Ptr->_Myval->isActive) {
			itCondition._Ptr->_Myval->InflictEffect(this);
		}

		itCondition._Ptr->_Myval->timeLeft -= 1;
		if (itCondition._Ptr->_Myval->timeLeft == 0) {
			itCondition._Ptr->_Myval->RemoveEffect(this);
		}

		//Remove if done 
		conditions.remove(itCondition._Ptr->_Myval);
	}
}

//Use to inflict staus effects to characters
void Character::InflictStatus(StatusEffect* effect)
{
	conditions.push_front(effect);
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

	std::map<Element, int>::iterator its;

	//Get characters elemental resistance
	its = elementMod.find(element_);
	
	//Element resistance modifications

	if (its->second == 2) {
		//Immunity Message?
	}
	else {
		damage -= its->second * 50;	
	}
	
	if (damage <= 0) {
		damage = 1;
	}
	else {
		//get random
		int random = rand() % 51 + 50;

		float randomFloat = random / 100.0f;
		damage = ceil(damage * randomFloat);
	}

	health -= damage;

	//Handles character death
	if (health <= 0) {
		health = 0;
		isDead = true;
	}
}