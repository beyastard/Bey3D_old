#ifndef __BEY_3D_APP_H__
#define __BEY_3D_APP_H__

#include "Window.h"
#include "BeyTimer.h"

class App
{
public:
	App();
	
	int Go(); // master frame / message loop

private:
	void DoFrame();

private:
	Window wnd;
	BeyTimer timer;
};

#endif // __BEY_3D_APP_H__
