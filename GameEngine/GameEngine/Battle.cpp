#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Battle.h"

//for inputs
sf::Event input;

//For keeping track of menu pointers (might be better method of keeping track off it)

int skillPointer; //Used to indicate what skill your pointing at

int skillOffset; //Used to scroll down the list of skills

size_t number_of_skills;

Battle::Battle(Blob *blob_, Monster* monster_) :  monsterPtr(monster_){
	playerPtr = blob_;
}

bool Battle::OnCreate(SceneManager * const & _transfer)
{
	//Set up variables
	turn = 0;
	number_of_skills = 0;
	skillPointer = 0;
	skillOffset = 0;

	//Who goes first 
	if (playerPtr->speed >= monsterPtr->speed)
	{
		current_menu = BLOB;
		first = 0;
	}
	else {
		current_menu = MONSTER;
		first = 1;
	}


	//building buffs
	//when characters turn comes buffs should internal 

	managerPtr = _transfer;	//connection to SceneManager

//Set up the visuals here

	

	//Get background texture
	backgroundTexture.loadFromFile("background.png");

	//Associate the sprite with the texture
	backgroundSprite.setTexture(backgroundTexture);

	//Set up character sprite positions
	sf::IntRect(50, 50, 50, 50); //This is a test 

	playerPtr->setSpritePos(0, -200);
	monsterPtr->setSpritePos(100, -200);

	//Set up the menu box
	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);
	
	//Set font for text
	font.loadFromFile("OpenSans-Light.ttf");

	//Set up guide name display
	playerName.setString(playerPtr->name);
	SetupText(&playerName);
	playerName.setPosition(-600, -300);

	//Set up Guide current health
	playerHealthDisplay.setString(std::to_string(playerPtr->health) + " / " + std::to_string(playerPtr->maxHealth));
	SetupText(&playerHealthDisplay);
	playerHealthDisplay.setPosition(-600, -250);

	playerEnergyDisplay.setString(std::to_string(playerPtr->energy) + " / " + std::to_string(playerPtr->maxEnergy));
	SetupText(&playerEnergyDisplay);
	playerEnergyDisplay.setPosition(-600, -200);

	//Set up monster name display
	monsterName.setString(monsterPtr->name);
	SetupText(&monsterName);
	monsterName.setPosition(500, -300);

	//Set up monster current health
	monsterHealthDisplay.setString(std::to_string(monsterPtr->health) + " / " + std::to_string(monsterPtr->maxHealth));
	SetupText(&monsterHealthDisplay);
	monsterHealthDisplay.setPosition(500, -250);

	//Set up monster current energy
	monsterEnergyDisplay.setString(std::to_string(monsterPtr->energy) + " / " + std::to_string(monsterPtr->maxEnergy));
	SetupText(&monsterEnergyDisplay);
	monsterEnergyDisplay.setPosition(500, -200);

	//Setup disposible textset
	SetupText(&text);

	//Set up first option
	text.setString("Attack");
	text.setPosition(-300, 0);
	text.setOutlineThickness(5);
	optionsMenu.AddText(text,0);

	//Set up skills
	text.setString("Skill");
	text.setPosition(-200, 0);
	text.setOutlineThickness(0);
	optionsMenu.AddText(text,1);
	
	//Set up run
	text.setString("Run");
	text.setPosition(-100, 0);
	text.setOutlineThickness(0);
	optionsMenu.AddText(text,2);

	text.setString("Chomp");
	text.setPosition(-100, 0);
	text.setOutlineThickness(5);
	chompMenu.AddText(text,0);

	text.setString("Kill");
	text.setPosition(100, 0);
	text.setOutlineThickness(0);
	chompMenu.AddText(text,1);

	//TODO change the skill display to a scroll system and figure out what is wrong with chomp selection

	//Set up skill display
	text.setCharacterSize(20);
	if (playerPtr->skills.size() > 0) {
		for (int i = 0; i > playerPtr->skills.size(); i++) {
			skills.AddOptions(playerPtr->skills[i]->name);
		}
	}
	
	text.setPosition(100, 0);
	skills.AddText(text,0);
	
	text.setPosition(300, 600);
	skills.AddText(text,1);

	text.setPosition(300, 450);
	skills.AddText(text,2);

	text.setPosition(300, 300);
	skills.AddText(text,3);

	text.setPosition(300, 150);
	skills.AddText(text,4);

	return true;
}

void Battle::OnDestroy()
{
}


