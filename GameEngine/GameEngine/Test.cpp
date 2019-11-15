#include "pch.h"
#include "Test.h"
#include "Debug.h"
#include "Blob.h"
#include "Bob.h"

Monster* encounterPtr;
sf::Event inp;
Tile map[25];

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

	//Set inital position
	playerCharacter.location = std::make_pair(1, 1);

//create full map here
	
	//for each tile in map set the scenes tile set and there location in space (remember center should be 50,50)
	
	for (int i = 0; i > 5; i++) {
		for (int j = 0; j > 5; j++) {
			map[i][j].SetLocation(i * 100 + 50, j * 100 + 50);
			map[i][j].SetTexture("background.png");
			map[i][j].SetSprite();
			if (i == 0) {
				map[i][j].isMoveable = false;
			}
			else if (j == 0){
				map[i][j].isMoveable = false;
			}
		}
	}
	//Shity thing is that 

	//Set up Pointers

	managerPtr = _transfer;

	//set up where the player starts

	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);

	sf::Text statusMenu;
	selectMenu.options.push_back(statusMenu);
	selectMenu.options[0].setString("Stats");
	SetupText(&selectMenu.options[0]);
	selectMenu.options[0].setOutlineThickness(5);
	

	sf::Text stomachMenu;
	selectMenu.options.push_back(stomachMenu);
	selectMenu.options[1].setString("Stomach");
	SetupText(&selectMenu.options[1]);

	sf:Text infoMenu;
	selectMenu.options.push_back(infoMenu);
	selectMenu.options[2].setString("Info");
	SetupText(&selectMenu.options[2]);

	return true;
}

void Test::OnDestroy()
{
	//if (partyPtr) delete partyPtr;// , partyPtr = nullptr;

	//if (managerPtr) delete managerPtr;// , managerPtr = nullptr;
}

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

		// handle things when not paused
		if (!isPaused) {

			//after movement rotate player to face the direction they are moveing
			if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::A)
			{
				if (map[playerCharacter.location.first - 1][playerCharacter.location.second].isMoveable) {
					playerCharacter.Move(-1, 0);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				if (map[playerCharacter.location.first + 1][playerCharacter.location.second].isMoveable) {
					playerCharacter.Move(1, 0);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				if (map[playerCharacter.location.first][playerCharacter.location.second - 1].isMoveable) {
					playerCharacter.Move(0, -1);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				if (map[playerCharacter.location.first][playerCharacter.location.second + 1].isMoveable) {
					playerCharacter.Move(0, 1);
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::X))
			{
				map[playerCharacter.location.first][playerCharacter.location.second].CalledEffect();
			}
		}
		if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::B) {
			//Test call prototype scene change
		//managerPtr->BuildScene(SceneManager::TOWN);

			//create a new encounterPtr every time this is called

			//delete previous encounter
			delete(encounterPtr);
			//create new one
			encounterPtr = new Bob();
			//Debug::Error("Encounter health not reseting properly", __FILE__, __LINE__);

			managerPtr->BuildBattle(*encounterPtr);
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
	playerCharacter.update(dtAsSeconds);

	// Set center of the camera to the player
	view.setCenter(playerCharacter.position.x, playerCharacter.position.y);

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

