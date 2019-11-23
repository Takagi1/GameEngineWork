#pragma once
#include <vector>
#include <forward_list>
#include "Character.h"

//Forward decleration

class Monster;
class Skill;
class Food;

class Blob : public Character
{
public:

	//Used to keep track of what you have
	struct count {
		std::string creature_name = "";
		int number_of_creatures = 0;
		int vector_location_1 = 0;
		int vector_location_2 = 0;
		int vector_location_3 = 0;
	};

	//used to store information about chomping
	struct infoStorage {
		int strength = 0;
		int dexterity = 0;
		int magic = 0;

		std::string skill_name = "No skill";
	};

	//used to store what is in the stomach
	struct guts {
		//image here
		std::string name = ""; //name of creature
	};


	Blob(); //Constructor

//Containers

	std::forward_list<std::pair<std::pair<std::string, int> , infoStorage > > info; //first set is the creatures name, the pair is how many and the infoStorage is what you get at that amount

	//stomach should contain the sprite of the creature and its name.  the stomach menu will output the sprites image and its name
	std::vector<guts> stomach; //Is used to determine what is in blobs stomach

	std::forward_list<count> stomachCount; //Used to determine how many copys of a creature do you have in your stomach

	std::forward_list<std::pair<std::string, int>> skill_names; //list of skills that blob has, use with add skill to make change skill during level

//Fuctions



	void Chomp(Food* food);

	void Digest(std::string creature); //Give the creature name to remove

	virtual void AddSkill(Skill* skill) override; //Add a skill to the blob

	void RemoveSkill(std::string name_); //Remove skill from blob

	virtual size_t GetSkillSize() override; //Get the number of skill the blob has

	virtual void Attack(Character* target) override; //Characters basic attack

	virtual void Run() override; //Run from battle
};


