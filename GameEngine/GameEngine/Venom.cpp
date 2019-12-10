#include "pch.h"
#include "Character.h"
#include "Poison.h"
#include "Venom.h"

Venom::Venom()
{
	name = "Venom";
	element = Element::Poison;
	pierce = false;
}

void Venom::Effect(Character* target, Character* caster)
{
	target->takeDamage(caster->magic * 0.5, element, pierce);
	target->InflictStatus(new Poison(caster->magic * 0.7, 3));
}
