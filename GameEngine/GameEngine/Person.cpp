#include "pch.h"
#include "Person.h"
#include "DodgerIdle.h"

Person::Person(){
	isPerson = true;

	animationController.Play(DodgerIdle());

	sentence.push_front("Goodbye World!");
	sentence.push_front("Hello World!");
}

Monster * Person::CallMonster()
{
	return nullptr;
}

