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

	/// <summary>
	/// ���W�b�h�{�f�B��o�^����
	/// </summary>
	/// <param name="rigidbody">�o�^���郊�W�b�h�{�f�B�̃|�C���^</param>
	/// <param name="isDynamic">���I�ȁA�����I�ȃ��W�b�h�{�f�B�ł��邩 true / false</param>
	static void RegisterRigidbody(Rigidbody* rigidbody, const bool& isDynamic);
	/// <summary>
	/// ���W�b�h�{�f�B�̓o�^��������
	/// </summary>
	/// <param name="rigidbody">�������郊�W�b�h�{�f�B�̃|�C���^</param>
	static void UnregisterRigidbody(Rigidbody* rigidbody);

	/// <summary>
	/// �R���C�_��o�^����
	/// </summary>
	/// <param name="collider">�o�^����R���C�_�̃|�C���^</param>
	static void RegisterCollider(Collider* collider);
	/// <summary>
	/// �R���C�_�̓o�^��������
	/// </summary>
	/// <param name="collider">��������R���C�_�̃|�C���^</param>
	static void UnregisterCollider(Collider* collider);
private:
	// MEMO: rigidbody�̒P���`��1�P��A�����`��2�P��...
	std::set<Rigidbody*> rigidBodies_;  // �S����
	std::set<Rigidbody*> dynamicRigidBodies_;  // ��������
	std::set<Collider*> colliders_;  // �����蔻��

	static PhysicsManager* instance;
};

