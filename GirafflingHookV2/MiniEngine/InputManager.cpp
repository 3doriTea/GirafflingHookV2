#include "InputManager.h"
#include "Input.h"

InputManager::InputManager() :
	Manager::Manager(CalledType::Frame)
{
}

InputManager::~InputManager()
{
}

void InputManager::Init()
{
	Input::Init();
	////�E�B���h�E�n���h��
	//hWnd_ = GetActiveWindow();

	////DirectInput�{��
	//DirectInput8Create(
	//	GetModuleHandle(nullptr),
	//	DIRECTINPUT_VERSION,
	//	IID_IDirectInput8,
	//	(VOID**)&pDInput_,
	//	nullptr);

	////�L�[�{�[�h
	//pDInput_->CreateDevice(GUID_SysKeyboard, &pKeyDevice_, nullptr);
	//pKeyDevice_->SetDataFormat(&c_dfDIKeyboard);
	//pKeyDevice_->SetCooperativeLevel(NULL, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);

	////�}�E�X
	//pDInput_->CreateDevice(GUID_SysMouse, &pMouseDevice_, nullptr);
	//pMouseDevice_->SetDataFormat(&c_dfDIMouse);
	//pMouseDevice_->SetCooperativeLevel(hWnd_, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
}

void InputManager::Update()
{
	Input::Update();
	////�L�[�{�[�h
	//pKeyDevice_->Acquire();
	//memcpy(prevKeyState_, keyState_, sizeof(keyState_));
	//pKeyDevice_->GetDeviceState(sizeof(keyState_), &keyState_);

	////�}�E�X
	//pMouseDevice_->Acquire();
	//memcpy(&prevMouseState_, &mouseState_, sizeof(mouseState_));
	//pMouseDevice_->GetDeviceState(sizeof(mouseState_), &mouseState_);
}

void InputManager::End()
{
	Input::Release();
}
