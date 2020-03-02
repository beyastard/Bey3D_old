#ifndef __BEY_3D_GRAPHICS_H__
#define __BEY_3D_GRAPHICS_H__

#include "BeyWin.h"
#include <d3d11.h>

class Graphics
{
public:
	Graphics(HWND hWnd);
	Graphics(const Graphics&) = delete;
	Graphics& operator=(const Graphics&) = delete;
	~Graphics();

	void EndFrame();

private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
};

#endif // __BEY_3D_GRAPHICS_H__
