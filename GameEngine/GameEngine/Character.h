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

	//need to make an equation to set isDead to true if health = 0


	//test function for basic character attack
	int BasicAttack(Character* target) {
		int damage = floor(strength * 1.5) + floor(dexterity * 0.5);
		
		return damage;
	}

	//test function for handeling damage
	void Damage(int damage) {
		health -= damage;

		//Handles character death
		if (health <= 0) {
			health = 0;
			isDead = true;
		}
	}

	//for drawing character in battle
	virtual void Draw() = 0;
};