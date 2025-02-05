#pragma once

#pragma once
#include "GameObject.h"

namespace Clear
{
	/// <summary>
	/// タイトルシーンのちょっとしか動かないカメラ
	/// </summary>
	class ClearCamera : public GameObject
	{
	public:
		ClearCamera();
		~ClearCamera();

		void Init() override;
		void Update() override;
		void Draw() const override;

	private:
		int mouseX_;
		int mouseY_;

		static const Vector3 BASE_POSITION;
	};
}