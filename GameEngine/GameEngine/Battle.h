#pragma once
#include "Scene.h"
#include <array>


class Battle : public Scene
{

public:
	explicit Battle(Blob& blob_, Monster& monster_);

	enum CURRENT_MENU {
		BLOB = 0,
		MONSTER,
		SKILL
	};

	virtual bool OnCreate(SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Input(sf::RenderWindow& window) override;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;
 
	void SwitchOutline(sf::Text& current, sf::Text& selected);
	void TurnComplete();
	void SkillDisplayChange();
	
	int turn; //Current turn

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	CURRENT_MENU current_menu; //For determining what input should be used and what should be drawn

	int first; //Who went first? 0 is player, 1 is monster

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

	Blob& playerPtr;
	Monster& monsterPtr;
	SceneManager* managerPtr;
};