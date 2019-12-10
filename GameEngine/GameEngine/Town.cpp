#include "pch.h"
#include "Town.h"



Town::Town(Blob* player_) {
	playerPtr = player_;
}

bool Town::OnCreate(SceneManager* const &_transfer) {

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

}

// Move Bob based on the input this frame,
// the time elapsed, and the speed.
void Town::Update(float dtAsSeconds, sf::RenderWindow& r_Window, sf::View& view) {
	mapCharacters[0].update(dtAsSeconds);

	if (mapCharacters[0].position.y <= 400) {
		//Test call prototype scene change
		//currentScene = sceneManager.BuildScene(sceneManager.TEST);
	}
}
