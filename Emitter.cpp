#include "Emitter.h"

Emitter::Emitter(int posX, int posY, Vector2 size) {
	mousePosX_ = posX;
	mousePosY_ = posY;
	size_ = size;
}

void Emitter::SetMousePos(int mousePosX, int mousePosY) {
	pos_.x = (float)mousePosX;
	pos_.y = (float)mousePosY;
}

void Emitter::Update(char *keys) {
	//サイズの調整
	if (keys[DIK_UP]) {
		size_.y += 1.0f;
	}
	if (keys[DIK_DOWN]) {
		size_.y -= 1.0f;
	}
	if (keys[DIK_LEFT]) {
		size_.x -= 1.0f;
	}
	if (keys[DIK_RIGHT]) {
		size_.x += 1.0f;
	}
}

void Emitter::Draw() {
	Novice::DrawBox(
		static_cast<int>(pos_.x - (size_.x/2.0f)),
		static_cast<int>(pos_.y - (size_.y / 2.0f)),
		static_cast<int>(size_.x),
		static_cast<int>(size_.y),
		0.0f,
		0xffffffff,
		kFillModeWireFrame
	);
}
