#pragma once
#include <string>
#include <vector>
#include <list>
#include <set>

class GameObject;

class GameScene
{
	friend GameObject;

public:
	GameScene();
	~GameScene();

	void InitScene();
	void UpdateScene();
	void DrawScene();
	void EndScene();

	template<typename GameObjectT, typename...Args>
	GameObjectT& AddGameObject(Args... args)
	{
		GameObjectT* gameObject{ new GameObjectT{ args... } };
		gameObjects_.push_back(gameObject);
		uninitialisedGameObjects_.insert(gameObject);

		return *gameObject;
	}
	template<typename GameObjectT>
	GameObjectT& AddGameObject()
	{
		GameObjectT* gameObject{ new GameObjectT{} };
		gameObjects_.push_back(gameObject);
		uninitialisedGameObjects_.insert(gameObject);

		return *gameObject;
	}
	void RemoveGameObject(GameObject*);
	template<typename GameObjectT>
	GameObjectT* FindGameObject()
	{
		for (auto&& gameObject : gameObjects_)
		{
			GameObjectT* casted{ dynamic_cast<GameObjectT*>(gameObject) };
			if (casted != nullptr)
			{
				return casted;
			}
		}

		return nullptr;
	}
	template<typename GameObjectT>
	std::vector<GameObjectT&> FindGameObjects()
	{
		std::vector<GameObjectT&> foundGameObjects{};
		for (auto&& gameObject : gameObjects_)
		{
			GameObjectT* casted{ dynamic_cast<GameObjectT*>(gameObject) };
			if (casted != nullptr)
			{
				foundGameObjects.push_back(*casted);
			}
		}

		return foundGameObjects;
	}
	GameObject* FindGameObject(const std::string& name);
	std::vector<GameObject*> FindGameObjects(const std::string& tag);

protected:
	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() const {};
	virtual void End() {};

private:
	std::list<GameObject*> gameObjects_;
	std::set<const GameObject*> uninitialisedGameObjects_;
};
