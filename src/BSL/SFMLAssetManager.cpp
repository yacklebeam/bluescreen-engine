#include "SFMLAssetManager.hpp"
#include <cstdio>
#include <cstring>

SFMLAssetManager::SFMLAssetManager()
{
	printf("Now managing assets...\n");
}

SFMLAssetManager::~SFMLAssetManager()
{

}

//TODO (jtroxel): Check if loaded already
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
SFMLAssetManager::loadSoundAsset(char* tagIn, char* path)
{
	sf::SoundBuffer sb;
	SoundAsset sa;

	std::string fullpath = "../res/";
	fullpath.append(path);

	if(sb.loadFromFile(fullpath))
	{
		sa.buffer = sb;
		sa.tag = tagIn;

		sounds.push_back(sa);
	}
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

sf::SoundBuffer*
SFMLAssetManager::getSoundAsset(char* search)
{
	sf::SoundBuffer* result;
	for(int i = 0; i < sounds.size(); ++i)
	{
		if(strcmp(sounds[i].tag, search) == 0)
		{
			result = &sounds[i].buffer;
		}	
	}

	return result;
}