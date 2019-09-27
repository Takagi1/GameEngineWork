#include "pch.h"
#include "Engine.h"
#include "Debug.h"
#include "MapCharacter.h"

//BIG NOTE: find out what your doing wrong with pointers and references
//the goal is to make it so that you can change the currentScene from 
//others locations.  this seems to not be working as 


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

	//What if? the scene manager sets the engines current scene.  it has the engine stored so that if its function is called the scene would
	//change.  This could allow for scene changes to occur in the scene.  however on create must then be done in the scene manager meaning
	//that the window would have to be there as well.  this could be achived by creating the window in main mabye and then lowering it into
	//the engine.

	//This might be the location for building the inital load system
	SceneManager *sceneManager = new SceneManager();
	sceneManager->ScenePtrSet(sceneManager);
	sceneManager->BuildScene(sceneManager->TEST);

	while (r_Window.isOpen())
	{

		//May need to change logic if battle needs to be sperated from 
		//Scene because of the way input's are handeled

		//somthing like a button could be used for input though 
		//visual design for battle is still not complete as of yet.

		//selection should make a outline around the target 
		 

		//Restart the clock adn save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//Call scene input
		sceneManager->callInput();

		//Temp escape function
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			r_Window.close();
		}
		//input battle input if in battle 

		//Call scene update
		sceneManager->callUpdate(dtAsSeconds);

		//Call scene draw
		sceneManager->currentScene->Draw(r_Window);
	}
}