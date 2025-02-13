#pragma once
#include "Transform.h"
#include "OccludableObject.h"

namespace Play
{
	class Player;

	class ScoreObject : public OccludableObject
	{
	public:
		ScoreObject(const std::string& name, const Vector3& position);
		~ScoreObject();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		int hAppleModel_;
		Player* player_;
	};
}
