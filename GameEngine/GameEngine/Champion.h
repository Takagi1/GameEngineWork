#pragma once
#include "SFML/Graphics.hpp"
#include <array>
#include <vector>

//Forward declerations
class Monster;

class Champion
{
	
private:

public:

	Champion() {}; //Constructor

//Variables

	int level = 0; //Champions current level

	int exp = 0; //Current exp

	std::string name = ""; //Character name

	int maxHealth = 0; 	//Characters max health

	int health = 0;  //Character current health

	int resource = 0; //Resource for champion

	int maxResource = 0; //Maximum resource for champion
 
	int power = 0;	//The strength of abilites

	int defense = 0;  //Reduces damage

	int speed = 0; //Increases turn order

	int basicRange = 0; //Range of basic action

	class Guide* guideRef; //Reference for guide

//Flags for status effects

	//could make these into somthing that is created from the TurnStart funtion stored in a vector array to change size and move add/remove effects as wanted.
	bool isDead = false; //Is unit dead

	bool guard1 = false; //Guard level 1.  Provides 10% decrease in damage 

	bool guard2 = false; //Guard level 2.  Provides 20% decrease in damage

//Abstract skill for Champions
	class Skill {

	public:
		Guide* guide;
		Champion* champion;
		int range;
		bool isRanged;
		std::string name;

		virtual void Effect(Monster& monster) = 0;
	};

	std::vector<Skill*> skills; //Champions skills

	virtual void AddSkill(std::string skill_name) = 0; //Add a skill to the guide

	virtual void turnStart(int turn) = 0; //for resolving changes on turn start
	//use a vector array?? or somthing.  idea is effect, turnLeft when turnLeft reverse effect ie +5 becomes -5 and
    //true becomes falses... mabye a struct could work with this. look into it.

	 virtual void setGuide(class Guide* guideRef_) {
		 guideRef = guideRef_;
	 };

//Champion options

	virtual void BasicAction(Monster& monster) = 0;

	virtual void Guard() = 0;

	virtual void CallSkill(Monster& monster, int skill_number) = 0;

//Drawing Functions

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


