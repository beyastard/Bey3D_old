#pragma once
#include "Window.h"
#include "BeyTimer.h"

class App
{
public:
	App();
	~App();

	// master frame / message loop
	int Go();
	
private:
	void DoFrame();

private:
	Window wnd;
	BeyTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};