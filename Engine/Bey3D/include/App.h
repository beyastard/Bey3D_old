#pragma once

#include "Window.h"
#include "BeyTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
#include "Model.h"
#include <set>

class App
{
public:
	App();
	~App();

	// master frame / message loop
	int Go();
	
private:
	void DoFrame();
	void ShowModelWindow();

private:
	ImguiManager imgui;
	Window wnd;
	BeyTimer timer;
	Camera cam;
	PointLight light;

	float speed_factor = 1.0f;

	Model nano{ wnd.Gfx(),"models/Girl.obj" };

	struct
	{
		float roll = 0.0f;
		float pitch = 0.0f;
		float yaw = 0.0f;
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	} pos;
};
