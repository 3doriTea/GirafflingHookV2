#pragma once
#include "Vector2.h"

class GameObject;

class Attachment
{
public:
	Attachment(GameObject& gameObject);
	virtual ~Attachment();

protected:
	GameObject& gameObject;
	Vector2& position;
};
