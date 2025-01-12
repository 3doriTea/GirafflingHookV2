#include "TransformManager.h"
#include "Transform.h"

TransformManager::TransformManager() :
	Manager::Manager(CalledType::Frame),
	transforms_{}
{
	instance_ = this;
}

TransformManager::~TransformManager()
{
}

void TransformManager::Init()
{
}

void TransformManager::Update()
{
	for (auto&& transform : transforms_)
	{
		transform->UpdateCalculate();
	}
}

void TransformManager::End()
{
}

void TransformManager::Register(Transform* _transform)
{
	instance_->transforms_.insert(_transform);
}

void TransformManager::Unregister(Transform* _transform)
{
	instance_->transforms_.erase(_transform);
}

TransformManager* TransformManager::instance_{ nullptr };
