#pragma once
#include <chrono>

class System
{
public:
	System();
	~System();

	static long getTimeNano();
};

