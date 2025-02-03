#pragma once
#include <string>
#include <cassert>
#include "Entity.h"
#include "GameScene.h"
#include "WorldModeVector.h"
#include "GameObjectBuilder.h"

class Attachment;

class GameObject : public Entity
{
	friend Attachment;

public:
	GameObject();
	GameObject(const GameObjectBuilder& builder);
	GameObject(
		const std::string& name);
	GameObject(
		const std::string& name,
		const std::string& tag);
	GameObject(
		const std::string& name,
		const std::string& tag,
		const WorldModeVector& position);
	virtual ~GameObject();

	virtual void Init() {};
	virtual void Update() {};
	virtual void Draw() const {};
	virtual void End() {};

	void Destroy();

	std::string GetName() const { return name; }
	std::string GetTag() const { return tag; }
	std::string SetTag(const std::string& _tag) { tag = _tag; }
	GameScene& GetGameScene() const { return gameScene_; }
	template<typename GameSceneT>
	GameSceneT& GetGameScene() const
	{
		GameSceneT* casted{ static_cast<GameSceneT*>(&gameScene_) };
		assert(casted != nullptr);  // 正しく特定のシーンにキャストできている
		return *casted;
	}

	std::string ToString() override;

protected:
	/// <summary>
	/// 所属シーンにゲームオブジェクトをインスタンスする
	/// </summary>
	/// <typeparam name="GameObjectT">ゲームオブジェクトのクラス</typeparam>
	/// <typeparam name="...Args">コンストラクタ引数(可変長)</typeparam>
	/// <returns>インスタンスされたゲームオブジェクトの参照</returns>
	template<typename GameObjectT, typename ...Args>
	GameObjectT& Instantiate(Args... args)
	{
		return GetGameScene().AddGameObject<GameObjectT>(args...);
	}
	/// <summary>
	/// 所属シーンからゲームオブジェクトをただ１つ取得
	/// </summary>
	/// <typeparam name="GameObjectT">ゲームオブジェクトのクラス</typeparam>
	/// <returns>見つかったゲームオブジェクトのポインタ / 見つからなかった nullptr</returns>
	template<typename GameObjectT>
	GameObjectT* FindGameObject()
	{
		return GetGameScene().FindGameObject<GameObjectT>();
	}
	/// <summary>
	/// 所属シーンからゲームオブジェクトを複数取得
	/// </summary>
	/// <typeparam name="GameObjectT">ゲームオブジェクトのクラス</typeparam>
	/// <returns>見つかったゲームオブジェクトの参照配列</returns>
	template<typename GameObjectT>
	std::vector<GameObjectT&> FindGameObjects()
	{
		return GetGameScene().FindGameObjects<GameObjectT>();
	}
	/// <summary>
	/// 所属シーンからゲームオブジェクトをただ１つ取得
	/// </summary>
	/// <param name="name">ゲームオブジェクト名</param>
	/// <returns>見つかったゲームオブジェクトのポインタ / 見つからなかった nullptr</returns>
	GameObject* FindGameObject(const std::string& name);
	/// <summary>
	/// 所属シーンからゲームオブジェクトを複数取得
	/// </summary>
	/// <param name="tag">ゲームオブジェクトタグ</param>
	/// <returns>見つかったゲームオブジェクトのポインタ配列</returns>
	std::vector<GameObject*> FindGameObjects(const std::string& tag);
	
public:
	Vector3 position;
	Vector3 rotate;
	Vector3 scale;

private:
	// MEMO: メモリレイアウト的にここに配置
	bool toDestroy_;

protected:
	std::string name;
	std::string tag;

private:
	GameScene& gameScene_;
};
