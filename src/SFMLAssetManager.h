#ifndef BLUESCREEN_SFMLASSET_H
#define BLUESCREEN_SFMLASSET_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Window.hpp>

class SFMLAssetManager
{
public:
	SFMLAssetManager();
	~SFMLAssetManager();
	void loadImageAsset(char* tag, char* path);
	void loadSoundAsset(char* tag, char* path);
	void loadTextAsset(char* tag, char* path);
	sf::Texture* getImageAsset(char* search);

private:
	struct TextureAsset
	{
		sf::Texture texture;
		char* tag;
	};
	std::vector<TextureAsset> textures;
};

#endif