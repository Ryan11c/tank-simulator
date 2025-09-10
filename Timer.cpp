#include "Timer.h"

Timer::Timer(float setTimeSMax, float setTimeSCurrent) :
	timeSMax(setTimeSMax), timeSCurrent(setTimeSCurrent) {
}

//increase the timer value by dT, but cap at max
void Timer::countUp(float dT) {
	if (timeSCurrent < timeSMax) {
		timeSCurrent += dT;
		if (timeSCurrent > timeSMax) {
			timeSCurrent = timeSMax;
        }
	}
}

//decrease the timer value by dT, but not below zero
void Timer::countDown(float dT) {
	if (timeSCurrent > 0.0f) {
		timeSCurrent -= dT;
		if (timeSCurrent < 0.0f) {
			timeSCurrent = 0.0f;
        }
	}
}

//reset timer back to zero
void Timer::resetToZero() {
	timeSCurrent = 0.0f;
}

//reset timer back to max
void Timer::resetToMax() {
	timeSCurrent = timeSMax;
}

//check if timer has reached zero
bool Timer::timeSIsZero() {
	return (timeSCurrent <= 0.0f);
}

//check if timer has reached max
bool Timer::timeSIsMax() {
	return (timeSCurrent >= timeSMax);
}

//check if timer is >= a given value
bool Timer::timeSIsGreaterThanOrEqualTo(float timeSCheck) {
	return (timeSCurrent >= timeSCheck);
}

//return current time as fraction of max (0.0 to 1.0)
float Timer::computeFTime() {
	if (timeSMax > 0.0f) {
		return (timeSCurrent / timeSMax);
    }

	return 0.0f;
}
