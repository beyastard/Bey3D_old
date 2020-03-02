#ifndef __WINDOWS_MESSAGE_MAP_H__
#define __WINDOWS_MESSAGE_MAP_H__

#include <unordered_map>
#include "BeyWin.h"

class WindowsMessageMap
{
public:
	WindowsMessageMap() noexcept;
	std::string operator()(DWORD msg, LPARAM lp, WPARAM wp) const noexcept;
private:
	std::unordered_map<DWORD, std::string> map;
};

#endif // __WINDOWS_MESSAGE_MAP_H__
