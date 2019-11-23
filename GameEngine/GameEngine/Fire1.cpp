#include "pch.h"
#include "Character.h"
#include "Fire1.h"

Fire1::Fire1() {
	name = "fire1";
	element = Element::Fire;
}


void Fire1::Effect(Character * target)
{
	float damage = target->magic * 1.5f;
	target->takeDamage(damage, element);
}