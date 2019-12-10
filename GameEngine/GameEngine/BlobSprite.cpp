#include "pch.h"
#include "BlobSprite.h"
#include "PlayerIdle.h"

BlobSprite::BlobSprite() {
	//Associate texture with sprite
//texture.loadFromFile("bob.png");

	animationController.Play(PlayerIdle());
	//sprite.setTexture(texture);	
}

Monster * BlobSprite::CallMonster()
{
	return nullptr;
}
