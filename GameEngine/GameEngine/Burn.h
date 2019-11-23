#pragma once
#include "StatusEffect.h"

class Burn : public StatusEffect {
	int damage;
public:
	Burn(int damage_value);


	virtual void InflictEffect(Character* target_) override;

	virtual void RemoveEffect(Character* target_) override;
};