#include "pch.h"
#include "SceneManager.h"
#include "Test.h"
#include "Town.h"
#include "Battle.h"


// PURPOSE: Handeling the transition and loading of scene's

SceneManager::SceneManager() {
	//Create/load party here
	currentScene = nullptr;
	
	party;
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
		currentScene = new Test();
		currentScene->OnCreate(&party, managerPtr);

		break;
	case TOWN:
		currentScene = new Town();
		currentScene->OnCreate(&party, managerPtr);
		break;

	default:
		//Debug::Error("Incorrect scene number assigned in the manager", __FILE__, __LINE__);
		currentScene = nullptr;
		break;
	}


}
//might be able to integrate this with the constructor theoreticly
void SceneManager::ScenePtrSet(SceneManager* const &_sceneManager)
{
	//Get a pointer to this scene manager
	*&managerPtr = *&_sceneManager;
}

//Transition to battle
void SceneManager::BuildBattle(Encounter &_encouter) {
	//save the current scene 
	saveScene = currentScene;

	//set current scene to battle
	currentScene = new Battle();
	currentScene->Init(party, _encouter,managerPtr);

}


