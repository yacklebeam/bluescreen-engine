#ifndef BLUESCREEN_INPUTMANAGER_H
#define BLUESCREEN_INPUTMANAGER_H

#include <SFML/Window.hpp>
#include <cstdio>
#include <vector>

//TODO (jtroxel): Remove this, yo?
enum JOYSTICK_ACTION
{
	CONTROLLER_BUTTON_0,
	CONTROLLER_BUTTON_1,
	CONTROLLER_BUTTON_2,
	CONTROLLER_BUTTON_3,
	CONTROLLER_L_BUMPER,
	CONTROLLER_R_BUMPER,
	CONTROLLER_SELECT_BUTTON,
	CONTROLLER_START_BUTTON,
	CONTROLLER_AXIS_LEFT,
	CONTROLLER_AXIS_RIGHT,
	CONTROLLER_AXIS_UP,
	CONTROLLER_AXIS_DOWN,
	CONTROLLER_SELECT,
	JOYSTICK_ACTION_COUNT
};

enum AXIS_DIRECTION
{
	AXIS_DIRECTION_MIN = 0,
	AXIS_DIRECTION_MAX = 1,
	AXIS_DIRECTION_LEFT = 0,
	AXIS_DIRECTION_RIGHT = 1,
	AXIS_DIRECTION_DOWN = 0,
	AXIS_DIRECTION_UP = 1,
};

//TODO (jtroxel): do we want this?
//TODO (jtroxel): finish this out, plus other controller maps
enum XBOX_BUTTON_SETUP
{
	XBOX_A_BUTTON,
	XBOX_B_BUTTON,
	XBOX_X_BUTTON,
	XBOX_Y_BUTTON,
	XBOX_L_BUMPER,
	XBOX_R_BUMPER,
	XBOX_BACK_BUTTON,
	XBOX_START_BUTTON,
	XBOX_L_STICK,
	XBOX_R_STICK,
};

class SFMLInputManager
{
public:
	SFMLInputManager();
	~SFMLInputManager();
	bool testIsKeyPressed(int);
	void processInput(sf::Event);
	void enableJoystick(bool);
	bool isJoystickEnabled();
	void initInputAction(int, bool, bool);
	void bindKeyToAction(sf::Keyboard::Key, int);
	void bindJoystickAxisToActions(sf::Joystick::Axis, int, int);
	void bindJoystickAxisDirectionToAction(sf::Joystick::Axis, AXIS_DIRECTION, int);
	void bindJoystickButtonToAction(int, int);

private:
	bool joystickEnabled;
	struct InputAction
	{
		bool down;
		bool reset;
		bool canHold;
		bool pKeyEnabled;
	};

	void initInput(int);
	std::vector<InputAction> actions;
	int inputCount;
	int joystickActions[JOYSTICK_ACTION_COUNT];
	int keyboardActions[sf::Keyboard::KeyCount];
	int joystickButtonActions[sf::Joystick::ButtonCount];
	int joystickAxisActions[sf::Joystick::AxisCount][2];
};

#endif