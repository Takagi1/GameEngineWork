#pragma once
#include "SFML/Graphics.hpp"
#include <array>

class Monster
{
private:

public:
	//Constructer
	Monster() {};

	//Character name
	std::string name = "";

	int health = 100;

	int maxHealth = 100;

	int resource = 100;

	int maxResource = 100;

	int power = 0;

	int defense = 0;

	int speed = 0;

	int exp = 0;

	//number of actions the monster gets
	int actions = 1;

	//number of actions the monster has left
	int actionsLeft = actions;

	//current location min 0, max 7
	int location = 0;

	bool isDead = false;

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

	//for drawing character in battle
	virtual sf::Sprite getSprite() = 0;

	virtual void setSpritePos(int x, int y) = 0;
};