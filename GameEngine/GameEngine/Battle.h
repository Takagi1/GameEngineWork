#pragma once
#include "Scene.h"
#include <vector>

class Battle : public Scene
{
public:


	virtual bool OnCreate(Party* const &_party,SceneManager* const &_transfer) override;
	virtual bool Init(Party &_party, Encounter &_encounter, SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Input(sf::RenderWindow& window) override;
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;

	//current turn
	int turn;

	//max size of turnOrder
	std::size_t size;

	//turn order
	std::vector<Character*> turnOrder;

	//what character's turn is it.
	int chaSel = 0;
	
	Texture backgroundTexture;
	Sprite backgroundSprite;

	//For drawing the menu and characters

	sf::RectangleShape rectangle;


	//mabye keep the indivual party and 
	//encounter to streamline check

	Party partyPtr;
	Encounter encounterPtr;
	SceneManager* managerPtr;

};