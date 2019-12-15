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

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;
};
#endif //!TEST_H
