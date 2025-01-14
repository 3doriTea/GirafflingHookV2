#pragma once
#include <functional>

using EventHandle = int;

class Event
{
	struct EventElement
	{
		void Invoke();


		std::function<void()> callback;
		float milliseconds;
	};

public:
	static EventHandle SetInterval(
		const std::function<void()>& callback,
		const float& milliseconds);
	static EventHandle SetTimeout(
		const std::function<void()>& callback,
		const float& milliseconds);

private:

};

