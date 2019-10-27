#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Battle.h"

//is the battle continuing?
bool battleStatus = false;

//for inputs
sf::Event input;

int optionPointer; //Used to determine what is being pointed at on the first menu, 0 is first, 1 is second, 2 is third(is always skills)

int skillPointer; //Used to indicate what skill your pointing at
int skillOffset; //Used to scroll down the list of skills

size_t number_of_skills;


Battle::Battle(Guide& party_, Monster& monster_) : partyPtr(party_), monsterPtr(monster_){}

bool Battle::OnCreate(SceneManager * const & _transfer)
{
	//Set up variables

	turn = 0;
	optionPointer = 0;
	number_of_skills = 0;
	skillPointer = 0;
	skillOffset = 0;

	turnSize = 2 + monsterPtr.actions; 	//Set turn size to 2 plus the monsters max actions

	//set inital locations 

	partyPtr.location = 3;
	monsterPtr.location = 4;

	//Who goes first 
	if (partyPtr.speed >= monsterPtr.speed)
	{
		current_menu = GUIDE;
	}
	else {
		current_menu = MONSTER;
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

	partyPtr.setSpritePos(200, 400);
	partyPtr.setChampionSpritePos(400, 200);
	monsterPtr.setSpritePos(600, 200);

	//Set up the menu box
	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);

	//Set font for text
	font.loadFromFile("OpenSans-Light.ttf");

	//Set up guide name display
	characterName1.setString(partyPtr.getChampionName());
	characterName1.setFont(font);
	characterName1.setCharacterSize(30);
	characterName1.setStyle(sf::Text::Bold);
	characterName1.setFillColor(sf::Color::Black);
	characterName1.setPosition(200, 400);

	//Set up Guide current health
	healthDisplay1.setString(std::to_string(partyPtr.getChampionHealth()) + " / " + std::to_string(partyPtr.getChampionMaxHealth()));
	healthDisplay1.setFont(font);
	healthDisplay1.setCharacterSize(30);
	healthDisplay1.setStyle(sf::Text::Bold);
	healthDisplay1.setFillColor(sf::Color::Black);
	healthDisplay1.setPosition(200, 450);

	//Set up first option
	options[0].setString("Move");
	options[0].setFont(font);
	options[0].setCharacterSize(30);
	options[0].setStyle(sf::Text::Bold);
	options[0].setFillColor(sf::Color::Red);
	options[0].setPosition(300, 500);
	options[0].setOutlineColor(sf::Color::Blue);
	options[0].setOutlineThickness(5);


	//Set up second option
	options[1].setString("Skill");
	options[1].setFont(font);
	options[1].setCharacterSize(30);
	options[1].setStyle(sf::Text::Bold);
	options[1].setFillColor(sf::Color::Red);
	options[1].setPosition(500, 500);
	options[1].setOutlineColor(sf::Color::Blue);

	//Set up skills
	options[2].setString("Skills");
	options[2].setFont(font);
	options[2].setCharacterSize(30);
	options[2].setStyle(sf::Text::Bold);
	options[2].setFillColor(sf::Color::Red);
	options[2].setPosition(700, 500);
	options[2].setOutlineColor(sf::Color::Blue);

	//Set up skill display
	skills[0].setFont(font);
	skills[0].setCharacterSize(20);
	skills[0].setStyle(sf::Text::Bold);
	skills[0].setFillColor(sf::Color::Red);
	skills[0].setPosition(300, 750);
	skills[0].setOutlineColor(sf::Color::Blue);

	skills[1].setFont(font);
	skills[1].setCharacterSize(20);
	skills[1].setStyle(sf::Text::Bold);
	skills[1].setFillColor(sf::Color::Red);
	skills[1].setPosition(300, 600);
	skills[1].setOutlineColor(sf::Color::Blue);

	skills[2].setFont(font);
	skills[2].setCharacterSize(20);
	skills[2].setStyle(sf::Text::Bold);
	skills[2].setFillColor(sf::Color::Red);
	skills[2].setPosition(300, 450);
	skills[2].setOutlineColor(sf::Color::Blue);

	skills[3].setFont(font);
	skills[3].setCharacterSize(20);
	skills[3].setStyle(sf::Text::Bold);
	skills[3].setFillColor(sf::Color::Red);
	skills[3].setPosition(300, 300);
	skills[3].setOutlineColor(sf::Color::Blue);

	skills[4].setFont(font);
	skills[4].setCharacterSize(20);
	skills[4].setStyle(sf::Text::Bold);
	skills[4].setFillColor(sf::Color::Red);
	skills[4].setPosition(300, 150);
	skills[4].setOutlineColor(sf::Color::Blue);

	return true;
}

