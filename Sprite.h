#pragma once

#include "RendererGL.h"
#include "Vector2D.h"

class Sprite {
public:
	Sprite(Vector2D setPos, float setAngle, float setRadius);
	Vector2D getPos();
	bool checkCircleOverlap(Vector2D posCircle, float radiusCircle);
	bool checkCircleOverlap(Sprite* other);

protected:
	void drawBody(RendererGL* rendererGL, int tileSize, Vector2D posCamera, int offsetPos,
		int offsetInner, SDL_Color color, bool isCircle = true);

	float angle;
	Vector2D pos;
	float radius;
};