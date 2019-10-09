// HelloSFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Engine.h"
#include "Debug.h"
#include "Party.h"
#include "Sec1.h"


int main()
{
	std::string name = { "Game Engine" };
	Debug::DebugInit(name + "_Log");
	Debug::Info("Starting the Engine", __FILE__, __LINE__);

	// Declare an instance of Engine
	Engine engine;

	// Start the engine
	engine.start();
	Party party;
	Sec1 sec(party);
	sec.testing();
	sec.Hurt(5);
	sec.testing();

	Sec1 sec2(party);
	sec2.testing();
	sec2.Hurt(5);
	sec2.testing();

	getchar();
	// Quit the game
	return 0;
}
