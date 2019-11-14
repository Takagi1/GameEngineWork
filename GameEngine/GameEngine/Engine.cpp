#include "pch.h"
#include "Engine.h"
#include <Windows.h>
#include <WinUser.h>
#include "MapCharacter.h"
#include "Debug.h"


//BIG NOTE: remember to go over code to clean if needed




Engine::Engine()
{    
	
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
	sceneManager = new SceneManager();
	sceneManager->ScenePtrSet(sceneManager);
	sceneManager->BuildScene(sceneManager->TEST);


	//Create camera

	sf::View view (sf::FloatRect(0, 0, 1280, 720));
	r_Window.setView(view);
	
	while (r_Window.isOpen())
	{
		//May need to change logic if battle needs to be sperated from 
		//Scene because of the way input's are handeled

		//somthing like a button could be used for input though 
		//visual design for battle is still not complete as of yet.

		//selection should make a outline around the target 
		 

		//Restart the clock and save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//Call scene input
		sceneManager->currentScene->Input(r_Window);

		//Temp escape function
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			r_Window.close();
		}

		//Problem is cannot resize the window back to max
		//this does not break but needs <Windows.h> to work
		//also not soution to problem
		if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
			ShowWindow(r_Window.getSystemHandle(), SW_RESTORE);
		}

		//Call scene update
		sceneManager->callUpdate(dtAsSeconds, r_Window, view);

		r_Window.setView(view);

		//Call draw
		sceneManager->currentScene->Draw(r_Window);
	}
}