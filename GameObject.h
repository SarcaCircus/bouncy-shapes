#pragma once

#include <memory>
#include "GeometryPrimitives.h"
#include "IRenderer.h"


class GameObject {
public:
	GameObject(std::shared_ptr<IRenderer> renderer, MPoint2F location);

	const IRenderer& getRenderer();
	const MPoint2F& getLocation();

	MPoint2F _location;

private:
	std::shared_ptr<IRenderer> _rendererPtr;
	
};