#pragma once
#include "Scene.h"
#include "SceneManager.h"

using namespace sf;

class Engine
{
private:

	//private functions for internal use only

	// A regular RenderWindow
	RenderWindow r_Window;

	// For changing scene's
	SceneManager* sceneManager;

public:
	//the Engine constructor
	Engine();

	//start will call all the private functions
	void start();
};