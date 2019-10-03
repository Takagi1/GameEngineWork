#pragma once
#include <array>
#include <math.h>

//Point of existance: this is the base for all living things in the game.  they must all inherit from them.
//include <array> here for party, encounter, and skills.
class Character
{
private:

public:
	//Constructer
	Character() {
	};

	//Characters max health
	int maxHealth = 0;

	//Character current health
	int health = 0;

	//Attributes

	int strength = 1;
	int dexterity = 1;
	int vitality = 1;
	int inteligence = 1;
	int wisdom = 1;
	int defense = 0;
	int speed = 0;

	//is unit dead
	bool isDead = false;

	//is this unit a monster(set to true if monster)
	bool isMonster = false;

	//need to make an equation to set isDead to true if health = 0


	//test function for basic character attack
	virtual int BasicAttack(Character* target) = 0;

	//test function for handeling damage
	void Damage(int damage) {
		
		damage -= defense;
		if (damage <= 0) {
			damage = 0;
		}
		//get random
		float random = rand() % 51 + 50;
		random = random / 100.0f;

		//multipling int by float is unsafe

		health -= ceil((damage - defense)  * random);
		

		

		//Handles character death
		if (health <= 0) {
			health = 0;
			isDead = true;
		}
	}

	//for drawing character in battle
	virtual void Draw() = 0;
};