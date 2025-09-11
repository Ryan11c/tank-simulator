#include "Destructible.h"

Destructible::Destructible(Vector2D setPos, int setHealthMax, int setExperienceGiven) :
    Sprite(setPos, MathAddon::randAngleRad(), 0.25f),
    healthMax(setHealthMax), healthCurrent(setHealthMax),
	experienceGiven(setExperienceGiven) {}