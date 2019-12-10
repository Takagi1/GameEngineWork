#pragma once
#include "Skill.h"

class Venom : public Skill {
public:

	Venom();

	virtual void Effect(Character* target, Character* caster) override;
};