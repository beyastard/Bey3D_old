#pragma once

#include "Window.h"
#include "BeyTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"

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
	ImguiManager imgui;
	Window wnd;
	BeyTimer timer;
	Camera cam;
	PointLight light;

	std::vector<std::unique_ptr<class Drawable>> drawables;
	static constexpr size_t nDrawables = 180;
	float speed_factor = 1.0f;
};
