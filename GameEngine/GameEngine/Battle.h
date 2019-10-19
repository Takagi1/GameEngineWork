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
 
	void SwitchOutline(Text& current, Text& selected);

	void TurnComplete();
	
	int turn; //Current turn

	int turnSize; //Max turn size

	int chaSel = 0;	//what character's turn is it.
	
	Texture backgroundTexture;
	Sprite backgroundSprite;

	CURRENT_MENU current_menu; //For determining what input should be used and what should be drawn

	CURRENT_MENU previous_menu; //What menu was previous to this (should be set to null at turn comp)


//Visual Components

	sf::Font font; // Declare and load a font

	sf::Text characterName0;
	sf::Text healthDisplay0;

	sf::Text characterName1;
	sf::Text healthDisplay1;

	std::array<sf::Text, 3> options; //For displaying main battle menu options
	std::array<sf::Text, 5> skills; //For displaying skills

	

	sf::RectangleShape menu;


	//The party, monster, and sceneManager

	Guide& partyPtr;
	Monster& monsterPtr;
	SceneManager* managerPtr;

private: 
	//who can be targeted
	std::vector<int> Targetable;
};