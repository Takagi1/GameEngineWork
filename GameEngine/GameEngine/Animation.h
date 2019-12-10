#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

//if you are using a sheet set texture then call SheetParse, if just using single sprite's, you have to set them manually
class Animation {
public:

	Texture texture;

	std::vector<Sprite> spriteSet; //Order of the sprites that will be played

	//For Testing 
	std::vector<RectangleShape> rectangleSet;

	//For parsing a sprite sheet into spriteSet
	virtual void SheetParse(int height, int width, int rows, int coloums);

};