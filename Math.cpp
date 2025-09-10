#include "math.h"

const float Math::PI = 3.14159265359f;

float Math::angleRadToDeg(float angle) {
	return angle * 180.0f / PI;
}

float Math::angleDegToRad(float angle) {
	return angle * PI / 180.0f;
}

float Math::randFloat() {
	return ((float)rand() / RAND_MAX);
}

float Math::randAngleRad() {
	return randFloat() * 2 * PI;
}
