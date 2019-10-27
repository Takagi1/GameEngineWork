#pragma once
#include "SFML/Graphics.hpp"
#include <array>
#include <forward_list>
#include "StatusEffect.h"

//Forward delcarations

class Guide;

class Monster
{
private:

public:
	//Constructer
	Monster() {};

//Atributes

	std::string name = ""; //Character name

	int health = 100;

	int maxHealth = 100;

	int resource = 100;

	int maxResource = 100;

	int power = 0;

	int defense = 0;

	int speed = 0;

	int exp = 0;

	int actions = 1; //number of actions the monster gets

	int actionsLeft = actions; //number of actions the monster has left

	int location = 0; //current location min 0, max 7

	bool isDead = false;


//Monster ai and actions

	virtual void MonsterAction(Guide& guide) = 0; // Call the monsters behaviour

	virtual void BasicAction(Guide& guide) = 0; // Basic attack

	virtual void Move(int direction) = 0; // Move the monster

//Abstract skill for Monsters

	class Skill {

	public:
		Guide* guide;
		int range;
		bool isRanged;
		int cooldown;
		std::string name;

		virtual void Effect(Guide& guide_) = 0;
	};

	std::vector<Skill*> skills; //Champions skills


//Misc

	virtual int GetExp() {
		return exp;
	};

	void takeDamage(int damage) {
		damage = damage - defense;
		if (damage <= 0) {
			damage = 0;
		}
		//get random
		int random = rand() % 51 + 50;


		float randomFloat  = random / 100.0f;

		//multipling int by float is unsafe

		health -= ceil((damage - defense)  * randomFloat);

		//Handles character death
		if (health <= 0) {
			health = 0;
			isDead = true;

		}
	}

//Drawing fucntions

	virtual sf::Sprite getSprite() = 0;

	virtual void setSpritePos(int x, int y) = 0;
};