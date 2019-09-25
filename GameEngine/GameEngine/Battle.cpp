#include "pch.h"
#include "Battle.h"

bool Battle::OnCreate(Party* const &_party, bool* const &_isMap) {

	//make the scene reconize that it is no longer on the map
	isMapPtr = _isMap;
	isMapPtr = false;

	return true;
}