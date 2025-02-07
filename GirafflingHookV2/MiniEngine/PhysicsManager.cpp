#include "PhysicsManager.h"
#include "Rigidbody.h"
#include "Frame.h"
#include "AABBCollider.h"
#include "Collider.h"
#include "GameObject.h"

#define USING_TRACE_WALL true;

PhysicsManager::PhysicsManager() :
	Manager::Manager{ CalledType::Frame },
	rigidBodies_{},
	dynamicRigidBodies_{},
	colliders_{}
{
	instance = this;
}

PhysicsManager::~PhysicsManager()
{
}

void PhysicsManager::Init()
{
}

void PhysicsManager::Update()
{
	float deltaTime = Frame::GetDeltaTime();

	for (auto&& rigidbody : dynamicRigidBodies_)
	{
#pragma region プロパティの参照
		// 座標
		Vector3& position{ rigidbody->position_ };
		// 移動速度
		Vector3& velocity{ rigidbody->velocity };
		// コライダーの反発ベクトル
		Vector3& reflection{ rigidbody->reflection };
		// 移動抵抗
		float& resistance{ rigidbody->resistance };
		// 重力
		float& gravity{ rigidbody->gravity };
		// 固定軸
		bool&
			fixedX{ rigidbody->fixedX },
			fixedY{ rigidbody->fixedY },
			fixedZ{ rigidbody->fixedZ };
#pragma endregion

#pragma region 重力適用
		velocity += Vector3::Down() * (gravity / deltaTime);
#pragma endregion

#pragma region 固定軸の速度を無効化
		if (fixedX)
		{
			velocity.x *= 0.f;
		}
		if (fixedY)
		{
			velocity.y *= 0.f;
		}
		if (fixedZ)
		{
			velocity.z *= 0.f;
		}
#pragma endregion

#pragma region 速度を座標に適用
		position += velocity * deltaTime;
#pragma endregion

#pragma region コライダ当たり判定更新と反発ベクトルを求める
		for (auto&& targetCollider : colliders_)
		{
			// 自分自身のコライダーなら回帰
			if (rigidbody->colliderPtr_ == targetCollider)
			{
				continue;
			}

			if (static_cast<AABBCollider*>(rigidbody->colliderPtr_)
				->IsHitAABB(*static_cast<AABBCollider*>(targetCollider)))
			{
				// TODO: ヒットしたときのイベント関数を呼び出したい
				/*printfDx(
					"OnHit %s : %s\n",
					rigidbody->gameObject.GetName().c_str(),
					targetCollider->gameObject.GetName().c_str());*/
				reflection +=
					static_cast<AABBCollider*>(rigidbody->colliderPtr_)
					->ReflectionAABB(*static_cast<AABBCollider*>(targetCollider));

				//self->velocity += reflection * 1.f;
			}
			else
			{
				//printfDx("当たってない！");
			}
		}
#pragma endregion

#pragma region 固定軸の埋込み反発を無効化
		if (fixedX)
		{
			reflection.x *= 0.f;
		}
		if (fixedY)
		{
			reflection.y *= 0.f;
		}
		if (fixedZ)
		{
			reflection.z *= 0.f;
		}
#pragma endregion

#pragma region 埋め込み反発ベクトルを適用
		position += reflection;
#pragma endregion

#pragma region 反射するなら反発ベクトルを求める
		// REF: http://marupeke296.com/COL_Basic_No5_WallVector.html
		
		if (Vector3::Length(reflection) > FLT_EPSILON)
		{
			Vector3 n{ reflection };
			Vector3 nNorm{ Vector3::Normalize(n) };
			float a{ -VDot(velocity, nNorm) };

			// 壁ずりベクトル
			Vector3 w
			{
				velocity - (nNorm * VDot(velocity, nNorm))
			};

			// 反射ベクトル
			Vector3 r
			{
				velocity + nNorm * (2.f * a)
			};

			// 反発係数
			float e{ 0.6f };//0.4f };  // TODO: 定数化する

#if USING_TRACE_WALL
			// 壁ずりベクトルの適用
			velocity = w;
#else
			// 普通の反射べクトルの適用
			velocity = r * e;
#endif
		}
#pragma endregion

#pragma region 適用と更新
		//// 速度の適用
		//position += velocity * deltaTime;
		// 移動抵抗の適用
		velocity += velocity * -resistance * deltaTime;

		// 角度
		Vector3& rotate{ rigidbody->rotate_ };
		// 回転速度
		Vector3& velocityTorque{ rigidbody->velocityTorque };
		// 回転抵抗
		float& resistanceTorque{ rigidbody->resistanceTorque };

		// 回転の適用
		rotate += velocityTorque * deltaTime;
		// 回転抵抗の適用
		velocityTorque += velocityTorque * -resistanceTorque * deltaTime;
		// 360度内に収める
		rotate %= 360.f;
		// 次のフレームでは引き続き使わないためクリア
		reflection = Vector3::Zero();
#pragma endregion
	}
}

void PhysicsManager::End()
{
}

void PhysicsManager::RegisterRigidbody(Rigidbody* rigidbody, const bool& isDynamic)
{
	instance->rigidBodies_.insert(rigidbody);
	if (isDynamic)
	{
		instance->dynamicRigidBodies_.insert(rigidbody);
	}
}

void PhysicsManager::UnregisterRigidbody(Rigidbody* rigidbody)
{
	instance->rigidBodies_.erase(rigidbody);

	// 動的剛体として登録済みなら消す
	if (instance->dynamicRigidBodies_.count(rigidbody))
	{
		instance->dynamicRigidBodies_.erase(rigidbody);
	}
}

void PhysicsManager::RegisterCollider(Collider* collider)
{
	instance->colliders_.insert(collider);
}

void PhysicsManager::UnregisterCollider(Collider* collider)
{
	instance->colliders_.erase(collider);
}

PhysicsManager* PhysicsManager::instance{ nullptr };
