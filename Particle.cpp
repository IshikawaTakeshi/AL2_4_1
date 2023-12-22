#include "Particle.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <stdlib.h>

Particle::Particle(Vector2 pos, Vector2 size, float gravity, bool isAlive) {
	pos_ = pos;
	size_ = size;
	gravity_ = gravity;
	isAlive_ = isAlive;
}

void Particle::Update() {
	if (isAlive_ == false) {
		isAlive_ = true;
	}
	if (isAlive_ == true) {
		pos_.x = pos_
	}
}
