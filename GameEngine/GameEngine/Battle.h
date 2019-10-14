#pragma once
#include "Scene.h"
#include <vector>

class Battle : public Scene
{

public:
	explicit Battle(Guide& party_, Monster& monster_);
	enum CURRENT_MENU {
		GUIDE = 0,
		CHAMPION,
		MONSTER,
		MOVE,
		SKILL
	};


	virtual bool OnCreate(SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Input(sf::RenderWindow& window) override;
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;
  
	//current turn
	int turn;

	int turnSize;

	//what character's turn is it.
	int chaSel = 0;
	
	Texture backgroundTexture;
	Sprite backgroundSprite;

	//For drawing the menu and characters
	CURRENT_MENU current_menu;


	// Declare and load a font
	sf::Font font;

	//Text

	sf::Text characterName0;
	sf::Text healthDisplay0;

	sf::Text characterName1;
	sf::Text healthDisplay1;

	sf::Text option1;
	sf::Text option2;
	sf::Text option3;
	sf::RectangleShape menu;


	//mabye keep the indivual party and 
	//encounter to streamline check

	Guide& partyPtr;
	Monster& monsterPtr;
	SceneManager* managerPtr;

private: 
	//who can be targeted
	std::vector<int> Targetable;
};