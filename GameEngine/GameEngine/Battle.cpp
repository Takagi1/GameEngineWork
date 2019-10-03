#include "pch.h"
#include <iostream>
//#include <event>
#include "Battle.h"

//is the battle continuing?
bool battleStatus = false;

//turn completed?
bool turnComp = false;

//for inputs
sf::Event input;

bool targ1 = true;
bool targ2 = false;

//thread for combat 
//exit when combat is resolved


bool Battle::OnCreate(Party * const & _party, SceneManager * const & _transfer)
{
	return true;
}

bool Battle::Init(Party &_party, Encounter &_encounter, SceneManager * const & _transfer)
{


	//set turn to zero
	turn = 0;

		
	//could you set up the game to start at 0 and then run every time a 
	//line is completed.  it runs up skiping if character is dead. 
	//and increasing turn if the number is going to be higher then the max
	//amount of characters.

	//set turn order here

	size = _party.getSize() + _encounter.getSize();
	turnOrder.resize(size);
	turnOrder[0] = _party.party[0];
	turnOrder[1] = _encounter.encounter[0];

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

	partyPtr = _party;
	encounterPtr = _encounter;
	managerPtr = _transfer;

	//Set up the visuals here

	encounterPtr.encounter[0]->setSpritPos(600, 200);

	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setOutlineThickness(5);

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
		if (input.type == sf::Event::KeyPressed) {
			if (input.key.code == sf::Keyboard::X)
			{
				//there needs to be somthing here that allows for 
				//the selection of targets
				if (targ1) {
					int damage = turnOrder[chaSel]->BasicAttack(turnOrder[1]);
					//cout << damage << endl;
					//target resolution for damage
					turnOrder[1]->Damage(damage);
					turnComp = true;
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
		}
		
	}

	if (turnComp) {

		//test for battle resolution
		if (encounterPtr.encounter[0]->isDead) {
			turnOrder.clear();
			managerPtr->endBattle();
		}

		//next character
		chaSel += 1;

		//if all character have gone increase turn and go back to 0
		if (chaSel > 5) {

		}

		turnComp = false;
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

	rectangle.setSize(sf::Vector2f(setX, setY/2));
	rectangle.setPosition(0, setY / 2);

	r_Window.draw(rectangle);

	// Declare and load a font
	sf::Font font;
	font.loadFromFile("OpenSans-Light.ttf");


	// Create a text
	sf::Text text("Attack", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	text.setPosition(200, 500);

	if (targ1) {
		text.setOutlineThickness(5);
		text.setOutlineColor(sf::Color::Blue);
	}
	else {
		text.setOutlineThickness(0);
	}

	// Draw it
	r_Window.draw(text);

	// Create a text
	sf::Text text2("Skill", font);
	text2.setCharacterSize(30);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::Red);
	text2.setPosition(500, 500);
	if (targ2) {
		text2.setOutlineThickness(5);
		text2.setOutlineColor(sf::Color::Blue);
	}
	else {
		text2.setOutlineThickness(0);
	}

	// Draw it
	r_Window.draw(text2);

	r_Window.draw(turnOrder[1]->getSprite());
	//Render all characters here 
	//add in test render for attack check.

	//display the menu

	r_Window.display();
}

//This is a experiment to see if multithreading battle may be the 
	//best idea.

	//combat calucalations could be held in this thread?

	//turn should start here
	//if monster then attack ai should be called here instead
	/*
	if (turnOrder[chaSel]->isMonster){
	//call monster ai here
	}

	if character is a champion then the menu should apear
	//make battle ui appear
	then allow for inputs to select between attack and skill.
	the cursor should start at attack

	for now the test should be for player to select attack and then
	for the game to transition to the target phase where the ui disapears
	and the cursour apears on the furthest to the right (the monster on the
	rightmost side of the screen who isMonster variable is true if attack)

	if player inputs X again then that selects the monster and the attack
	will then run, basic attack in this case, with the monster that was
	targeted as the target variable.

	damage will then run through and then resoultion should occur

	if battle is not finished then increase the character selector
	if charactor selector is higher then the number of combatents then
	reset it back to 0 and increase the turn by 1.

	this has created a note that at the start of a characters turn
	buffs should be updated accordingly/

	//for going to the next character/turn.

	chaSel++ unless
	if (chaSel > size){
	chaSel = 0;
	turn += 1;
	}

	*/

	//cout << "hi";