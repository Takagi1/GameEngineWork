#include "pch.h"
#include "SceneManager.h"
#include "Test.h"
#include "Town.h"
#include "Battle.h"

// PURPOSE: Handeling the transition and loading of scene's

SceneManager::SceneManager(Scene* const &_currentScene) {
	//Create/load party here
	currentScenePtr = _currentScene;
	
	party = new Party();
}

//Loads Scene 
//Note when inputing a scene, all caps is the enum case, lowercase is the class
void SceneManager::BuildScene(SCENE_NUMBER scene_) {

	//Destroy scene if moveing to another
	if (currentScenePtr != NULL) {
		//need to safely remove the previous scene

		currentScenePtr->OnDestroy();
		//delete currentScenePtr??;
		currentScenePtr = NULL;
	}


	switch (scene_) {
	case TEST:
		currentScenePtr = new Test();
		currentScenePtr->OnCreate(party, managerPtr);
		break;
	case TOWN:
		currentScenePtr = new Town();
		currentScenePtr->OnCreate(party, managerPtr);
		break;

	default:
		//Debug::Error("Incorrect scene number assigned in the manager", __FILE__, __LINE__);
		currentScenePtr = nullptr;
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
void SceneManager::BuildBattle(Encounter* const &_encouter) {
	//save the current scene 
	saveScene = currentScenePtr;

	//set current scene to battle
	currentScenePtr = new Battle();
	currentScenePtr->Init(party, _encouter,managerPtr);

}
