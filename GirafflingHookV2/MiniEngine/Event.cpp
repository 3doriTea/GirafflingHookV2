#include "Event.h"

Event::EventElement::EventElement(
	const EventHandle& _handle,
	const float& _timeMax,
	const EventCallback& _callback) :
	HANDLE{ _handle },
	TIME_MAX{ _timeMax },
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
	EventElement element{ handleCounter, seconds, callback };
	events.insert({ handleCounter, element });
	handleCounter++;
	return element.HANDLE;
}

EventHandle Event::SetTimeout(const EventCallback& callback, const float& seconds)
{
	return EventHandle();
}

void Event::Delete(const EventHandle& handle)
{
}
