#include "yaToolScene.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaImage.h"

namespace ya
{

    ToolScene::ToolScene()
    {
    }

    ToolScene::~ToolScene()
    {
    }

    void ToolScene::Initialize()
    {
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

    void ToolScene::OnEnter()
    {
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
       
        std::shared_ptr <ya::Image> tile = std::make_shared<ya::Image>();
        tile = ya::Resources::Load<ya::Image >(L"TileAtlas", L"..\\Resources\\Tile\\Tile.bmp");
        RECT rect = { 0, 0, 512, 512 };
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        SetWindowPos(hWnd
            , nullptr, 1600, 0
            , rect.right - rect.left
            , rect.bottom - rect.top
            , 0);
        ShowWindow(hWnd, true);
    }
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        std::shared_ptr <ya::Image> tile
            = ya::Resources::Find<ya::Image>(L"TileAtlas");
        ::BitBlt(hdc, 0, 0, tile->GetWidth(), tile->GetHeight(), tile->GetHdc(), 0, 0, SRCCOPY);
        Ellipse(hdc, 500, 500, 600, 700);
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