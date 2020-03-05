#pragma once

#include "Window.h"
#include "BeyTimer.h"
#include "ImguiManager.h"
#include "Camera.h"
#include "PointLight.h"
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
	void SpawnSimulationWindow() noexcept;
	void SpawnBoxWindowManagerWindow() noexcept;
	void SpawnBoxWindows() noexcept;

private:
	ImguiManager imgui;
	Window wnd;
	BeyTimer timer;
	Camera cam;
	PointLight light;

	std::vector<class Box*> boxes;
	std::vector<std::unique_ptr<class Drawable>> drawables;
	static constexpr size_t nDrawables = 180;
	float speed_factor = 1.0f;

	std::optional<int> comboBoxIndex;
	std::set<int> boxControlIds;
};
