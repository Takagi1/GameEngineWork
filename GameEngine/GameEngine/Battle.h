#pragma once
#include "Scene.h"
#include <vector>

class Battle : public Scene
{

public:
	explicit Battle(const Party& party_);
	enum CURRENT_MENU {
		MAIN = 0,
		TARGET = 1,
		SKILL = 2
	};


	virtual bool OnCreate(SceneManager* const &_transfer) override;
	virtual bool Init(Encounter &_encounter, SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Input(sf::RenderWindow& window) override;
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& r_Window) override;

	void TargetSetup(Character* current);

	

	//current turn
	int turn;

	//max size of turnOrder
	//std::size_t size;

	//turn order
	std::vector<Character*> turnOrder;

	//what character's turn is it.
	int chaSel = 0;
	
	Texture backgroundTexture;
	Sprite backgroundSprite;

	//For drawing the menu and characters
	CURRENT_MENU menu_;


	// Declare and load a font
	sf::Font font;

	//Text

	sf::Text characterName0;
	sf::Text healthDisplay0;

	sf::Text characterName1;
	sf::Text healthDisplay1;

	sf::Text attack;
	sf::Text skill;
	sf::Text targSel1;
	sf::RectangleShape menu;


	//mabye keep the indivual party and 
	//encounter to streamline check

	const Party& partyPtr;
	Encounter encounterPtr;
	SceneManager* managerPtr;

private: 
	//who can be targeted
	std::vector<int> Targetable;
};