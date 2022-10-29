#pragma once

#include <chrono>

class TimerCustom {
public:
	TimerCustom();
	bool start();
	bool stop();
	long long getNanoseconds();
	long long getMicroseconds();
	long long getMilliseconds();
	long long getSeconds();
	bool print();
private:
	std::chrono::steady_clock::time_point m_Start;
	std::chrono::steady_clock::time_point m_Stop;
};