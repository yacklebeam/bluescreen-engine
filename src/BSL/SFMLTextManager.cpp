#include "SFMLTextManager.hpp"
#include <cstdio>

SFMLTextManager::SFMLTextManager()
{

}

SFMLTextManager::~SFMLTextManager()
{

}

void
SFMLTextManager::createSFMLText(char* tagIn, char* textIn, sf::Font *font, sf::Color color, int X, int Y)
{
	TextObject to;
	to.tag = tagIn;
	sf::Text newText;
	newText.setFont(*font);
	newText.setString(textIn);
	newText.setPosition(X, Y);
	newText.setColor(color);
	newText.setCharacterSize(12);

	to.text = newText;
	texts.push_back(to);
}

void
SFMLTextManager::createSFMLText(char* tagIn, std::string textIn)
{
}

void
SFMLTextManager::setText(char* tagIn, char* textIn)
{
	int index = getIndexFromTag(tagIn);
	if(index >= 0) texts[index].text.setString(textIn);
}

void
SFMLTextManager::setText(char* tagIn, std::string textIn)
{
	int index = getIndexFromTag(tagIn);
	if(index >= 0) texts[index].text.setString(textIn);
}

sf::Text*
SFMLTextManager::getSFMLText(char* search)
{
	int index = getIndexFromTag(search);
	if(index >= 0) 
	{
		return &(texts[index].text);
	}
	else return NULL;
}

int
SFMLTextManager::getIndexFromTag(char* search)
{
	for(int i = 0; i < texts.size(); ++i)
	{
		if(strcmp(texts[i].tag, search) == 0)
		{
			return i;
		}
	}

	return -1;
}