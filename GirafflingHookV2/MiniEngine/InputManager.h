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

	//LPDIRECTINPUTDEVICE8 pKeyDevice_;  //�f�o�C�X�I�u�W�F�N�g
	//BYTE keyState_[256];  //���݂̊e�L�[�̏��
	//BYTE prevKeyState_[256];  //�O�t���[���ł̊e�L�[�̏��

	//LPDIRECTINPUTDEVICE8 pMouseDevice_;  //�f�o�C�X�I�u�W�F�N�g
	//DIMOUSESTATE mouseState_;  //�}�E�X�̏��
	//DIMOUSESTATE prevMouseState_;  //�O�t���[���̃}�E�X�̏��
	//POINT mousePos_;  //�}�E�X�J�[�\���̈ʒu
};
