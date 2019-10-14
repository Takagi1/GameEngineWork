#pragma once
#include "SFML/Graphics.hpp"
#include <array>


class Champion
{
	
private:

public:

	//Constructer
	Champion() {};

	//Champions current level
	int level = 0;

	//current exp
	int exp = 0;

	//Character name
	std::string name = "";

	//Characters max health
	int maxHealth = 0;

	//Character current health
	int health = 0;

	//resource for champion
	int resource = 0;

	int maxResource = 0;

	//The strength of abilites 
	int power = 0;

	//Reduces damage
	int defense = 0;

	//increases turn order
	int speed = 0;

	//is unit dead
	bool isDead = false;

	bool guard1 = false;

	//reference for guide and monster
	class Guide* guideRef;

	//for resolving changes on turn start
	virtual void turnStart(int turn) = 0; //use a vector array?? or somthing.  idea is effect, turnLeft when turnLeft reverse effect ie +5 becomes -5 and
										  //true becomes falses... mabye a struct could work with this. look into it.

	 virtual void setGuide(class Guide* guideRef_) {
		 guideRef = guideRef_;
	 };

	virtual void BasicAction(class Monster& monster) = 0;

	virtual void Guard() = 0;

	//for drawing character in battle
	virtual sf::Sprite getSprite() = 0;

	virtual void setSpritePos(int x, int y) = 0;

	void takeDamage(int damage) {
		damage = damage - defense;
		if (damage <= 0) {
			damage = 0;
		}
		//get random
		int random = rand() % 51 + 50;

		if (guard1) random -= 10;
		
		float randomFloat = random / 100.0f;

		health -= ceil((damage - defense)  * randomFloat);

		//Handles character death
		if (health <= 0) {
			health = 0;
			isDead = true;

		}
	}
};