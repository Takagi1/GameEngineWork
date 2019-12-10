#include "pch.h"
#include "Map.h"
#include <string>
void Map::Draw(sf::RenderWindow & r_Window)
{

	// Rub out the last frame
	r_Window.clear(sf::Color::White);

	// Draw the background
	//r_Window.draw(m_BackgroundSprite);
	for (int i = 0; i < (mapLength * mapWidth) ; i++) {
		/*sf::RectangleShape a(Vector2f(20,20));
		a.setFillColor(sf::Color::Red);
		a.setOutlineThickness(3);
		a.setOutlineColor(sf::Color::Blue);
		a.setPosition(-500 + (i * 50), i * 2);
		*/
		r_Window.draw(map[i].rec);
		sf::Text tex;
		SetupText(&tex);
		tex.setCharacterSize(15);
		tex.setFillColor(sf::Color::Black);
		std::string word = std::to_string(i);
		tex.setString(word);
		tex.setPosition(map[i].rec.getPosition() + Vector2f(25,25));
		r_Window.draw(tex);
	}

	r_Window.draw(mapCharacters[0].getRect());


	//should draw over all things on screen
	if (isPaused) {
		float setX = r_Window.getSize().x;
		float setY = r_Window.getSize().y;

		menu.setSize(sf::Vector2f(setX / 1.5, setY / 1.5));

		//Rule seems to be that position has to be twise what size is divided by
		menu.setPosition(mapCharacters[0].position.x - setX / 3, mapCharacters[0].position.y - setY / 3);

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

	// Show everything we have just drawn
	r_Window.display();
}