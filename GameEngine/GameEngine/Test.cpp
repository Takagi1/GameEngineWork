#include "pch.h"
#include "Test.h"
#include "Debug.h"
#include "Blob.h"
#include "Dodger.h"
#include "BlobSprite.h"
#include "DodgerSprite.h"

Monster* encounterPtr;
sf::Event inp;

Test::Test(Blob * player_) {
	playerPtr = player_;
}

bool Test::OnCreate(SceneManager* const &_transfer) {

	//For setting up tiles
	//create tiles based on size of screen
	//then set up there locations and what part of the sprite sheet the tile shows.
	//mabye in update create a loop of the tiles to display all the tiles
	//set in collsion detection in update

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

			Tile tile;

			//put just i for entire collum, put just j for entire row, put both for a secific tile 
			if (j == 0 || i == 0) {
				tile.isMoveable = false;
			}

			//map[(i * 5) + j].SetLocation((i * 100) + 50, (j * 100) + 50);
			//map[(i * 5) + j].SetTexture("background.png");

			//map[(i * 5) + j].SetSprite();

		//Setup Tile visuals

			sf::RectangleShape rectangle(Vector2f(100, 100));
			rectangle.setFillColor(sf::Color::Red);
			rectangle.setOutlineThickness(3);
			rectangle.setOutlineColor(sf::Color::Blue);
			rectangle.setPosition(-600 + ((j * 100 ) + 50), -200 + (i * 100) + 50);

			tile.rec = rectangle;

			map.push_back(tile);
			
		}
	}
//Create monsters and player

	//Player
	BlobSprite blobSprite;
	blobSprite.location = std::make_pair(1, 1);

	//Setup
	mapCharacters.push_back(blobSprite);
	
	//Set up Pointers

	managerPtr = _transfer;

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
//you can use IntRect for collision with monsters and player. will have to add in collision detection with update


void Test::Input(sf::RenderWindow& r_Window) {

	while (r_Window.pollEvent(inp)) {

		//Paused inputs 
		if (isPaused) {

			//Controls 
			if (inp.type == sf::Event::KeyPressed) {
				if (menuDisplay == SELECT) {

					if (inp.key.code == sf::Keyboard::Right) {
						selectMenu.MenuScroll(1);	
					}

					if (inp.key.code == sf::Keyboard::Left) {
						selectMenu.MenuScroll(-1);
					}

					if (inp.key.code == sf::Keyboard::X) {
						if (selectMenu.menuPtr == 0) {
							//Status menu
							//Should output players current stats and abilites

							menuDisplay = STATUS;
						}
						else if (selectMenu.menuPtr == 1) {
							//Stomach menu
							//show side by side with image then name

							menuDisplay = STOMACH;
						}
						else if (selectMenu.menuPtr == 2) {
							//Info menu
							//display info menu

							menuDisplay = INFO;
						}
					}
				}
				
				if (menuDisplay != SELECT) {
					if (inp.key.code == sf::Keyboard::BackSpace)
					{
						menuDisplay = SELECT;
					}
				}
			}
		}
		//Double press seems to be occuring when you press a button 
		// handle things when not paused
		if (!isPaused) {
			if (inp.type == sf::Event::KeyPressed) {
				//after movement rotate player to face the direction they are moveing
				if (inp.key.code == sf::Keyboard::W || Keyboard::isKeyPressed(Keyboard::Up))
				{
					
					try {
						if (map.at(((mapCharacters[0].location.second - 1) * mapWidth) + mapCharacters[0].location.first).isMoveable == true) {
							mapCharacters[0].Move(0, -1);
							mapCharacters[0].dir = MapCharacter::Direction::Up;
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0].location.first << " " << mapCharacters[0].location.second << " " << (mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
				{
					try {
						if (map.at(((mapCharacters[0].location.second + 1) * mapWidth) + mapCharacters[0].location.first ).isMoveable == true){
							mapCharacters[0].Move(0,1);
							mapCharacters[0].dir = MapCharacter::Direction::Down;
						} 
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0].location.first << " " << mapCharacters[0].location.second << " " << (mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
				{
					try {
						if (map.at((mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first + 1).isMoveable) {
							mapCharacters[0].Move(1, 0);
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0].location.first << " " << mapCharacters[0].location.second << " " << (mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
				{
					try {
						if (map.at((mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first - 1 ).isMoveable) {
							mapCharacters[0].Move(-1,0);
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0].location.first << " " << mapCharacters[0].location.second << " " << (mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::X))
				{
					map[(mapCharacters[0].location.second * mapWidth) + mapCharacters[0].location.first].CalledEffect();
				}
			}
		}
		if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::B) {
			//Test call prototype scene change
		//managerPtr->BuildScene(SceneManager::TOWN);

			//create a new encounterPtr every time this is called

			//delete previous encounter
			if (encounterPtr != NULL) { delete(encounterPtr); }
			//create new one
			encounterPtr = new Dodger();
			//Debug::Error("Encounter health not reseting properly", __FILE__, __LINE__);

			managerPtr->BuildBattle(encounterPtr);
		}

		//Time should pause here
		if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::P) {

			if (!isPaused) isPaused = true;
			else isPaused = false;
		}
	}
}


std::vector<Text> Test::CreateInfoDisplay()
{
	std::forward_list<std::string> strings;

	std::vector<Text> text;
	for (std::forward_list<std::pair<std::pair<std::string, int>, Blob::infoStorage > >::iterator its = playerPtr->info.begin(); its != playerPtr->info.end(); ++its) {
		strings.push_front(its->first.first);
	}

	strings.unique();

	for (std::forward_list<std::string>::iterator its = strings.begin(); its != strings.end(); ++its) {
		Text tex;
		tex.setString(*its);
		text.push_back(tex);
	}

	return text;
}

// Move Bob based on the input this frame,
// the time elapsed, and the speed.
void Test::Update(float dtAsSeconds, sf::RenderWindow& r_Window, sf::View& view) {
	//check to see if the movement will cause the player the collision
	mapCharacters[0].update(dtAsSeconds);

	// Set center of the camera to the player
	view.setCenter(mapCharacters[0].position.x, mapCharacters[0].position.y);

	//if any map monsters intersect with player engage battle here

	/*//Example of changing scene
	if (playerCharacter.position.y <= 400) {

		//Test call prototype scene change
		//managerPtr->BuildScene(SceneManager::TOWN);

		//Test battle call
		Encounter encounterPtr;

		managerPtr->BuildBattle(encounterPtr);
	}
	*/
}

