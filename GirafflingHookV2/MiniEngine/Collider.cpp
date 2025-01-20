#include "Collider.h"
#include "Vector3.h"
#include <cfloat>
#include <DirectXMath.h>
#include <cmath>
#include <DxLib.h>
#include "AABBCollider.h"
#include "GameObject.h"
#include "PhysicsManager.h"

Collider::Collider(const GameObject& _gameObject) :
	gameObject{ _gameObject }
{
	PhysicsManager::RegisterCollider(this);
}

Collider::~Collider()
{
	PhysicsManager::UnregisterCollider(this);
}

bool Collider::IsHit_AABB2AABB(const AABBCollider& a, const AABBCollider& b) const
{
	Vector3 abDistance
	{
		(a.transform_.ToWorldPosition(Vector3::Zero())
		- b.transform_.ToWorldPosition(Vector3::Zero()))
		.Abs()
	};

	Vector3 abLength{ a.HalfSize() + b.HalfSize() };

	for (int i = 0; i < 3; i++)
	{
		// x y z 成分にインデックスでアクセス
		if ((abLength[i] <= abDistance[i]))
		{
			return false;
		}
	}

	return true;
}

Vector3 Collider::Reflection_AABB2AABB(
	const AABBCollider& self,
	const AABBCollider& target) const
{
	/*
	//// 自分と相手との位置関係ベクトル
	//Vector3 diff
	//{
	//	self.transform_.ToWorldPosition(Vector3::Zero())
	//	- target.transform_.ToWorldPosition(Vector3::Zero())
	//};

	//// 自分と相手、両方を足したサイズベクトル
	//Vector3 bothSize
	//{
	//	self.HalfSize() + target.HalfSize()
	//};

	//Vector3 volume
	//{
	//	diff.Abs() + bothSize
	//};

	//Vector3 reflection{ Vector3::One() };

	//float volumeMax{ std::fmaxf(std::fmaxf(volume.x, volume.y), volume.z) };
	//for (int i = 0; i < 3; i++)
	//{
	//	if (volume[i] < volumeMax)
	//	{
	//		reflection[i] = 0.f;
	//	}
	//}


	//return reflection;

	*/

	Vector3 selfCenter
	{
		self.transform_.ToWorldPosition(Vector3::Zero())
	};
	
	Vector3 targetCenter
	{
		target.transform_.ToWorldPosition(Vector3::Zero())
	};

	Vector3 restitution{};

	for (int i = 0; i < 3; i++)
	{
		if (targetCenter[i] < selfCenter[i])
		{
			restitution[i] = target.Max()[i] - self.Min()[i];
		}
		else
		{
			restitution[i] = target.Min()[i] - self.Max()[i];
		}
	}

	Vector3 absRestitution{ restitution.Abs() };

	float minRestitution
	{
		std::fminf(absRestitution.x, std::fminf(absRestitution.y, absRestitution.z))
	};

	for (int i = 0; i < 3; i++)
	{
		if (minRestitution < absRestitution[i])
		restitution[i] = 0.f;
	}

	/*if (selfCenter.x < targetCenter.x)
	{
		restitution.x -= self.Max().x - target.Min().x;
	}
	if (targetCenter.x < selfCenter.x)
	{
		restitution.x += self.Max().x - target.Min().x;
	}

	if (selfCenter.y < targetCenter.y)
	{
		restitution.y -= target.Max().y - self.Min().y;
	}
	if (targetCenter.y < selfCenter.y)
	{
		restitution.y += self.Max().y - target.Min().y;
	}*/

	// MEMO: 2軸別の埋め込み率を計算

	//float restitutionRateX{ std::fabsf(restitution.x) / self.HalfSize().x };
	//float restitutionRateY{ std::fabsf(restitution.y) / self.HalfSize().y };

	// MEMO: 埋め込み率が低い方は無視...?
	//     : でも実際埋め込み率が高い方を無視で上手く動く...

	/*if (restitutionRateY < restitutionRateX)
	{
		restitution.x = 0.f;
	}

	if (restitutionRateX < restitutionRateY)
	{
		restitution.y = 0.f;
	}*/

	// MEMO: 埋め込み率が等しい = ピッタリ斜めからの場合は斜めで返す

	return restitution;
}
