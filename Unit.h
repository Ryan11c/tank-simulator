#pragma once
#include "Sprite.h"
#include "Timer.h"
#include "Projectile.h"

class Unit : public Sprite {
public:
	Unit(Vector2D setPos, float setRadius, int setHealthMax);
	void update(float dT);
	bool isAlive();
	void removeHealth(int amount);

protected:
	void drawTurret(RendererGL* rendererGL, int tileSize, Vector2D posCamera, int offsetPos, int offsetInner, SDL_Color color);
	void shootProjectile(Game& game, bool setShotFromPlayer);

	int weaponDamage = 1;
	float weaponRange = 8.0f;
	Timer timerWeaponCooldown;

private:
	int healthMax;
	int healthCurrent;
};