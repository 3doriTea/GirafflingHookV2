#pragma once

#include <string>

/// <summary>
/// 表示可能なすべてのものはこのクラスを継承する
/// </summary>
class Entity
{
public:
	virtual std::string ToString();
};
