#include "pch.h"
#include "Scene.h"

std::vector<Text> Scene::CreateInfoDisplay()
{
	std::forward_list<std::string> strings;
	std::vector<Text> text;
	for (std::forward_list<std::pair<std::pair<std::string, int>, Blob::infoStorage > >::iterator its = playerPtr->info.begin(); its != playerPtr->info.end(); ++its) {
		strings.push_front(its->first.first);
	}
	strings.unique();
	for (std::forward_list<std::string>::iterator its = strings.begin(); its != strings.end(); ++its) {
		Text tex;
		tex.setString(*its);
		text.push_back(tex);
	}

	return text;
}

void Scene::SetupText(Text* text)
{
	text->setFillColor(sf::Color::Red);
	text->setFont(font);
	text->setCharacterSize(30);
	text->setStyle(sf::Text::Bold);
	text->setOutlineColor(sf::Color::Blue);
	text->setOutlineThickness(0);
}