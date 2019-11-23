#include "pch.h"
#include "SceneManager.h"
#include "Test.h"
#include "Town.h"
#include <Windows.h>
#include <WinUser.h>
#include "Battle.h"
#include "Debug.h"


// PURPOSE: Handeling the transition and loading of scene's

SceneManager::SceneManager() {
	//Create/load party here
	currentScene = nullptr;

	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	//RenderWindow window

	r_Window.create(VideoMode(1280, 720),
		"Simple Game Engine",
		Style::Default);
}


void SceneManager::Start()
{
	//Timing
	Clock clock;

	//This might be the location for building the inital load system (save load?)
	BuildScene(TEST);

	//Create camera
	sf::View view(sf::FloatRect(0, 0, 1280, 720));
	r_Window.setView(view);

	while (r_Window.isOpen())
	{

		//Restart the clock and save the elapsed time into dt
		Time dt = clock.restart();

		// Make a fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		//Call scene input
		currentScene->Input(r_Window);

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
		currentScene->Update(dtAsSeconds, r_Window, view);

		r_Window.setView(view);

		//Call draw
		currentScene->Draw(r_Window);
	}
}


//Loads Scene 
//Note when inputing a scene, all caps is the enum case, lowercase is the class
void SceneManager::BuildScene(SCENE_NUMBER scene_) {

	//Destroy scene if moveing to another
	if (currentScene != NULL) {
		//need to safely remove the previous scene

		currentScene->OnDestroy();
		//delete currentScenePtr??;
		currentScene = NULL;
	}
	
	//int ti = &party->party.size;
	switch (scene_) {
	case TEST:
		currentScene = new Test(&blob);
		currentScene->OnCreate(this);

		break;
	case TOWN:
		currentScene = new Town(&blob);
		currentScene->OnCreate(this);

		break;
	default:
		Debug::Error("Incorrect scene number assigned in the manager", __FILE__, __LINE__);
		currentScene = nullptr;
		break;
	}
}

//Transition to battle
void SceneManager::BuildBattle(Monster *_encouter) {
	//save the current scene 
	saveScene = currentScene;

	//set current scene to battle
	currentScene = new Battle(&blob, _encouter);
	currentScene->OnCreate(this);
}


void SceneManager::endBattle() {
	currentScene->OnDestroy();
	currentScene = saveScene;
}