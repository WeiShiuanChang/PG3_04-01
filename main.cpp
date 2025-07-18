#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "GC2B_06_チョウ_イ_セン_PG3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	const Vector2 windowSize = { 1280, 720 };

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, static_cast<int>(windowSize.x), static_cast<int>(windowSize.y));

	GameManager* gameManager = new GameManager();

	gameManager->Run();

	delete gameManager;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

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
