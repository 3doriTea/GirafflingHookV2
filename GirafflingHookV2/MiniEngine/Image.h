#pragma once
#include <string>
#include <map>

using ImageHandle = int;

class ImageManager;

/// <summary>
/// ‰æ‘œŠÖŒW‚ÌƒNƒ‰ƒX
/// </summary>
class Image
{
	friend ImageManager;

public:
	static ImageHandle Handle(const std::string& name);
	static ImageHandle Load(const std::string& name, const std::string& fileName);

private:
	static std::map<std::string, ImageHandle> loadedImageHandles;
};

