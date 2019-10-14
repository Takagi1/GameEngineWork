#pragma once
#include "Champion.h"

class Guide
{
private:
	sf::Texture characterTexture;
	sf::Sprite characterSprite;

public:
	//Constructor
	Guide();

	//References
	std::array<Champion*, 4> party;

	//create draw of current 

	int currentChampion = 0;

	//Champions current level
	int level = 0;

	//current exp
	int exp = 0;

	//Character name
	std::string name = "";

	int resource = 100;

	int maxResource = 100;

	int speed = 0;

	//current location min 0, max 7 
	int location = 0;

//Guide options

	//Move
	void Move(int direction);

	//Charge
	void Charge();

	//Guide skills

//Champion options 

	//Champions basic action
	void ChampionAttack(class Monster& monster);

	//Guard
	void callGuard() {
		party[currentChampion]->Guard();
	}

	//Champion skills

	//for drawing character
	sf::Sprite getSprite();

	void setSpritePos(int x, int y);

	//get current champions name
	std::string getChampionName() {
		return party[currentChampion]->name;
	}

	//get current champions health
	int getChampionHealth() {
		return party[currentChampion]->health;
	}

	//get current champions maxHealth
	int getChampionMaxHealth() {
		return party[currentChampion]->maxHealth;
	}

	//make current champions take damage
	void takeDamage(int damage) {
		party[currentChampion]->takeDamage(damage);
	};

	//for drawing champions
	sf::Sprite getChampionSprite();

};

