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

	static void RegisterRigidbody(Rigidbody* rigidbody, const bool& isDynamic);
	static void UnregisterRigidbody(Rigidbody* rigidbody);

	static void RegisterCollider(Collider* collider);
	static void UnregisterCollider(Collider* collider);
private:
	// MEMO: rigidbodyの単数形は1単語、複数形は2単語...
	std::set<Rigidbody*> rigidBodies_;  // 全剛体
	std::set<Rigidbody*> dynamicRigidBodies_;  // 動く剛体
	std::set<Collider*> colliders_;

	static PhysicsManager* instance;
};

