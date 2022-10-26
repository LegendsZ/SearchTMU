#include "Timer.h"

Timer::Timer()
{
}

bool Timer::start()
{
	m_Start = std::chrono::steady_clock::now();
	return true;
}

bool Timer::stop()
{
	m_Stop = std::chrono::steady_clock::now();
	return true;

	
}

long long Timer::getNanoseconds()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(m_Stop - m_Start).count();
}

long long Timer::getMicroseconds()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(m_Stop - m_Start).count();
}

long long Timer::getMilliseconds()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_Stop - m_Start).count();
}

long long Timer::getSeconds()
{
	return std::chrono::duration_cast<std::chrono::seconds>(m_Stop - m_Start).count();
}

bool Timer::print()
{
	std::cout << "Statistics\nNanoseconds: " << getNanoseconds() << "\nMicroseconds: " << getMicroseconds() << "\nMilliseconds: " << getMilliseconds() << "\nSeconds: " << getSeconds() << "\n";
	return true;
}
