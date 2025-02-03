#include "Manager.h"
#include <DxLib.h>

Manager::Manager(
	const CalledType& _calledType,
	const int& _initOrder) :
	order_{ 0 },
	initOrder_{ _initOrder },
	calledType_{ _calledType }
{
	managers_.push_back(this);

	// ‰Šú‰»‘Ò‚¿ƒŠƒXƒg‚Ì“KØ‚ÈêŠ‚É‘}“ü
	for (auto&& itr = uninitialisedManagers_.begin();
		itr != uninitialisedManagers_.end();
		itr++)
	{
		if ((*itr)->initOrder_ > _initOrder)
		{
			uninitialisedManagers_.insert(itr, this);
			return;
		}
	}

	// ‘}“üæ‚ª‚È‚¯‚ê‚ÎÅŒã”ö‚É’Ç‰Á
	uninitialisedManagers_.push_back(this);
}

Manager::~Manager()
{
}

void Manager::UpdateFrame()
{
	for (auto&& itr = uninitialisedManagers_.begin();
		itr != uninitialisedManagers_.end();)
	{
		if ((*itr)->calledType_ == CalledType::Frame)
		{
			(*itr)->Init();
			itr = uninitialisedManagers_.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	for (auto&& manager : managers_)
	{
		if (manager->calledType_ == CalledType::Frame)
		{
			manager->Update();
		}
	}

	for (auto&& manager : managers_)
	{
		if (manager->calledType_ == CalledType::Frame)
		{
			manager->LateUpdate();
		}
	}
}

void Manager::UpdateCycle()
{
	for (auto&& itr = uninitialisedManagers_.begin();
		itr != uninitialisedManagers_.end();)
	{
		if ((*itr)->calledType_ == CalledType::Cycle)
		{
			(*itr)->Init();
			itr = uninitialisedManagers_.erase(itr);
		}
		else
		{
			itr++;
		}
	}

	for (auto&& manager : managers_)
	{
		if (manager->calledType_ == CalledType::Cycle)
		{
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
std::list<Manager*> Manager::uninitialisedManagers_{};
