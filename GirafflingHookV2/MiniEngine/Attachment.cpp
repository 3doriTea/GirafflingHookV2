#include "Attachment.h"
#include "GameObject.h"

Attachment::Attachment(GameObject& gameObject) :
	gameObject{ gameObject }
{
}

Attachment::~Attachment()
{
}
