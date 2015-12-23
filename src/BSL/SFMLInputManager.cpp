#include "SFMLInputManager.hpp"

SFMLInputManager::SFMLInputManager()
{
	for(int i = 0; i < sf::Joystick::AxisCount; ++i)
	{
		joystickAxisActions[i][0] = -1;
		joystickAxisActions[i][1] = -1;
	}

	for(int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		keyboardActions[i] = -1;
	}

	for(int i = 0; i < sf::Joystick::ButtonCount; ++i)
	{
		joystickButtonActions[i] = -1;
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
SFMLInputManager::bindKeyToAction(sf::Keyboard::Key inputIn, int actionIn)
{
	initInput(actionIn);
	keyboardActions[inputIn] = actionIn;
}

void
SFMLInputManager::bindJoystickAxisToActions(sf::Joystick::Axis axisIn, int actionMin, int actionMax)
{
	initInput(actionMax);
	initInput(actionMin);

	joystickAxisActions[axisIn][AXIS_DIRECTION_MIN] = actionMin;
	joystickAxisActions[axisIn][AXIS_DIRECTION_MAX] = actionMax;
}

void
SFMLInputManager::bindJoystickAxisDirectionToAction(sf::Joystick::Axis axisIn, AXIS_DIRECTION direction, int actionIn)
{
	initInput(actionIn);
	joystickAxisActions[axisIn][direction] = actionIn;
}

void
SFMLInputManager::bindJoystickButtonToAction(int buttonIn, int actionIn)
{
	initInput(actionIn);
	joystickButtonActions[buttonIn] = actionIn;
}

bool
SFMLInputManager::testIsKeyPressed(int index)
{
	if(actions[index].canHold)
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
				int minIndex = joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MIN];
				int maxIndex = joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MAX];

				if(event.joystickMove.position < -50.0f)
				{
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MIN]].down = true;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MAX]].down = false;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MAX]].reset = true;
				}
				else if(event.joystickMove.position > 50.0f)
				{
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MAX]].down = true;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MIN]].down = false;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MIN]].reset = true;
				}
				else
				{
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MAX]].down = false;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MAX]].reset = true;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MIN]].down = false;
					actions[joystickAxisActions[event.joystickMove.axis][AXIS_DIRECTION_MIN]].reset = true;
				}
			
			}
			break;
		case sf::Event::JoystickButtonPressed:
			if(joystickEnabled)
			{
				actions[joystickButtonActions[event.joystickButton.button]].down = true;
			}
			break;
		case sf::Event::JoystickButtonReleased:
			if(joystickEnabled)
			{
				actions[joystickButtonActions[event.joystickButton.button]].down = false;
				actions[joystickButtonActions[event.joystickButton.button]].reset = true;
			}
			break;
	}
}

void
SFMLInputManager::initInputAction(int actionIn, bool canHoldDown, bool permanentKeyEnabled)
{
	initInput(actionIn);
	actions[actionIn].canHold = canHoldDown;
	actions[actionIn].pKeyEnabled = permanentKeyEnabled;
}