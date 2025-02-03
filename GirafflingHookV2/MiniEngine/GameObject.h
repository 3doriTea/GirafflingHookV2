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
		assert(casted != nullptr);  // ����������̃V�[���ɃL���X�g�ł��Ă���
		return *casted;
	}

	std::string ToString() override;

protected:
	/// <summary>
	/// �����V�[���ɃQ�[���I�u�W�F�N�g���C���X�^���X����
	/// </summary>
	/// <typeparam name="GameObjectT">�Q�[���I�u�W�F�N�g�̃N���X</typeparam>
	/// <typeparam name="...Args">�R���X�g���N�^����(�ϒ�)</typeparam>
	/// <returns>�C���X�^���X���ꂽ�Q�[���I�u�W�F�N�g�̎Q��</returns>
	template<typename GameObjectT, typename ...Args>
	GameObjectT& Instantiate(Args... args)
	{
		return GetGameScene().AddGameObject<GameObjectT>(args...);
	}
	/// <summary>
	/// �����V�[������Q�[���I�u�W�F�N�g�������P�擾
	/// </summary>
	/// <typeparam name="GameObjectT">�Q�[���I�u�W�F�N�g�̃N���X</typeparam>
	/// <returns>���������Q�[���I�u�W�F�N�g�̃|�C���^ / ������Ȃ����� nullptr</returns>
	template<typename GameObjectT>
	GameObjectT* FindGameObject()
	{
		return GetGameScene().FindGameObject<GameObjectT>();
	}
	/// <summary>
	/// �����V�[������Q�[���I�u�W�F�N�g�𕡐��擾
	/// </summary>
	/// <typeparam name="GameObjectT">�Q�[���I�u�W�F�N�g�̃N���X</typeparam>
	/// <returns>���������Q�[���I�u�W�F�N�g�̎Q�Ɣz��</returns>
	template<typename GameObjectT>
	std::vector<GameObjectT&> FindGameObjects()
	{
		return GetGameScene().FindGameObjects<GameObjectT>();
	}
	/// <summary>
	/// �����V�[������Q�[���I�u�W�F�N�g�������P�擾
	/// </summary>
	/// <param name="name">�Q�[���I�u�W�F�N�g��</param>
	/// <returns>���������Q�[���I�u�W�F�N�g�̃|�C���^ / ������Ȃ����� nullptr</returns>
	GameObject* FindGameObject(const std::string& name);
	/// <summary>
	/// �����V�[������Q�[���I�u�W�F�N�g�𕡐��擾
	/// </summary>
	/// <param name="tag">�Q�[���I�u�W�F�N�g�^�O</param>
	/// <returns>���������Q�[���I�u�W�F�N�g�̃|�C���^�z��</returns>
	std::vector<GameObject*> FindGameObjects(const std::string& tag);
	
public:
	Vector3 position;
	Vector3 rotate;
	Vector3 scale;

private:
	// MEMO: ���������C�A�E�g�I�ɂ����ɔz�u
	bool toDestroy_;

protected:
	std::string name;
	std::string tag;

private:
	GameScene& gameScene_;
};
