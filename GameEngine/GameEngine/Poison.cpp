#include "pch.h"
#include "Character.h"
#include "Poison.h"

Poison::Poison(int damage_value, int time) {
	damage = damage_value;
	timeLeft = time;
}

void Poison::InflictEffect(Character* target_)
{
	target_->takeDamage(damage, Element::Poison, false);
}

void Poison::RemoveEffect(Character * target_)
{
	//Nothing should occur for Poison as the effet will just be removed
}