void Battle::Input(sf::RenderWindow& r_Window)
{
	//this is used for the turn order and for handeling the battle's info

	
	while (r_Window.pollEvent(input)) {
		switch (current_menu)
		{

		//Guide inputs
		case BLOB:
			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X)
				{
					//select attack
					if (optionsMenu.menuPtr == 0) {
						playerPtr->Attack(monsterPtr);
						TurnComplete();
					}
					//select skills
					if (optionsMenu.menuPtr == 1) {
						current_menu = SKILL;
						number_of_skills = playerPtr->GetSkillSize();
					}
					//select run
					if (optionsMenu.menuPtr == 2) {
						//Run option here
					}
				}
				else if (input.key.code == sf::Keyboard::Left) {
					optionsMenu.MenuScroll(-1);
				}

				else if (input.key.code == sf::Keyboard::Right) {
					optionsMenu.MenuScroll(1);
				}
			}

			break;

		case SKILL:

			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X) {
					//call skill
					try {
						if (playerPtr->skills.at(skillPointer + skillOffset)->isBuff) {
							playerPtr->CallSkill(playerPtr, skillPointer + skillOffset);
						}
						else {
							playerPtr->CallSkill(monsterPtr, skillPointer + skillOffset);
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
				}
				else if (input.key.code == sf::Keyboard::Backspace) 
				{
					current_menu = BLOB;
				}
				else if (input.key.code == sf::Keyboard::Left) 
				{
					//So you dont scroll to the bottom of the list
					if (skillOffset != 0)
					{
						skillOffset -= 1;
						//add in new scroll system
						//SkillDisplayChange();
					}
					else if (skillPointer != 0) 
					{
						skills.MenuScroll(-1);
						skillPointer -= 1;
					}

				}

				else if (input.key.code == sf::Keyboard::Right) 
				{
					if (skillPointer != 4 && skillPointer < number_of_skills) 
					{
						skills.MenuScroll(1);
						skillPointer += 1;
					}
					else if (skillOffset + 4 < number_of_skills) {
						skillOffset += 1;
						skills.MenuScroll(1);
					}
				}
			}
			break;

		case MONSTER:
			monsterPtr->MonsterAction(playerPtr);
			TurnComplete();
			break;

		case CHOMP:

			if (input.type == sf::Event::KeyPressed) {
				
				if (input.key.code == sf::Keyboard::Left) {
					optionsMenu.MenuScroll(-1);

				}
				
				else if (input.key.code == sf::Keyboard::Right) {
					optionsMenu.MenuScroll(1);
				}

				if (input.key.code == sf::Keyboard::X) {
					if (chompMenu.menuPtr == 0) {
						playerPtr->Chomp(monsterPtr->GetFood());
						managerPtr->endBattle();
					}
					else {
						managerPtr->endBattle();
					}
				}
			}

			break;
		default:
			//error here
			break;
		}
	}
}
	
void Battle::Update(float dtAsSeconds, sf::RenderWindow& window, sf::View& view)
{
	//Reset the camera to 0
	view.setCenter(0, 0);
}


void Battle::SwitchOutline(sf::Text& current, sf::Text& selected)
{
	current.setOutlineThickness(0);
	selected.setOutlineThickness(5);
}

void Battle::TurnComplete() {
	//test for battle resolution
	if (monsterPtr->isDead) {
		current_menu = CHOMP;
	}

	//check if all champions are dead

	if (current_menu == BLOB) {
		current_menu = MONSTER;
		if (first == 1) {
			turn += 1;
		}
	}

	else if (current_menu == MONSTER) {
		current_menu = BLOB;
		if (first == 0) {
			turn += 1;
		}
	}
	//refresh display

	playerHealthDisplay.setString(std::to_string(playerPtr->health) + " / " + std::to_string(playerPtr->maxHealth));
	playerEnergyDisplay.setString(std::to_string(playerPtr->energy) + " / " + std::to_string(playerPtr->maxEnergy));

	monsterHealthDisplay.setString(std::to_string(monsterPtr->health) + " / " + std::to_string(monsterPtr->maxHealth));
	monsterEnergyDisplay.setString(std::to_string(monsterPtr->energy) + " / " + std::to_string(monsterPtr->maxEnergy));


	//reset options if they were invalid
	//if (optionsMenu.options[0].getFillColor() == sf::Color::Black) optionsMenu.options[0].setFillColor(sf::Color::Red);
	//if (optionsMenu.options[1].getFillColor() == sf::Color::Black) optionsMenu.options[1].setFillColor(sf::Color::Red);

	//reset menu pointers 
	optionsMenu.menuPtr = 0;
	optionsMenu.display[0].setOutlineThickness(5);
	optionsMenu.display[1].setOutlineThickness(0);
	optionsMenu.display[2].setOutlineThickness(0);
}

void Battle::Draw(sf::RenderWindow& r_Window)
{
	r_Window.clear(sf::Color::Black);

	// Draw the background
	r_Window.draw(backgroundSprite);


	float setX = r_Window.getSize().x;
	float setY = r_Window.getSize().y;

	menu.setSize(sf::Vector2f(setX - 10, setY / 2));
	menu.setPosition((setX/2)*-1 + 5, -10);
	
	r_Window.draw(menu);

	switch (current_menu) {
	case BLOB:
		
		r_Window.draw(playerName);
		r_Window.draw(playerHealthDisplay);
		r_Window.draw(playerEnergyDisplay);
		r_Window.draw(monsterName);
		r_Window.draw(monsterHealthDisplay);
		r_Window.draw(monsterEnergyDisplay);

		r_Window.draw(optionsMenu.display[0]);
		r_Window.draw(optionsMenu.display[1]);
		r_Window.draw(optionsMenu.display[2]);

		break;  

	case SKILL:

		r_Window.draw(playerName);
		r_Window.draw(playerHealthDisplay);
		r_Window.draw(playerEnergyDisplay);
		r_Window.draw(monsterName);
		r_Window.draw(monsterHealthDisplay);
		r_Window.draw(monsterEnergyDisplay);

		//Should display 5 skills at once 
		try {
			//skills.display.setString(playerPtr->skills.at(0)->name);
		}
		catch (const std::out_of_range& oor) {
			std::cerr << "Out of Range error: " << oor.what() << '\n';
		}

		r_Window.draw(skills.display[0]);
		r_Window.draw(skills.display[1]);
		r_Window.draw(skills.display[2]);
		r_Window.draw(skills.display[3]);
		r_Window.draw(skills.display[4]);

		break;

	case CHOMP:

		r_Window.draw(chompMenu.display[0]);
		r_Window.draw(chompMenu.display[1]);

		break;
	default:

		//put error here
		break;

	}

	//Render all characters here 

	r_Window.draw(playerPtr->getSprite());
	r_Window.draw(monsterPtr->getSprite());

	//add in test render for attack check.

	//display the menu

	r_Window.display();
}

//Todo for battle

	/*
	1. Create Skill display

	2. Create and test the sprite positioning system.

	*/