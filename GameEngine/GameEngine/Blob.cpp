#include "pch.h"
#include "Blob.h"
#include "Food.h"


Blob::Blob() {
	stomach.resize(3); //Set inital stomach size

	name = "Blob";

	speed = 10;

	setTexture("Robo.png");

	setSprite();
}

void Blob::Attack(Character & target)
{
	//Put attack here
}

void Blob::Run()
{
	//Run from battle comand
}

//When you eat two of the same creature how do you get back down to one when removing one
//mabye a check to see what you have in your stomach 
//what connects the two togheter?  

//you could have a list of pictures that would be the creatueres
//

void Blob::Chomp(Food* food)
{
	if (food->number == 1) {
		stomach.push_back(food);
		count note;
		note.creature_name = food->creature;
		note.number_of_creatures = 1;
		note.vector_location_1 = stomach.size();
		stomachCount.push_front(note);
	}
	else {
		for (std::forward_list<count>::iterator its = stomachCount.begin(); its != stomachCount.end(); ++its) {
			if (its->creature_name == food->creature) {
				stomach.push_back(food);
				if (food->number == 2) {
					its->number_of_creatures = 2;
					its->vector_location_2 = stomach.size();
				}
				else if (food->number == 3) {
					its->number_of_creatures = 3;
					its->vector_location_3 = stomach.size();
				}
				break;
			}
		}
	}
	strength += food->strength;

	//add skill if true
	if (food->hasSkill) {
		AddSkill(food->skill);
	}
}

void Blob::Digest(std::string creature)
{
	//put in removel of count at the end

	int slot;
	for (std::forward_list<count>::iterator its = stomachCount.begin(); its != stomachCount.end(); ++its) {
		if (its->creature_name == creature) {
			if (its->number_of_creatures == 1) {
				slot = its->vector_location_1;
				//remove count here
				break;
			}
			else if (its->number_of_creatures == 2) {
				its->number_of_creatures = 1;
				slot = its->vector_location_2;
				its->vector_location_2 = 0;
				break;
			}
			else if (its->number_of_creatures == 3) {
				its->number_of_creatures = 2;
				slot = its->vector_location_3;
				its->vector_location_3 = 0;
				break;
			}
		}
	}
	strength -= stomach[slot]->strength;

	//remove skill if stomach has it
	if (stomach[slot]->hasSkill) {
		RemoveSkill(stomach[slot]->skill);
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

void Blob::RemoveSkill(Skill* skill) {
	for (std::forward_list<std::pair<std::string, int>>::iterator its = skill_names.begin(); its != skill_names.end(); ++its) {

		//If only one found remove skill else just remove 1 copy from list, also add in error if skill is givin that is not found
		if (its->first == skill->name) {
			if (its->second > 1) {
				its->second -= 1;
			}
			else if (its->second == 1) {
				for (int check = 0; check > skills.size(); check++) {
					if (skills[check]->name == skill->name) {
						//remove skill
						skills.erase(skills.begin() + (check - 1));
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
