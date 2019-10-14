#include "pch.h"
#include "Guide.h"
#include "Barbarian.h"
#include "Monster.h"
 
Guide::Guide() {
	party[0] = new Barbarian();

	name = "Guide";

	speed = 10;
}

void Guide::Move(int direction) {
	//increase or decrease location
	location += direction;
}

void Guide::Charge()
{
	resource += 10;
	if (resource > maxResource) {
		resource = maxResource;
	}
}

void Guide::ChampionAttack(Monster & monster)
{
	party[currentChampion]->BasicAction(monster);
}

sf::Sprite Guide::getSprite() {
	return characterSprite;
}

void Guide::setSpritePos(int x, int y) {
	characterSprite.setPosition(x, y);
}

sf::Sprite Guide::getChampionSprite()
{
	return party[currentChampion]->getSprite();
}

