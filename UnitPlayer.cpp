#include "UnitPlayer.h"
#include "Game.h"

UnitPlayer::UnitPlayer(Vector2D setPos) :
	Unit(setPos, 0.375f, 20) {
	setStatsWithLevel();
}

void UnitPlayer::update(float dT, Game& game) {
    //Update any generic Unit behavior first
    Unit::update(dT);

    //Check if movement input was given
    if (directionX != 0 || directionY != 0) {
        //Movement direction vector from input
        Vector2D move((float)directionX, (float)directionY);

        //Normalize to prevent faster diagonal movement
        move.normalize();

        //Scale by this frame's distance
        move *= speed * dT;

        //Apply to position
        pos += move;

        //Clamp position to stay within level boundaries
        const float offsetFromEdge = 0.75f;
        pos.x = std::min(std::max(offsetFromEdge, pos.x), game.getTileCountX() - offsetFromEdge);
        pos.y = std::min(std::max(offsetFromEdge, pos.y), game.getTileCountY() - offsetFromEdge);
    }

    //Update facing angle toward the view target
    angle = (posViewTarget - pos).angle();

    //Reset movement inputs for next frame
    directionX = 0;
    directionY = 0;
}
