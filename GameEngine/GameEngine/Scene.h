#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include "SceneManager.h"
#include "Tile.h"
#include <iostream>
#include <array>

class Scene
{
public:

	Scene() {
		font.loadFromFile("OpenSans-Light.ttf");
	};

	virtual bool OnCreate(SceneManager* const &_transfer) = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Input(sf::RenderWindow& window) = 0;
	
	sf::Font font;   // Declare and load a font

	enum MenuDisplay
	{
		SELECT = 0,
		STATUS,
		STOMACH,
		INFO
	};
	
	struct scroll {
		std::vector<std::string> options;
		std::vector<sf::Text> display;
		int menuPtr = 0; //What is currently being pointed at?
		int menuOffset = 0; //How far have you scrolled
		int maxOffset = 0; //Max size of offset
		int displayLength = 5;

		void AddOptions(std::string name) {
			options.push_back(name);
			if (options.size() > displayLength) {
				maxOffset = options.size() - 5;
			}
			else {
				display[options.size() - 1].setString(name);
			}
		}
		
		void AddText(sf::Text text, int num) {
			display.push_back(text);
			display[num] = text;
		}

		void MenuScroll(int direction)
		{
			display[menuPtr].setOutlineThickness(0);

			if (maxOffset == 0) {
				//if menu is at 0
				if (menuPtr + direction < 0) {
					menuPtr = display.size() - 1;
				}
				//if menu is going to go over max
				else if (menuPtr + direction == display.size()) {
					menuPtr = 0;
				}
				else {
					menuPtr += direction;
				}
			}
			else {
				//if menu is at 0 or if menu is going to go over max
				if (menuPtr + direction < 0 || menuPtr + menuOffset + direction == options.size()) {
					
				}
				//if you are moving via offset 
				else if (menuPtr + direction > 4 || menuOffset != 0)
				{
					menuOffset += direction;
					DisplayChange(menuOffset);
				}
				else {
					menuPtr += direction;
				}
			}
			display[menuPtr].setOutlineThickness(5);
		};


		//It might be better to simply change the text rather then create more texts?
		void DisplayChange(int offset) {
			display[0].setString(options[0 + offset]);
			display[1].setString(options[1 + offset]);
			display[2].setString(options[2 + offset]);
			display[3].setString(options[3 + offset]);
			display[4].setString(options[4 + offset]);
		}

		void Draw(sf::RenderWindow& r_Window) {
			try {
				for (int i = 0; i < display.size(); i++) {
					r_Window.draw(display.at(i));
				}
			}
			catch (const std::out_of_range& oor) {
				std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
		}
	};

	//Might be a terrible way of orginizing the info
	std::vector<std::string> CreateInfoDisplay(); 

	//Use to Quickly setup text
	void SetupText(Text * text);

	Blob *playerPtr;
	//Things that must be included in inheriting scenes

	// Declare a sprite and a Texture for the background
	//sf::Sprite m_BackgroundSprite;
	//sf::Texture m_BackgroundTexture;

	//MapCharacter playerCharacter;

	//for paused menu
	//sf::RectangleShape menu;
};
#endif // !SCENE_H