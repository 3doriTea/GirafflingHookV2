#include "GameObject.h"
#include "Attachment.h"
#include "SceneManager.h"

GameObject::GameObject() :
	GameObject::GameObject{ "" }
{
}

GameObject::GameObject(
	const std::string& name) :
	GameObject::GameObject{ name, "" }
{
}

GameObject::GameObject(
	const std::string& name,
	const std::string& tag) :
	GameObject::GameObject{ name, tag, { 0.f, 0.f } }
{
}

GameObject::GameObject(
	const std::string& name,
	const std::string& tag,
	const Vector2& position) :
	name{ name },
	tag{ tag },
	position{ position },
	gameScene_{ SceneManager::RefActiveGameScene() },
	toDestroy_{}
{
}

GameObject::~GameObject()
{
}

void GameObject::Destroy()
{
	toDestroy_ = true;
}

std::string GameObject::ToString()
{
	return "{" + name + "}";
}
