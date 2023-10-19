#pragma once
#include "System.h"

class Engine
{
public:
	Engine() {}
	~Engine() {}

	bool initialize();
	bool run();

private:
	System _system;

};