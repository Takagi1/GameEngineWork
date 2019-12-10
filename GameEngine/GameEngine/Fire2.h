#pragma once
#include "Skill.h"

class Fire2 : public Skill {
public:

	Fire2();

	virtual void Effect(Character* target, Character* caster) override;
};