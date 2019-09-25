#include "pch.h"
#include "Engine.h"
#include "Debug.h"
#include "MapCharacter.h"
#include "Town.h"

Engine::Engine()
{    
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window;

	r_Window.create(VideoMode(1280, 720),
		"Simple Game Engine",
		Style::Default);
}

void Engine::start()
{
	//Timing
	Clock clock;

	// this is here beacuse of an error that occurs when scene is trying to function with a nullptr
	currentScene = new Town();

	
	//What if? the scene manager sets the engines current scene.  it has the engine stored so that if its function is called the scene would
	//change.  This could allow for scene changes to occur in the scene.  however on create must then be done in the scene manager meaning
	//that the window would have to be there as well.  this could be achived by creating the window in main mabye and then lowering it into
	// the engine.

	//This might be the location for building the inital load system
	SceneManager *sceneManager = new SceneManager(currentScene);
	sceneManager->ScenePtrSet(sceneManager);
	sceneManager->BuildScene(sceneManager->TEST);
	
	while (r_Window.isOpen())
	{
		//Restart the clock adn save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//Call scene input
		currentScene->Input();

		//Temp escape function
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			r_Window.close();
		}
		//input battle input if in battle 

		//Call scene update
		currentScene->Update(dtAsSeconds);

		//Call scene draw
		currentScene->Draw(r_Window);
	}
}