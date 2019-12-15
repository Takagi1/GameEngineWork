#include "pch.h"
#include "Test.h"
#include "Debug.h"
#include "Blob.h"
#include "BlobSprite.h"
#include "DodgerSprite.h"
#include "Person.h"



Test::Test(Blob * player_) {
	playerPtr = player_;
}

bool Test::OnCreate(SceneManager* const &_transfer, sf::RenderWindow& r_Window, int X, int Y) {

	//Set up Pointers

	managerPtr = _transfer;
	//For setting up tiles

	//should be where tileset is set
	
	//get background texture
	m_BackgroundTexture.loadFromFile("background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	m_BackgroundSprite.setPosition(100, 100);

//create full map here
	
	//for each tile in map set the scenes tile set and there location in space (remember center should be 50,50)
	
	mapLength = 8;
	mapWidth = 6;

	for (int i = 0; i < mapLength; i++) {
		for (int j = 0; j < mapWidth; j++) {
		//Setup Tile properties

			Tile tile(Tile::NoEffect);

			//put just i for entire collum, put just j for entire row, put both for a secific tile 
			if (j == 0 || i == 0 || j == mapWidth - 1 || i == mapLength - 1) {
				tile.isMoveable = false;
			}

			//map[(i * 5) + j].SetSprite();

		//Setup Tile visuals

			sf::RectangleShape rectangle(Vector2f(100, 100));
			rectangle.setFillColor(sf::Color::Red);
			rectangle.setOutlineThickness(3);
			rectangle.setOutlineColor(sf::Color::Blue);
			rectangle.setPosition((r_Window.getSize().x / 2 - rectangle.getLocalBounds().width / 2) + j * 100, (r_Window.getSize().y / 2 - rectangle.getLocalBounds().height / 2) + i * 100);

			if (i == 3 && j == 0) {
				tile.SetChangeScene(1, 1, 1);
				rectangle.setFillColor(sf::Color::Blue);
			}

			tile.rec = rectangle;

			map.push_back(tile);
			
		}
	}
//Create monsters and player

	//Player
	BlobSprite* blobSprite = new BlobSprite();
	blobSprite->location = std::make_pair(X, Y);

	//Dodger
	DodgerSprite* dodgerSprite = new DodgerSprite();
	dodgerSprite->location = std::make_pair(3, 3);

	//Person
	Person* pop = new Person();
	pop->location = std::make_pair(3, 4);

	//Setup
	mapCharacters.push_back(blobSprite);
	mapCharacters.push_back(dodgerSprite);
	mapCharacters.push_back(pop);

	//set up where the player starts

	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);

	sf::Text text;
	SetupText(&text);
	text.setString("Stats");
	text.setOutlineThickness(5);
	selectMenu.AddText(text,0);

	text.setString("Stomach");
	text.setOutlineThickness(0);
	selectMenu.AddText(text,1);

	text.setString("Info");
	selectMenu.AddText(text,2);

	return true;
}

void Test::OnDestroy()
{
	//if (partyPtr) delete partyPtr;// , partyPtr = nullptr;

	//if (managerPtr) delete managerPtr;// , managerPtr = nullptr;
}







