#include "Movement.h"
#include "Scene.h"


void Scene::insertGameObject(std::unique_ptr<GameObject>& object)
{
	_gameObjects.push_back(std::move(object));

}

void Scene::Update(double deltaTime)
{
	
	//auto thun3 = *_gameObjects.at(5);
	//MPoint2F start = thun3.getLocation();
	//thun3._location = { start.x /(float)deltaTime*17,start.y };
	//*_gameObjects.at(5) = thun3;
	
	//auto one = moveGreenSquare(*_gameObjects.at(5),deltaTime);
	auto thun4 = *_gameObjects.at(6);
	MPoint2F star = thun4.getLocation();
	if (star.y == 486 || star.y==0) {
		wall == true;
		if (star.y == 486) {
			while (star.y <= 486 && star.y > 0) {
				thun4._location = { star.x,star.y * (float)deltaTime / 17 };
				*_gameObjects.at(6) = thun4;
			}
			wall == false;
		}
		else if (star.y == 0) {
			while (star.y >= 0 && star.y < 486) {
				thun4._location = { star.x,star.y / (float)deltaTime * 17 };
				*_gameObjects.at(6) = thun4;
			}
			wall == false;
		}
		//thun4._location = { star.x,star.y / (float)deltaTime /17 };
		//wall == false;
		//*_gameObjects.at(6) = thun4;
	 
	}
	//else if ((star.y ==10 &&wall==true)||wall ==false) {
	//	if (wall == true)wall = false;
		thun4._location = { star.x,star.y / (float)deltaTime*17  };
		*_gameObjects.at(6) = thun4;
		
	

	auto thun5 = *_gameObjects.at(3);
	MPoint2F tar = thun5.getLocation();
	thun5._location = { tar.x / (float)deltaTime * 18,tar.y / (float)deltaTime * 17 };
	*_gameObjects.at(3) = thun5;

	// TODO: update objects in the scene
}

void Scene::Draw(ID2D1HwndRenderTarget & target)
{
	auto result = target.GetSize();
	for (auto& object : _gameObjects)
	{
		const auto& renderer = object->getRenderer();
		renderer.Render(target, object->getLocation());
	}
}
