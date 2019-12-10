#include "pch.h"
#include "Character.h"
#include "Headbut.h"

Headbut::Headbut()
{
	name = "Headbut";
	element = Element::Physical;
	pierce = false;
}

void Headbut::Effect(Character * target, Character* caster)
{
	target->takeDamage(caster->strength, element, pierce);
}
