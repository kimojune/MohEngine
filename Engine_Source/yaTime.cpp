#include "yaTime.h"
#include "yaApplication.h"
#include "yaInput.h"

extern ya::Application application;

namespace ya
{
	double Time::mDeltaTime = 0.0l;
	double Time::mSecond = 0.0f;
	float Time::fps = 0.0f;
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};

	void Time::Initialize()
	{
		// CPU 고유 진동수 가져오기
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램이 처음 시작할때 진동수
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);

		double differnceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;

		mDeltaTime = differnceFrequency / mCpuFrequency.QuadPart;

		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}

	void Time::Render()
	{
		mSecond += mDeltaTime;

		HWND hWnd = application.GetHwnd();

		wchar_t szFloat[256] = {};
		Vector2 cursorPos = Input::GetMousePos();
		Vector2 mainCursorPos = Input::GetClientMousePos(enums::eCameraType::Main);
		Vector2 UICursorPos = Input::GetClientMousePos(enums::eCameraType::UI);

		if (mSecond > 1.0f)
		{
			fps = 1.0f / (float)mDeltaTime;
			mSecond = 0.0f;
		}
		//swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
		swprintf_s(szFloat, 256, L"FPS : %d | Window : %f, %f Main : %f, %f, UI %f, %f) "
			, (UINT)fps
			, cursorPos.x, cursorPos.y
			, mainCursorPos.x, mainCursorPos.y
			, UICursorPos.x, UICursorPos.y);

		SetWindowText(hWnd, szFloat);
	}
}
