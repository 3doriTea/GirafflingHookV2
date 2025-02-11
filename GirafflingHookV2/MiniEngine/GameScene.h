#pragma once
#include <string>
#include <vector>
#include <list>
#include <set>

class GameObject;

/// <summary>
/// �Q�[���V�[���̊��N���X
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
	/// �V�[���ɃQ�[���I�u�W�F�N�g��ǉ�����
	/// </summary>
	/// <typeparam name="GameObjectT">�Q�[���I�u�W�F�N�g�̌^</typeparam>
	/// <typeparam name="...Args">�R���X�g���N�^�ɓn���ϒ������^</typeparam>
	/// <param name="...args">�R���X�g���N�^�ɓn���ϒ�����</param>
	/// <returns>�ǉ����ꂽ�Q�[���I�u�W�F�N�g�̎Q��</returns>
	template<typename GameObjectT, typename...Args>
	GameObjectT& AddGameObject(Args... args)
	{
		GameObjectT* gameObject{ new GameObjectT{ args... } };
		RegisterGameObject(gameObject);
		uninitialisedGameObjects_.insert(gameObject);

		return *gameObject;
	}
	/// <summary>
	/// �V�[���ɃQ�[���I�u�W�F�N�g��ǉ�����
	/// </summary>
	/// <typeparam name="GameObjectT">�Q�[���I�u�W�F�N�g�̌^</typeparam>
	/// <returns>�ǉ����ꂽ�Q�[���I�u�W�F�N�g�̎Q��</returns>
	template<typename GameObjectT>
	GameObjectT& AddGameObject()
	{
		GameObjectT* gameObject{ new GameObjectT{} };
		RegisterGameObject(gameObject);
		uninitialisedGameObjects_.insert(gameObject);

		return *gameObject;
	}
	/// <summary>
	/// �V�[���̃Q�[���I�u�W�F�N�g����������
	/// </summary>
	/// <param name="">�w�肷��Q�[���I�u�W�F�N�g�̃|�C���^</param>
	void RemoveGameObject(GameObject*);
	/// <summary>
	///   <para> �V�[������Q�[���I�u�W�F�N�g��T�� </para>
	///   <para> NOTE: �Q�[���I�u�W�F�N�g����������ꍇ�A�ŏ��Ɍ��������Q�[���I�u�W�F�N�g���Ԃ���� </para>
	/// </summary>
	/// <typeparam name="GameObjectT">�T���Q�[���I�u�W�F�N�g�̌^</typeparam>
	/// <returns>���������Q�[���I�u�W�F�N�g�̃|�C���^ / ������Ȃ����� nullptr</returns>
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
	/// �V�[������Q�[���I�u�W�F�N�g�𕡐��T��
	/// </summary>
	/// <typeparam name="GameObjectT">�T���Q�[���I�u�W�F�N�g�̌^</typeparam>
	/// <returns>
	///   <para> ���������Q�[���I�u�W�F�N�g�̎Q�Ƃ��i�[���ꂽvector </para>
	///   <para> MEMO: �L�q���������߁A�߂�l���󂯎��Ƃ��̌^��auto�Ŗ��Ȃ� </para>
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
	///   <para> �V�[������Q�[���I�u�W�F�N�g��T�� </para>
	///   <para> NOTE: �Q�[���I�u�W�F�N�g����������ꍇ�A�ŏ��Ɍ��������Q�[���I�u�W�F�N�g���Ԃ���� </para>
	/// </summary>
	/// <param name="name">�T���Q�[���I�u�W�F�N�g�̖��O</param>
	/// <returns>���������Q�[���I�u�W�F�N�g�̃|�C���^ / ������Ȃ����� nullptr</returns>
	GameObject* FindGameObject(const std::string& name);
	/// <summary>
	/// �V�[������Q�[���I�u�W�F�N�g�𕡐��T��
	/// </summary>
	/// <param name="tag">�T���Q�[���I�u�W�F�N�g�̃^�O</param>
	/// <returns>
	///   <para> ���������Q�[���I�u�W�F�N�g�̃|�C���^���i�[���ꂽvector </para>
	///   <para> NOTE: �h���N���X�̓��肪�ł��Ȃ����߁A���N���X�̃|�C���^�������Ă��� </para>
	///   <para> NOTE: ���肷��ꍇ�̓e���v���[�g�t���̕����g���� </para>
	///   <para> MEMO: �L�q���������߁A�߂�l���󂯎��Ƃ��̌^��auto�Ŗ��Ȃ� </para>
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
