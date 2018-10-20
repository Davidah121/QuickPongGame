#include "Window.h"
#include <iostream>
#include "Input.h"

Window* Window::staticWindow = nullptr;

LRESULT CALLBACK windowProc(HWND wndHandle, UINT unit, WPARAM wParam, LPARAM lParam)
{
	HWND wnd;
	PAINTSTRUCT ps;
	HDC paintDC;
	HDC mem;
	BITMAP img;
	HGDIOBJ oldImg;
	switch (unit)
	{
	case WM_PAINT:
		
		wnd = Window::getStaticWindow()->getWindowHandle();

		paintDC = BeginPaint(wnd, &ps);
		mem = CreateCompatibleDC(paintDC);

		oldImg = SelectObject(mem, Window::getStaticWindow()->getWindowImage());
		GetObject(Window::getStaticWindow()->getWindowImage(), sizeof(BITMAP), &img);

		BitBlt(paintDC, 0, 0, img.bmWidth, img.bmHeight, mem, 0, 0, SRCCOPY);

		//SelectObject(mem, oldImg);
		DeleteDC(mem);

		EndPaint(wnd, &ps);

		break;
	case WM_KEYDOWN:

		if ((lParam & 0b00000010) == 0)
		{
			Input::setKeyPressed(wParam);
		}
		break;
	case WM_KEYUP:
		Input::setKeyUp(wParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);

		break;
	default:
		return DefWindowProc(wndHandle, unit, wParam, lParam);
	}
	
}

Window::Window(int width, int height)
{
	this->width = width;
	this->height = height;
	windowPixels = new unsigned char[width*height * 3];

	hIns = (HINSTANCE) GetWindowLong(GetConsoleWindow(), GWL_HINSTANCE);
	
	wndClass = WNDCLASSEX();
	ZeroMemory(&wndClass, sizeof(WNDCLASSEX));

	wndClass.cbClsExtra = 0;
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)BLACK_BRUSH + 1;
	wndClass.hCursor = LoadCursor(hIns, IDC_ARROW);
	wndClass.hIcon = LoadIcon(hIns, IDI_APPLICATION);
	wndClass.hIconSm = LoadIcon(hIns, IDI_APPLICATION);
	wndClass.hInstance = hIns;
	
	wndClass.lpfnWndProc = windowProc;
	wndClass.lpszClassName = "wndClassName";
	wndClass.lpszMenuName = "wndMenuName";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	
	if (!RegisterClassEx(&wndClass))
	{
		std::cout << "Failed to create window class" << std::endl;
	}

	windowHandle = CreateWindowEx(NULL, "wndClassName", "PONG", WS_OVERLAPPEDWINDOW, 0, 0, width+16, height+40, NULL, NULL, hIns, NULL);

	if (windowHandle == NULL)
	{
		std::cout << "Failed to create Window" << std::endl;
	}

	info.bmiColors->rgbBlue = 0;
	info.bmiColors->rgbRed = 0;
	info.bmiColors->rgbGreen = 0;
	info.bmiColors->rgbReserved = 0;

	info.bmiHeader.biBitCount = 24;
	info.bmiHeader.biClrImportant = 0;
	info.bmiHeader.biClrUsed = 0;
	info.bmiHeader.biCompression = BI_RGB;
	info.bmiHeader.biHeight = -height;
	info.bmiHeader.biPlanes = 1;
	info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	info.bmiHeader.biSizeImage = 0;
	info.bmiHeader.biWidth = width;
	info.bmiHeader.biXPelsPerMeter = 0;
	info.bmiHeader.biYPelsPerMeter = 0;

	hdc = GetDC(windowHandle);

	bitmapHandle = CreateCompatibleBitmap(hdc, width, height);

	ShowWindow(windowHandle, SW_SHOW);
}

Window::~Window()
{
	CloseWindow(this->windowHandle);
	DestroyWindow(this->windowHandle);

	UnregisterClass("wndClassName", hIns);

	DeleteObject(bitmapHandle);
	DeleteDC(hdc);
	delete[] windowPixels;
}

void Window::setWindowPixels(Image * c)
{
	int** pixels = c->getPixelData();
	
	for (int i = 0; i < c->getHeight(); i++)
	{
		for (int i2 = 0; i2 < c->getWidth()*3; i2+=3)
		{
			int value = pixels[i][i2/3];

			windowPixels[(i*width*3) + i2] = (value >> 8) & 0xFF; //blue
			windowPixels[(i*width*3) + i2 + 1] = (value >> 16) & 0xFF; //green
			windowPixels[(i*width*3) + i2 + 2] = (value >> 24) & 0xFF; //red
		}
	}

	SetDIBits(hdc, bitmapHandle, 0, height, &windowPixels[0], &info, DIB_RGB_COLORS);
	RedrawWindow(windowHandle, NULL, NULL, RDW_INVALIDATE);
}

int Window::getWidth()
{
	return width;
}

int Window::getHeight()
{
	return height;
}

void Window::processMessages()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

bool Window::windowExists()
{
	return IsWindow(windowHandle);
}

void Window::close()
{
	CloseWindow(windowHandle);
	DestroyWindow(windowHandle);
}

HWND Window::getWindowHandle()
{
	return windowHandle;
}

HBITMAP Window::getWindowImage()
{
	return bitmapHandle;
}

void Window::setStaticWindow(Window* wnd)
{
	staticWindow = wnd;
}

Window* Window::getStaticWindow()
{
	return staticWindow;
}
