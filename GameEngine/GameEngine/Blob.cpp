#include "pch.h"
#include "Blob.h"
#include "Food.h"

Blob::Blob() {
	stomach.resize(3); //Set inital stomach size

	name = "Blob";

//Setup attributes
	strength = 10;
	dexterity = 10;
	magic = 10;
	vitality = 10;
	defense = 10;
	speed = 10;

//Set health, maxhealth, energy, and maxenergy

	maxHealth = vitality * 5;
	health = maxHealth;

	maxEnergy = 100;
	energy = maxEnergy;
	
	setTexture("Robo.png");

	setSprite();
}

void Blob::Attack(Character & target)
{
	//Put attack here
	target.takeDamage(10, Element::Normal);
}

void Blob::Run()
{
	//Run from battle comand
}

//When you eat two of the same creature how do you get back down to one when removing one
//mabye a check to see what you have in your stomach 
//what connects the two togheter?  

//you could have a list of pictures that would be the creatueres

void Blob::Chomp(Food* food)
{
	guts placeholder; //for adding in info for the stomach
	placeholder.name = food->creature; //put name here
	//put picture here

	bool doesExist = false; //Does this creature already exist?
	int infoSearch = 0; //How many creatures are in the stomach now?

	for (std::forward_list<count>::iterator its = stomachCount.begin(); its != stomachCount.end(); ++its) {
		if (its->creature_name == food->creature) {
			doesExist = true;
			stomach.push_back(placeholder);
			if (its->number_of_creatures == 1) {
				//add stats from food one

				strength += food->amount[1].strength;
				if (food->amount[1].hasSkill) {
					AddSkill(food->amount[1].skill);
				}

				infoSearch = 2;
				its->number_of_creatures = 2;
				its->vector_location_2 = stomach.size();
			}
			else if (its->number_of_creatures == 2) {
				//add stats from food one

				strength += food->amount[2].strength;
				if (food->amount[2].hasSkill) {
					AddSkill(food->amount[2].skill);
				}
				
				infoSearch = 3;
				its->number_of_creatures = 3;
				its->vector_location_3 = stomach.size();
			}
			else if (its->number_of_creatures == 3) {
				//you cannot grow anymore from this creature
			}
			break;
		}
	}
	if (!doesExist) {
		stomach.push_back(placeholder);

		//add stats from food one

		strength += food->amount[0].strength;
		if (food->amount[0].hasSkill) {
			AddSkill(food->amount[0].skill);
		}

		infoSearch = 1;

		//create note for reference
		count note;
		note.creature_name = food->creature;
		note.number_of_creatures = 1;
		note.vector_location_1 = stomach.size();
		stomachCount.push_front(note);
	}

	//For adding to info
	for (std::forward_list<std::pair<std::pair<std::string, int>, infoStorage > >::iterator its = info.begin(); its != info.end(); ++its) {
		//have you eaten this creature before?

		/* do you have the info store?*/
		if (its->first != std::make_pair(food->creature, infoSearch)) {
			infoStorage store;
			store.strength = food->amount[infoSearch - 1].strength;
			info.push_front(std::make_pair(std::make_pair(food->creature, infoSearch), store));
		}
	}
}

//Use info to remove the effects of the creature from blob
void Blob::Digest(std::string creature_)
{
	for (std::forward_list<count>::iterator its = stomachCount.begin(); its != stomachCount.end(); ++its) {
		if (its->creature_name == creature_) {

			for (std::forward_list<std::pair<std::pair<std::string, int>, infoStorage > >::iterator infoSet = info.begin(); infoSet != info.end(); infoSet++) {
				if (infoSet->first == std::make_pair(creature_, its->number_of_creatures)) {
					strength -= infoSet->second.strength;

					if (infoSet->second.skill_name != "No skill") {
						RemoveSkill(infoSet->second.skill_name);
					}
					break;
				}
			}
			break;
		}
	}
}

void Blob::AddSkill(Skill* skill) {

	//indicate 
	bool doesHave = false;

	//iterate through the skill_name list to see what skills are givin to blob from his stomach
	//if skill is there do not add, just add name to list.  during removel if skill name is in list more then once then remove one 
	//copy of the name and do not remove the skill.  this can solve the issue of skill addition and removel.  

	for (int check = 0; check > skills.size(); check++) {
		if (skills[check]->name == skill->name) doesHave = true;
	}
	if (!doesHave)
	{
		skills.push_back(skill);
		skill_names.emplace_front(skill->name, 1);
	}
	else {
		for (std::forward_list<std::pair<std::string, int>>::iterator its = skill_names.begin(); its != skill_names.end(); ++its) {
			
			if (its->first == skill->name) {
				its->second += 1;
				break;
			}
		}
	}
}

void Blob::RemoveSkill(std::string name_) {
	for (std::forward_list<std::pair<std::string, int>>::iterator its = skill_names.begin(); its != skill_names.end(); ++its) {

		//If only one found remove skill else just remove 1 copy from list, also add in error if skill is givin that is not found
		if (its->first == name_) {
			if (its->second > 1) {
				its->second -= 1;
			}
			else if (its->second == 1) {
				for (int check = 0; check > skills.size(); check++) {
					if (skills[check]->name == name_) {
						//remove skill
						skills.erase(skills.begin() + check);
					}
				}
				skill_names.remove(its._Ptr->_Myval);
				break;
			}
			else {
				//add in error, skill not in list
			}
		}
	}
}

size_t Blob::GetSkillSize()
{
	return skills.size();
}
