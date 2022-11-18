#include <Novice.h>
#include "Player.h"

const char *kWindowTitle = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Object player{
		{ 0,0 },
		{ 50,50 },
		10.0f,
		true,
	};
	// キー入力結果を受け取る箱
	char keys[256];
	char preKeys[256];

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		PlayerMove(&player, keys);
		MoveLimit(&player);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		PlayerDraw(&player);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (keys[DIK_ESCAPE] && !preKeys[DIK_ESCAPE]) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
