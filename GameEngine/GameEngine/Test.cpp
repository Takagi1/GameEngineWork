#include "pch.h"
#include "Test.h"
#include "Debug.h"
#include "Blob.h"
#include "Bob.h"
#include "Tile.h"

Monster* encounterPtr;

bool isPaused = false;
sf::Event inp;
Tile map[25];

Test::Test(Blob& player_) : playerPtr(player_){}

bool Test::OnCreate(SceneManager* const &_transfer) {

	//For setting up tiles
	//create tiles based on size of screen
	//then set up there locations and what part of the sprite sheet the tile shows.
	//mabye in update create a loop of the tiles to display all the tiles
	//set in collsion detection in update
	//

	//should be where tileset is set

	//get background texture
	m_BackgroundTexture.loadFromFile("background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	//Set inital position
	playerCharacter.location.operator=<0, 0>;


//create full map here
	
	//for each tile in map set the scenes tile set and there location in space (remember center should be 50,50)
	map[0][0].SetLocation(50,50);

	map[0][1].SetLocation(50, 150);

	map[0][2].SetLocation(50, 250);

	map[0][3].SetLocation(50, 350);

	map[0][4].SetLocation(50, 450);


	//Set up Pointers

	managerPtr = _transfer;

	//set up where the player starts

	menu.setOutlineColor(sf::Color::Red);
	menu.setOutlineThickness(5);

	sf::Text statusMenu;
	selectMenu.options.push_back(statusMenu);
	selectMenu.options[0].setString("Stats");
	selectMenu.options[0].setFillColor(sf::Color::Red);
	selectMenu.options[0].setFont(font);
	selectMenu.options[0].setCharacterSize(30);
	selectMenu.options[0].setStyle(sf::Text::Bold);
	selectMenu.options[0].setOutlineColor(sf::Color::Blue);
	selectMenu.options[0].setOutlineThickness(5);

	sf::Text stomachMenu;
	selectMenu.options.push_back(stomachMenu);
	selectMenu.options[1].setString("Stomach");
	selectMenu.options[1].setFillColor(sf::Color::Red);
	selectMenu.options[1].setFont(font);
	selectMenu.options[1].setCharacterSize(30);
	selectMenu.options[1].setStyle(sf::Text::Bold);
	selectMenu.options[1].setOutlineColor(sf::Color::Blue);

	return true;
}

void Test::OnDestroy()
{
	//if (partyPtr) delete partyPtr;// , partyPtr = nullptr;

	if (managerPtr) delete managerPtr;// , managerPtr = nullptr;
}

void Test::Input(sf::RenderWindow& r_Window) {

	while (r_Window.pollEvent(inp)) {
		//Paused inputs 
		if (isPaused) {
			//Controls 
			if (inp.type == sf::Event::KeyPressed) {
				if (menuDisplay == SELECT) {
					if (inp.key.code == sf::Keyboard::Right) {
						if (selectMenu.menuPtr == 0) {
							selectMenu.MenuScroll(-1);
						}
						else {
							selectMenu.MenuScroll(1);
						}
					}
					if (inp.key.code == sf::Keyboard::Left) {
						if (selectMenu.menuPtr == 2) {
							selectMenu.MenuScroll(1);
						}
						else {
							selectMenu.MenuScroll(-1);
						}
					}
				}
			}

			//Status menu
			//Should output players current stats and abilites

			//Stomach menu
			//show side by side with image then name

			//Info menu
			//display infomenu
		}

		// handle things when not paused
		if (!isPaused) {

			//after movement rotate player to face the direction they are moveing
			if (inp.type == sf::Event::KeyPressed && inp.key.code == sf::Keyboard::A)
			{
				//map check here
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
				if (map[playerCharacter.location.first][playerCharacter.location.second + 1].isMoveable) {
					playerCharacter.Move(0, 1);
				}
			}


			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				if (map[playerCharacter.location.first][playerCharacter.location.second - 1].isMoveable) {
					playerCharacter.Move(0, -1);
				}
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

void Test::Draw(sf::RenderWindow& r_Window){
	
	// Rub out the last frame
	r_Window.clear(sf::Color::White);

	// Draw the background
	r_Window.draw(m_BackgroundSprite);

	r_Window.draw(playerCharacter.getSprite());


	//should draw over all things on screen
	if (isPaused) {
		float setX = r_Window.getSize().x;
		float setY = r_Window.getSize().y;
		
		menu.setSize(sf::Vector2f(setX /1.5, setY / 1.5));

		//Rule seems to be that position has to be twise what size is divided by
		menu.setPosition(playerCharacter.position.x - setX/3, playerCharacter.position.y - setY/3);

		//draw paused menu here
		r_Window.draw(menu);

		sf::Vector2f menuSize = menu.getPosition();

		selectMenu.options[0].setPosition(menuSize.x + 10, menuSize.y + 25);

		selectMenu.options[1].setPosition(menuSize.x + 10, menuSize.y + 60);

		r_Window.draw(selectMenu.options[0]);
		r_Window.draw(selectMenu.options[1]);

	}

	// Show everything we have just drawn
	r_Window.display();
}