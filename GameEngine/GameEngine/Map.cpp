#include "pch.h"
#include "Map.h"
#include <string>

sf::Event inp;

void Map::Input(sf::RenderWindow& r_Window) {

	while (r_Window.pollEvent(inp)) {

		//Double press seems to be occuring when you press a button 
		// handle things when not paused
		if (!isPaused) {
			if (inp.type == sf::Event::KeyPressed) {
				//after movement rotate player to face the direction they are moveing
				if (inp.key.code == sf::Keyboard::W || Keyboard::isKeyPressed(Keyboard::Up))
				{

					try {
						if (map.at(((mapCharacters[0]->location.second - 1) * mapWidth) + mapCharacters[0]->location.first).isMoveable == true) {
							mapCharacters[0]->Move(0, -1);
							mapCharacters[0]->dir = MapCharacter::Direction::Up;
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0]->location.first << " " << mapCharacters[0]->location.second << " " << (mapCharacters[0]->location.second * mapWidth) + mapCharacters[0]->location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down))
				{
					try {
						if (map.at(((mapCharacters[0]->location.second + 1) * mapWidth) + mapCharacters[0]->location.first).isMoveable == true) {
							mapCharacters[0]->Move(0, 1);
							mapCharacters[0]->dir = MapCharacter::Direction::Down;
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0]->location.first << " " << mapCharacters[0]->location.second << " " << (mapCharacters[0]->location.second * mapWidth) + mapCharacters[0]->location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
				{
					try {
						if (map.at((mapCharacters[0]->location.second * mapWidth) + mapCharacters[0]->location.first + 1).isMoveable) {
							mapCharacters[0]->Move(1, 0);
							mapCharacters[0]->dir = MapCharacter::Direction::Right;
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0]->location.first << " " << mapCharacters[0]->location.second << " " << (mapCharacters[0]->location.second * mapWidth) + mapCharacters[0]->location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
				{
					try {
						if (map.at((mapCharacters[0]->location.second * mapWidth) + mapCharacters[0]->location.first - 1).isMoveable) {
							mapCharacters[0]->Move(-1, 0);
							mapCharacters[0]->dir = MapCharacter::Direction::Left;
						}
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
					std::cerr << "current location " << mapCharacters[0]->location.first << " " << mapCharacters[0]->location.second << " " << (mapCharacters[0]->location.second * mapWidth) + mapCharacters[0]->location.first << '\n';
				}

				if (Keyboard::isKeyPressed(Keyboard::X))
				{
					if (mapCharacters.size() > 1) {
						for (int i = 1; i < mapCharacters.size(); i++) {
							if (mapCharacters[0]->collision().intersects(mapCharacters[i]->rectangle.getGlobalBounds()) && mapCharacters[i]->isPerson == true)
							{
								//Pause game 
								isPaused = true;
								//Display dialog here
								toast = true;
								sentance = mapCharacters[i]->sentence;
							}
						}
					}
				}
			}
		}
		//Paused inputs 
		else if (isPaused) {

			if (!toast)
			{
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
			else {
				if (isPaused && inp.type == sf::Event::KeyPressed && Keyboard::isKeyPressed(Keyboard::X)) {
					//Advance text or end box if at the end of dialogue
					sentance.pop_front();
					if (sentance.empty()) {
						toast = false;
						isPaused = false;
					}
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
			//encounterPtr =
			encounterPtr = mapCharacters[1]->CallMonster();
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


void Map::Draw(sf::RenderWindow & r_Window)
{

	// Rub out the last frame
	r_Window.clear(sf::Color::White);

	// Draw the background
	//r_Window.draw(m_BackgroundSprite);
	for (int i = 0; i < (mapLength * mapWidth) ; i++) {

		r_Window.draw(map[i].rec);

		//Count number of tiles
		sf::Text tex;
		SetupText(&tex);
		tex.setCharacterSize(15);
		tex.setFillColor(sf::Color::Black);
		std::string word = std::to_string(i);
		tex.setString(word);
		tex.setPosition(map[i].rec.getPosition() + Vector2f(25,25));
		r_Window.draw(tex);
	}

	for (auto& characters : mapCharacters) {
		r_Window.draw(characters->rectangle);
	}
	
	//For dipslaying toast to player



	//should draw over all things on screen
	if (isPaused) {
		if (toast) {
			sf::RectangleShape toastMenu(sf::Vector2f(r_Window.getSize().x / 1.5, r_Window.getSize().y /3));

			toastMenu.setOutlineColor(sf::Color::Blue);
			toastMenu.setOutlineThickness(5);
			//Rule seems to be that position has to be twise what size is divided by
			toastMenu.setPosition(r_Window.getSize().x / 3.6, r_Window.getSize().y /1.2);

			sf::Text words;
			SetupText(&words);
			words.setString(sentance.front());
			words.setPosition(sf::Vector2f(toastMenu.getGlobalBounds().width / 1.1, toastMenu.getGlobalBounds().height * 2.5));
			//draw paused menu here
			r_Window.draw(toastMenu);
			r_Window.draw(words);
		}
		else {
			float setX = r_Window.getSize().x;
			float setY = r_Window.getSize().y;

			menu.setSize(sf::Vector2f(setX / 1.5, setY / 1.5));

			//Rule seems to be that position has to be twise what size is divided by
			menu.setPosition(mapCharacters[0]->position.x - setX / 3, mapCharacters[0]->position.y - setY / 3);

			//draw paused menu here
			r_Window.draw(menu);

			sf::Vector2f menuSize = menu.getPosition();

			if (menuDisplay == SELECT) {
				selectMenu.display[0].setPosition(menuSize.x + 10, menuSize.y + 25);
				selectMenu.display[1].setPosition(menuSize.x + 10, menuSize.y + 60);
				selectMenu.display[2].setPosition(menuSize.x + 10, menuSize.y + 100);

				r_Window.draw(selectMenu.display[0]);
				r_Window.draw(selectMenu.display[1]);
				r_Window.draw(selectMenu.display[2]);
			}
			else if (menuDisplay == STATUS) {
				//Display stats here

				Text text;
				SetupText(&text);

				text.setString("Health: " + std::to_string(playerPtr->health) + " / " + std::to_string(playerPtr->maxHealth));
				text.setPosition(menuSize.x + 10, menuSize.y + 30);
				r_Window.draw(text);

				text.setString("Energy: " + std::to_string(playerPtr->energy) + " / " + std::to_string(playerPtr->maxEnergy));
				text.setPosition(menuSize.x + 10, menuSize.y + 60);
				r_Window.draw(text);

				text.setString("Strength: " + std::to_string(playerPtr->strength));
				text.setPosition(menuSize.x + 10, menuSize.y + 90);
				r_Window.draw(text);

				text.setString("Dexterity: " + std::to_string(playerPtr->dexterity));
				text.setPosition(menuSize.x + 10, menuSize.y + 120);
				r_Window.draw(text);

				text.setString("Magic: " + std::to_string(playerPtr->magic));
				text.setPosition(menuSize.x + 10, menuSize.y + 150);
				r_Window.draw(text);

			}
			else if (menuDisplay == STOMACH) {
				//Should display monster?

			}
			else if (menuDisplay == INFO) {
				scroll infoScroll;
				infoScroll.options = CreateInfoDisplay();
			}
		}
	}

	// Show everything we have just drawn
	r_Window.display();
}