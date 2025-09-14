#pragma once
#include "Sprite.h"
class Game;

class Projectile : public Sprite {
public:
	Projectile(Vector2D setPos, float setAngle, int setDamage,
		float setDistanceTravelMax, bool setShotFromPlayer);

private:
	void checkCollisions(Game& game);
};