#pragma once
#include <list>
#include <set>

/// <summary>
/// 更新するタイミングの種類
/// </summary>
enum struct CalledType
{
	Cycle,  // 1ゲームサイクル(ものすごく速い)
	Frame,  // 1フレーム(60fpsなら1秒間に60回)
};

class Manager
{
public:
	Manager(const CalledType&);
	~Manager();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

	/// <summary>
	/// 1フレームの更新処理
	/// </summary>
	static void UpdateFrame();
	/// <summary>
	/// 1サイクルの更新処理
	/// </summary>
	static void UpdateCycle();
	/// <summary>
	/// すべての動的メモリ確保したやつを解放
	/// </summary>
	static void ReleaseAll();

protected:
	/// <summary>
	/// 更新順番をお願いする
	/// </summary>
	/// <param name="">更新順番低いほど順番が早い</param>
	void SetOrder(const int&);

private:
	int order_;
	CalledType calledType_;

	static std::list<Manager*> managers_;
	static std::set<const Manager*> uninitialisedManagers_;
};
