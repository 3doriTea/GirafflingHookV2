#pragma once

class Ease  // static class
{
public:
	/// <summary>
	/// src: https://easings.net/ja#easeOutBounce
	/// </summary>
	/// <param name="x">アニメーションレート</param>
	/// <returns>0.f <= x <= 1.f</returns>
	static float OutBounce(float x);

	/// <summary>
	/// src: https://easings.net/ja#easeInOutExpo
	/// </summary>
	/// <param name="x">アニメーションレート</param>
	/// <returns>0.f <= x <= 1.f</returns>
	static float InOutExpo(float x);
};
