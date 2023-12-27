#pragma once
#include "Novice.h"
#include "Vector2.h"

class Emitter {
public:
	Emitter(int posX,int posY,Vector2 size);

	float GetPosX() { return pos_.x; };
	float GetPosY() { return pos_.y; };
	float GetSizeX() { return size_.x; };
	float GetSizeY() { return size_.y; };

	void SetMousePos(int mousePosX, int mousePosY);
	void Update(char *keys);
	void Draw();
private:
	Vector2 pos_;
	Vector2 size_;
	int mousePosX_;
	int mousePosY_;
};

