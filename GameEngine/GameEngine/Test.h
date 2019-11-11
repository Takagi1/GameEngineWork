#pragma once
#ifndef TEST_H
#define TEST_H
#include "Scene.h"

//Forward declarations

class Test : public Scene
{
public:

	explicit Test(Blob& blob_);

	virtual bool OnCreate(SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) override ;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Input(sf::RenderWindow& window) override;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	MapCharacter playerCharacter;

//Pointers for player and scene

	Blob& playerPtr;
	SceneManager* managerPtr;

	Tile map[5][5];

//Menu info

	//Paused menu 
	sf::RectangleShape menu;

	sf::Text stomachMenu;
	sf::Text infoMenu;

	scroll selectMenu;

	MenuDisplay menuDisplay;
};
#endif //TEST_H