void Battle::OnDestroy()
{
	chaSel = NULL;
}


void Battle::Input(sf::RenderWindow& r_Window)
{
	//this is used for the turn order and for handeling the battle's info

	
	while (r_Window.pollEvent(input)) {
		switch (current_menu)
		{


		//Guide inputs
		case GUIDE:

			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X)
				{
					//select move
					if (optionPointer == 0) {
						previous_menu = GUIDE;
						current_menu = MOVE;
					}
					//select charge
					if (optionPointer == 1) {
						partyPtr.Charge();
						TurnComplete();
					}
					//select skills
					if (optionPointer == 2) {
						previous_menu = GUIDE;
						current_menu = SKILL;
						number_of_skills = partyPtr.GetSkillSize();
					}
				}
				else if (input.key.code == sf::Keyboard::Left) {
					if (optionPointer == 0) {
						optionPointer = 2;
						SwitchOutline(options[0], options[2]);
					} 
					else {
						SwitchOutline(options[optionPointer], options[optionPointer-1]);
						optionPointer -= 1;
					}
				}

				else if (input.key.code == sf::Keyboard::Right) {
					if (optionPointer == 2) {
						optionPointer = 0;
						SwitchOutline(options[2], options[0]);
					}
					else {
						SwitchOutline(options[optionPointer], options[optionPointer + 1]);
						optionPointer += 1;
					}
				}
			}

			break;

		case MOVE: 

			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X) {
					//move right
					if (optionPointer == 0 && partyPtr.location != 7) {
						partyPtr.Move(1);
						current_menu = GUIDE;
						TurnComplete();
					}
					//move left
					else if (optionPointer == 1 && partyPtr.location != 0) {
						partyPtr.Move(-1);
						current_menu = GUIDE;
						TurnComplete();
					}
				}
				else if (input.key.code == sf::Keyboard::Backspace) {
					if (options[0].getFillColor() == sf::Color::Black) options[0].setFillColor(sf::Color::Red);
					if (options[1].getFillColor() == sf::Color::Black) options[1].setFillColor(sf::Color::Red);
					current_menu = previous_menu;
				}
				else if (input.key.code == sf::Keyboard::Left || input.key.code == sf::Keyboard::Right) {
					if (optionPointer == 0) {
						SwitchOutline(options[0], options[1]);
						optionPointer = 1;
					}
					else {
						SwitchOutline(options[1], options[0]);
						optionPointer = 0;
					}
				}
			}
			break;

		case CHAMPION:
			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X)
				{
					//select attack
					if (optionPointer == 0 && partyPtr.GetBasicRange >= LocationCompare()) {
						partyPtr.ChampionAttack(monsterPtr);
						TurnComplete();
					}
					//select guard
					else if (optionPointer == 1) {
						partyPtr.callGuard();
						TurnComplete();
					}
					//select skills
					else if (optionPointer ==  2) {
						previous_menu = CHAMPION;
						current_menu = SKILL;
					}
				}
				else if (input.key.code == sf::Keyboard::Left) {
					if (optionPointer == 0) {
						optionPointer = 2;
						SwitchOutline(options[0], options[2]);
					}
					else {
						SwitchOutline(options[optionPointer], options[optionPointer - 1]);
						optionPointer -= 1;
					}
				}

				else if (input.key.code == sf::Keyboard::Right) {
					if (optionPointer == 2) {
						optionPointer = 0;
						SwitchOutline(options[2], options[0]);
					}
					else {
						SwitchOutline(options[optionPointer], options[optionPointer + 1]);
						optionPointer += 1;
					}
				}
			}
			break;

		case SKILL:

			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X) {

				}
				else if (input.key.code == sf::Keyboard::Backspace) 
				{
					current_menu = previous_menu;
				}
				else if (input.key.code == sf::Keyboard::Left) 
				{
					if (skillPointer != 0) 
					{
						SwitchOutline(skills[skillPointer], skills[skillPointer - 1]);
						skillPointer -= 1;
					}
					else if (skillOffset != 0) 
					{
						skillOffset -= 1;
						SkillDisplayChange();
					}
				}

				else if (input.key.code == sf::Keyboard::Right) 
				{
					if (skillPointer != 4 && skillPointer < number_of_skills) 
					{
						SwitchOutline(skills[skillPointer], skills[skillPointer + 1]);
						skillPointer += 1;
					}
					else if (skillOffset + 4 < number_of_skills) {
						skillOffset += 1;
						SkillDisplayChange();
					}
				}
			}

			break;

		case MONSTER:
			monsterPtr.MonsterAction(partyPtr);
			TurnComplete();
			break;

		default:
			//error here
			break;
		}
	}
}
	
