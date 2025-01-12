#pragma once
#include "Manager.h"
#include <set>

class Transform;

class TransformManager : public Manager
{
public:
	TransformManager();
	~TransformManager();

	void Init() override;
	void Update() override;
	void End() override;

	static void Register(Transform* _transform);
	static void Unregister(Transform* _transform);

private:
	std::set<Transform*> transforms_;

private:
	static TransformManager* instance_;
};
