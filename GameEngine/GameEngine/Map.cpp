#include "pch.h"
#include "Map.h"



void Map::Draw(sf::RenderWindow & r_Window)
{

	// Rub out the last frame
	r_Window.clear(sf::Color::White);

	// Draw the background
	r_Window.draw(m_BackgroundSprite);

	r_Window.draw(playerCharacter.getSprite());


	//should draw over all things on screen
	if (isPaused) {
		float setX = r_Window.getSize().x;
		float setY = r_Window.getSize().y;

		menu.setSize(sf::Vector2f(setX / 1.5, setY / 1.5));

		//Rule seems to be that position has to be twise what size is divided by
		menu.setPosition(playerCharacter.position.x - setX / 3, playerCharacter.position.y - setY / 3);

		//draw paused menu here
		r_Window.draw(menu);

		sf::Vector2f menuSize = menu.getPosition();

		if (menuDisplay == SELECT) {
			selectMenu.options[0].setPosition(menuSize.x + 10, menuSize.y + 25);
			selectMenu.options[1].setPosition(menuSize.x + 10, menuSize.y + 60);
			selectMenu.options[2].setPosition(menuSize.x + 10, menuSize.y + 100);

			r_Window.draw(selectMenu.options[0]);
			r_Window.draw(selectMenu.options[1]);
			r_Window.draw(selectMenu.options[2]);
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