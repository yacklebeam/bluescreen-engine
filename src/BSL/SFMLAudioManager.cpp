#include "SFMLAudioManager.h"
#include <cstdio>

SFMLAudioManager::SFMLAudioManager()
{
	systemVolume = 20;
}

SFMLAudioManager::~SFMLAudioManager()
{

}

void
SFMLAudioManager::addSound(char* tagIn, sf::SoundBuffer* buffer, float volumeScalingIn, int typeIn)
{
	GameSound gs;
	gs.tag = tagIn;

	sf::Sound s;
	s.setBuffer(*buffer);
	s.setVolume(systemVolume * volumeScalingIn);
	gs.type = typeIn;
	gs.sound = s;
	gs.scalingFactor = volumeScalingIn;

	sounds.push_back(gs);
#ifndef RELEASE
	printf("Creating Sound: %s\n", tagIn);
#endif
}

void
SFMLAudioManager::playSound(char* search)
{
	for(int i = 0; i < sounds.size(); ++i)
	{
		if(strcmp(sounds[i].tag, search) == 0)
		{	
			sounds[i].sound.play();
		}
	}
}

void
SFMLAudioManager::setSystemVolume(int volume)
{
	if(volume <= 100 && volume >= 0)
	{
		systemVolume = volume;
		for(int i = 0; i < sounds.size(); ++i)
		{
			sounds[i].sound.setVolume(volume * sounds[i].scalingFactor);
		}		
	}
}

int
SFMLAudioManager::getSystemVolume()
{
	return systemVolume;
}