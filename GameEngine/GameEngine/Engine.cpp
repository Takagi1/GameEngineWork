#include "pch.h"
#include "Engine.h"
#include "Debug.h"
#include "MapCharacter.h"
#include "Scene'sTest.h"
#include "Champion.h"

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

	//Create the party
	Champion party[1];
	
	// Select inital scene

	//What if? the scene manager sets the engines current scene.  it has the engine stored so that if its function is called the scene would
	//change.  This could allow for scene changes to occur in the scene.  however on create must then be done in the scene manager meaning
	//that the window would have to be there as well.  this could be achived by creating the window in main mabye and then lowering it into
	// the engine.

	//overall goal: allow for currentScene to be changed from a call within scene to allow for scene changes based on distance

	//Current Logic: when sceneManager is created make a call of a Init function to set currentScene and window
	//Stoped here becasue current logic does not make sense.  Must re-evaluate method of implimination.  must ask teachers or classmates
	//if any solution comes to mind 

	SceneManager *sceneManager = new SceneManager();

	//sceneManager->SceneSet(currentScene, r_Window);
	currentScene = sceneManager->BuildScene(sceneManager->TEST);
	
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


		//Current interation of scene change code solves some problems but is still rough
		//best implimintation would be to be able to call a version of sceneManager change and effect the code in 
		//the scene
		//Logic: current scene->buildScene on SceneManager from engine which changes the current scene dirrectly

		if (currentScene->ScreenT() != SceneManager::HOLD) {
			//Load new Scene
			currentScene = sceneManager->BuildScene(currentScene->ScreenT());
		}
	}
}