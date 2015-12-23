#include "AchievementManager.hpp"
#include <SFML/Graphics.hpp>
#include <cstdio>

//////////////////////////////////////
//	ACHIEVEMENT MANAGER
//////////////////////////////////////

AchievementManager::AchievementManager()
{
	printf("Now managing achievements...\n");
	count = 3 * 60;
}

AchievementManager::~AchievementManager()
{
	
}

bool
AchievementManager::hasAchievement()
{
	return true;
}

void
AchievementManager::testDisplayAchievement(sf::RenderWindow *win)
{
	sf::Font font;
    if(!font.loadFromFile("res/sansation.ttf")) {
        printf("ERROR loading font.\n");
    }

    sf::Text text;
	text.setFont(font);
	text.setString("TEST");
	text.setCharacterSize(24);
	text.setPosition(100.0f, 100.0f);

	win->draw(text);
}

void
AchievementManager::addAchievement(char* name, char* desc)
{

}

//////////////////////////////////////
//	ACHIEVEMENT
//////////////////////////////////////

AchievementManager::Achievement::Achievement()
{

}

AchievementManager::Achievement::Achievement(char* nameIn, char* descIn)
{
	printf("Loaded Achievement: %s--%s\n", nameIn, descIn);
	name = nameIn;
	desc = descIn;
}

AchievementManager::Achievement::~Achievement()
{
	
}