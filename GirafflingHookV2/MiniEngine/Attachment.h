#pragma once
#include "WorldModeVector.h"

class GameObject;

class Attachment
{
public:
	Attachment(GameObject& attachingGameObject);
	virtual ~Attachment();

	virtual void Draw() const = 0;

protected:
	GameObject& gameObject;
};
