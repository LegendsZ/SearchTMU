#pragma once

#include <chrono>
#include <string>
#include <iostream>

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
	System::String^ toString();

private:
	std::chrono::steady_clock::time_point m_Start;
	std::chrono::steady_clock::time_point m_Stop;
};