#include "Event.h"

Event::EventElement::EventElement(
	const EventHandle& _handle,
	const float& _timeMax,
	const EventCallback& _callback,
	const EventType& _type) :
	HANDLE{ _handle },
	TIME_MAX{ _timeMax },
	TYPE{ _type },
	callback{ _callback },
	timeLeft{ _timeMax }
{
}

void Event::EventElement::Invoke() const
{
	callback();
}

EventHandle Event::SetInterval(const EventCallback& callback, const float& seconds)
{
	EventElement element{ handleCounter, seconds, callback, EventType::Interval };
	events.insert({ handleCounter, element });
	handleCounter++;

	return element.HANDLE;
}

EventHandle Event::SetTimeout(const EventCallback& callback, const float& seconds)
{
	EventElement element{ handleCounter, seconds, callback, EventType::Timeout };
	events.insert({ handleCounter, element });
	handleCounter++;

	return element.HANDLE;
}

void Event::Delete(const EventHandle& handle)
{
}

std::map<EventHandle, Event::EventElement> Event::events{};
EventHandle Event::handleCounter{ 0 };
