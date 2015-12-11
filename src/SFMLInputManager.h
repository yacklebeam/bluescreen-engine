#ifndef TROXEL_INPUTMANAGER_H
#define TROXEL_INPUTMANAGER_H

#include <SFML/Window.hpp>
#include <cstdio>
#include <vector>

class SFMLInputManager
{
public:
	SFMLInputManager();
	~SFMLInputManager();
	void bindInputAction(sf::Keyboard::Key, int);
private:
	struct InputAction
	{
		sf::Keyboard::Key input;
		int action;
	};

	std::vector<InputAction> inputs;
	int inputCount;
};

#endif