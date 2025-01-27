#pragma once
#include "Manager.h"
#include <set>

class Rigidbody;
class Collider;

/// <summary>
/// 物理の管理クラス
/// </summary>
class PhysicsManager : public Manager
{
public:
	PhysicsManager();
	~PhysicsManager();

	void Init() override;
	void Update() override;
	void End() override;

	/// <summary>
	/// リジッドボディを登録する
	/// </summary>
	/// <param name="rigidbody">登録するリジッドボディのポインタ</param>
	/// <param name="isDynamic">動的な、自発的なリジッドボディであるか true / false</param>
	static void RegisterRigidbody(Rigidbody* rigidbody, const bool& isDynamic);
	/// <summary>
	/// リジッドボディの登録解除する
	/// </summary>
	/// <param name="rigidbody">解除するリジッドボディのポインタ</param>
	static void UnregisterRigidbody(Rigidbody* rigidbody);

	/// <summary>
	/// コライダを登録する
	/// </summary>
	/// <param name="collider">登録するコライダのポインタ</param>
	static void RegisterCollider(Collider* collider);
	/// <summary>
	/// コライダの登録解除する
	/// </summary>
	/// <param name="collider">解除するコライダのポインタ</param>
	static void UnregisterCollider(Collider* collider);
private:
	// MEMO: rigidbodyの単数形は1単語、複数形は2単語...
	std::set<Rigidbody*> rigidBodies_;  // 全剛体
	std::set<Rigidbody*> dynamicRigidBodies_;  // 動く剛体
	std::set<Collider*> colliders_;  // 当たり判定

	static PhysicsManager* instance;
};

