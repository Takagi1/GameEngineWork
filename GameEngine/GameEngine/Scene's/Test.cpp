#include "\Github\GameEngineWork\GameEngine\GameEngine\pch.h"
#include "Test.h"

Test::Test() {}

bool Test::OnCreate() {


	//is this a map scene?
	isMap = true;

	//get background texture
	m_BackgroundTexture.loadFromFile("`background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	return true;
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

	if (playerCharacter.position.y <= 400) {
		//Test call prototype scene change
		trans = SceneManager::TOWN;
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

SceneManager::SCENE_NUMBER Test::ScreenT() {

	return trans;
}