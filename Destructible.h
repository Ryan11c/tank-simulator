#pragma once
#include "Sprite.h"
#include "Math.h"

class Destructible : public Sprite {
public:
    Destructible(Vector2D setPos, int setHealthMax = 1, int setExperienceGiven = 1);
};
