#pragma once
#ifndef TOWN_H
#define TOWN_H
#include "Map.h"

class Town : public Map
{
public:

	explicit Town(Blob* player_);

	virtual bool OnCreate(SceneManager* const &_transfer, sf::RenderWindow& r_Window, int X, int Y) override;
	virtual void OnDestroy() override;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) override;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	//Pointers

	SceneManager* managerPtr;
};
#endif //!TEST_H
