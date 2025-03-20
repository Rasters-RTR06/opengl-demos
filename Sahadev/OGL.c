// Win32 headers
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "Sahadev.c"

// OpenGL related header file
#include <gl/GL.h>

// Custom header files
#include "OGL.h"

// OpenGL related libraries
#pragma comment(lib, "opengl32.lib")

// macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //FUNCTION DECLARATION/PROTOTYPE/SIGNATURE

// global variable declarations
// variables related with full screen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// OpenGL related global variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

// variables related with file I/O
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// active window related variable
BOOL gbActiveWindow = FALSE;

// exit key press related
BOOL gbEscapeKeyIsPressed = FALSE;

// Entry-point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// local function declarations
	int initialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);

	// variable declarations
	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");
	BOOL bDone = FALSE;

	// create log file
	gpFile = fopen(gszLogFileName, "w");
	
	if(gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log file creation failed"), TEXT("File I/O error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program Started Successfully\n");
	}

	// window class initialization
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);

	int window_x = (screen_width / 2) - (WIN_WIDTH /2);
	int window_y = (screen_height / 2) - (WIN_HEIGHT /2);


	// Registration of Window class
	RegisterClassEx(&wndClass);

	// Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("VISHAL V. KAMBLE"), 
			WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
			window_x,
			window_y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
	
	ghwnd = hwnd;

	// Show window
	ShowWindow(hwnd, iCmdShow);

	// Paint background of the window
	UpdateWindow(hwnd);

	// initialize
	int result = initialize();

	if(result != 0)
	{
		fprintf(gpFile, "Initialized function failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "Initialized Functions completed successfully\n");
	}

	// set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// Game loop
	while(bDone == FALSE)
	{
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

		}
		else
		{
			if (gbActiveWindow = TRUE)
			{
				if(gbEscapeKeyIsPressed == TRUE)
				{
					bDone = TRUE;
				}

				// render
				display();

				// update
				update();
			}
		}
	}

	// uninitialize
	uninitialize();

	return((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	void resize(int, int);
	void uninitialize(void);


	// local function declarations
	void toggleFullScreen(void);

	//code
	switch(iMsg)
	{
		case WM_CREATE :
			ZeroMemory((void *) &wpPrev, sizeof(WINDOWPLACEMENT));
			wpPrev.length = sizeof(WINDOWPLACEMENT);
			break;

		case WM_SETFOCUS :
			gbActiveWindow = TRUE;
			break;

		case WM_KILLFOCUS :
			gbActiveWindow = FALSE;
			break;

		case WM_ERASEBKGND :
			return(0);

		case WM_SIZE :
			resize(LOWORD(lParam), HIWORD(lParam));
			break;

		case WM_KEYDOWN :
			switch(wParam)
			{
				case VK_ESCAPE :
					gbEscapeKeyIsPressed = TRUE;
					break;

				default :
					break;
			}
			break;

		case WM_CHAR :
			switch(wParam)
			{
				case 'F' :

				case 'f' :
					if (gbFullScreen == FALSE)
					{
						toggleFullScreen();
						gbFullScreen = TRUE;
					}
					else
					{
						toggleFullScreen();
						gbFullScreen = FALSE;
					}
					break;

				default:
					break;
			}
			break;

		case WM_CLOSE :
			uninitialize();
			break;

		case WM_DESTROY :
			PostQuitMessage(0);
			break;
		
		default:
			break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen(void)
{
	// variable declarations
	MONITORINFO mi;

	// code
	GetWindowLong(ghwnd,GWL_STYLE);

	if (gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			ZeroMemory((void *) &mi, sizeof(MONITORINFO));
			mi.cbSize = sizeof(MONITORINFO);
			
			if (GetWindowPlacement(ghwnd, &wpPrev) && (GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi)))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(	FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}

int initialize(void)
{
	// Variable declaratios
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	
	// code

	// PIXELFORMATDESCRIPTOR initialization
	ZeroMemory((void *) &pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	
	// GetDC
	ghdc = GetDC(ghwnd);

	if(ghdc == NULL)
	{
		fprintf(gpFile, "GetDC function failed\n");
		return(-1);
	}

	// Get matching pixel format index using hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	
	if(iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() failed\n");
		return(-2);
	}

	// Select the pixel format of found index
	if(SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat format function failed\n");
		return(-3);
	}

	// Create rendering context using hdc, pfd and iPixelFormatIndex and chosen pixel format index
	ghrc = wglCreateContext(ghdc);

	if(ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext function failed\n");
		return(-4);
	}

	// Make this rendering contect as current context
	if(wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wgl make current function failed\n");
		return(-5);
	}

	// From here onwards OpenGL code starts

	// Tell OpenGL to choose colour to clear the sceeen
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	return(0);
}

void resize(int width, int height)
{
	// code

	//height by accident becomes 0 or less than 0 then make height 1
	if(height <= 0)
	{
		height = 1;
	}

	// set the viewport
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);


}

void display(void)
{
	// code

	// clear OpenGL buffers
	glClear(GL_COLOR_BUFFER_BIT);

	drawSahadev(0.0f, 0.0f, 1.0f, 1);

    glEnd();
	// Swap the buffers
	SwapBuffers(ghdc);
}

void update(void)
{
	// code

}

void uninitialize(void)
{
	// function declarations
	void toggleFullScreen(void);

	// code

	// If user is exitting in fullscreen then restore the fullscreen back to normal
	if(gbFullScreen = TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}

	// Make hdc as currect context by releasing rendering context as current context
	if(wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	// Delete the rendering context
	if(ghrc)		
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// Release the DC
	if(ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// Destroy window
	if(ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close the file
	if(gpFile)
	{
		fprintf(gpFile,"Program Terminated Successfully\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}
