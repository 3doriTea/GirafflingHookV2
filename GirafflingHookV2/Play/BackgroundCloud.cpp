#include "BackgroundCloud.h"
#include "Frame.h"
#include "Screen.h"
#include <cmath>

namespace
{
	static const float MOVE_SPEED{ 100.0f };  // 1•bŠÔ‚ ‚½‚è‚ÌˆÚ“®ƒsƒNƒZƒ‹
}

Play::BackgroundCloud::BackgroundCloud() :
	GameObject
	{
		GameObjectBuilder{}
			.LayerOrder(LayerOrderType::Background)
	},
	cloudShowTimeLeft_{ 0.0f },
	clouds_{}
{
}

Play::BackgroundCloud::~BackgroundCloud()
{
}

void Play::BackgroundCloud::Update()
{
	float moveX{ -MOVE_SPEED * Frame::GetDeltaTime() };
	float moveAngle{ DX_PI_F / 2.0f * Frame::GetDeltaTime() };

	for (auto itr = clouds_.begin(); itr != clouds_.end();)
	{
		(*itr)->position.x += moveX;
		(*itr)->angle += moveAngle;
		(*itr)->angle = std::fmodf((*itr)->angle, DX_PI_F * 2.0f);

		//if ((*itr)->position.x > (*itr)->position.z * 2.0f + Screen::WIDTH)
		// ‰ñ“]‚µ‚½‚Æ‚«‚Ì• + ‰~‚Ì••ª‰æ–Ê‚©‚ço‚Ä‚¢‚½‚çÁ‚·
		if ((*itr)->position.x < -(*itr)->position.z * 2.0f)
		{
			delete (*itr);
			itr = clouds_.erase(itr);
		}
		else
		{
			itr++;
		}
	}


	// ’èŠú“I‚È‰_‚Ì¶¬
	cloudShowTimeLeft_ -= Frame::GetDeltaTime();
	if (cloudShowTimeLeft_ <= 0.0f)
	{
		cloudShowTimeLeft_ += GetRand(1000) / 1000.0f;
		for (int i = 0; i < GetRand(3); i++)
		{
			float radius{ GetRand(45) + 5.0f };
			Cloud* cloud = new Cloud
			{
				Vector3{ Screen::WIDTH + radius * 2.0f, Screen::HEIGHT / 3.0f - GetRand(Screen::HEIGHT / 3.0f), radius },
				float{ DX_PI_F * 2.0f * (1.0f / GetRand(100)) }
			};
			clouds_.push_back(cloud);
		}
	}
}

void Play::BackgroundCloud::Draw() const
{
	for (auto&& cloud : clouds_)
	{
		DrawCircle(
			static_cast<int>(cloud->position.z * std::cosf(cloud->angle) + cloud->position.x),
			static_cast<int>(cloud->position.z * std::sinf(cloud->angle) + cloud->position.y),
			static_cast<int>(cloud->position.z),
			0xbcf2f6,
			TRUE);
	}
}

void Play::BackgroundCloud::End()
{
	// ‰_‚Ì‰ğ•ú
	for (auto&& cloud : clouds_)
	{
		delete cloud;
	}
}
