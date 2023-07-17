#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"
#include "yaSceneManager.h"
#include "yaCollisionManager.h"

namespace ya
{
	

	Application::Application()
		: graphicDevice(nullptr)
		, mHwnd(NULL)
		, mWidth(-1)
		, mHeight(-1) 
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();

	}
	void Application::Initialize()
	{
		Time::Initialize();
		Input::Initialize();

		renderer::Initialize();
		SceneManager::Initialize();

		//CollisionManager::Initialize();

	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();

		CollisionManager::Update();
	}
	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		Time::Render();

		graphicDevice->ClearTarget();
		graphicDevice->UpdateViewPort();
		//SceneManager::Render();
		renderer::Render();
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Present()
	{
		graphicDevice->Present();
	}
	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mWidth = width;
			mHeight = height;

			graphicDevice = std::make_unique<ya::graphics::GraphicDevice_Dx11>();
			ya::graphics::GetDevice() = graphicDevice.get();
		}

		RECT rt{ 0, 0, (LONG)width,(LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}
}
