#include "pch.h"
#include "Test.h"


Test::Test() {}

bool Test::OnCreate(Party* const &_party, SceneManager* const &_transfer) {
	//is this a map scene?
	isMap = true;

	//get background texture
	m_BackgroundTexture.loadFromFile("`background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	//Set up Pointers

	partyPtr = _party;
	managerPtr = _transfer;

	//test for party interaction
	//partyPtr->party[0]->maxHealth -= 10;
	return true;
}

bool Test::Init(Party * const & _party, Encounter * const & _encounter, SceneManager * const & _transfer)
{
	return false;
}

void Test::OnDestroy()
{
	if (partyPtr) delete partyPtr;// , partyPtr = nullptr;

	if (managerPtr) delete managerPtr;// , managerPtr = nullptr;
}

void Test::Input() {

	// Handle the player moving
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		playerCharacter.moveLeft();
	}
	else
	{
		playerCharacter.stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		playerCharacter.moveRight();
	}
	else
	{
		playerCharacter.stopRight();
	}

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		playerCharacter.moveUp();
	}
	else
	{
		playerCharacter.stopUp();
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		playerCharacter.moveDown();
	}
	else
	{
		playerCharacter.stopDown();
	}
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed.
void Test::Update(float dtAsSeconds) {
	playerCharacter.update(dtAsSeconds);

	//Example of changing scene
	if (playerCharacter.position.y <= 400) {



		//Test call prototype scene change
		//managerPtr->BuildScene(SceneManager::TOWN);

		//Test battle call

		Encounter* encounterPtr = new Encounter();
		
		managerPtr->BuildBattle(encounterPtr);
	}
}

void Test::Draw(sf::RenderWindow& r_Window){
	
	// Rub out the last frame
	r_Window.clear(sf::Color::White);
	// Draw the background
	r_Window.draw(m_BackgroundSprite);

	r_Window.draw(playerCharacter.getSprite());

	// Show everything we have just drawn
	r_Window.display();
}
