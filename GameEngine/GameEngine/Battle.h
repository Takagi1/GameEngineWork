#pragma once
#include "Scene.h"
#include <vector>



class Battle : public Scene
{
public:


	virtual bool OnCreate(Party* const &_party,SceneManager* const &_transfer) override;
	virtual bool Init(Party &_party, Encounter &_encounter, SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Input() override;
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;

	//current turn
	int turn;

	//max size of turnOrder
	std::size_t size;

	//turn order
	std::vector<Character*> turnOrder;
	
	Texture backgroundTexture;
	Sprite backgroundSprite;

	//mabye keep the indivual party and 
	//encounter to streamline check

};