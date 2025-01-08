#pragma once
#include "Manager.h"

//#define DIRECTINPUT_VERSION 0x0800
//#pragma comment(lib, "dxguid.lib")
//#pragma comment(lib, "dInput8.lib")

class InputManager : public Manager
{
public:
	InputManager();
	~InputManager();

	void Init() override;
	void Update() override;
	void End() override;

private:
	//HWND hWnd_;

	//LPDIRECTINPUT8  pDInput_;

	//LPDIRECTINPUTDEVICE8 pKeyDevice_;  //デバイスオブジェクト
	//BYTE keyState_[256];  //現在の各キーの状態
	//BYTE prevKeyState_[256];  //前フレームでの各キーの状態

	//LPDIRECTINPUTDEVICE8 pMouseDevice_;  //デバイスオブジェクト
	//DIMOUSESTATE mouseState_;  //マウスの状態
	//DIMOUSESTATE prevMouseState_;  //前フレームのマウスの状態
	//POINT mousePos_;  //マウスカーソルの位置
};
