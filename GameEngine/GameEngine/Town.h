#pragma once
#ifndef TOWN_H
#define TOWN_H
#include "Scene.h"

class Town : public Scene
{
public:

	explicit Town();

	virtual bool OnCreate(Party* const &_party, SceneManager* const &_transfer) override;
	virtual bool Init(Party &_party, Encounter &_encounter, SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Input(sf::RenderWindow& window) override;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool isMap;

	MapCharacter playerCharacter;

	//Pointers

	Party* partyPtr;
	SceneManager* managerPtr;
};
#endif //!TEST_H
