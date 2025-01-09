#pragma once
#include <string>
#include "Entity.h"
#include "Vector3.h"
#include "Vector2.h"

class GameScene;
class Attachment;

class GameObject : public Entity
{
	friend Attachment;

public:
	GameObject();
	GameObject(
		const std::string& name);
	GameObject(
		const std::string& name,
		const std::string& tag);
	GameObject(
		const std::string& name,
		const std::string& tag,
		const Vector2& position);
	virtual ~GameObject();

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() const {};
	virtual void End() {};

	void Destroy();

	std::string GetName() { return name; }
	std::string GetTag() { return tag; }
	std::string SetTag(const std::string& _tag) { tag = _tag; }
	GameScene& GetGameScene() { return gameScene_; }

	std::string ToString() override;

protected:
	std::string name;
	std::string tag;
	Vector2 position;

private:
	GameScene& gameScene_;
	bool toDestroy_;
};
