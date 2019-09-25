#pragma once
#include <SFML/Graphics.hpp>
#include "Party.h"

class Battle
{
public:


	bool OnCreate(Party* const &_party, bool* const &_isMap);
	//virtual void OnDestroy();
	//virtual void Update(const float dtAsSeconds) override;
	//virtual void Draw(sf::RenderWindow& window) override;
	//virtual void Input() override;
	

	bool *isMapPtr;

};