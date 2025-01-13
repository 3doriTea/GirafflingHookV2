#pragma once
#include "GameObject.h"

namespace Title
{
	/// <summary>
	/// タイトルシーンのちょっとしか動かないカメラ
	/// </summary>
	class TitleCamera : public GameObject
	{
	public:
		TitleCamera();
		~TitleCamera();

		void Init() override;
		void Update() override;
		void Draw() const override;

	private:
		int mouseX_;
		int mouseY_;

		static const Vector3 BASE_POSITION;
	};
}
