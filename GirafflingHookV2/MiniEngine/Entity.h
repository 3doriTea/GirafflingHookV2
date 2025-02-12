#pragma once

#include <string>

/// <summary>
///   <para>表示可能なすべてのものはこのクラスを継承する</para>
///   <para>TODO: 余裕が出たら活用したい</para>
/// </summary>
class Entity
{
public:
	virtual std::string ToString();
};
