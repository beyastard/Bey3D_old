#ifndef __BEY_3D_WINDOW_H__
#define __BEY_3D_WINDOW_H__

#include "BeyWin.h"
#include "BeyException.h"
#include "Keyboard.h"
#include "Mouse.h"
#include <optional>
#include "Graphics.h"

class Window
{
public:
	class Exception : public BeyException
	{
	public:
		Exception(int line, const char* file, HRESULT hr) noexcept;
		const char* what() const noexcept override;
		virtual const char* GetType() const noexcept;
		static std::string TranslateErrorCode(HRESULT hr) noexcept;
		HRESULT GetErrorCode() const noexcept;
		std::string GetErrorString() const noexcept;

	private:
		HRESULT hr;
	};

private:
	// singleton manages registration/cleanup of window class
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;

	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "Bey3D Engine Window";
		static WindowClass wndClass;
		HINSTANCE hInst;
	};

public:
	Window(int width, int height, const char* name);
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void SetTitle(const std::string& title);
	static std::optional<int> ProcessMessages(); // std::optional seems to have some problems with x64
	Graphics& Gfx();

private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

public:
	Keyboard kbd;
	Mouse mouse;

private:
	int width;
	int height;
	HWND hWnd;
	std::unique_ptr<Graphics> pGfx;
};

// error exception helper macro
#define BEYWND_EXCEPT(hr) Window::Exception(__LINE__, __FILE__, hr)
#define BEYWND_EXCEPT(hr) Window::Exception(__LINE__, __FILE__, hr)
#define BEYWND_LAST_EXCEPT() Window::Exception(__LINE__, __FILE__, GetLastError())

#endif // __BEY_3D_WINDOW_H__
