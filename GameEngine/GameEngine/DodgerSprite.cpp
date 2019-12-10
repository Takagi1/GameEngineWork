#include "pch.h"
#include "DodgerSprite.h"
#include "DodgerIdle.h"
#include "Dodger.h"


DodgerSprite::DodgerSprite() {
	//Associate texture with sprite
//texture.loadFromFile("bob.png");

	monster = new Dodger();

	animationController.Play(DodgerIdle());
	//sprite.setTexture(texture);	
}

Monster* DodgerSprite::CallMonster() {
	return new Dodger();
}
