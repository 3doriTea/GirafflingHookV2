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
	/// <summary>
	/// ���̃Q�[���I�u�W�F�N�g�͍폜�\�肩
	/// </summary>
	/// <returns>�폜�\�� true / false</returns>
	inline bool IsToDestory() const { return toDestroy_; }

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
	inline short GetLayerOrder() const { return layerOrder_; }
	/// <summary>
	/// ���̃Q�[���I�u�W�F�N�g���A�N�e�B�u�ǂ���
	/// </summary>
	/// <returns>�A�N�e�B�u�ł��� true / false</returns>
	inline bool GetIsActive() const { return isActive_; }
	inline void SetIsActive(const bool& _isActive) { isActive_ = _isActive; }

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
	Vector3 position;  // ���[���h���W
	Vector3 rotate;  // ���[���h��]
	Vector3 scale;  // ���[���h�X�P�[��

private:
	// MEMO: ���������C�A�E�g�I�ɂ����ɔz�u

	bool toDestroy_;  // ���̃Q�[���I�u�W�F�N�g�͍폜�\�肩
	bool isActive_;  // ���̃Q�[���I�u�W�F�N�g���L����
	
	// MEMO: ���������C�A�E�g�̓s����short�^
	short layerOrder_;  // �X�V�E�`��̏��ԗv��

protected:
	std::string name;  // ���O (�P��̌����Ɏg��)
	std::string tag;  // �^�O (�����܂Ƃ߂Ă̌����Ɏg��)

private:
	GameScene& gameScene_;  // ��������Q�[���V�[���̎Q��
};
