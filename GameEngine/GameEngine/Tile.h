#pragma once
#include "SFML/Graphics.hpp"

class SceneManager;

class Tile {

private:
	sf::Sprite sprite;

	sf::Texture texture;

public:

	enum Effect {
		NoEffect,
		Damage,
		Transition
	};

	Tile(Effect eff);

	Effect effect;

	sf::RectangleShape rec;
	void SetTexture(std::string name);

	void SetSprite();

	void SetLocation(int x, int y);

	void CalledEffect(SceneManager** manager); //Player interact

	void TickEffect(); //What happens every tick

	//Reference SceneManager to see what number sends you to what scene
	void SetChangeScene(int scene_number_, int x_, int y_);

	//Attributes for scene change
	int scene_number;
	int x;
	int y;

	sf::Sprite getSprite(); //send copy of the sprite to main 

	bool isMoveable = true; //Is this tile movable

};