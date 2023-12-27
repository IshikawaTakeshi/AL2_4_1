#pragma once
#include "Vector2.h"
#include "Emitter.h"

class Particle {
public:
	Particle(Vector2 pos,Vector2 size,float gravity, bool isAlive);

	bool GetIsAlive() { return isAlive_; };
	void SetIsAlive(bool isAlive);
	void Update(Emitter emitter);
	void Draw();

private:
	Vector2 pos_;
	Vector2 size_;
	float velosityY_;
	float gravity_;
	bool isAlive_ = false;
};

