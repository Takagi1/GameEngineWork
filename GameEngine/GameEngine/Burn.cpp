#include "pch.h"
#include "Character.h"
#include "Burn.h"

Burn::Burn(int damage_value) {
	damage = damage_value;
}

void Burn::InflictEffect(Character* target_)
{
	target_->health -= 5;
}

void Burn::RemoveEffect(Character * target_)
{
	//Nothing should occur for burn as the effet will just be removed
}
