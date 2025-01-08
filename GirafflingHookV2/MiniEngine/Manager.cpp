#include "Manager.h"
#include <DxLib.h>

Manager::Manager(const CalledType& calledType) :
	order_{ 0 },
	calledType_{ calledType }
{
	managers_.push_back(this);
	uninitialisedManagers_.insert(this);
}

Manager::~Manager()
{
}

void Manager::UpdateFrame()
{
	printfDx("\n\nManager\n");
	for (auto&& manager : managers_)
	{
		if (manager->calledType_ == CalledType::Frame)
		{
			if (uninitialisedManagers_.count(manager))
			{
				manager->Init();
				uninitialisedManagers_.erase(manager);
			}
			manager->Update();
		}
	}
}

void Manager::UpdateCycle()
{
	for (auto&& manager : managers_)
	{
		if (manager->calledType_ == CalledType::Cycle)
		{
			if (uninitialisedManagers_.count(manager))
			{
				manager->Init();
				uninitialisedManagers_.erase(manager);
			}
			manager->Update();
		}
	}
}

void Manager::ReleaseAll()
{
	for (auto&& manager : managers_)
	{
		delete manager;
	}

	uninitialisedManagers_.clear();
	managers_.clear();
}

void Manager::SetOrder(const int& order)
{
	order_ = order;

	for (auto itr = managers_.begin(); itr != managers_.end();)
	{
		if ((*itr) == this)
		{
			itr = managers_.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	for (auto itr = managers_.begin(); itr != managers_.end(); itr++)
	{
		if ((*itr)->order_ > this->order_)
		{
			itr = managers_.insert(itr, this);
			return;
		}
	}

	managers_.push_back(this);
}

std::list<Manager*> Manager::managers_{};
std::set<const Manager*> Manager::uninitialisedManagers_{};
