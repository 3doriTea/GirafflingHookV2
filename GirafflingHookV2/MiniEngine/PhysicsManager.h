#pragma once
#include "Manager.h"
#include <set>

class Rigidbody;

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

	static void Register(Rigidbody* rigidbody);
	static void Unregister(Rigidbody* rigidbody);

private:
	// MEMO: rigidbody�̒P���`��1�P��A�����`��2�P��...
	std::set<Rigidbody*> rigidBodies_;

	static PhysicsManager* instance;
};

