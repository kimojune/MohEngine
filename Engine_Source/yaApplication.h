#pragma once
#include "MohEngine.h"
#include "yaGraphicDevice_Dx11.h"


namespace ya
{

class Application
{
public:
	Application();
	~Application();

	void Run();

	void Initialize();
	void Update();
	void LateUpdate();
	void Render();
	void Destroy();

	void SetWindow(HWND hwnd, UINT width, UINT height);

	UINT GetWidth() { return mWidth; }
	UINT GetHeight() { return mHeight; }
	HWND GetHwnd() { return mHwnd; }
	
	void SetToolHwnd(HWND hwnd) { mToolHwnd = hwnd; }
	HWND GetToolHwnd() { return mToolHwnd; }
	

private:
	bool mbInitialize = false;
	
	//오로지 한개의 객체만 만들수 있는 스마트 포인터
	std::unique_ptr<ya::graphics::GraphicDevice_Dx11> graphicDevice;
	//HDC mhdc; -> GPU API;
	HWND mHwnd;
	//Tool
	HWND mToolHwnd;

	UINT mWidth;
	UINT mHeight;

};

}
