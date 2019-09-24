#pragma once
#ifndef TOWN_H
#define TOWN_H
#include "Scene.h"

class Town : public Scene
{
public:

	explicit Town();

	virtual bool OnCreate() override;
	//virtual void OnDestroy();
	virtual void Update(const float dtAsSeconds) override;
	virtual void Draw(sf::RenderWindow& window) override;
	virtual void Input() override;
	virtual SceneManager::SCENE_NUMBER ScreenT() override;

	SceneManager::SCENE_NUMBER trans = SceneManager::HOLD;

	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	bool isMap = false;

	MapCharacter playerCharacter;
};
#endif //!TEST_H
