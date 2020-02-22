#include "Seedpch.h"
#include "Timer.h"

#include "Platform/Windows/Win32Timer.h"

namespace Seed {

	Timer* Timer::CreateTimer()
	{
		return new Win32Timer();
	}

}