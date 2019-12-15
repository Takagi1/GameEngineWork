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
};
#endif //TEST_H

