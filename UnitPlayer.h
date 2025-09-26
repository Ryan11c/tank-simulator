#pragma once
#include "Unit.h"
#include "Math.h"

class UnitPlayer : public Unit {
public:
	UnitPlayer(Vector2D setPos);
	void update(float dT, Game& game);
	void draw(RendererGL* rendererGL, int tileSize, Vector2D posCamera);
	void drawShadow(RendererGL* rendererGL, int tileSize, Vector2D posCamera);

	void addExperience(int amount);

	void setDirectionX(int setDirectionRight);
	void setDirectionY(int setDirectionForward);
	void setPosViewTarget(Vector2D setPosViewTarget);

	void shootProjectile(Game& game);


private:
	void setStatsWithLevel();

	int experienceSum = 0;
	int experienceRequiredNextLevel = 5;
	int level = 1;

	float speed = 2.5f;

	int directionX = 0, directionY = 0;
	Vector2D posViewTarget;
};
