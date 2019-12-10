#pragma once
#include "Animation.h"

class AnimationController {
public:

	Animation currentAnimation;
	int curSprite;

	AnimationController();

	void Play(Animation animation); //Use to play animations

	sf::Sprite GetSprite();

	//For Testing
	sf::RectangleShape GetRectangle();	
};
