#ifndef __WINDOWS_MESSAGE_MAP_H__
#define __WINDOWS_MESSAGE_MAP_H__

#include <unordered_map>
#include <Windows.h>

class WindowsMessageMap
{
public:
	WindowsMessageMap();
	std::string operator()(DWORD msg, LPARAM lp, WPARAM wp) const;
private:
	std::unordered_map<DWORD, std::string> map;
};

#endif // __WINDOWS_MESSAGE_MAP_H__
