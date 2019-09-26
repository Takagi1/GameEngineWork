#pragma once
#include "Scene.h"



class Battle : public Scene
{
public:


	virtual bool OnCreate(Party* const &_party,SceneManager* const &_transfer) override;
	virtual bool Init(Party* const &_party, Encounter* const &_encounter, SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Input() override;
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;

	//current turn
	int turn;

	//turn order
	Character* turnOrder;

};