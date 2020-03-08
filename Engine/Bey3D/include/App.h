#pragma once

#include "Window.h"
#include "BeyTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "Mesh.h"

class App
{
public:
	App();
	~App();

	// master frame / message loop
	int Go();
	
private:
	void DoFrame();
	void ShowImguiDemoWindow();
	void ShowRawInputWindow();

private:
	ImguiManager imgui;
	Window wnd;
	BeyTimer timer;

	float speed_factor = 1.0f;

	int x = 0, y = 0;

	Camera cam;
	PointLight light;

	Model girl{ wnd.Gfx(),"Models/girl.fbx" };
};
