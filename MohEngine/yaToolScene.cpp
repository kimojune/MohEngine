#include "yaToolScene.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaImage.h"
#include "yaApplication.h"
#include "yaTilePalatte.h"
#include "yaGrid.h"
#include "yaGridScript.h"
#include "yaMainCamera.h"
#include "yaCursor.h"
#include "yaWorldCursor.h"
#include "yaTileScript.h"
#include "yaResources.h"
#include "yaMeshRenderer.h"
#include "yaAnimator.h"
#include "yaTexture.h"
#include "yaInput.h"

using namespace ya;

extern ya::Application application;
static std::vector<std::shared_ptr <ya::Image>> tileatlases = {};
static UINT atlasIndex = 0;

namespace ya
{

	ToolScene::ToolScene()
		:mAtlasIndex(0)
	{
		SetName(L"ToolScene");
	}

	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		MainCamera* mCamera = new MainCamera();
		//UICamera* uicamera = new UICamera();
		Cursor* cursor = new Cursor;
		WorldCursor* wCursor = new WorldCursor();
		wCursor->AddComponent<TileScript>();

		TilePalatte::Intialize();


		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::O))
			atlasIndex++;
		
		if (Input::GetKeyDown(eKeyCode::P))
			atlasIndex--;
			

		if (atlasIndex >= (UINT)eAtlasType::End)
			atlasIndex = 0;
			
		if (atlasIndex < 0)
			atlasIndex = (UINT)eAtlasType::End - 1;
			
		UpdateWindow(application.GetToolHwnd());
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();
	}

	void ToolScene::Render()
	{
		Scene::Render();
	}

	void ToolScene::OnEnter()
	{
		TilePalatte::Clear();
	}

	void ToolScene::OnExit()
	{
	}
}




LRESULT CALLBACK AtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
		//case WM_KEYDOWN:
		//{

		//}

	case WM_COMMAND:
	{
	case WM_CREATE:
	{
		tileatlases.resize((UINT)ya::ToolScene::eAtlasType::End);

		tileatlases[0] = ya::Resources::Load<ya::Image >(L"ENV_Tileset_Castle", L"..\\Resources\\Tile\\ENV_Tileset_Castle\\ENV_Tileset_Castle.bmp");
		tileatlases[1] = ya::Resources::Load<ya::Image >(L"ENV_Stamps_Castle", L"..\\Resources\\Tile\\ENV_Tileset_Castle\\ENV_Stamps_Castle.bmp");
		tileatlases[2] = ya::Resources::Load<ya::Image >(L"shoptileset001", L"..\\Resources\\Tile\\ENV_Tileset_Castle\\shoptileset001.bmp");
		

		RECT rect = { 0, 0, tileatlases[atlasIndex]->GetWidth(), tileatlases[atlasIndex]->GetHeight() };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(hWnd
			, nullptr, 1600, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(hWnd, true);
		
		ya::TilePalatte::Intialize();
	}
	case WM_LBUTTONDOWN:
	{

		if (GetFocus())
		{
			::POINT mousePos = {};
			::GetCursorPos(&mousePos);
			::ScreenToClient(application.GetToolHwnd(), &mousePos);

			int x = mousePos.x / TILE_SIZE_X;
			int y = mousePos.y / TILE_SIZE_Y;

			int MAX_X = tileatlases[atlasIndex]->GetWidth() / TILE_SIZE_X;
			int MAX_Y = tileatlases[atlasIndex]->GetHeight() / TILE_SIZE_Y;

			int index = (y * MAX_X) + (x % MAX_X);
			
			ya::TilePalatte::SetIndex(index);
		}
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		std::shared_ptr <ya::Image> tile
			= tileatlases[atlasIndex];

		
		::BitBlt(hdc, 0, 0, tile->GetWidth(), tile->GetHeight(), tile->GetHdc(), 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		////Ellipse(hdc, 500, 500, 600, 700);
		////RoundRect(hdc, 200, 200, 300, 300, 500, 500);

		//// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
	}
	int wmId = LOWORD(wParam);
	// 메뉴 선택을 구문 분석합니다:
	switch (wmId)
	{
		//case IDM_ABOUT:
		//    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		//    break;
		//case IDM_EXIT:
		//    DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}
	break;
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}