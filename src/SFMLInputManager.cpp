#include "SFMLInputManager.h"

SFMLInputManager::SFMLInputManager()
{
	printf("Now reading inputs...\n");
	inputCount = 0;
}

SFMLInputManager::~SFMLInputManager()
{

}

void
SFMLInputManager::bindInputAction(sf::Keyboard::Key inputIn, int actionIn)
{
	InputAction ia;
	ia.input = inputIn;
	ia.action = actionIn;

	inputs.push_back(ia);
	inputCount++;
}

