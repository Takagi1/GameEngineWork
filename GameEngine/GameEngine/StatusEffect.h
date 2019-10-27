#pragma once

class StatusEffect {
public:

	int timeLeft;
	bool& status;

	StatusEffect(int timeLeft_ , bool& status_);
	//~StatEffect();

	void StatusTick();


};