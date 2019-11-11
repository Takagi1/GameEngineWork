#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include "SceneManager.h"
#include "MapCharacter.h"
#include <array>


class Scene
{
public:
	explicit Scene() {
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
		STATUS
	};


	struct scroll {
		std::vector<sf::Text> options;
		int menuPtr = 0;
		void MenuScroll(int direction)
		{
			options[menuPtr].setOutlineThickness(0);
			if (menuPtr + direction < 0) {
				menuPtr = options.size() - 1;
			}
			else if (menuPtr + direction > options.size() - 1) {
				menuPtr = 0;
			}
			else {
				menuPtr += direction;
			}
			options[menuPtr].setOutlineThickness(5);
		};
	};


	//Things that must be included in inheriting scenes

	// Declare a sprite and a Texture for the background
	//sf::Sprite m_BackgroundSprite;
	//sf::Texture m_BackgroundTexture;

	//MapCharacter playerCharacter;

	//for paused menu
	//sf::RectangleShape menu;
};
#endif // !SCENE_H