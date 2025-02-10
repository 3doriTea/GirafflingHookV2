#pragma once
#include "WorldModeVector.h"

class GameObject;

/// <summary>
/// �Q�[���I�u�W�F�N�g�ɕt����n�̊��N���X
/// </summary>
class Attachment
{
public:
	Attachment(GameObject& attachingGameObject);
	virtual ~Attachment();

	virtual void Draw() const = 0;

protected:
	GameObject& gameObject;
};
