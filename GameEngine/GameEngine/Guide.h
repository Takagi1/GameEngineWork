#pragma once
#include "SFML/Graphics.hpp"
#include <array>
#include <vector>
#include <forward_list>
#include "StatusEffect.h"

//Forward decleration

class Champion;
class Monster;

class Guide
{
private:

	sf::Texture characterTexture;

	sf::Sprite characterSprite;

public:

	Guide(); //Constructor

//Variables

	std::array<Champion*, 4> party; //Current battle champions in party

	int currentChampion = 0; //Which champion is out

	int level = 0; //Champions current level

	int exp = 0; //Current exp

	std::string name = ""; //Character name

	int energy = 100; //Current energy

	int maxEnergy = 100; //Maximum Energy

	int speed = 0; //Used to determine who goes first

	int location = 0; //Current location. min 0, max 7.

//Turn Start
	void TurnStart();

//Status Effects

	std::forward_list<StatusEffect> conditions;

	void InflictStatus(StatusEffect effect); //Use to inflict status effect on character

	bool stuck = false; //Will stop the character from moveing

//Setup Skill for guide

	class Skill {

	public:

		Guide * guide;
		int range; //How far can it go?
		bool ranged; //True if used on monster
		std::string name;

		virtual void Effect(Monster& monster) = 0;
	};

	std::vector<Skill*> skills; //Guide skills

	void AddSkill(std::string skill_name); //Add a skill to the guide

	size_t GetSkillSize(); //Get the number of skill the guide has

//Guide options

	void Move(int direction); //Move
	
	void Charge(); //Charge
	
	void CallSkill(Monster& monster, int skill_number); //Skill

//Champion Options 

	void ChampionAttack(Monster& monster); //Champions basic action

	void callGuard(); //Champion guard
	
	void ChampionSkills(Monster& monster, int skill_number); //Champion skills

//Drawing Functions

	sf::Sprite getSprite();	//For drawing character

	sf::Sprite getChampionSprite();	//For drawing champions

	void setSpritePos(int x, int y); //Set the characters sprite position

	void setChampionSpritePos(int x, int y); //Set the champions sprite position

//Get variable/functions from champion

	std::string getChampionName(); //Get current champions name

	int getChampionHealth(); //Get current champions health

	int getChampionMaxHealth(); //Get current champions maxHealth

	int GetBasicRange(); //Get current cahmpions basic action range

	int GetSkillRange(int skill_number); //Get current champions skill range

	std::string GetSkillName(int skill_number); //Get current champions skill names

	void takeDamage(int damage); //Call the damage function on the current champion


};


