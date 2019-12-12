#pragma once
#ifndef TEST_H
#define TEST_H
#include "Map.h"

//Forward declarations

class Test : public Map
{
public:

	explicit Test(Blob * blob_);

	virtual bool OnCreate(SceneManager* const &_transfer, sf::RenderWindow& r_Window, int X, int Y) override;
	virtual void OnDestroy() override;
	virtual void Update(const float dtAsSeconds, sf::RenderWindow& window, sf::View& view) override;

	std::vector<Text> CreateInfoDisplay(); //Might be a terrible way of orginizing the info



};
#endif //TEST_H

