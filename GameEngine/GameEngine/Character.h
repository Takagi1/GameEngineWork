#pragma once
#include <vector>
#include <forward_list>
#include "StatusEffect.h"
#include "Skill.h"
#include "AnimationController.h"

//Forward decleration


class Character
{
private:

	sf::Texture texture;

	sf::Sprite sprite;

public:
	AnimationController animationController;

//Character orientation

//Attributes

	std::string name = ""; //Name of character

	//Offensive Stats

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

//Type resitances
	//create reference that allow you to check how elements effect damage
	std::map<Element, int> elementMod;

//Turn Start
	void TurnStart(); //Used when turn starts

//Status Effects

	std::forward_list<StatusEffect*> conditions; //Status effects on character

	void InflictStatus(StatusEffect* effect); //Use to inflict status effect on character

	bool stuck = false; //Will stop the character from moveing

//Drawing Functions

	void setTexture(std::string name); //Set character texture

	void setSprite(); //Set character sprite with the current texture

	sf::Sprite getSprite();	//For drawing character

	void setSpritePos(int x, int y); //Set the characters sprite position

//Misc functions

	void takeDamage(double damage, Element element_, bool Pierce); //Used to take damage
	
};


