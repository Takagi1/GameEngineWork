#include "pch.h"
#include "StatusEffect.h"

StatusEffect::StatusEffect(int timeLeft_, bool & status_) : status(status_), timeLeft(timeLeft_) {}

void StatusEffect::StatusTick()
{
	if (timeLeft > 0) {
		timeLeft -= 1;
	}
	if (timeLeft == 0){
		status = false;
	}
}
;



