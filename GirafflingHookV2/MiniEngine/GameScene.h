#pragma once
#include <string>
#include <vector>
#include <list>
#include <set>

class GameObject;

/// <summary>
/// ゲームシーンの基底クラス
/// </summary>
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

	/// <summary>
	/// シーンにゲームオブジェクトを追加する
	/// </summary>
	/// <typeparam name="GameObjectT">ゲームオブジェクトの型</typeparam>
	/// <typeparam name="...Args">コンストラクタに渡す可変長引数型</typeparam>
	/// <param name="...args">コンストラクタに渡す可変長引数</param>
	/// <returns>追加されたゲームオブジェクトの参照</returns>
	template<typename GameObjectT, typename...Args>
	GameObjectT& AddGameObject(Args... args)
	{
		GameObjectT* gameObject{ new GameObjectT{ args... } };
		RegisterGameObject(gameObject);
		uninitialisedGameObjects_.insert(gameObject);

		return *gameObject;
	}
	/// <summary>
	/// シーンにゲームオブジェクトを追加する
	/// </summary>
	/// <typeparam name="GameObjectT">ゲームオブジェクトの型</typeparam>
	/// <returns>追加されたゲームオブジェクトの参照</returns>
	template<typename GameObjectT>
	GameObjectT& AddGameObject()
	{
		GameObjectT* gameObject{ new GameObjectT{} };
		RegisterGameObject(gameObject);
		uninitialisedGameObjects_.insert(gameObject);

		return *gameObject;
	}
	/// <summary>
	/// シーンのゲームオブジェクトを除去する
	/// </summary>
	/// <param name="">指定するゲームオブジェクトのポインタ</param>
	void RemoveGameObject(GameObject*);
	/// <summary>
	///   <para> シーンからゲームオブジェクトを探す </para>
	///   <para> NOTE: ゲームオブジェクトが複数ある場合、最初に見つかったゲームオブジェクトが返される </para>
	/// </summary>
	/// <typeparam name="GameObjectT">探すゲームオブジェクトの型</typeparam>
	/// <returns>見つかったゲームオブジェクトのポインタ / 見つからなかった nullptr</returns>
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
	/// <summary>
	/// シーンからゲームオブジェクトを複数探す
	/// </summary>
	/// <typeparam name="GameObjectT">探すゲームオブジェクトの型</typeparam>
	/// <returns>
	///   <para> 見つかったゲームオブジェクトの参照が格納されたvector </para>
	///   <para> MEMO: 記述が長いため、戻り値を受け取るときの型はautoで問題ない </para>
	/// </returns>
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
	/// <summary>
	///   <para> シーンからゲームオブジェクトを探す </para>
	///   <para> NOTE: ゲームオブジェクトが複数ある場合、最初に見つかったゲームオブジェクトが返される </para>
	/// </summary>
	/// <param name="name">探すゲームオブジェクトの名前</param>
	/// <returns>見つかったゲームオブジェクトのポインタ / 見つからなかった nullptr</returns>
	GameObject* FindGameObject(const std::string& name);
	/// <summary>
	/// シーンからゲームオブジェクトを複数探す
	/// </summary>
	/// <param name="tag">探すゲームオブジェクトのタグ</param>
	/// <returns>
	///   <para> 見つかったゲームオブジェクトのポインタが格納されたvector </para>
	///   <para> NOTE: 派生クラスの特定ができないため、基底クラスのポインタが入っている </para>
	///   <para> NOTE: 特定する場合はテンプレート付きの方を使って </para>
	///   <para> MEMO: 記述が長いため、戻り値を受け取るときの型はautoで問題ない </para>
	/// </returns>
	std::vector<GameObject*> FindGameObjects(const std::string& tag);

protected:
	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() const {};
	virtual void End() {};

private:
	void RegisterGameObject(GameObject* gameObject);

private:
	std::list<GameObject*> gameObjects_;
	std::set<const GameObject*> uninitialisedGameObjects_;
};
