#include "pch.h"
#include "Character.h"
#include "Fire1.h"

Fire1::Fire1() {
	name = "Fire1";
	element = Element::Fire;
	pierce = false;
}


void Fire1::Effect(Character* target, Character* caster)
{
	target->takeDamage(caster->magic * 1.5, element, pierce);
}