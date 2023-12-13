#include <Novice.h>
#include "Matrix.h"
#include "Vec3.h"
#include "Quartenion.h"

const char kWindowTitle[] = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };


	Quartenion q1 = { 2.0f,3.0f,4.0f,1.0f };
	Quartenion q2 = { 1.0f,3.0f,5.0f,2.0f };

	Quartenion identity = IdentityQurtenion();
	Quartenion conj = Conjugate(q1);
	Quartenion inv = Inverse(q1);
	Quartenion normal = Normalize(q1);
	Quartenion mul1 = Multiply(q1, q2);
	Quartenion mul2 = Multiply(q2, q1);
	float norm = Norm(q1);

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		QuartenionScreenPrint(0, 0, identity, "Identity");
		QuartenionScreenPrint(0,20, conj, "Conjugate");
		QuartenionScreenPrint(0,40, inv, "Inverse");
		QuartenionScreenPrint(0, 60, normal , "Normalize");
		QuartenionScreenPrint(0,80, mul1, "Multiply(q1,q2)");
		QuartenionScreenPrint(0, 100, mul2, "Multiply(q2,q1)");
		Novice::ScreenPrintf(0, 120, "%0.2f", norm);

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
