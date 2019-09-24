#pragma once

//Point of existance: this is the base for all living things in the game.  they must all inherit from them.
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
};