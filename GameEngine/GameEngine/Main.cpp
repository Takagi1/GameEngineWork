// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "SceneManager.h"
#include "Debug.h"


int main()
{
	std::string name = { "Game Engine" };
	Debug::DebugInit(name + "_Log");
	Debug::Info("Starting the Engine", __FILE__, __LINE__);

	// Declare an instance of SceneManger
	SceneManager sceneManager;

	// Start the engine
	sceneManager.Start();
	
	getchar();
	// Quit the game
	return 0;
}
