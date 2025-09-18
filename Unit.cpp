#include "Unit.h"

Unit::Unit(Vector2D setPos, float setRadius, int setHealthMax) 
    : Sprite(setPos, 0.0f, setRadius),
      healthMax(setHealthMax),
      healthCurrent(setHealthMax),
      timerWeaponCooldown(2.0f) {
}

void Unit::update(float dT) {
    //UpdateWeaponCooldown
    timerWeaponCooldown.countDown(dT);
}

void Unit::drawTurret(RendererGL* rendererGL, int tileSize, Vector2D posCamera,
                      int offsetPos, int offsetInner, SDL_Color color) {
    if (rendererGL != nullptr) {
        //DrawTurretShape
        int sizeBody = (int)round(tileSize * radius * 2.0f);

        int w = sizeBody / 2 + 22;
        int h = 22;

        SDL_Rect rect = {
            (int)round(pos.x * tileSize + posCamera.x * tileSize) - w / 2 - offsetPos + offsetInner,
            (int)round(pos.y * tileSize + posCamera.y * tileSize) - h / 2 + offsetPos + offsetInner,
            w - offsetInner * 2,
            h - offsetInner * 2
        };

        rendererGL->setDrawColor(color.r, color.g, color.b, color.a);
        rendererGL->fillRect(&rect, angle, w / 2);
    }
}

bool Unit::isAlive() {
    //CheckIfAlive
    return (healthCurrent > 0);
}

void Unit::removeHealth(int amount) {
    //DecreaseHealth
    if (amount > 0) {
        healthCurrent -= amount;
        if (healthCurrent < 0) {
            healthCurrent = 0;
        }
    }
}

void Unit::shootProjectile(Game& game, bool setShotFromPlayer) {
    //ShootProjectileIfCooldownReady
    if (timerWeaponCooldown.timeSIsZero()) {
        game.getListProjectiles().push_back(Projectile(
            pos + Vector2D(angle) * radius,
            angle, weaponDamage, weaponRange, setShotFromPlayer));

        timerWeaponCooldown.resetToMax();
    }
}
