#include "Image.h"
#include "ImageManager.h"
#include <DxLib.h>

ImageHandle Image::Handle(const std::string& name)
{
	return loadedImageHandles[name];
}

ImageHandle Image::Load(const std::string& name, const std::string& fileName)
{
	ImageHandle hImage{ LoadGraph(fileName.c_str()) };
	loadedImageHandles.insert({ name, hImage });

	return hImage;
}

std::map<std::string, ImageHandle> Image::loadedImageHandles{};
