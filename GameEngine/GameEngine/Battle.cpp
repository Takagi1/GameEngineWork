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

bool targ1 = true;
bool targ2 = false;

//who is being targeted
int target = 0;



//thread for combat 
//exit when combat is resolved

Battle::Battle(const Party& party_) : partyPtr(party_){}

bool Battle::OnCreate(SceneManager * const & _transfer)
{
	return true;
}

bool Battle::Init(Encounter &_encounter, SceneManager * const & _transfer)
{

	//set turn to zero
	turn = 0;

	menu_ = MAIN;
	//could you set up the game to start at 0 and then run every time a 
	//line is completed.  it runs up skiping if character is dead. 
	//and increasing turn if the number is going to be higher then the max
	//amount of characters.

	//size should be 3 always (guide, champ, mons)
	//size = partyPtr.getSize() + _encounter.getSize();

	turnOrder.resize(3);

	//set turn order here

	turnOrder[0] = partyPtr.party[0];
	turnOrder[1] = partyPtr.party[1];
	turnOrder[2] = _encounter.encounter[0];

	//get background texture
	backgroundTexture.loadFromFile("background.png");

	// Associate the sprite with the texture
	backgroundSprite.setTexture(backgroundTexture);

	//they should be ordered by the speed equation.
	//after all go then turn should increase by 1

	//building buffs
	//when characters turn comes buffs should internal 

	//theory code for battle
	/*

	attack/turn logic

	1. attack is called with a specified target/s
	2. damage resoultion (what do you do if its not an attack? ex. heal or buff) 
	3. resolve effects (apply damage, if health hits 0 set isDead to true
	4. move to next in array set for turn list, if at end increase turn 
	and go back to the top.  ie. set var to 0 and turn to ++
	5. skip turn if target isDead is true.  
	6. if all enemies isDead = true then resolve battle and apply exp
	7. if Guide isDead = true then game over. this should be check every
	change or should be dynamic because game should end at its death

	*/

	encounterPtr = _encounter;
	managerPtr = _transfer;

	//Set up the visuals here

	//Set up character sprite positions
	sf::IntRect(50, 50, 50, 50);
	partyPtr.party[0]->setSpritePos(400, 200);
	encounterPtr.encounter[0]->setSpritePos(600, 200);

	//Set up the menu box
	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);

	//Set font for text
	font.loadFromFile("OpenSans-Light.ttf");

	//Set up guide name display
	characterName1.setString(partyPtr.party[1]->name);
	characterName1.setFont(font);
	characterName1.setCharacterSize(30);
	characterName1.setStyle(sf::Text::Bold);
	characterName1.setFillColor(sf::Color::Black);
	characterName1.setPosition(200, 400);

	//Set up Guide current health
	healthDisplay1.setString(std::to_string(partyPtr.party[1]->health) + " / " + std::to_string(partyPtr.party[1]->maxHealth));
	healthDisplay1.setFont(font);
	healthDisplay1.setCharacterSize(30);
	healthDisplay1.setStyle(sf::Text::Bold);
	healthDisplay1.setFillColor(sf::Color::Black);
	healthDisplay1.setPosition(200, 450);

	//Set up attack menu option
	attack.setString("Attack");
	attack.setFont(font);
	attack.setCharacterSize(30);
	attack.setStyle(sf::Text::Bold);
	attack.setFillColor(sf::Color::Red);
	attack.setPosition(500, 500);


	//Set up skill menu option
	skill.setString("Skill");
	skill.setFont(font);
	skill.setCharacterSize(30);
	skill.setStyle(sf::Text::Bold);
	skill.setFillColor(sf::Color::Red);
	skill.setPosition(800, 500);

	targSel1.setString("badguy");
	targSel1.setFont(font);
	targSel1.setCharacterSize(30);
	targSel1.setStyle(sf::Text::Bold);
	targSel1.setFillColor(sf::Color::Red);
	targSel1.setPosition(500, 500);


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
		switch (menu_)
		{
		case MAIN:
			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X)
				{
					
					if (targ1) {
						//set up target type
						for_each(turnOrder.begin(), turnOrder.end(), [](Character* chara) {

						});
						menu_ = TARGET;
					}
				}
				if (input.key.code == sf::Keyboard::Left || input.key.code == sf::Keyboard::Right) {
					if (targ1) {
						targ1 = false;
						targ2 = true;
					}
					else {
						targ1 = true;
						targ2 = false;
					}
				}

				break;
			}
		case TARGET:

			if (input.type == sf::Event::KeyPressed) {
				if (input.key.code == sf::Keyboard::X) {
					
					int damage = turnOrder[chaSel]->BasicAttack(turnOrder[target]);
					//cout << damage << endl;
					//target resolution for damage
					turnOrder[target]->Damage(damage);
					turnComp = true;
				}
				if (input.key.code == sf::Keyboard::D) {

				}
			}

			break;

		default:
			//error here
			break;
		}

		if (turnComp) {

			//test for battle resolution
			if (encounterPtr.encounter[0]->isDead) {
				turnOrder.clear();
				managerPtr->endBattle();
			}

			//if all character have gone increase turn and go back to 0
			if (chaSel == 2) {
				chaSel = 0;
				turn += 1;
			}
			else {
				chaSel += 1;
			}

			turnComp = false;
		}
	}
}
	
void Battle::Update(const float dtAsSeconds)
{

}

void Battle::Draw(sf::RenderWindow& r_Window)
{
	r_Window.clear();

	// Draw the background
	r_Window.draw(backgroundSprite);


	float setX = r_Window.getSize().x;
	float setY = r_Window.getSize().y;

	menu.setSize(sf::Vector2f(setX, setY/2));
	menu.setPosition(0, setY / 2);

	r_Window.draw(menu);
	r_Window.draw(characterName1);
	r_Window.draw(healthDisplay1);

	switch (menu_) {

	case MAIN:



		if (targ1) {
			attack.setOutlineThickness(5);
			attack.setOutlineColor(sf::Color::Blue);
		}
		else {
			attack.setOutlineThickness(0);
		}

		// Draw it
		r_Window.draw(attack);

		if (targ2) {
			skill.setOutlineThickness(5);
			skill.setOutlineColor(sf::Color::Blue);
		}
		else {
			skill.setOutlineThickness(0);
		}
		// Draw it
		r_Window.draw(skill);
		break;

	case TARGET:

		r_Window.draw(targSel1);


		break;

	case SKILL:

		break;

	default:
		//put error here
		break;

	}

	//Render all characters here 

	r_Window.draw(turnOrder[0]->getSprite());
	r_Window.draw(turnOrder[1]->getSprite());
	r_Window.draw(turnOrder[2]->getSprite());

	//add in test render for attack check.

	//display the menu

	r_Window.display();
}

void Battle::TargetSetup(Character* current) {
	
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