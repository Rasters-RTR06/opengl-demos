//Standard Header Files
// Win32 headers
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
// OpenGL related header files
#include <gl/GL.h>
// Custom header files
#include "OGL.h"

//OpenGL Related Libraries
#pragma comment(lib, "opengl32.lib")

//Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable declarations
//variables related with FullScreen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

//variables related with File I/O
char gszLogFileName[] = "Log.txt";
FILE* gpFile = NULL;

//active window related variable
BOOL gbActiveWindow = FALSE;

//exit key press related
BOOL gbEscapeIsPressed = FALSE;

//OenGL Related Global Variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

//common variables
struct RGBColor {
	float rColorValue;
	float gColorValue;
	float bColorValue;
};

// Entry-Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//function declarations
	int initialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);

	// variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");
	BOOL bDone = FALSE;

	// code
	//Create Log File
	gpFile = fopen(gszLogFileName, "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File Creation Failed."), TEXT("File I/O Error.") , MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program Started Successfully.\n");
	}

	// Window class intialization
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

	// Registration of Window class
	RegisterClassEx(&wndclass);

	// Create window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, TEXT("Himanshu Choudhary"), WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) / 2) - (WIN_WIDTH / 2), (GetSystemMetrics(SM_CYSCREEN) / 2) - (WIN_HEIGHT / 2), WIN_WIDTH, WIN_HEIGHT, NULL, NULL, hInstance, NULL);

	ghwnd = hwnd;

	// Show window
	ShowWindow(hwnd, iCmdShow);

	// Paint background of window
	UpdateWindow(hwnd);

	//initialize
	int result = initialize();
	if (result != 0)
	{
		fprintf(gpFile, "Intialize() Failed.\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "Initialize() Completed Successfully.\n");
	}

	//set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//game loop
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
				if (gbEscapeIsPressed == TRUE)
				{
					bDone = TRUE;
				}

				//render
				display();

				//update
				update();
			}
		}
	}

	//uninitialize
	uninitialize();

	return((int)msg.wParam);
}

// Callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//local function declarations
	void toggleFullScreen(void);
	void resize(int, int);
	void uninitialize(void);

	// code
	switch(iMsg)
	{
	case WM_CREATE:
		ZeroMemory((void*)&wpPrev, sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break;
	case WM_SETFOCUS:
		gbActiveWindow = TRUE;
		break;
	case WM_KILLFOCUS:
		gbActiveWindow = FALSE;
		break;
	case WM_ERASEBKGND:
		return(0);
	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			gbEscapeIsPressed = TRUE;
			break;
		default:
			break;
		}
		break;
	case WM_CHAR:
		switch (wParam)
		{
		case 'F':
		case 'f':
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
	case WM_CLOSE:
		uninitialize();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void toggleFullScreen(void)
{
	//variable declarations
	MONITORINFO mi;

	//code
	 if (gbFullScreen == FALSE)
	 {
		 dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		 if (dwStyle & WS_OVERLAPPEDWINDOW)
		 {
			 ZeroMemory((void*)&mi, sizeof(MONITORINFO));
			 mi.cbSize = sizeof(MONITORINFO);
			 if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			 {
				 SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				 SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			 }
		 }
		 ShowCursor(FALSE);
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
	//variable declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

	//code
	//PIXELFORMATDESCRIPTOR initialization
	ZeroMemory((void *)&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	
	//Get DC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() Failed!!\n");
		return(-1);
	}

	//Get Matching Pixel Format Index Using hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() Failed!!\n");
		return(-2);
	}

	//Select the pixel format of found imdex
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() Failed!!\n");
		return(-3);
	}

	//Create Rendering Context using hdc, pfd and chosen pixel format index
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() Failed!!\n");
		return(-4);
	}

	//Make this rendering context as current context 
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() Failed!!\n");
		return(-5);
	}

	//From here onwards OpenGL code starts
	//Tell OpenGL to choose the color to clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return(0);
}

