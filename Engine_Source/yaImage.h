#pragma once
#include "yaResource.h"
<<<<<<< HEAD
#include "yaApplication.h"

extern ya::Application application;
=======

>>>>>>> d9a94a9551f41f858dde7da4e143a0c74f01405b
namespace ya
{
	class Image : public ya::Resource
	{
	public:
		//static std::shared_ptr<Image> Create(const std::wstring& name, UINT widht, UINT height, COLORREF rgb = RGB(255, 255, 255));

		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetHdc() { return mHdc; }
		HBITMAP GetBitmap() { return mBitmap; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

		COLORREF GetPixel(int x, int y);
		void SetPixel(int x, int y, COLORREF color);

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}
