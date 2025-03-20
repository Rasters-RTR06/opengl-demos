// custom header files
#include "Raster.h"
#include "../common/common.h"
#include "SceneRender.c"

// OpenGL realated libraries
#pragma comment(lib, "opengl32.lib")

// Macros
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
// variables related with fullscreen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// variable related to file I/O
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// active window related variables
BOOL gbActiveWindow = FALSE;

// Exit keypress related variables
BOOL gbEscapeKeyIsPressed = FALSE;

//	time interval to update the update()
UINT timeInterval = 100; //	10 * updateInterval = 1 sec

// Opengl related global variable
HDC ghdc = NULL;   // global handle to device context
HGLRC ghrc = NULL; // global handle to rendering context (rc -> rendering context, HGLRC -> handle to openGL rendering context)

// Demo Required global Variables
UINT_PTR timerId = 1;
UINT iTimeElapsed = 0;

// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// local function declarations
	int initialize(void);
	void display(void);
	void uninitialize(void);
	void update(void);

	// Variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR06");
	BOOL bDone = FALSE;

	// create log file
	gpFile = fopen(gszLogFileName, "w");
	if (gpFile == NULL)
	{
		MessageBox(HWND_DESKTOP, TEXT("Log file creation failed"), TEXT("File I/O error!!"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program (Raster.exe) started successfully\n");
	}

	int screenWidth = GetSystemMetrics(SM_CXFULLSCREEN);
	if (screenWidth == 0)
	{
		fprintf(gpFile, "GetSystemMetrics() failed for width...\n");
		exit(0);
	}
	int screenHeight = GetSystemMetrics(SM_CYFULLSCREEN);
	if (screenHeight == 0)
	{
		fprintf(gpFile, "GetSystemMetrics() failed for height...\n");
		exit(0);
	}

	int windowStartX = (screenWidth / 2) - (WIN_WIDTH / 2);
	int windowStartY = (screenHeight / 2) - (WIN_HEIGHT / 2);

	// code
	// window class initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Registration of window class
	RegisterClassEx(&wndclass);

	// Create window
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
		TEXT("RASTER GROUP"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		windowStartX, // window center x start - to be calculated as part of window
		windowStartY, // window center y start - to be calculated as part of window
		WIN_WIDTH,	  // WIN_WIDTH
		WIN_HEIGHT,	  // WIN_HEIGHT
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;

	// show window
	ShowWindow(hwnd, iCmdShow);

	// paint background of window
	UpdateWindow(hwnd);

	// initialize
	int result = initialize();

	if (result != 0)
	{
		fprintf(gpFile, "initialize() failed...\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "initialize() success...\n");
	}

	// set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// game loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
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
			if (gbActiveWindow == TRUE)
			{
				if (gbEscapeKeyIsPressed == TRUE)
				{
					bDone = TRUE;
				}
				// update
				update();

				// render
				display();
			}
		}
	}

	// uninitialize
	uninitialize();

	return ((int)msg.wParam);
}

// window callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// local function prototypes
	void toggleFullScreen();
	void resize(int, int);
	void uninitialize(void);

	// local variable declarations

	// code
	switch (iMsg)
	{
	case WM_CREATE:
		ZeroMemory((void *)&wpPrev, sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;

	case WM_SETFOCUS:
		gbActiveWindow = TRUE;
		break;

	case WM_KILLFOCUS:
		gbActiveWindow = FALSE;
		break;

	case WM_ERASEBKGND:
		return (0);

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			gbEscapeKeyIsPressed = TRUE;
			break;

		default:
			break;
		}
		break;

	case WM_TIMER:
		iTimeElapsed++;
		break;
	case WM_CLOSE:
		uninitialize();
		break;

	case WM_CHAR:
		switch (wParam)
		{
		case 'F':
		case 'f':
			if (gbFullScreen == FALSE)
			{
				fprintf(gpFile, "Window entered fullscreen mode\n");
				toggleFullScreen();
				gbFullScreen = TRUE;
			}
			else
			{
				fprintf(gpFile, "Window exited fullscreen mode\n");
				toggleFullScreen();
				gbFullScreen = FALSE;
			}
			break;

		case 'S':
		case 's':
			// Scene skipping
			fprintf(gpFile, "Scene skipping requested\n");
			if (currentScene && currentScene->shouldTransition && currentScene->nextScene)
			{
				if (currentScene->shouldTransition(TRUE))
				{
					fprintf(gpFile, "Transitioning to next scene at time %d seconds\n", iTimeElapsed);
					currentScene = currentScene->nextScene;
				}
			}
			break;
		default:
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		break;
	}
	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen()
{
	// variable declarations
	MONITORINFO mi;

	// code
	if (gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			ZeroMemory((void *)&mi, sizeof(MONITORINFO));
			mi.cbSize = sizeof(MONITORINFO);
			if (GetWindowPlacement(ghwnd, &wpPrev) &&
				GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(
					ghwnd,
					HWND_TOP,
					mi.rcMonitor.left,
					mi.rcMonitor.top,
					mi.rcMonitor.right - mi.rcMonitor.left,
					mi.rcMonitor.bottom - mi.rcMonitor.top,
					SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		// optional - hides cursor when endered full screen mode
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(
			ghwnd,
			HWND_TOP,
			0,
			0,
			0,
			0,
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}

int initialize(void)
{
	// function declarations
	void printGLInfo(void);

	// variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

	// code
	//  pixelformatdescriptor initialization
	ZeroMemory((void *)&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32; // c => count
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	// get device context
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() failed in initialize...\n");
		return (-1);
	}

	// get matching pixel format index using hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() call failed in initialize...\n");
		return (-2);
	}

	// select pixel format of found index
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() failed in initialize...\n");
		return (-3);
	}

	// create rendering context using hdc pfd and chosen pixelformatindex
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() failed in initialize...\n");
		return (-4);
	}

	// make this rendering context as current context
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() failed in initialize...\n");
		return (-5);
	}

	// from here onwards openGL code starts
	// tell openGL to choose color to clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	printGLInfo();

	// checkout https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-settimer
	timerId = SetTimer(ghwnd, timerId, 100, (TIMERPROC)NULL);

	if (timerId == 0)
	{
		// Handle timer creation error
		fprintf(gpFile, "SetTimer failed\n");
		return -1;
	}

	// Initialize the scene chain
	initScenes();

	return 0;
}

void printGLInfo(void)
{
	// code
	// printglinfo
	fprintf(gpFile, "*******************OPENGL INFORMATION*******************\n");
	fprintf(gpFile, "|- OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "|- OpenGL Renderer: %s\n", glGetString(GL_RENDERER));
	fprintf(gpFile, "|- OpenGL Version: %s\n", glGetString(GL_VERSION));

	fprintf(gpFile, "********************************************************\n");
}

void resize(int width, int height)
{
	// code
	// if by accident if height becomes 0 then make height 1
	if (height <= 0)
	{
		height = 1;
	}

	// set the view port
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
	// code
	// clear openGL bufferes
	glClear(GL_COLOR_BUFFER_BIT);

	//	enable alpha blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// Render current scene
	renderCurrentScene();

	glDisable(GL_BLEND);

	// swap the bufferes
	SwapBuffers(ghdc); // win32 function
}

void update(void)
{
	// Update current scene with the current time
	updateCurrentScene(iTimeElapsed);
}

void uninitialize(void)
{
	// function declarations
	void toggleFullScreen(void);

	// code
	// if full screen restore to normal as good habit and standard to follow
	if (gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}

	// make hdc as current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL); // null -> default | make the dc as current context
	}

	// kill timer
	if (timerId != 0)
	{
		KillTimer(ghwnd, timerId);
	}

	// delete rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// release the device context
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// distroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close the file
	if (gpFile)
	{
		fprintf(gpFile, "Program terminated successfully");
		fclose(gpFile);
		gpFile = NULL;
	}
}
