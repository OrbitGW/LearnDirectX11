/***********************************************************************************
 * LearnDirectX11 Project                                                           *
 * @file framework.h                                                               *
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
#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#ifndef UNICODE
#define UNICODE
#endif

/***********************************************************************************
 * Includes                                                                        *
 ***********************************************************************************/
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "input.h"
#include "graphics.h"

 /***********************************************************************************
  * Classes                                                                         *
  ***********************************************************************************/
class Framework {
public:
	Framework(HINSTANCE hInstance);
	Framework(const Framework&);
	~Framework();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows();
	void ShutdownWindows();

private:
	struct {
		LPWSTR m_title = L"DX11 Window";
		LPCWSTR m_APP_NAME = L"DX11 Engine";
		HINSTANCE m_hInstance;
		HWND m_hWnd;
		UINT width = 800;
		UINT height = 600;
	}window;
	
	InputClass* m_Input;
	GraphicsClass* m_Graphics;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/***********************************************************************************
 * Globals                                                                         *
 ***********************************************************************************/
static Framework* appHandle = nullptr;

#endif