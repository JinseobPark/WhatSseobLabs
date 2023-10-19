#include "Engine.h"

bool Engine::initialize()
{
	return _system.initialize();
}

bool Engine::run()
{
	while (!_system.isExit())
	{
		_system.update();
		_system.draw();
	}
	return true;
}

