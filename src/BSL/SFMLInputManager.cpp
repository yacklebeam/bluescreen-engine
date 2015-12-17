#include "SFMLInputManager.h"

SFMLInputManager::SFMLInputManager()
{
	for(int i = 0; i < JOYSTICK_ACTION_COUNT; ++i)
	{
		joystickActions[i] = -1;
	}

	for(int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		keyboardActions[i] = -1;
	}

	joystickEnabled = false;
}

SFMLInputManager::~SFMLInputManager()
{

}

void
SFMLInputManager::enableJoystick(bool doThat)
{
	joystickEnabled = doThat;
}

void
SFMLInputManager::initInput(int index)
{
	if(index >= actions.size())
	{
		for(int i = actions.size(); i <= index; ++i)
		{
			InputAction ia;
			ia.down = false;
			ia.reset = true;
			actions.push_back(ia);
		}
	}
}

bool
SFMLInputManager::isJoystickEnabled()
{
	return joystickEnabled;
}

void
SFMLInputManager::bindKeyAction(sf::Keyboard::Key inputIn, int actionIn, bool canHoldDown)
{
	initInput(actionIn);
	keyboardActions[inputIn] = actionIn;
	actions[actionIn].keyCanHold = canHoldDown;
}

void
SFMLInputManager::bindJoystickAction(JOYSTICK_ACTION ja, int actionIn, bool canHoldDown)
{
	initInput(actionIn);
	joystickActions[ja] = actionIn;
	actions[actionIn].jsCanHold = canHoldDown;
}

bool
SFMLInputManager::testIsKeyPressed(int index)
{
	if(actions[index].jsCanHold)
	{
		return actions[index].down;
	}
	else
	{
		if(actions[index].down && actions[index].reset)
		{
			actions[index].reset = false;
			return true;
		}
		else
		{
			return false;
		}
	}
}

void
SFMLInputManager::processInput(sf::Event event)
{
	switch(event.type)
	{
		case sf::Event::KeyPressed:
			if(!joystickEnabled)
			{
				actions[keyboardActions[event.key.code]].down = true;
			}
			break;
		case sf::Event::KeyReleased:
			if(!joystickEnabled)
			{
				actions[keyboardActions[event.key.code]].down = false;
				actions[keyboardActions[event.key.code]].reset = true;
			}
			break;
		case sf::Event::JoystickMoved:
			if(joystickEnabled)
			{
				if(event.joystickMove.axis == sf::Joystick::X)
				{
					if(event.joystickMove.position < -50.0f)
					{
						actions[joystickActions[CONTROLLER_AXIS_LEFT]].down = true;
						actions[joystickActions[CONTROLLER_AXIS_RIGHT]].down = false;
					}
					else if(event.joystickMove.position > 50.0f)
					{
						actions[joystickActions[CONTROLLER_AXIS_RIGHT]].down = true;
						actions[joystickActions[CONTROLLER_AXIS_LEFT]].down = false;
					}
					else
					{
						actions[joystickActions[CONTROLLER_AXIS_RIGHT]].down = false;
						actions[joystickActions[CONTROLLER_AXIS_LEFT]].down = false;					
					}
				}
			}
			break;
		case sf::Event::JoystickButtonPressed:
			if(joystickEnabled)
			{
				actions[joystickActions[event.joystickButton.button]].down = true;
				/*if(event.joystickButton.button == 0)
				{
					actions[joystickActions[BUTTON_0]].down = true;
				}*/
			}
			break;
		case sf::Event::JoystickButtonReleased:
			if(joystickEnabled)
			{
				actions[joystickActions[event.joystickButton.button]].down = false;
				actions[joystickActions[event.joystickButton.button]].reset = true;

				/*if(event.joystickButton.button == 0)
				{
					actions[joystickActions[A_BUTTON]].down = false;
					actions[joystickActions[A_BUTTON]].reset = true;
				}*/
			}
			break;
	}
}