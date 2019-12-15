#pragma once
#include "Scene.h"

class Map : public Scene {
public:
	virtual bool OnCreate(SceneManager* const &_transfer, sf::RenderWindow& r_Window, int X, int Y) = 0;
	virtual void OnDestroy() = 0;


	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;
	virtual void Input(sf::RenderWindow& window) override;

	//Pointers for player and scene
	SceneManager* managerPtr;
	Monster* encounterPtr;


	bool isPaused = false;

	bool toast = false;
	std::forward_list<std::string> sentance;

	//Local Monsters
	std::vector<MapCharacter*> mapCharacters;

//Maps background
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	std::vector<Tile> map;

	int mapLength;
	int mapWidth;

//Menu info

	//Paused menu 
	sf::RectangleShape menu;

	scroll selectMenu;

	MenuDisplay menuDisplay;

	std::vector<std::string> CreateInfoDisplay(); //Might be a terrible way of orginizing the info

};