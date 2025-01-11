#include "GameObject.h"
#include "Attachment.h"
#include "SceneManager.h"

GameObject::GameObject() :
	GameObject::GameObject{ "" }
{
}

GameObject::GameObject(const GameObjectBuilder& builder) :
	position{ builder.position },
	rotate{ builder.rotate },
	scale{ builder.scale },
	name{ builder.name },
	tag{ builder.tag },
	gameScene_{ SceneManager::RefActiveGameScene() },
	toDestroy_{ false }
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
	GameObject::GameObject{ name, tag, WorldModeVector{} }
{
}

GameObject::GameObject(
	const std::string& name,
	const std::string& tag,
	const WorldModeVector& position) :
	name{ name },
	tag{ tag },
	position{ position },
	rotate{ Vector3::Zero() },
	scale{ Vector3::One() },
	gameScene_{ SceneManager::RefActiveGameScene() },
	toDestroy_{ false }
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

GameObject* GameObject::FindGameObject(const std::string& name)
{
	return GetGameScene().FindGameObject(name);
}

std::vector<GameObject*> GameObject::FindGameObjects(const std::string& tag)
{
	return FindGameObjects(tag);
}
