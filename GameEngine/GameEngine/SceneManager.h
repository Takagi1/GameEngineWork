#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Blob.h"
#include "Monster.h"

class SceneManager {
public:
	//HOLD is there to allow for the scene change system to work
	enum SCENE_NUMBER {
		HOLD = 0,
		TEST,
		TOWN
	};
	
	//Constructor
	SceneManager();

	void ScenePtrSet(SceneManager* const &_sceneManager);
	Blob blob;

	class Scene* currentScene;
	SceneManager* managerPtr;

	class Scene* saveScene;

	void BuildScene(SCENE_NUMBER scene_);
	void BuildBattle(Monster& _encouter);

	//return to scene after battle
	void endBattle();

	//call current scene update
	void callUpdate(float dtAsSeconds);
private:


};
#endif // !SCENEMANAGER_H