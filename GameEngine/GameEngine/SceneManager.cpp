#include "pch.h"
#include "SceneManager.h"
#include "\Github\GameEngineWork\GameEngine\GameEngine\Scene's\Test.h"
#include "\Github\GameEngineWork\GameEngine\GameEngine\Scene's\Town.h"

// PURPOSE: Handeling the transition and loading of scene's

SceneManager::SceneManager() {
}

//Loads Scene 
//Note when inputing a scene, all caps is the enum case, lowercase is the class
Scene* SceneManager::BuildScene(SCENE_NUMBER scene_) {

	Scene* currentScene = nullptr;

	switch (scene_) {
	case TEST:
		currentScene = new Test();
		currentScene->OnCreate();
		break;
	case TOWN:
		currentScene = new Town();
		currentScene->OnCreate();
		break;
		
	default:
		//Debug::Error("Incorrect scene number assigned in the manager", __FILE__, __LINE__);
		currentScene = nullptr;
		break;
	}
	return currentScene;
}