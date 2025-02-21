#pragma once
//#define DIRECTINPUT_VERSION 0x0800
#include <dInput.h>
#include <DirectXMath.h>
//#include "DxLib.h"
//#include "XInput.h"
#include "KeyCode.h"
#include "ButtonCode.h"

#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dInput8.lib")
#pragma comment(lib, "Xinput.lib")


using namespace DirectX;

//-----------------------------------------------------------
//DirectInputを使ったキーボード入力処理
//-----------------------------------------------------------
namespace Input
{
	//初期化
	//引数：hWnd	ウィンドウハンドル
	void Init();

	//更新
	void Update();


	///////////////////////////　キーボード　//////////////////////////////////
	//キーが押されているか調べる
	//引数：keyCode	調べたいキーのコード
	//戻値：押されていれば true
	bool IsKey(int keyCode);
	bool IsKey(KeyCode keyCode);

	//キーを今押したか調べる（押しっぱなしは無効）
	//引数：keyCode	調べたいキーのコード
	//戻値：押した瞬間だったら true
	bool IsKeyDown(int keyCode);
	bool IsKeyDown(KeyCode keyCode);

	//キーを今放したか調べる
	//引数：keyCode	調べたいキーのコード
	//戻値：放した瞬間だったら true
	bool IsKeyUp(int keyCode);
	bool IsKeyUp(KeyCode keyCode);


	///////////////////////////　マウス　//////////////////////////////////
	//マウスのボタンが押されているか調べる
	//引数：buttonCode	調べたいボタンの番号
	//戻値：押されていれば true
	bool IsMouseButton(int buttonCode);
	bool IsMouseButton(ButtonCode buttonCode);

	//マウスのボタンを今押したか調べる（押しっぱなしは無効）
	//引数：buttonCode	調べたいボタンの番号
	//戻値：押した瞬間だったら true
	bool IsMouseButtonDown(int buttonCode);
	bool IsMouseButtonDown(ButtonCode buttonCode);

	//マウスのボタンを今放したか調べる
	//引数：buttonCode	調べたいボタンの番号
	//戻値：放した瞬間だったら true
	bool IsMouseButtonUp(int buttonCode);
	bool IsMouseButtonUp(ButtonCode buttonCode);


	//マウスカーソルの位置を取得
	//戻値：マウスカーソルの位置
	XMFLOAT3 GetMousePosition();

	//マウスカーソルの位置をセット
	//引数：マウスカーソルの位置
	void SetMousePosition(int x, int y);

	//そのフレームでのマウスの移動量を取得
	//戻値：X,Y マウスの移動量　／　Z,ホイールの回転量
	XMFLOAT3 GetMouseMove();


	///////////////////////////　コントローラー　//////////////////////////////////
	//コントローラーのボタンが押されているか調べる
	//引数：buttonCode	調べたいボタンの番号
	//戻値：押されていればtrue
	bool IsPadButton(int buttonCode, int padID = 0);

	//コントローラーのボタンを今押したか調べる（押しっぱなしは無効）
	//引数：buttonCode	調べたいボタンの番号
	//戻値：押した瞬間だったらtrue
	bool IsPadButtonDown(int buttonCode, int padID = 0);

	//コントローラーのボタンを今放したか調べる
	//引数：buttonCode	調べたいボタンの番号
	//戻値：放した瞬間だったらtrue
	bool IsPadButtonUp(int buttonCode, int padID = 0);

	//左スティックの傾きを取得
	//戻値:傾き具合（-1〜1）
	XMFLOAT3 GetPadStickL(int padID = 0);

	//右スティックの傾きを取得
	//戻値:傾き具合（-1〜1）
	XMFLOAT3 GetPadStickR(int padID = 0);

	//左トリガーの押し込み具合を取得
	//戻値:押し込み具合（0〜1）
	float		GetPadTrrigerL(int padID = 0);

	//右トリガーの押し込み具合を取得
	//戻値:押し込み具合（0〜1）
	float		GetPadTrrigerR(int padID = 0);

	//振動させる
	void SetPadVibration(int l, int r, int padID = 0);




	//開放
	void Release();
};
