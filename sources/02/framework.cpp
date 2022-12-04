/***********************************************************************************
 * LearnDirectX11 Project                                                          *
 * @file framework.cpp                                                             *
 * @date 12/3/2022                                                                 *
 * @author Chirs Cheng                                                             *
 * @copyright Copyright (c) 2022 Chris Cheng                                       *
 ***********************************************************************************
 * Permission is hereby granted, free of charge, to any person obtaining a copy    *
 * of this software and associated documentation files (the "Software"), to deal   *
 * in the Software without restriction, including without limitation the rights    *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is           *
 * furnished to do so, subject to the following conditions:                        *
 *                                                                                 *
 * The above copyright notice and this permission notice shall be included in all  *
 * copies or substantial portions of the Software.                                 *
 *                                                                                 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE     *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE   *
 * SOFTWARE.                                                                       *
 ***********************************************************************************/

#include "framework.h"

Framework::Framework(HINSTANCE hInstance) {
	m_Input = nullptr;
	m_Graphics = nullptr;
	window.m_hInstance = hInstance;
}
Framework::Framework(const Framework&){}
Framework::~Framework() {}

bool Framework::Initialize()
{
	bool result;

	InitializeWindows();

	m_Input = new InputClass;
	m_Input->Initialize();

	m_Graphics = new GraphicsClass;
	if (!m_Graphics->Initialize(window.width, window.height, window.m_hWnd))
	{
		return false;
	}
	return true;
}

void Framework::Shutdown()
{
	if (m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = nullptr;
	}

	if (m_Input)
	{
		delete m_Input;
		m_Input = nullptr;
	}

	ShutdownWindows();
}

void Framework::Run()
{
	MSG msg = {};

	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		
		if (!Frame()){
			PostQuitMessage(0);
		}
	}
}

bool Framework::Frame()
{
	bool result;

	if (m_Input->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	result = m_Graphics->Frame();
	if (!result)
	{
		return false;
	}

	return true;
}
LRESULT CALLBACK Framework::MessageHandler(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
	{
		m_Input->KeyDown((unsigned int)wParam);
		return 0;
	}
	case WM_KEYUP:
	{
		m_Input->KeyUp((unsigned int)wParam);
		return 0;
	}
	default:
	{
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	}
}

void Framework::InitializeWindows()
{
	appHandle = this;
	WNDCLASSEX wcex;

	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = window.m_hInstance;
	wcex.hIcon = LoadIcon(nullptr, IDI_WINLOGO);
	wcex.hIconSm = wcex.hIcon;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = window.m_APP_NAME;
	wcex.cbSize = sizeof(WNDCLASSEX);
	  
	RegisterClassEx(&wcex);

	int posX = (GetSystemMetrics(SM_CXSCREEN) - window.width) / 2;
	int posY = (GetSystemMetrics(SM_CYSCREEN) - window.height) / 2;

	window.m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, window.m_APP_NAME, window.m_title,
		WS_OVERLAPPEDWINDOW,
		posX, posY, window.width, window.height, nullptr, nullptr, window.m_hInstance, nullptr);

	ShowWindow(window.m_hWnd, SW_SHOW);
	SetForegroundWindow(window.m_hWnd);
	SetFocus(window.m_hWnd);
}

void Framework::ShutdownWindows()
{
	DestroyWindow(window.m_hWnd);
	window.m_hWnd = nullptr;

	UnregisterClass(window.m_APP_NAME, window.m_hInstance);
	window.m_hInstance = nullptr;

	appHandle = nullptr;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	default:
	{
		return appHandle->MessageHandler(hWnd, uMsg, wParam, lParam);
	}
	}
}

