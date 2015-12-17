#ifndef BLUESCREEN_INPUTMANAGER_H
#define BLUESCREEN_INPUTMANAGER_H

#include <SFML/Window.hpp>
#include <cstdio>
#include <vector>

enum JOYSTICK_ACTION
{
	CONTROLLER_A_BUTTON,
	CONTROLLER_B_BUTTON,
	CONTROLLER_X_BUTTON,
	CONTROLLER_Y_BUTTON,
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


class SFMLInputManager
{
public:
	SFMLInputManager();
	~SFMLInputManager();
	void bindKeyAction(sf::Keyboard::Key, int, bool);
	void bindJoystickAction(JOYSTICK_ACTION, int, bool);
	bool testIsKeyPressed(int);
	void processInput(sf::Event);
	void enableJoystick(bool);
	bool isJoystickEnabled();
private:
	bool joystickEnabled;
	struct InputAction
	{
		bool down;
		bool reset;
		bool jsCanHold;
		bool keyCanHold;
	};

	std::vector<InputAction> actions;
	int inputCount;
	int joystickActions[JOYSTICK_ACTION_COUNT];
	int keyboardActions[sf::Keyboard::KeyCount];
	void initInput(int);
};

#endif