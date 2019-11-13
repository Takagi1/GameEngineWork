#pragma once
#include "Scene.h"

class Map : public Scene {
public:
	virtual bool OnCreate(SceneManager* const &_transfer) = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view)  = 0;
	virtual void Draw(sf::RenderWindow& r_Window) override;
	virtual void Input(sf::RenderWindow& window) = 0;

	bool isPaused = false;
	MapCharacter playerCharacter;

//Maps background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

//Menu info

	//Paused menu 
	sf::RectangleShape menu;

	scroll selectMenu;

	MenuDisplay menuDisplay;
};