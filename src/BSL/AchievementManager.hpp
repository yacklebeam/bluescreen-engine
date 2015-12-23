#ifndef BLUESCREEN_ACHIEVEMENT_H
#define BLUESCREEN_ACHIEVEMENT_H

#include <SFML/Window.hpp>
#include <cstring>

class AchievementManager 
{
public:
	AchievementManager();
	~AchievementManager();
	bool hasAchievement();
	void testDisplayAchievement(sf::RenderWindow *win);
	void addAchievement(char* name, char* desc);

private:
	class Achievement 
	{
	public:
		Achievement();
		Achievement(char* name, char* desc);
		~Achievement();
		char* name;
		char* desc;
	};

	int count;
};

#endif