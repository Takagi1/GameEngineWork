#include "pch.h"
#include "Battle.h"


bool Battle::OnCreate(Party * const & _party, SceneManager * const & _transfer)
{
	return true;
}

bool Battle::Init(Party * const & _party, Encounter * const & _encounter, SceneManager * const & _transfer)
{
	//set turn to zero

	turn = 0;


	//combine the party and the encounter into one character array
	//they should be ordered by the speed equation.
	//after all go then turn should increase by 1

	//building buffs
	//when characters turn comes buffs should internal 

	//theory code for battle
	/*
	//set turnOrder length to current battle amount (single so 2 + encounter)
	Character turnOrder;


	this is a example of an attack 
	the variable for the attack is the target

	partyPtr->party[0]->BasicAttack(Character* target);
	

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

	damage calcuation?
	 monsterPtr->Damage(round down((partyPtr->party[0]->BasicAttack(Character* target)
				  - monsterPtr here[0]->defense) * (random number to 50 
				  + 50)/100));


	*/

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

		//note for work.  create a party version of monster "encounter"
		//this will have monsters bob, then create a damage function
		//how this will be impleminted i dont know but the attack 
		//should return the damage to this equation(i think this may be the 
		//best version of this but it can be changed.

		
	}
}

void Battle::Update(const float dtAsSeconds)
{
}

void Battle::Draw(sf::RenderWindow& r_Window)
{
	r_Window.clear();


	//Render all characters here 

	r_Window.display();
}

