#include "SFMLAssetManager.h"
#include <cstdio>
#include <cstring>

SFMLAssetManager::SFMLAssetManager()
{
	printf("Now managing assets...\n");
}

SFMLAssetManager::~SFMLAssetManager()
{

}

void
SFMLAssetManager::loadImageAsset(char* tagIn, char* path)
{
	sf::Texture t;
	TextureAsset ta;

	std::string fullpath = "../res/";
	fullpath.append(path);

	if(t.loadFromFile(fullpath))
	{
		ta.texture = t;
		ta.tag = tagIn;

		textures.push_back(ta);
	}
}

void
SFMLAssetManager::loadSoundAsset(char* tag, char* path)
{

}

void
SFMLAssetManager::loadTextAsset(char* tag, char* path)
{
	
}

sf::Texture*
SFMLAssetManager::getImageAsset(char* search)
{
	sf::Texture* result;
	for(int i = 0; i < textures.size(); ++i)
	{
		if(strcmp(textures[i].tag, search) == 0)
		{
			result = &textures[i].texture;
		}
	}

	return result;
}