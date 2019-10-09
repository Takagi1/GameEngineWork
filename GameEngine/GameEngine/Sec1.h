#pragma once
#include "Party.h"
class Sec1 {
public:
	Sec1(const Party& part);
	void testing();
	void Hurt(int value);
	const Party& party;
};