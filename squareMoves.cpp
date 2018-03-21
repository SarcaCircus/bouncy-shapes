#include "Movement.h"
#include <vector>



const GameObject & Movement::moveGreenSquare(GameObject change, double deltaTime) {
	auto thun3 = change;
	MPoint2F start = thun3.getLocation();
	thun3._location = { start.x / (float)deltaTime * 17,start.y };
	return thun3;
}