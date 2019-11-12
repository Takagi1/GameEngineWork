#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Battle.h"

//for inputs
sf::Event input;

int optionPointer; //Used to determine what is being pointed at on the first menu, 0 is first, 1 is second, 2 is third(is always skills)

int skillPointer; //Used to indicate what skill your pointing at
int skillOffset; //Used to scroll down the list of skills

size_t number_of_skills;

Battle::Battle(Blob *blob_, Monster& monster_) :  monsterPtr(monster_){
	playerPtr = blob_;
}

bool Battle::OnCreate(SceneManager * const & _transfer)
{
	//Set up variables
	turn = 0;
	optionPointer = 0;
	number_of_skills = 0;
	skillPointer = 0;
	skillOffset = 0;

	//Who goes first 
	if (playerPtr->speed >= monsterPtr.speed)
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

	playerPtr->setSpritePos(200, 400);
	monsterPtr.setSpritePos(600, 200);

	//Set up the menu box
	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);

	//Set font for text
	font.loadFromFile("OpenSans-Light.ttf");

	//Set up guide name display
	characterName1.setString(playerPtr->name);
	characterName1.setFont(font);
	characterName1.setCharacterSize(30);
	characterName1.setStyle(sf::Text::Bold);
	characterName1.setFillColor(sf::Color::Black);
	characterName1.setPosition(200, 400);

	//Set up Guide current health
	healthDisplay1.setString(std::to_string(playerPtr->health) + " / " + std::to_string(playerPtr->maxHealth));
	healthDisplay1.setFont(font);
	healthDisplay1.setCharacterSize(30);
	healthDisplay1.setStyle(sf::Text::Bold);
	healthDisplay1.setFillColor(sf::Color::Black);
	healthDisplay1.setPosition(200, 450);

	//Set up first option
	options[0].setString("Attack");
	options[0].setFont(font);
	options[0].setCharacterSize(30);
	options[0].setStyle(sf::Text::Bold);
	options[0].setFillColor(sf::Color::Red);
	options[0].setPosition(300, 500);
	options[0].setOutlineColor(sf::Color::Blue);
	options[0].setOutlineThickness(5);


	//Set up skills
	options[1].setString("Skill");
	options[1].setFont(font);
	options[1].setCharacterSize(30);
	options[1].setStyle(sf::Text::Bold);
	options[1].setFillColor(sf::Color::Red);
	options[1].setPosition(500, 500);
	options[1].setOutlineColor(sf::Color::Blue);

	//Set up run
	options[2].setString("Run");
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
	skills[0].setPosition(300, 500);
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
					if (optionPointer == 0) {
						playerPtr->Attack(monsterPtr);
					}
					//select skills
					if (optionPointer == 1) {
						current_menu = SKILL;
						number_of_skills = playerPtr->GetSkillSize();
					}
					//select run
					if (optionPointer == 2) {
						//Run option here
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

		case SKILL:

			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X) {

				}
				else if (input.key.code == sf::Keyboard::Backspace) 
				{
					current_menu = BLOB;
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
			monsterPtr.MonsterAction(*playerPtr);
			TurnComplete();
			break;

		default:
			//error here
			break;
		}
	}
}
	
void Battle::Update(float dtAsSeconds, sf::RenderWindow& window, sf::View& view)
{

}


void Battle::SwitchOutline(sf::Text& current, sf::Text& selected)
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


	//reset options if they were invalid
	if (options[0].getFillColor() == sf::Color::Black) options[0].setFillColor(sf::Color::Red);
	if (options[1].getFillColor() == sf::Color::Black) options[1].setFillColor(sf::Color::Red);

	//reset menu pointers 
	optionPointer = 0;
	options[0].setOutlineThickness(5);
	options[1].setOutlineThickness(0);
	options[2].setOutlineThickness(0);
}

void Battle::SkillDisplayChange() {
	for (size_t i = 0; i < 4 || i < number_of_skills; i++)
	{

		skills[i].setString(playerPtr->skills[i + skillOffset]->name);
	}
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
	case BLOB:
		
		r_Window.draw(characterName1);
		r_Window.draw(healthDisplay1);

		r_Window.draw(options[0]);
		r_Window.draw(options[1]);
		r_Window.draw(options[2]);

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

	r_Window.draw(playerPtr->getSprite());
	r_Window.draw(monsterPtr.getSprite());

	//add in test render for attack check.

	//display the menu

	r_Window.display();
}

//Todo for battle

	/*
	1. Create Skill display

	2. Create and test the sprite positioning system.

	*/