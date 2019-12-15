#include "pch.h"
#include "Scene.h"

void Scene::SetupText(Text* text)
{
	text->setFillColor(sf::Color::Red);
	text->setFont(font);
	text->setCharacterSize(30);
	text->setStyle(sf::Text::Bold);
	text->setOutlineColor(sf::Color::Blue);
	text->setOutlineThickness(0);
}
