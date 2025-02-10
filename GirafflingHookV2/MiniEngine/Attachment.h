#pragma once
#include "WorldModeVector.h"

class GameObject;

/// <summary>
/// ゲームオブジェクトに付ける系の基底クラス
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
