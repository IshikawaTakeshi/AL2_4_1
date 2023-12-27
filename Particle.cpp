#include "Particle.h"
#include "Novice.h"
#define _USE_MATH_DEFINES
#include <stdlib.h>

Particle::Particle(Vector2 pos, Vector2 size, float gravity, bool isAlive) {
	pos_ = pos;
	size_ = size;
	velosityY_ = 0;
	gravity_ = gravity;
	isAlive_ = isAlive;
}

void Particle::Spawn(Emitter emitter) {
	if (isAlive_ == false) {
		//座標の初期化
		pos_.x = (emitter.GetPosX() - (size_.x / 2.0f))
			+ (rand() % (int)emitter.GetSizeX() - (int)emitter.GetSizeX() / 2);
		pos_.y = (emitter.GetPosY() - (size_.y / 2.0f))
			+ (rand() % (int)emitter.GetSizeY() - (int)emitter.GetSizeY() / 2);
		velosityY_ = 0;
		//フラグをtrueに
		isAlive_ = true;
	}
}

void Particle::Update() {
	if (isAlive_ == true) {
		//落下の計算
		velosityY_ += gravity_;
		pos_.y += velosityY_;

		if (pos_.x >= 1280 || pos_.x <= 0 || pos_.y >= 740.0f) {
			//画面外に出たときフラグをfalseに
			isAlive_ = false;
		}
	}
}

void Particle::Draw() {
	if (isAlive_ == true) {
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(size_.x),
			static_cast<int>(size_.y),
			0.0f,
			0xffffffff,
			kFillModeSolid
		);
	}

}
