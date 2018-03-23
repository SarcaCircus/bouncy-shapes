
#include "Scene.h"
#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"
#include <d2d1.h>

using namespace std;

class Movement {
public:
	Movement(string type, GameObject toMove)
		: _type(type), _toMove(toMove){}
	
	auto move(double deltaTime) {
		auto thun3 = _toMove;
		MPoint2F start = thun3.getLocation();
		thun3._location = { start.x / (float)deltaTime * 17,start.y };
		_toMove = thun3;
		return _toMove;
	}
protected:
	string _type;
	GameObject _toMove;

};
class GreenSquare : public Movement{

public:
	GreenSquare(string type, GameObject toMove)
		:Movement(type,toMove){}

	GameObject move( double deltaTime) {
		auto thun3 = _toMove;
		MPoint2F start = thun3.getLocation();
		thun3._location = { start.x / (float)deltaTime * 17,start.y };
		_toMove = thun3;
		return _toMove;
	}

};
class PurpleSquare : public Movement {

public:
	PurpleSquare(string type, GameObject toMove)
		:Movement(type, toMove) {}

	GameObject move(double deltaTime) {
		if (_type == "one") {
			auto thon3 = _toMove;//purple square 7
			MPoint2F art = thon3.getLocation();
			thon3._location = { art.x / (float)deltaTime * 15,art.y / (float)deltaTime * 15 };
			_toMove = thon3;
			return _toMove;
		}
		else if (_type == "two") {
			auto reduin = _toMove;//purple square
			MPoint2F mat = reduin.getLocation();
			reduin._location = { mat.x / (float)deltaTime * 20,mat.y / (float)deltaTime * 15 };
			_toMove = reduin;
			return _toMove;
		}
		else if (_type == "three") {
			auto thu2 = _toMove;//purple square 8
			MPoint2F why = thu2.getLocation();
			thu2._location = { why.x / (float)deltaTime * 18,why.y / (float)deltaTime * 17 };
			_toMove = thu2;
			return _toMove;
		}
	}

};
class GreenCircle : public Movement {

public:
	GreenCircle(string type, GameObject toMove)
		:Movement(type, toMove) {}

	GameObject move(double deltaTime) {
		if (_type == "one") {
			auto redun = _toMove;//green circle 4
			MPoint2F at = redun.getLocation();
			redun._location = { at.x / (float)deltaTime * 20,at.y / (float)deltaTime * 15 };
			_toMove = redun;
			return _toMove;
		}
		else if (_type == "two") {
			auto thun1 = _toMove;//green circle
			MPoint2F stt = thun1.getLocation();
			thun1._location = { stt.x ,stt.y / (float)deltaTime * 15 };
			_toMove = thun1;
			return _toMove;
		}
	}

};

class BlueSquare: public Movement {

public:
	BlueSquare(string type, GameObject toMove)
		:Movement(type, toMove) {}

	GameObject move(double deltaTime) {
		auto thun4 = _toMove;
		MPoint2F star = thun4.getLocation();
		thun4._location = { star.x,star.y / (float)deltaTime*17  };//blue square
		_toMove = thun4;
		return _toMove;
	}

};

class RedCircle : public Movement {

public:
	RedCircle(string type, GameObject toMove)
		:Movement(type, toMove) {}

	GameObject move(double deltaTime) {
		auto thu = _toMove;//red circle 1
		MPoint2F sorry = thu.getLocation();
		thu._location = { sorry.x / (float)deltaTime * 20,sorry.y / (float)deltaTime * 20 };
		_toMove = thu;
		return _toMove;
	}

};
class BlueCircle : public Movement {

public:
	BlueCircle(string type, GameObject toMove)
		:Movement(type, toMove) {}

	GameObject move(double deltaTime) {
		auto tu = _toMove;//blue circle 0
		MPoint2F sor = tu.getLocation();
		tu._location = { sor.x / (float)deltaTime * 18,sor.y };
		_toMove = tu;
		return _toMove;
	}

};
class PurpleCircle : public Movement {

public:
	PurpleCircle(string type, GameObject toMove)
		:Movement(type, toMove) {}

	GameObject move(double deltaTime) {
		auto thun5 = _toMove;//purple circle 3
		MPoint2F tar = thun5.getLocation();
		thun5._location = { tar.x / (float)deltaTime * 18,tar.y / (float)deltaTime * 17 };
		_toMove = thun5;
		return _toMove;
	}

};



void Scene::insertGameObject(std::unique_ptr<GameObject>& object)
{
	_gameObjects.push_back(std::move(object));

}

void Scene::Update(double deltaTime)
{
	auto gs = *_gameObjects.at(5);
	GreenSquare a{"green", gs };
	*_gameObjects.at(5) = a.move(deltaTime);
	auto ps = *_gameObjects.at(7);
	PurpleSquare b{ "one", ps };
	*_gameObjects.at(7) = b.move(deltaTime);
	auto gc = *_gameObjects.at(4);
	GreenCircle c{ "one", gc };
	*_gameObjects.at(4) = c.move(deltaTime);
	auto ps2 = *_gameObjects.at(9);
	PurpleSquare d{ "two", ps2 };
	*_gameObjects.at(9) = d.move(deltaTime);
	auto gc2 = *_gameObjects.at(2);
	GreenCircle e{ "two", gc2 };
	*_gameObjects.at(2) = e.move(deltaTime);
	auto bs = *_gameObjects.at(6);
	BlueSquare f{ "blue", bs };
	*_gameObjects.at(6) = f.move(deltaTime);
	auto ps3 = *_gameObjects.at(8);
	PurpleSquare g{ "three", ps3 };
	*_gameObjects.at(8) = g.move(deltaTime);
	auto rc = *_gameObjects.at(1);
	RedCircle h{ "red", rc };
	*_gameObjects.at(1) = h.move(deltaTime);
	auto bc = *_gameObjects.at(0);
	BlueCircle i{ "blue", bc };
	*_gameObjects.at(0) = i.move(deltaTime);
	auto pc = *_gameObjects.at(3);
	PurpleCircle j{ "purple", pc };
	*_gameObjects.at(3) = j.move(deltaTime);


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
