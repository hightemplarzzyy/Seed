#pragma once

#include "Seed/Core/Timer.h"

namespace Seed {

	struct Members
	{
		LARGE_INTEGER m_Start;
		double m_Frequency;
	};

	class Win32Timer : public Timer
	{
	public:
		Win32Timer();
		virtual float GetTime() override;
	private:
		Scope<Members> m_Members;
	};

}