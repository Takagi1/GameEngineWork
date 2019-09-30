#pragma once
//#include "MapMovement.h"
//#include "Character.h"
//#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "SceneManager.h"

using namespace sf;

class Engine
{
private:

	//private functions for internal use only

	// For player input while in battle
	void battleInput();

public:
	//the Engine constructor
	Engine();

	//start will call all the private functions
	void start();
	

};