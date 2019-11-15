#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Blob.h"
#include "Monster.h"
#include "MapCharacter.h"

class SceneManager {
public:
	//HOLD is there to allow for the scene change system to work
	enum SCENE_NUMBER {
		HOLD = 0,
		TEST,
		TOWN
	};
	
	//Constructor
	SceneManager(); //Constructor
	void Start(); //Start game

	Blob blob;

	class Scene* currentScene;

	class Scene* saveScene;

	void BuildScene(SCENE_NUMBER scene_);
	void BuildBattle(Monster& _encouter);

	//return to scene after battle
	void endBattle();


private:
	// A regular RenderWindow
	RenderWindow r_Window;

	// For changing scene's
	SceneManager* sceneManager;
};
#endif // !SCENEMANAGER_H