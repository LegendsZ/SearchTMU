#pragma once

#include <chrono>
#include <iostream>

class Timer {
public:
	Timer();
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