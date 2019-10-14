// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Engine.h"
#include "Debug.h"


int main()
{
	std::string name = { "Game Engine" };
	Debug::DebugInit(name + "_Log");
	Debug::Info("Starting the Engine", __FILE__, __LINE__);

	// Declare an instance of Engine
	Engine engine;

	// Start the engine
	engine.start();
	
	getchar();
	// Quit the game
	return 0;
}
