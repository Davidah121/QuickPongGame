#pragma once
#include <Windows.h>
#include "Image.h"

class Window
{
public:
	Window(int width, int height);
	~Window();

	void setWindowPixels(Image* c);
	int getWidth();
	int getHeight();

	void processMessages();

	bool windowExists();
	void close();

	HWND getWindowHandle();
	HBITMAP getWindowImage();

	static void setStaticWindow(Window* windowHandle);
	static Window* getStaticWindow();

private:
	static Window* staticWindow;

	unsigned char* windowPixels = nullptr;
	int width = 0;
	int height = 0;

	WNDCLASSEX wndClass;
	HWND windowHandle;
	HBITMAP bitmapHandle;
	BITMAPINFO info;
	HINSTANCE hIns;

	HDC hdc;
};

