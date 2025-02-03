#pragma once
#include <functional>
#include <map>

using EventHandle = int;
using EventCallback = std::function<void()>;

class Event
{
	enum struct EventType : char
	{
		Interval,
		Timeout,
	};
	struct EventElement
	{
		EventElement(
			const EventHandle& _handle,
			const float& _timeMax,
			const EventCallback& _callback,
			const EventType& _type);

		void Invoke() const;

		EventCallback callback;
		const float TIME_MAX;
		const EventHandle HANDLE;
		const EventType TYPE;
		float timeLeft;
	};

public:
	static EventHandle SetInterval(
		const EventCallback& callback,
		const float& seconds);
	static EventHandle SetTimeout(
		const EventCallback& callback,
		const float& seconds);
	static void Delete(const EventHandle& handle);

private:
	static std::map<EventHandle, EventElement> events;
	static EventHandle handleCounter;
};

