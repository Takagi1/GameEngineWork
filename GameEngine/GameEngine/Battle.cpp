#include "pch.h"
#include <iostream>
#include "Battle.h"

//thread for combat info 
void CombatThread(int id) {
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

	//sf::Event event;
	
		//cout << "hello";
	
	//cout << "hi";

}

bool Battle::OnCreate(Party * const & _party, SceneManager * const & _transfer)
{
	return true;
}

bool Battle::Init(Party &_party, Encounter &_encounter, SceneManager * const & _transfer)
{
	//create a thread for battle? this is theory for now
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
	backgroundTexture.loadFromFile("`background.png");

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

	party = _party;
	encounter = _encounter;
	return true;
}

void Battle::OnDestroy()
{
}


void Battle::Input()
{
	
	if (Keyboard::isKeyPressed(Keyboard::X))
	{
		//put placeholder attack test here
		
		//create theoretical target system.  example of attack is bellow
		
		//action

		int damage = turnOrder[0]->BasicAttack(turnOrder[1]);
		
		//target resolution for damage
		turnOrder[1]->Damage(damage);
		
		//cout << turnOrder[1]->health;
	}
}

void Battle::Update(const float dtAsSeconds)
{

	//test for battle resolution
	if (turnOrder[1]->isDead) {
	}
}

void Battle::Draw(sf::RenderWindow& r_Window)
{
	r_Window.clear();


	//Render all characters here 
	//add in test render for attack check.

	//determine how rendering is going to work.  along with the
	//find form of the visuals for a scene, so that when artist
	//starts, he/she will be able to work


	//display the menu

	r_Window.display();
}

