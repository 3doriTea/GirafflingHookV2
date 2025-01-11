#include "GameObjectBuilder.h"

GameObjectBuilder::GameObjectBuilder() :
	position{ Vector3::Zero() },
	rotate{ Vector3::Zero() },
	scale{ Vector3::One() },
	name{ "GameObject" },
	tag{ "None" }
{
}

GameObjectBuilder& GameObjectBuilder::Position(const Vector3& _position)
{
	this->position = _position;

	return *this;
}

GameObjectBuilder& GameObjectBuilder::Rotate(const Vector3& _rotate)
{
	this->rotate = _rotate;

	return *this;
}

GameObjectBuilder& GameObjectBuilder::Scale(const Vector3& _scale)
{
	this->scale = _scale;

	return *this;
}

GameObjectBuilder& GameObjectBuilder::Name(const std::string& _name)
{
	this->name = _name;

	return *this;
}

GameObjectBuilder& GameObjectBuilder::Tag(const std::string& _tag)
{
	this->tag = _tag;

	return *this;
}
