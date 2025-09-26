#include "UnitPlayer.h"
#include "Game.h"

UnitPlayer::UnitPlayer(Vector2D setPos) :
	Unit(setPos, 0.375f, 20) {
	setStatsWithLevel();
}