void resize(int width, int height)
{
	//code
	//If height by accident becomes 0 or less than 0 then make height 1
	if (height <= 0)
	{
		height = 1;
	}
	
	//Set the view port
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void drawLetterStroke(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3, float scalingFactor, float xOffset, float yOffset, int segments)
{
	x0 = x0 / scalingFactor - xOffset;
	x1 = x1 / scalingFactor - xOffset;
	x2 = x2 / scalingFactor - xOffset;
	x3 = x3 / scalingFactor - xOffset;

	y0 = y0 / scalingFactor - yOffset;
	y1 = y1 / scalingFactor - yOffset;
	y2 = y2 / scalingFactor - yOffset;
	y3 = y3 / scalingFactor - yOffset;

	glVertex2f(x0, y0);
	for (int i = 0; i <= segments; i++) {
		float t = (float)i / (float)segments;
		float x = (1 - t) * (1 - t) * (1 - t) * x0 + 3 * (1 - t) * (1 - t) * t * x1 + 3 * (1 - t) * t * t * x2 + t * t * t * x3;
		float y = (1 - t) * (1 - t) * (1 - t) * y0 + 3 * (1 - t) * (1 - t) * t * y1 + 3 * (1 - t) * t * t * y2 + t * t * t * y3;
		glVertex2f(x, y);
	}
}

void drawLetterSa(float scalingFactor, float xOffset, float yOffset, struct RGBColor letterColor, struct RGBColor backgroundColor)
{
	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.06f, 0.16f, 0.05f, 0.07f, -0.15f, 0.07f, -0.16f, 0.16f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.06f, 0.16f, 0.05f, 0.25f, -0.15f, 0.25f, -0.16f, 0.16f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper Tip
	drawLetterStroke(-0.7f, 0.12f, -0.8f, 0.11f, -0.8f, 0.01f, -0.65f, 0.0612f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	drawLetterStroke(-0.7f, 0.12f, -0.5f, 0.18f, -0.3f, 0.01f, -0.35f, -0.08f, scalingFactor, xOffset, yOffset, 1000);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.56f, -0.08f, -0.5f, -0.04f, -0.5f, 0.00f, -0.56f, 0.04f, scalingFactor, xOffset, yOffset, 1000);
	drawLetterStroke(-0.56f, 0.04f, -0.58f, 0.061f, -0.59f, 0.062f, -0.7f, 0.053f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Middle horizontal stick
	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glEnd();

	//Maatra line
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.08f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.07f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.78f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.50f / scalingFactor - yOffset);
	glVertex2f(-0.40f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	//Big stroke below stick
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.19f, -0.19f, 0.10f, -0.47f, -0.10f, -0.47f, -0.38f, -0.26f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Left Below stroke
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.40f, -0.45f, -0.63f, -0.12f, -0.71f, -0.10f, -0.78f, -0.14f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.78f, -0.14f, -0.82f, -0.16f, -0.82f, -0.05f, -0.78f, -0.07f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	//Little stroke for stick
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.16f, -0.17f, -0.18f, -0.24f, -0.22f, -0.27f, -0.24f, -0.29f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.29f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.50f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.30f, -0.355f, -0.38f, -0.21f, -0.47f, -0.18f, -0.50f, -0.14f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.23f / scalingFactor - yOffset);
	glVertex2f(0.19f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.56f, -0.08f, -0.58f, -0.09f, -0.69f, -0.092f, -0.8f, -0.07f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();
}

void drawLetterDe(float scalingFactor, float xOffset, float yOffset, struct RGBColor letterColor, struct RGBColor backgroundColor)
{

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);

	glBegin(GL_POLYGON);
	glVertex2f(0.01f / scalingFactor - xOffset, 0.23f / scalingFactor - yOffset);
	glVertex2f(-0.47f / scalingFactor - xOffset, 0.23f / scalingFactor - yOffset);
	glVertex2f(-0.47f / scalingFactor - xOffset, 0.08f / scalingFactor - yOffset);
	glVertex2f(0.12f / scalingFactor - xOffset, 0.08f / scalingFactor - yOffset);
	glEnd();

	//Maatra line
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.06f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);

	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.13f, 0.08f, -0.28f, 0.14f, -0.33f, 0.28f, -0.45f, 0.08f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);

	glBegin(GL_POLYGON);
	glVertex2f(0.12f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, 0.00f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(0.12f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.13f, -0.085f, -0.58f, -0.105f, -0.58f, -0.535f, -0.13f, -0.485f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Inner
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.13f, -0.17f, -0.38f, -0.205f, -0.38f, -0.435f, -0.13f, -0.453f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(-0.13f / scalingFactor - xOffset, -0.58f / scalingFactor - yOffset);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.58f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.12f, -0.37f, 0.16f, -0.54f, 0.20f, -0.57f, 0.30f, -0.56f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(0.12f / scalingFactor - xOffset, -0.37f / scalingFactor - yOffset);
	glVertex2f(0.30f / scalingFactor - xOffset, -0.56f / scalingFactor - yOffset);
	glEnd();
}

void drawLetterSha(float scalingFactor, float xOffset, float yOffset, struct RGBColor letterColor, struct RGBColor backgroundColor)
{
	//Maatra line
	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.13f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.13f / scalingFactor - yOffset);
	glVertex2f(-0.25f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, 0.07f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.20f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.20f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.56f / scalingFactor - xOffset, -0.16f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.78f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glVertex2f(-0.80f / scalingFactor - xOffset, -0.24f / scalingFactor - yOffset);
	glVertex2f(-0.8f / scalingFactor - xOffset, -0.50f / scalingFactor - yOffset);
	glVertex2f(-0.40f / scalingFactor - xOffset, -0.45f / scalingFactor - yOffset);
	glEnd();

	//Big stroke below stick
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(0.19f, -0.19f, 0.10f, -0.47f, -0.10f, -0.47f, -0.35f, -0.27f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Left Below stroke Decrease Y
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.40f, -0.45f, -0.63f, -0.22f, -0.71f, -0.26f, -0.78f, -0.24f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.78f, -0.24f, -0.82f, -0.26f, -0.82f, -0.15f, -0.78f, -0.17f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	//Little Stroke for stick
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.16f, -0.17f, -0.18f, -0.24f, -0.22f, -0.27f, -0.24f, -0.29f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(-0.24f / scalingFactor - xOffset, -0.29f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.17f / scalingFactor - yOffset);
	glVertex2f(-0.16f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.50f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	drawLetterStroke(-0.6f, 0.16f, -0.20f, 0.18f, -0.18f, -0.15f, -0.35f, -0.30f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper outer stroke
	drawLetterStroke(-0.5f, 0.05f, -0.38f, 0.10f, -0.39f, -0.15f, -0.47f, -0.16f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper Tip
	drawLetterStroke(-0.6f, 0.16f, -0.9f, 0.11f, -0.9f, -0.21f, -0.30f, 0.0f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	//Middle void
	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	//Sa upper Tip
	drawLetterStroke(-0.4f, 0.04f, -0.7f, 0.25f, -0.7f, -0.15f, -0.4f, 0.04f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.10f, -0.4145f, -0.20f, -0.37f, -0.27f, -0.28f, -0.35f, -0.30f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_POLYGON);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.14f / scalingFactor - yOffset);
	glVertex2f(0.05f / scalingFactor - xOffset, -0.23f / scalingFactor - yOffset);
	glVertex2f(0.19f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glVertex2f(0.21f / scalingFactor - xOffset, -0.19f / scalingFactor - yOffset);
	glEnd();

	glColor3f(letterColor.rColorValue, letterColor.gColorValue, letterColor.bColorValue);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.434f / scalingFactor - xOffset, -0.142f / scalingFactor - yOffset);
	glVertex2f(-0.35f / scalingFactor - xOffset, -0.30f / scalingFactor - yOffset);
	glVertex2f(-0.50f / scalingFactor - xOffset, -0.16f / scalingFactor - yOffset);
	glEnd();

	glColor3f(backgroundColor.rColorValue, backgroundColor.gColorValue, backgroundColor.bColorValue);
	glBegin(GL_TRIANGLE_FAN);
	drawLetterStroke(-0.437f, -0.142f, -0.48f, -0.24f, -0.69f, -0.192f, -0.8f, -0.17f, scalingFactor, xOffset, yOffset, 1000);
	glEnd();
}

void drawSandesh()
{
	struct RGBColor letterColor = {1.0f, 1.0f, 1.0f};
	struct RGBColor backgroundColor = {0.0f, 0.0f, 0.0f};
	drawLetterSa(2.6f, 0.27f, 0.0f, letterColor, backgroundColor);
	drawLetterDe(3.0f, 0.0f, 0.0f, letterColor, backgroundColor);
	drawLetterSha(2.6f, -0.395f, 0.0f, letterColor, backgroundColor);
}

void display(void)
{
	//code
	//clear opengl buffers
	glClear(GL_COLOR_BUFFER_BIT);
	drawSandesh();
	//Swap the buffers
	SwapBuffers(ghdc);
}

void update(void)
{
	//code
}

void uninitialize(void)
{
	//function declarations
	void toggleFullScreen(void);

	//code
	//If user is exiting in full screen then restore the full screen back to normal
	if (gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}
	
	//Make hdc as a current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	//Delete the rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//Relase the DC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	//close the file
	if (gpFile)
	{
		fprintf(gpFile, "Program Terminated Successfully.\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}

