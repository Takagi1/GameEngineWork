#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

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

	class Scene* currentScene;
	Scene* BuildScene(SCENE_NUMBER scene_);

	

};
#endif // !SCENEMANAGER_H