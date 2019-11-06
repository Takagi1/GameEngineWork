#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include "SceneManager.h"
#include "MapCharacter.h"


class Scene
{
public:
	//explicit Scene(const Party &party_) {};

	virtual bool OnCreate(SceneManager* const &_transfer) = 0;
	virtual void OnDestroy() = 0;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Input(sf::RenderWindow& window) = 0;

	//Things that must be included in inheriting scenes

	// Declare a sprite and a Texture for the background
	//sf::Sprite m_BackgroundSprite;
	//sf::Texture m_BackgroundTexture;

	//MapCharacter playerCharacter;

	//for paused menu
	//sf::RectangleShape menu;
};
#endif // !SCENE_H