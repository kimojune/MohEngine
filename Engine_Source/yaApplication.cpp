#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaRenderer.h"

namespace ya
{
	static Vector4 pos(0.0f, 0.0f, 0.0f, 1.0f);

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

	}
	void Application::Initialize()
	{
		Time::Initialize();
		Input::Initialize();

		renderer::Initialize();
	}
	void Application::Update()
	{
		Time::Update();
		Input::Update();

		

	}
	void Application::LateUpdate()
	{

		if (Input::GetKey(eKeyCode::UP))
			pos.y += 5 * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::DOWN))
			pos.y -= 5 * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::LEFT))
			pos.x -= 5 * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::RIGHT))
			pos.x += 5 * Time::DeltaTime();

			
		ya::graphics::GetDevice()->SetConstantBuffer(ya::renderer::triangleConstantBuffer, &pos, sizeof(Vector4));
		ya::graphics::GetDevice()->BindConstantBuffer(eShaderStage::VS, eCBType::Transform, ya::renderer::triangleConstantBuffer);

	}
	void Application::Render()
	{
		Time::Render();

		graphicDevice->Draw();
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
