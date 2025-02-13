#include "ScoreObject.h"
#include <DxLib.h>
#include "Player.h"
#include <cassert>
#include "../PlayScene.h"
#include "GiraffePointRoot.h"
#include <imgui.h>

namespace
{
	static const float GET_DISTANCE{ 300.0f };  // ���a3m
}

Play::ScoreObject::ScoreObject(
	const std::string& name,
	const Vector3& position) :
	GameObject::GameObject
	{
		GameObjectBuilder{}
			.Name(name)
			.Position(position)
			.Scale({ 100.0f, 100.0f, 100.0f })
	},
	hAppleModel_{ -1 },
	player_{ nullptr }
{
	transform_.SetParent(GiraffePointRoot::GetGroundTransform());
}

Play::ScoreObject::~ScoreObject()
{
}

void Play::ScoreObject::Init()
{
	hAppleModel_ = MV1DuplicateModel(GiraffePointRoot::GethAppleModelSourceHandle());
	assert(hAppleModel_ != -1);  // ���f���̃f���v���P�[�g�͂ł���
	player_ = FindGameObject<Player>();
	assert(player_ != nullptr);  // �v���C���[�͌�����
}

void Play::ScoreObject::Update()
{
	if (Vector3::Distance(GetWorldPosition(), player_->GetWorldPosition()) < GET_DISTANCE)
	{
		GetGameScene<PlayScene>().AddScore(10);

		static int count{ 0 };
		
		ImGui::Begin("score object");
		ImGui::InputInt("count", &count);
		ImGui::End();

		//printfDx("%s] Destory!!", name.c_str());
		count++;
		Destroy();
	}

	MV1SetPosition(
		hAppleModel_,
		transform_.ToWorldPosition({ 0.f, 0.f, 0.f })
		+ Vector3{ 0.f, -150.f, 0.f });
	MV1SetRotationXYZ(hAppleModel_, transform_.GetRotateRadian());
	MV1SetScale(hAppleModel_, scale * 0.01f);
}

void Play::ScoreObject::Draw() const
{
	MV1DrawModel(hAppleModel_);
}

void Play::ScoreObject::End()
{
	DeleteGraph(hAppleModel_);
}
