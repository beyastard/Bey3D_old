#include "App.h"


App::App() : wnd(1140, 600, "Bey3D Engine Window")
{

}

int App::Go()
{
	MSG msg;
	BOOL gResult;
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
	{
		// TranslateMessage will post auxiliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}

	// check if GetMessage call itself puked
	if (gResult == -1)
		throw BEYWND_LAST_EXCEPT();

	// wParam here is the value passed to PostQuitMessage
	return int(msg.wParam);
}

void App::DoFrame()
{

}
