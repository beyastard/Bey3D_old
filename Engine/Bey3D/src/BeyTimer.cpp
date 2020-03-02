#include "BeyTimer.h"

using namespace std::chrono;

BeyTimer::BeyTimer() noexcept
{
	last = steady_clock::now();
}

float BeyTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();

	const duration<float> frameTime = last - old;

	return frameTime.count();
}

float BeyTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
