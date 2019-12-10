#include "pch.h"
#include "DodgerIdle.h"

DodgerIdle::DodgerIdle()
{
	sf::RectangleShape rec;
	rec.setSize(Vector2f(25, 25));
	rec.setOutlineThickness(3);
	rec.setOutlineColor(sf::Color::Black);

	rec.setFillColor(sf::Color::Cyan);
	rectangleSet.push_back(rec);
}
