#pragma once

namespace Seed {

	class Timer
	{
	public:
		static Timer& Get() { static Timer* timer = CreateTimer(); return *timer; }
		virtual float GetTime() = 0;
	protected:
		// If there is a cross-platform future, do the timer here
		static Timer* CreateTimer();
	};

}