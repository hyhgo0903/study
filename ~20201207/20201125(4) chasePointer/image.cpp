#include "stdafx.h"
#include "image.h"


image::image()
	: _backBuffer(NULL)
{
}


image::~image()
{
}

HRESULT image::init(int width, int height)
{
	if (_backBuffer != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_backBuffer = new IMAGE_INFO;
	_backBuffer->hMemDC = CreateCompatibleDC(hdc);
	_backBuffer->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_backBuffer->hOBit = (HBITMAP)SelectObject(_backBuffer->hMemDC, _backBuffer->hBit);
	_backBuffer->width = width;
	_backBuffer->height = height;

	
	if (_backBuffer == NULL)
	{
		release();

		return E_FAIL;
	}



	ReleaseDC(_hWnd, hdc);


	return S_OK;
}

void image::release()
{
	if (_backBuffer)
	{
		SelectObject(_backBuffer->hMemDC, _backBuffer->hOBit);
		DeleteObject(_backBuffer->hBit);
		DeleteDC(_backBuffer->hMemDC);

		SAFE_DELETE(_backBuffer);
	}

}

void image::render(HDC hdc, int destX, int destY)
{
	//�갡 �װ��Դϴ� DC���� ���� ���Ӻ��縦 ���ִ� �Լ�
	BitBlt(hdc,					//������ DC
		destX,					//������ ��ǥ X (left)
		destY,					//������ ��ǥ Y (top)
		_backBuffer->width,		//������ ũ��
		_backBuffer->height,	
		_backBuffer->hMemDC,	//����� DC
		0, 0,					//����� ������ (left, top)
		SRCCOPY);				//�������� �����Ұ���
}