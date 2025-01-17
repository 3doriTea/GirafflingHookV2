#pragma once
#include "Manager.h"
#include <set>

class Rigidbody;
class Collider;

/// <summary>
/// �����̊Ǘ��N���X
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
	// MEMO: rigidbody�̒P���`��1�P��A�����`��2�P��...
	std::set<Rigidbody*> rigidBodies_;  // �S����
	std::set<Rigidbody*> dynamicRigidBodies_;  // ��������
	std::set<Collider*> colliders_;

	static PhysicsManager* instance;
};

