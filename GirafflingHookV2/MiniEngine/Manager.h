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

	static void UpdateFrame();
	static void UpdateCycle();
	static void ReleaseAll();

protected:
	void SetOrder(const int&);

private:
	int order_;
	CalledType calledType_;

	static std::list<Manager*> managers_;
	static std::set<const Manager*> uninitialisedManagers_;
};
