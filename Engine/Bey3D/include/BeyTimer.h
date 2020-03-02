#ifndef __BEY_3D_TIMER_H__
#define __BEY_3D_TIMER_H__

#include <chrono>

class BeyTimer
{
public:
	BeyTimer() noexcept;

	float Mark() noexcept;
	float Peek() const noexcept;

private:
	std::chrono::steady_clock::time_point last;
};

#endif // __BEY_3D_TIMER_H__
