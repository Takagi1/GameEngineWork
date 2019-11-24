#pragma once
#ifndef TEST_H
#define TEST_H
#include "Map.h"

//Forward declarations

class Test : public Map
{
public:

	explicit Test(Blob * blob_);

	virtual bool OnCreate(SceneManager* const &_transfer) override;
	virtual void OnDestroy() override;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) override ;
	virtual void Input(sf::RenderWindow& window) override;

	std::vector<Text> CreateInfoDisplay(); //Might be a terrible way of orginizing the info

//Pointers for player and scene

	SceneManager* managerPtr;

};
#endif //TEST_H

