#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Party.h"

class SceneManager {
public:
	//HOLD is there to allow for the scene change system to work
	enum SCENE_NUMBER {
		HOLD = 0,
		TEST,
		TOWN
	};
	
	//Constructor
	SceneManager(class Scene* _currentScene);

	void ScenePtrSet(SceneManager* const &_sceneManager);
	Party party;

	class Scene* currentScenePtr;
	SceneManager* managerPtr;
	void BuildScene(SCENE_NUMBER scene_);
	void BuildBattle();


};
#endif // !SCENEMANAGER_H