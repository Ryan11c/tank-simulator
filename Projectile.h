#pragma once
#include "Sprite.h"
class Game;

class Projectile : public Sprite {
public:
	Projectile(Vector2D setPos, float setAngle, int setDamage,
		float setDistanceTravelMax, bool setShotFromPlayer);
    void update(float dT, Game& game);
	void draw(RendererGL* rendererGL, int tileSize, Vector2D posCamera);
	void drawShadow(RendererGL* rendererGL, int tileSize, Vector2D posCamera);
	bool getCollisionOccurred();

private:
	void checkCollisions(Game& game);
    void checkCollisions(Game& game);

	float speed = 6.0f;
	int damage;
	bool shotFromPlayer;
	bool collisionOccurred = false;
    
	float distanceTraveled = 0.0f;
	float distanceTravelMax;
};
