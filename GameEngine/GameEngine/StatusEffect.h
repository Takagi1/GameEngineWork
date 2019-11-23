#pragma once

//Forward Decleration

class Character;

class StatusEffect {
public:

	int timeLeft; //How long will the effect last?

	bool isActive; //Does this skill effect trigger somthing every turn?

	virtual void InflictEffect(Character* target_) = 0;

	virtual void RemoveEffect(Character* target_) = 0;

};