#include "ImageManager.h"
#include "Image.h"
#include <DxLib.h>

ImageManager::ImageManager() :
	Manager::Manager{ CalledType::Frame }
{
}

ImageManager::~ImageManager()
{
}

void ImageManager::Init()
{
}

void ImageManager::Update()
{
}

void ImageManager::End()
{
	for (auto&& hImagePair : Image::loadedImageHandles)
	{
		DeleteGraph(hImagePair.second);
	}
	Image::loadedImageHandles.clear();
}
