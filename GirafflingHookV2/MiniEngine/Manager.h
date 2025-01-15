#pragma once
#include <list>
#include <set>

/// <summary>
/// �X�V����^�C�~���O�̎��
/// </summary>
enum struct CalledType
{
	Cycle,  // 1�Q�[���T�C�N��(���̂���������)
	Frame,  // 1�t���[��(60fps�Ȃ�1�b�Ԃ�60��)
};

class Manager
{
public:
	Manager(const CalledType&);
	~Manager();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	/// <summary>
	/// 1�t���[���̍X�V����
	/// </summary>
	static void UpdateFrame();
	/// <summary>
	/// 1�T�C�N���̍X�V����
	/// </summary>
	static void UpdateCycle();
	/// <summary>
	/// ���ׂĂ̓��I�������m�ۂ���������
	/// </summary>
	static void ReleaseAll();

protected:
	/// <summary>
	/// �X�V���Ԃ����肢����
	/// </summary>
	/// <param name="">�X�V���ԒႢ�قǏ��Ԃ�����</param>
	void SetOrder(const int&);

private:
	int order_;
	CalledType calledType_;

	static std::list<Manager*> managers_;
	static std::set<const Manager*> uninitialisedManagers_;
};
