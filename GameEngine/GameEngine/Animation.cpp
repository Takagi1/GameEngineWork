#include "pch.h"
#include "Animation.h"

void Animation::SheetParse(int height, int width, int rows, int coloums)
{
	Sprite sprite(texture);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < coloums; j++) {
			sprite.setTextureRect(IntRect(width * j, height * i, height, width));
			spriteSet.push_back(sprite);
		}
	}	
}
