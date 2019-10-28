#include "pch.h"
#include "Town.h"

Town::Town(Blob& player_) : playerPtr(player_) {}


bool Town::OnCreate(SceneManager* const &_transfer) {

	//is this a map scene?
	isMap = true;

	//get background texture
	m_BackgroundTexture.loadFromFile("background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);


	return true;
}

void Town::OnDestroy()
{
	//if (partyPtr) delete partyPtr;//, partyPtr = nullptr;
	if (managerPtr) delete managerPtr;// , managerPtr = nullptr;
}

void Town::Input(sf::RenderWindow& window) {

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
void Town::Update(float dtAsSeconds) {
	playerCharacter.update(dtAsSeconds);

	if (playerCharacter.position.y <= 400) {
		//Test call prototype scene change
		//currentScene = sceneManager.BuildScene(sceneManager.TEST);
	}
}

void Town::Draw(sf::RenderWindow& r_Window) {

	// Rub out the last frame
	r_Window.clear(sf::Color::White);
	// Draw the background
	r_Window.draw(m_BackgroundSprite);

	r_Window.draw(playerCharacter.getSprite());

	// Show everything we have just drawn
	r_Window.display();
}
