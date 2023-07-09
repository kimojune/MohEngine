#include "yaImage.h"


namespace ya
{
	/*std::shared_ptr<image> image::create(const std::wstring& name, uint widht, uint height, colorref rgb)
	{
		if (widht == 0 || height == 0)
			return nullptr;

		std::shared_ptr<image> image = resources::find<image>(name);
		if (image != nullptr)
			return image;

		image = std::make_shared<image>();
		hdc mainhdc = getdc(application.gethwnd());
		

		image->mbitmap = createcompatiblebitmap(mainhdc, widht, height);

		image->mhdc = createcompatibledc(mainhdc);

		hbitmap oldbitmap = (hbitmap)selectobject(image->mhdc, image->mbitmap);
		deleteobject(oldbitmap);

		image->mwidth = widht;
		image->mheight = height;

		image->setkey(name);
		resources::insert<image>(name, image);

		hbrush brush = createsolidbrush(rgb);
		hbrush oldbrush = (hbrush)selectobject(image->gethdc(), brush);
		::rectangle(image->gethdc(), -1, -1, image->mwidth + 1, image->mheight + 1);

		selectobject(image->gethdc(), oldbrush);
		deleteobject(brush);

		return image;*/
	//}
	Image::Image()
		: Resource(ya::enums::eResourceType::Image)
		, mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{


	}

	Image::~Image()
	{

	}

	HRESULT Image::Load(const std::wstring& path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr
			, path.c_str(), IMAGE_BITMAP
			, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr)
			return E_FAIL;

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth;
		mHeight = bitInfo.bmHeight;

		HDC mainDC = GetDC(application.GetHwnd());
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(oldBitmap);

		return S_OK;
	}

	COLORREF Image::GetPixel(int x, int y)
	{
		return ::GetPixel(mHdc, x, y);
	}
	void Image::SetPixel(int x, int y, COLORREF color)
	{
		::SetPixel(mHdc, x, y, color);
	}
}
