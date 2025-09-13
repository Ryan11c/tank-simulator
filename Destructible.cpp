#include "Destructible.h"

Destructible::Destructible(Vector2D setPos, int setHealthMax, int setExperienceGiven) :
    Sprite(setPos, MathAddon::randAngleRad(), 0.25f),
    healthMax(setHealthMax), healthCurrent(setHealthMax),
	experienceGiven(setExperienceGiven) {}

void Destructible::update(float dT) {
    angle += speedAngular * dT;
}

void Destructible::draw(RendererGL* rendererGL, int tileSize, Vector2D posCamera) {
    drawBody(rendererGL, tileSize, posCamera, 0, 0, SDL_Color{ 254, 151, 78, 255 }, false);
    drawBody(rendererGL, tileSize, posCamera, 0, 4, SDL_Color{ 231, 116, 0, 255 }, false);
}

void Destructible::drawShadow(RendererGL* rendererGL, int tileSize, Vector2D posCamera) {
    drawBody(rendererGL, tileSize, posCamera, 5, 0, SDL_Color{ 109, 25, 72, 255 }, false);
}

bool Destructible::isAlive() {
	return (healthCurrent > 0);
}

void Destructible::removeHealth(int amount) {
	if (amount > 0) {
		healthCurrent -= amount;
		if (healthCurrent < 0) {
			healthCurrent = 0;
        }
	}
}

int Destructible::getExperienceGiven() {
	return experienceGiven;
}