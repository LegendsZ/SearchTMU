#include "TimerCustom.h"

TimerCustom::TimerCustom()
{
}

bool TimerCustom::start()
{
	m_Start = std::chrono::steady_clock::now();
	return true;
}

bool TimerCustom::stop()
{
	m_Stop = std::chrono::steady_clock::now();
	return true;


}

long long TimerCustom::getNanoseconds()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(m_Stop - m_Start).count();
}

long long TimerCustom::getMicroseconds()
{
	return std::chrono::duration_cast<std::chrono::microseconds>(m_Stop - m_Start).count();
}

long long TimerCustom::getMilliseconds()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(m_Stop - m_Start).count();
}

long long TimerCustom::getSeconds()
{
	return std::chrono::duration_cast<std::chrono::seconds>(m_Stop - m_Start).count();
}

bool TimerCustom::print()
{
	//std::cout << "Statistics\nNanoseconds: " << getNanoseconds() << "\nMicroseconds: " << getMicroseconds() << "\nMilliseconds: " << getMilliseconds() << "\nSeconds: " << getSeconds() << "\n";
	return false;
}
