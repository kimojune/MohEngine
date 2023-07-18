#include "yaToolScene.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaImage.h"
#include "yaApplication.h"
#include "yaTilePalatte.h"
#include "yaGrid.h"
#include "yaGridScript.h"
#include "yaMainCamera.h"
#include "hoCursor.h"
#include "haWorldCursor.h"
#include "yaTileScript.h"

using namespace ho;

extern ya::Application application;
static MainCamera* mCamera = nullptr;

namespace ya
{

	ToolScene::ToolScene()
	{

		
		//GameObject* grid = new GameObject();
		//grid->SetName(L"Grid");
		//AddGameObject(eLayerType::Grid, grid);
		//MeshRenderer* mr = grid->AddComponent<MeshRenderer>();
		//mr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//mr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		//GridScript* gridSc = grid->AddComponent<GridScript>();
		//gridSc->SetCamera(camera->GetComponent<Camera>());

		//grid->GetScript()->SetCamera(camera->GetComponent<Camera>());

	}

	ToolScene::~ToolScene()
	{
	}

	void ToolScene::Initialize()
	{
		MainCamera* mCamera = new MainCamera();
		UICamera* uicamera = new UICamera();

		Cursor* cursor = new Cursor(uicamera);
		WorldCursor* wCursor = new WorldCursor(mCamera);
		wCursor->AddComponent<TileScript>();
		

		TilePalatte::Intialize();


		Scene::Initialize();
	}

	void ToolScene::Update()
	{


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
	}

	void ToolScene::OnExit()
	{
	}
}

static std::shared_ptr <ya::Image> tileatlas;

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
		tileatlas = std::make_shared<ya::Image>();
		tileatlas = ya::Resources::Load<ya::Image >(L"TileAtlas", L"..\\Resources\\Tile\\Tile.bmp");
		RECT rect = { 0, 0, tileatlas->GetWidth(), tileatlas->GetHeight() };
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

			int MAX_X = tileatlas->GetWidth() / TILE_SIZE_X;
			int MAX_Y = tileatlas->GetHeight() / TILE_SIZE_Y;

			int index = (y * MAX_X) + (x % MAX_X);
			
			ya::TilePalatte::SetIndex(index);
		}
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		std::shared_ptr <ya::Image> tile
			= ya::Resources::Find<ya::Image>(L"TileAtlas");
		::BitBlt(hdc, 0, 0, tile->GetWidth(), tile->GetHeight(), tile->GetHdc(), 0, 0, SRCCOPY);
		//Ellipse(hdc, 500, 500, 600, 700);
		//RoundRect(hdc, 200, 200, 300, 300, 500, 500);

		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
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