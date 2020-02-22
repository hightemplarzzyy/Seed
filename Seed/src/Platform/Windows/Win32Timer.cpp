#include "Seedpch.h"
#include "Win32Timer.h"

namespace Seed {

	Win32Timer::Win32Timer()
	{
		m_Members = CreateScope<Members>();
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		m_Members->m_Frequency = 1.0 / frequency.QuadPart;
		QueryPerformanceCounter(&m_Members->m_Start);
	}

	float Win32Timer::GetTime()
	{
		LARGE_INTEGER current;
		QueryPerformanceCounter(&current);
		uint64_t cycles = current.QuadPart - m_Members->m_Start.QuadPart;
		return (float)(cycles * m_Members->m_Frequency);
	}

}