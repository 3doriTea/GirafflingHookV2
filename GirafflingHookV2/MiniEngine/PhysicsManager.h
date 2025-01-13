#pragma once
#include "Manager.h"
#include <set>

class Rigidbody;

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

	static void Register(Rigidbody* rigidbody);
	static void Unregister(Rigidbody* rigidbody);

private:
	// MEMO: rigidbodyの単数形は1単語、複数形は2単語...
	std::set<Rigidbody*> rigidBodies_;

	static PhysicsManager* instance;
};

