#include "System.h"



System::System()
{
}


System::~System()
{
}

long System::getTimeNano()
{
	return std::chrono::high_resolution_clock::now().time_since_epoch().count();
}
