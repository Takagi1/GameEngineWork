#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Battle.h"

//is the battle continuing?
bool battleStatus = false;

//turn completed?
bool turnComp = false;

//for inputs
sf::Event input;

bool targ1 = false;
bool targ2 = false;
bool targ3 = false;


//thread for combat 
//exit when combat is resolved

Battle::Battle(Guide& party_, Monster& monster_) : partyPtr(party_), monsterPtr(monster_){}

bool Battle::OnCreate(SceneManager * const & _transfer)
{
	//set turn to zero
	turn = 0;

	//set turn size to 2 plus the monsters max actions
	turnSize = 2 + monsterPtr.actions;

	turnComp = false;
	targ1 = true;
	

	//set inital locations 

	partyPtr.location = 3;
	monsterPtr.location = 4;

	//Who goes first 
	if (partyPtr.speed > monsterPtr.speed)
	{
		current_menu = GUIDE;
	}


	//building buffs
	//when characters turn comes buffs should internal 

	//connection to SceneManager
	managerPtr = _transfer;

//Set up the visuals here

	//get background texture
	backgroundTexture.loadFromFile("background.png");

	// Associate the sprite with the texture
	backgroundSprite.setTexture(backgroundTexture);

	//Set up character sprite positions
	sf::IntRect(50, 50, 50, 50);

	partyPtr.setSpritePos(200, 400);
	partyPtr.party[0]->setSpritePos(400, 200);
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
	option1.setString("Move");
	option1.setFont(font);
	option1.setCharacterSize(30);
	option1.setStyle(sf::Text::Bold);
	option1.setFillColor(sf::Color::Red);
	option1.setPosition(300, 500);
	option1.setOutlineColor(sf::Color::Blue);
	option1.setOutlineThickness(5);


	//Set up second option
	option2.setString("Skill");
	option2.setFont(font);
	option2.setCharacterSize(30);
	option2.setStyle(sf::Text::Bold);
	option2.setFillColor(sf::Color::Red);
	option2.setPosition(500, 500);
	option2.setOutlineColor(sf::Color::Blue);

	//Set up skills
	option3.setString("Skills");
	option3.setFont(font);
	option3.setCharacterSize(30);
	option3.setStyle(sf::Text::Bold);
	option3.setFillColor(sf::Color::Red);
	option3.setPosition(700, 500);
	option3.setOutlineColor(sf::Color::Blue);

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
					if (targ1) {
						current_menu = MOVE;
					}
					//select charge
					if (targ2) {
						partyPtr.Charge();
						turnComp = true;
					}
					//select skills
					if (targ3) {
						//skills
					}

				}
				if (input.key.code == sf::Keyboard::Left) {
					if (targ1) {
						targ1 = false;
						targ3 = true;
						option1.setOutlineThickness(0);
						option3.setOutlineThickness(5);
					} 
					
					else if (targ2) {
						targ2 = false;
						targ1 = true;
						option2.setOutlineThickness(0);
						option1.setOutlineThickness(5);
					}

					else if (targ3) {
						targ3 = false;
						targ2 = true;
						option3.setOutlineThickness(0);
						option2.setOutlineThickness(5);
					}
				}

				else if (input.key.code == sf::Keyboard::Right) {
					if (targ1) {
						targ1 = false;
						targ2 = true;
						option1.setOutlineThickness(0);
						option2.setOutlineThickness(5);
					}

					else if (targ2) {
						targ2 = false;
						targ3 = true;
						option2.setOutlineThickness(0);
						option3.setOutlineThickness(5);
					}

					else if (targ3) {
						targ3 = false;
						targ1 = true;
						option3.setOutlineThickness(0);
						option1.setOutlineThickness(5);
					}
				}
			}
			break;
		case MOVE: 
			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X) {
					//move right
					if (targ1 && partyPtr.location != 7) {
						partyPtr.Move(1);
						current_menu = GUIDE;
						turnComp = true;
					}
					//move left
					else if (targ2 && partyPtr.location != 0) {
						partyPtr.Move(-1);
						current_menu = GUIDE;
						turnComp = true;
					}
				}

				if (input.key.code == sf::Keyboard::Left) {
					if (targ1) {
						targ1 = false;
						targ2 = true;

						option1.setOutlineThickness(0);
						option2.setOutlineThickness(5);
					}
					else if (targ2) {
						targ2 = false; 
						targ1 = true;

						option2.setOutlineThickness(0);
						option1.setOutlineThickness(5);
					}
				}
				
				else if (input.key.code == sf::Keyboard::Right) {
					if (targ1) {
						targ1 = false;
						targ2 = true;

						option1.setOutlineThickness(0);
						option2.setOutlineThickness(5);
					}
					else if (targ2) {
						targ2 = false;
						targ1 = true;

						option2.setOutlineThickness(0);
						option1.setOutlineThickness(5);
					}
				}
			}
			break;

		case CHAMPION:
			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X)
				{
					//select attack
					if (targ1) {
						partyPtr.ChampionAttack(monsterPtr);
						turnComp = true;
					}
					//select guard
					else if (targ2) {
						partyPtr.callGuard();
						turnComp = true;
					}
					//select skills
					else if (targ3) {
						//skills
					}
				}
				if (input.key.code == sf::Keyboard::Left) {
					if (targ1) {
						targ1 = false;
						targ3 = true;
						option1.setOutlineThickness(0);
						option3.setOutlineThickness(5);
					}

					else if (targ2) {
						targ2 = false;
						targ1 = true;
						option2.setOutlineThickness(0);
						option1.setOutlineThickness(5);
					}

					else if (targ3) {
						targ3 = false;
						targ2 = true;
						option3.setOutlineThickness(0);
						option2.setOutlineThickness(5);
					}
				}
				else if (input.key.code == sf::Keyboard::Right) {
					if (targ1) {
						targ1 = false;
						targ2 = true;
						option1.setOutlineThickness(0);
						option2.setOutlineThickness(5);
					}

					else if (targ2) {
						targ2 = false;
						targ3 = true;
						option2.setOutlineThickness(0);
						option3.setOutlineThickness(5);
					}

					else if (targ3) {
						targ3 = false;
						targ1 = true;
						option3.setOutlineThickness(0);
						option1.setOutlineThickness(5);
					}
				}
			}
			break;
		
		case MONSTER:

			break;

		default:
			//error here
			break;
			

			if (turnComp) {
				
				//test for battle resolution
				if (monsterPtr.isDead) {
					managerPtr->endBattle();
				}

				//check if all champions are dead

				if (current_menu == GUIDE) {
					current_menu = CHAMPION;
				}

				else if (current_menu == CHAMPION) {
					current_menu == MONSTER;
				}
				
				else if (current_menu == MONSTER && monsterPtr.actionsLeft == 0) {
					current_menu = GUIDE;
				} 
				

				//reset options if they were invalid
				if (option1.getFillColor() == sf::Color::Black) option1.setFillColor(sf::Color::Red);
				if (option2.getFillColor() == sf::Color::Black) option2.setFillColor(sf::Color::Red);

				//reset menu pointers 
				targ1 = true;
				option1.setOutlineThickness(5);
				option2.setOutlineThickness(0);
				option3.setOutlineThickness(0);

				//if all character have gone increase turn and go back to 0
				if (chaSel == turnSize) {
					chaSel = 0;
					monsterPtr.actionsLeft = monsterPtr.actions;
					turn += 1;
				}
				else {
					chaSel += 1;
				}



				turnComp = false;
			}
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
	r_Window.draw(characterName1);
	r_Window.draw(healthDisplay1);

	switch (current_menu) {
	case GUIDE:

		option1.setString("Move");
		option2.setString("Charge");
		
		r_Window.draw(option1);
		r_Window.draw(option2);
		r_Window.draw(option3);
		break;  

	case CHAMPION:

		option1.setString("Attack");
		option2.setString("Guard");

		r_Window.draw(option1);
		r_Window.draw(option2);
		r_Window.draw(option3);
		break;

	case MOVE:

		option1.setString("Left");
		option2.setString("Right");

		if (partyPtr.location == 0) {
			option1.setFillColor(sf::Color::Black);
		}
		if (partyPtr.location == 7) {
			option2.setFillColor(sf::Color::Black);
		}


		r_Window.draw(option1);
		r_Window.draw(option2);
		break;

	case SKILL:

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
//Todo for battle

	//if monster then attack ai should be called here instead
	/*
	if (turnOrder[chaSel]->isMonster){
	//call monster ai here
	}

	for now the test should be for player to select attack and then
	for the game to transition to the target phase where the ui disapears
	and the cursour apears on the furthest to the right (the monster on the
	rightmost side of the screen who isMonster variable is true if attack)

	if player inputs X again then that selects the monster and the attack
	will then run, basic attack in this case, with the monster that was
	targeted as the target variable.

	if battle is not finished then increase the character selector
	if charactor selector is higher then the number of combatents then
	reset it back to 0 and increase the turn by 1.

	this has created a note that at the start of a characters turn
	buffs should be updated accordingly/

	*/