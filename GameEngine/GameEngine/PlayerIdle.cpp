#include "pch.h"
#include "PlayerIdle.h"

PlayerIdle::PlayerIdle() {
	//Set Animation here

	sf::RectangleShape rec;
	rec.setSize(Vector2f(25, 25));
	rec.setOutlineThickness(3);
	rec.setOutlineColor(sf::Color::Black);

	rec.setFillColor(sf::Color::Green);
	rectangleSet.push_back(rec);

	rec.setFillColor(sf::Color::Blue);
	rectangleSet.push_back(rec);
	
	
}