void Battle::Update(const float dtAsSeconds)
{

}

void Battle::Draw(sf::RenderWindow& r_Window)
{
	r_Window.clear(sf::Color::Black);

	// Draw the background
	r_Window.draw(backgroundSprite);


	float setX = r_Window.getSize().x;
	float setY = r_Window.getSize().y;

	menu.setSize(sf::Vector2f(setX, setY/2));
	menu.setPosition(0, setY / 2);

	r_Window.draw(menu);

	switch (current_menu) {
	case GUIDE:

		options[0].setString("Move");
		options[1].setString("Charge");
		
		r_Window.draw(characterName1);
		r_Window.draw(healthDisplay1);

		r_Window.draw(options[0]);
		r_Window.draw(options[1]);
		r_Window.draw(options[2]);

		break;  

	case CHAMPION:

		options[0].setString("Attack");
		options[1].setString("Guard");

		if (partyPtr.GetBasicRange() < LocationCompare()) {
			options[0].setFillColor(sf::Color::Black);
		}

		r_Window.draw(characterName1);
		r_Window.draw(healthDisplay1);

		r_Window.draw(options[0]);
		r_Window.draw(options[1]);
		r_Window.draw(options[2]);

		break;

	case MOVE:

		options[0].setString("Left");
		options[1].setString("Right");

		if (partyPtr.location == 0) {
			options[0].setFillColor(sf::Color::Black);
		}
		if (partyPtr.location == 7) {
			options[1].setFillColor(sf::Color::Black);
		}


		r_Window.draw(options[0]);
		r_Window.draw(options[1]);
		break;

	case SKILL:

		//Should display 5 skills at once 
		


		r_Window.draw(skills[0]);
		r_Window.draw(skills[1]);
		r_Window.draw(skills[2]);
		r_Window.draw(skills[3]);
		r_Window.draw(skills[4]);

		break;

	default:

		//put error here
		break;

	}

	//Render all characters here 

	r_Window.draw(partyPtr.getSprite());
	r_Window.draw(partyPtr.getChampionSprite());
	r_Window.draw(monsterPtr.getSprite());

	//add in test render for attack check.

	//display the menu

	r_Window.display();
}

void Battle::SwitchOutline(Text& current,Text& selected)
{
	current.setOutlineThickness(0);
	selected.setOutlineThickness(5);
}

void Battle::TurnComplete() {
	//test for battle resolution
	if (monsterPtr.isDead) {
		managerPtr->endBattle();
	}

	//check if all champions are dead

	if (current_menu == GUIDE) {
		current_menu = CHAMPION;
	}

	else if (current_menu == CHAMPION) {
		current_menu = MONSTER;
	}

	else if (current_menu == MONSTER && monsterPtr.actionsLeft == 0) {
		current_menu = GUIDE;
	}


	//reset options if they were invalid
	if (options[0].getFillColor() == sf::Color::Black) options[0].setFillColor(sf::Color::Red);
	if (options[1].getFillColor() == sf::Color::Black) options[1].setFillColor(sf::Color::Red);

	//reset menu pointers 
	optionPointer = 0;
	options[0].setOutlineThickness(5);
	options[1].setOutlineThickness(0);
	options[2].setOutlineThickness(0);

	//if all character have gone increase turn and go back to 0
	if (chaSel == turnSize) {
		chaSel = 0;
		monsterPtr.actionsLeft = monsterPtr.actions;
		turn += 1;
	}
	else {
		chaSel += 1;
	}
}

int Battle::LocationCompare()
{
	int diff;
	diff = partyPtr.location - monsterPtr.location;
	if (diff < 0) {
		diff *= -1;
	}
	return diff;
}

void Battle::SkillDisplayChange() {
	if (previous_menu == GUIDE) {
		for (size_t i = 0; i < 4 || i < number_of_skills; i++)
		{
			skills[i].setString(partyPtr.skills[i + skillOffset]->name);
		}
	}

	if (previous_menu == CHAMPION) {
		for (size_t i = 0; i < 4 || i < number_of_skills; i++)
		{
			skills[i].setString(partyPtr.GetSkillName(i + skillPointer));
		}
	}
}

//Todo for battle

	/*
	1. Create Skill display

	2. Create and test the sprite positioning system.

	*/