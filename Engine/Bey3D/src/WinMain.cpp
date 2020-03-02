﻿#include "Window.h"


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow)
{
	Window wnd(1140, 600, "Bey3D Engine Window");
	
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxiliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// check if GetMessage call itself puked
	if (gResult == -1)
		return -1;

	// wParam here is the value passed to PostQuitMessage
	return int(msg.wParam);
}
