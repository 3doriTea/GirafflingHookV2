#include "GameObjectBuilder.h"

GameObjectBuilder::GameObjectBuilder() :
	position{ Vector3::Zero() },
	rotate{ Vector3::Zero() },
	scale{ Vector3::One() },
	name{ "GameObject" },
	tag{ "None" },
	layerOrder{ LayerOrderType::Default },
	isActiveStart{ true }  // デフォルトでアクティブ状態からスタート
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

GameObjectBuilder& GameObjectBuilder::LayerOrder(const short& _layerOrder)
{
	this->layerOrder = _layerOrder;

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

GameObjectBuilder& GameObjectBuilder::IsActiveStart(const bool& _isActive)
{
	this->isActiveStart = _isActive;

	return *this;
}
