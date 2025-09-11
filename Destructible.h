#pragma once
#include "Sprite.h"
#include "Math.h"

class Destructible : public Sprite {
public:
    Destructible(Vector2D setPos, int setHealthMax = 1, int setExperienceGiven = 1);
    void update(float dT);
	void draw(RendererGL* rendererGL, int tileSize, Vector2D posCamera);
	void drawShadow(RendererGL* rendererGL, int tileSize, Vector2D posCamera);
	bool isAlive();
	void removeHealth(int amount);
	int getExperienceGiven();

private:
	int healthMax;
	int healthCurrent;
	int experienceGiven;
	float speedAngular = MathAddon::angleDegToRad(45.0f);
};
