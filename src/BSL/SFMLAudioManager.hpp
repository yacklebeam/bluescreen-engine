#ifndef BLUESCREEN_AUDIO_H
#define BLUESCREEN_AUDIO_H

#include <SFML/Audio.hpp>
#include <vector>
#include <SFML/Window.hpp>

class SFMLAudioManager
{
public:
	SFMLAudioManager();
	~SFMLAudioManager();
	void addSound(char* tag, sf::SoundBuffer* buffer, float volumeScaling, int type);
	void playSound(char* tag);
	void pauseSound(char* tag);
	void setSystemVolume(int);
	int getSystemVolume();
private:
	struct GameSound
	{
		char* tag;
		sf::Sound sound;
		int type;
		float scalingFactor;
	};
	int systemVolume;
	std::vector<GameSound> sounds;
};

#endif