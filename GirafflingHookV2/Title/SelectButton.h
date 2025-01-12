#pragma once
#include "GameObject.h"
#include "Transform.h"
#include "Vector3.h"
#include <string>

namespace Title
{
	class TitleCamera;

	class SelectButton : public GameObject
	{
	public:
		SelectButton(
			const std::string& buttonId,
			const Vector3& position);
		~SelectButton();

		void Init() override;
		void Update() override;
		void Draw() const override;
		void End() override;

	private:
		std::string buttonId_;
		Transform transform_;
		int hButtonModel_;
		TitleCamera* camera_;
	};
}
