#include <Novice.h>
#include "Emitter.h"
#include "Particle.h"

const char kWindowTitle[] = "AL2_02_イシカワタケシ_AL2_4_1_確認課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Emitter* emitter = new Emitter(0, 0, { 400,200 });
	int mousePosX = 0;
	int mousePosY = 0;

	Particle* particle[200];
	for (int i = 0; i < 200; i++) {
		particle[i] = new Particle({ 0,0 }, { 10,10 }, 0.1f, false);
	}

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
		Novice::GetMousePosition(&mousePosX, &mousePosY);

		///
		/// ↓更新処理ここから
		///

		emitter->SetMousePos(mousePosX, mousePosY);
		emitter->Update(keys);
		for (int i = 0; i < 200; i++) {	
			if (particle[i]->GetIsAlive() == false) {
				particle[i]->Spawn(*emitter);
				break;
			}	
		}

		for (int i = 0; i < 200; i++) {
			particle[i]->Update();
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0x000000ff, kFillModeSolid);
		Novice::DrawLine(640, 0, 640, 720, 0xffffffff);
		Novice::DrawLine(0, 360, 1280, 360, 0xffffffff);

		emitter->Draw();

		for (int i = 0; i < 200; i++) {
			particle[i]->Draw();
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
