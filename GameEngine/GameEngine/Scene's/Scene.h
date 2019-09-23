#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include "MapCharacter.h"
#include "SceneManager.h"

class Scene
{
public:
	explicit Scene() {};

	virtual bool OnCreate() = 0;
	//virtual void OnDestroy() = 0;
	virtual void Update(const float dtAsSeconds) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Input() = 0;
	virtual SceneManager::SCENE_NUMBER ScreenT() = 0;


	//Things that must be included in inheriting scenes

	//Used for ScreenT to indicate to the engine what scene to transfer too
	//	SceneManager::SCENE_NUMBER trans = SceneManager::HOLD;


	// Declare a sprite and a Texture for the background
	//sf::Sprite m_BackgroundSprite;
	//sf::Texture m_BackgroundTexture;

	// Is this scene a map? Note: this can be changed if no scene switch is used to create a battle view which might be better
	//isMap = false;


	//MapCharacter playerCharacter;
};
#endif // !SCENE_H