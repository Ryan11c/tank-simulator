#include "Sprite.h"

Sprite::Sprite(Vector2D setPos, float setAngle, float setRadius) :
	pos(setPos), angle(setAngle), radius(setRadius) {
}

//return the position of the sprite
Vector2D Sprite::getPos() {
	return pos;
}

//check if a circle at posCircle with radiusCircle overlaps with this sprite
bool Sprite::checkCircleOverlap(Vector2D posCircle, float radiusCircle) {
	//overlap happens if distance between centers <= sum of radii
	return (posCircle - pos).magnitude() <= (radiusCircle + radius);
}

//check overlap with another sprite object
bool Sprite::checkCircleOverlap(Sprite* other) {
	if (other != nullptr)
		//reuse the first function with the other sprite's data
		return checkCircleOverlap(other->pos, other->radius);

	//if other is null, no overlap
	return false;
}

//draw the body of the sprite
void Sprite::drawBody(RendererGL* rendererGL, int tileSize, Vector2D posCamera, int offsetPos, int offsetInner, SDL_Color color, bool isCircle) {
	if (rendererGL != nullptr) {
		//calculate the size of the sprite based on its radius
		int size = (int)round(tileSize * radius * 2.0f);

		//create a rectangle that represents the sprite's position on screen
		SDL_Rect rect = {
			(int)round(pos.x * tileSize + posCamera.x * tileSize) - size / 2 - offsetPos + offsetInner,
			(int)round(pos.y * tileSize + posCamera.y * tileSize) - size / 2 + offsetPos + offsetInner,
			size - offsetInner * 2,
			size - offsetInner * 2 };
		
		//set the drawing color
		rendererGL->setDrawColor(color.r, color.g, color.b, color.a);

		//draw either a circle or rectangle based on the flag
		if (isCircle) {
			rendererGL->fillOval(&rect, angle);
        }
		else {
			rendererGL->fillRect(&rect, angle);
        }
	}
}
