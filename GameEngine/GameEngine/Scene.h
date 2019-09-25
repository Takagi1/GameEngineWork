#pragma once
#ifndef SCENE_H
#define SCENE_H
#include <SFML\Graphics.hpp>
#include "MapCharacter.h"
#include "SceneManager.h"
#include "Battle.h"

class Scene
{
public:
	explicit Scene() {};

	virtual bool OnCreate(Party* const &_party, SceneManager* const &_transfer) = 0;
	//virtual void OnDestroy() = 0;
	virtual void Update(const float dtAsSeconds) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual void Input() = 0;


	//Things that must be included in inheriting scenes

	// Declare a sprite and a Texture for the background
	//sf::Sprite m_BackgroundSprite;
	//sf::Texture m_BackgroundTexture;

	// Is this scene a map? Note: this can be changed if no scene switch is used to create a battle view which might be better
	//bool isMap;


	//MapCharacter playerCharacter;
};
#endif // !SCENE_H