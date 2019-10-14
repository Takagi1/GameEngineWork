#pragma once
#ifndef TEST_H
#define TEST_H

#include "Scene.h"

class Test : public Scene
{
public:

	explicit Test(Guide& party_);

	virtual bool OnCreate(SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Update(const float dtAsSeconds) override ;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Input(sf::RenderWindow& window) override;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool isMap;

	MapCharacter playerCharacter;

	//Pointers

	Guide& partyPtr;
	SceneManager* managerPtr;

	//Battle* battle;
};
#endif //TEST_H

