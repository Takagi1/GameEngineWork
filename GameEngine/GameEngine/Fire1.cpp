#include "pch.h"
#include "Character.h"
#include "Fire1.h"


Fire1::Fire1(Character* self, std::string name_) {
	character = self;
	name = name_;
}


void Fire1::Effect(Character * target)
{
	float damage = character->magic * 1.5f;
	character->takeDamage(damage);
}