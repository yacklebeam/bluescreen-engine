#ifndef BLUESCREEN_TEXTRENDERER_H
#define BLUESCREEN_TEXTRENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstring>

class SFMLTextManager
{
public:
	SFMLTextManager();
	~SFMLTextManager();
	void createSFMLText(char* tag, char* text, sf::Font*, sf::Color, int, int);
	void createSFMLText(char* tag, std::string text);
	void setText(char* tag, char* text);
	void setText(char* tag, std::string text);
	sf::Text* getSFMLText(char* tag);
private:
	struct TextObject
	{
		char* tag;
		sf::Text text;
	};
	int getIndexFromTag(char* tag);
	std::vector<TextObject> texts;
	std::vector<sf::Text> textTest;
};

#endif