#pragma once
#include "Vector2.h"

class Particle {
public:
	Particle(Vector2 pos,Vector2 size,float gravity, bool isAlive);
	void Update();
	void Draw();

private:
	Vector2 pos_;
	Vector2 size_;
	float gravity_;
	bool isAlive_ = false;
};

