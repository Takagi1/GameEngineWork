#pragma once
#include "StatusEffect.h"

/*
Summary: DOT effect
*/

class Poison : public StatusEffect {
	int damage;
public:
	Poison(int damage_value, int time);

	virtual void InflictEffect(Character* target_) override;

	virtual void RemoveEffect(Character* target_) override;
};