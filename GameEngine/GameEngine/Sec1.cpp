#include "pch.h"
#include <iostream>
#include "Sec1.h"

Sec1::Sec1(const Party& part) : party(part){}

void Sec1::testing() {
	cout << party.party[0]->health << "\n";
}

void Sec1::Hurt(int value) {
	party.party[0]->Damage(value);
}