#include "pch.h"
#include "AnimationController.h"

AnimationController::AnimationController()
{
	curSprite = 0;
}

void AnimationController::Play(Animation animation)
{
	curSprite = 0;
	currentAnimation = animation;
}

sf::Sprite AnimationController::GetSprite()
{
	//Get current sprite
	sf::Sprite sprite = currentAnimation.spriteSet[curSprite];

	//increase curSprite for the next loop
	if (curSprite >= currentAnimation.spriteSet.size() - 1) {
		curSprite = 0;
	}
	else {
		curSprite += 1;
	}
	
	return sprite;
}

sf::RectangleShape AnimationController::GetRectangle()
{
	//Get current sprite
	sf::RectangleShape sprite = currentAnimation.rectangleSet[curSprite];

	//increase curSprite for the next loop
	if (curSprite >= currentAnimation.rectangleSet.size() - 1) {
		curSprite = 0;
	}
	else {
		curSprite += 1;
	}

	return sprite;
}
