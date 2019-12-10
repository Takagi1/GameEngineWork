#pragma once
#include "Skill.h"

class Headbut : public Skill {
public:

	Headbut();

	virtual void Effect(Character* target, Character* caster) override;
};