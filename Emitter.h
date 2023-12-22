#pragma once
#include "Novice.h"
#include "Vector2.h"

class Emitter {
public:
	Emitter(int posX,int posY,Vector2 size);
	void SetMousePos(int mousePosX, int mousePosY);
	void Update(char *keys);
	void Draw();
private:
	Vector2 pos_;
	Vector2 size_;
	int mousePosX_;
	int mousePosY_;
};

