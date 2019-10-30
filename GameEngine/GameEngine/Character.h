#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <forward_list>
#include "StatusEffect.h"
#include "Skill.h"

//Forward decleration


class Character
{
private:

	sf::Texture texture;

	sf::Sprite sprite;

public:

//Blob only variables and functions

	int level = 0; //Character current level
	int exp = 0; //Current exp
	int expNext = 10; //Exp to next level

	virtual void AddSkill(Skill* skill) = 0; //Add a skill to the blob

	virtual size_t GetSkillSize() = 0; //Get the number of skill the blob has

	virtual void Run() = 0; //Run from battle

//Attributes

	std::string name = ""; //Name of character

	int strength = 0; //Characters current Strength, used for physical attacks
	int dexterity = 0; //Characters current dexterity, used for accuracy and evasion
	int magic = 0; //Characters current Magic, used for magical attacks
	int vitality = 0; //Characters current vitality, used to determine blobs health
	int defense = 0; //Characters current defense, used to determine damage
	int speed = 0; //Characters current speed, used to determine who goes first in combat

	int health = 0; //Characters current health
	int maxHealth = 0; //Characters max health

	int energy = 100; //Characters current energy
	int maxEnergy = 100; //Characters max Energy

	bool isDead = false; //Is Character dead?

//Turn Start
	void TurnStart(); //Used when turn starts

//Status Effects

	std::forward_list<StatusEffect> conditions; //Status effects on character

	void InflictStatus(StatusEffect effect); //Use to inflict status effect on character

	bool stuck = false; //Will stop the character from moveing

//Setup Skills

	std::vector<Skill*> skills; //Skills character has

//Menu options

	virtual void Attack(Character& target) = 0; //Characters basic attack

	void CallSkill(Character& target, int skill_number); //Use skills if you have any 

//Drawing Functions

	void setTexture(std::string name); //Set character texture

	void setSprite(); //Set character sprite with the current texture

	sf::Sprite getSprite();	//For drawing character

	void setSpritePos(int x, int y); //Set the characters sprite position

//Misc functions

	void takeDamage(double damage);//Used to take damage
};


