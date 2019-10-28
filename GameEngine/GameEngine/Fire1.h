#pragma once
#include "Skill.h"

class Fire1 : public Skill {
public:

	Fire1(Character* self, std::string name_);
	virtual void Effect(Character* character_);
};