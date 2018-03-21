#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include <d2d1.h>


class Movement {
public:
	const GameObject & moveGreenSquare(GameObject change, double deltaTime);
private:
	std::vector<std::unique_ptr<GameObject>> _gameObjects = {};
	double deltaTime;

};

