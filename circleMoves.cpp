#include "CircleRenderer.h"
#include "GameObject.h"
#include "Movement.h"


MPoint2F moveCircle(GameObject toMove) {
	MPoint2F play{ 1.0f,1.0f };
	play=toMove.getLocation();
	play.x-=110;
	return play;
}