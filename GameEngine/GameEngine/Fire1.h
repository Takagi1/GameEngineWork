#pragma once
#include "Skill.h"

class Fire1 : public Skill {
public:

	Fire1();

	virtual void Effect(Character* target, Character* caster) override;
};