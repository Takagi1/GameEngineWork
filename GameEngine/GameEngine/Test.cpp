#include "pch.h"
#include "Test.h"
#include "Debug.h"
#include "Blob.h"
#include "Bob.h"

Monster* encounterPtr;

bool isPaused = false;
sf::Event inp;

Test::Test(Blob& player_) : playerPtr(player_){}

bool Test::OnCreate(SceneManager* const &_transfer) {

	//For setting up tiles
	//create tiles based on size of screen
	//then set up there locations and what part of the sprite sheet the tile shows.
	//mabye in update create a loop of the tiles to display all the tiles
	//set in collsion detection in update
	//


	//get background texture
	m_BackgroundTexture.loadFromFile("background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	//Size of tile here (25,25)?
	//set up rectangle display on the sprite list
	//

	
	//Set up Pointers

	managerPtr = _transfer;

	//set up where the player starts

	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);


	return true;
}

void Test::OnDestroy()
{
	//if (partyPtr) delete partyPtr;// , partyPtr = nullptr;

	if (managerPtr) delete managerPtr;// , managerPtr = nullptr;
}

void Test::Input(sf::RenderWindow& r_Window) {

	while (r_Window.pollEvent(inp)) {
		//Paused inputs 
		if (isPaused) {
			//Status menu

			//Stomach menu

			//Info menu
		}

		// handle things when not paused
		if (!isPaused) {

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
		if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::B) {
			//Test call prototype scene change
		//managerPtr->BuildScene(SceneManager::TOWN);

			//create a new encounterPtr every time this is called


			//delete previous encounter
			delete(encounterPtr);
			//create new one
			encounterPtr = new Bob();
			//Debug::Error("Encounter health not reseting properly", __FILE__, __LINE__);


			managerPtr->BuildBattle(*encounterPtr);
		}

		//Time should pause here
		if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::P) {

			if (!isPaused) isPaused = true;
			else isPaused = false;
		}
	}
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed.
void Test::Update(float dtAsSeconds, sf::RenderWindow& r_Window, sf::View& view) {
	playerCharacter.update(dtAsSeconds);

	// Set center of the camera to the player
	view.setCenter(playerCharacter.position.x, playerCharacter.position.y);

	/*//Example of changing scene
	if (playerCharacter.position.y <= 400) {

		//Test call prototype scene change
		//managerPtr->BuildScene(SceneManager::TOWN);

		//Test battle call
		Encounter encounterPtr;

		managerPtr->BuildBattle(encounterPtr);
	}
	*/
}

void Test::Draw(sf::RenderWindow& r_Window){
	
	// Rub out the last frame
	r_Window.clear(sf::Color::White);

	// Draw the background
	r_Window.draw(m_BackgroundSprite);

	r_Window.draw(playerCharacter.getSprite());


	//should draw over all things on screen
	if (isPaused) {
		float setX = r_Window.getSize().x;
		float setY = r_Window.getSize().y;

		menu.setSize(sf::Vector2f(setX, setY / 2));
		menu.setPosition(30, setY / 2);
		//draw paused menu here

		r_Window.draw(menu);
	}

	// Show everything we have just drawn
	r_Window.display();
}
