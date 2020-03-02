#include "BeyTimer.h"

using namespace std::chrono;

BeyTimer::BeyTimer()
{
	last = steady_clock::now();
}

float BeyTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();

	const duration<float> frameTime = last - old;

	return frameTime.count();
}

float BeyTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}
