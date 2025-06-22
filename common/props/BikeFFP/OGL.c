// Win32 headers

#define _USE_MATH_DEFINES

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//open gl related header files
#include <gl/GL.h>
#include <gl/GLU.h>

#include"OGL.h"

//open-gl related libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")

// macros
#define WIN_WIDTH	800
#define WIN_HEIGHT	600

// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
// variables related to full screen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;  // this struct taks help of WSM (Window station manager)

// variable related to File I/O
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// variable related to Active window
BOOL gbActiveWindow = FALSE;

// variable related to exit keypress 
BOOL gbEscapeKeyIsPressed = FALSE;

// open-gl related global variables
HDC ghdc = NULL;
HGLRC ghrc = NULL; //graphics library rendering context

//Solar System related variables
GLUquadric* quadric = NULL;

// Entry point funtion
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// function declarations
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
	int windowTop, windowLeft;

	// code
	// create log file
	gpFile = fopen(gszLogFileName, "w");
	
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log file creation failed."), TEXT("File I/O Error"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program started successfully\n");
	}

	// window class Initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;  // DC Fixed jagi thev (Reliable jagi thev) (Fixed/Movable/Discardable)
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE( MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	
	// registration of window class
	RegisterClassEx(&wndclass);

	windowLeft = (GetSystemMetrics(SM_CXFULLSCREEN) / 2) - (WIN_WIDTH / 2);
	windowTop = (GetSystemMetrics(SM_CYFULLSCREEN) / 2) - (WIN_HEIGHT / 2);
	
	// create window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
						szAppName,
						TEXT("Imrankhan Pathan"),
						WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
						windowLeft,
						windowTop,
						WIN_WIDTH,
						WIN_HEIGHT,
						NULL,
						NULL,
						hInstance,
						NULL);

	ghwnd = hwnd;
						
	// show window
	ShowWindow(hwnd, iCmdShow);
	
	// paint background of the window
	UpdateWindow(hwnd);
	
	// Message Loop
	/*while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}*/

	// initialize
	int result = initialize();

	if (result != 0)
	{
		fprintf(gpFile, "initialize() failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "initialize() completed successfully\n");
	}

	// set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	// GameLoop
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
				// Render
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
	// function declarations
	void toggleFullScreen(void);
	void resize(int, int);
	void uninitialize(void);

	switch(iMsg)
	{
	case WM_CREATE:
	{
		ZeroMemory((void*)&wpPrev, sizeof(WINDOWPLACEMENT));
		wpPrev.length = sizeof(WINDOWPLACEMENT);
		break; 
	}
	case WM_SETFOCUS:
	{
		gbActiveWindow = TRUE;
		break; 
	}
	case WM_KILLFOCUS:
	{
		gbActiveWindow = FALSE;
		break;
	}
	case WM_ERASEBKGND: //flicker free sathi
	{
		return(0);
	}
	case WM_SIZE:
	{
		resize(LOWORD(lParam), HIWORD(lParam));
		break;
	}
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE: //Virtual Keycode
		{
			gbEscapeKeyIsPressed = TRUE;
			break;
		}
		default:
			break;
		}
		break;
	}
	case WM_CHAR:
	{
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
	}
	case WM_CLOSE:
	{
		uninitialize();
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

void toggleFullScreen(void)
{
	// variable declarations
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
				SetWindowPos(ghwnd, HWND_TOP,
					mi.rcMonitor.left,
					mi.rcMonitor.top,
					mi.rcMonitor.right - mi.rcMonitor.left,
					mi.rcMonitor.bottom - mi.rcMonitor.top,
					SWP_NOZORDER | SWP_FRAMECHANGED);
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
	//function declaration
	void resize(int, int);

	// variable declarations
	PIXELFORMATDESCRIPTOR pFd; //framebufferattributes, pixelattributes
	int iPixelFormatIndex = 0;

	// code
	//PIXELFORMATDESCRIPTOR initialization
	ZeroMemory((void*)&pFd, sizeof(PIXELFORMATDESCRIPTOR));

	pFd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pFd.nVersion = 1; // os specific numbr for FFP
	pFd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER; // draw on window, render mode api are going to be used
	pFd.iPixelType = PFD_TYPE_RGBA;
	pFd.cColorBits = 32;
	pFd.cRedBits = 8;
	pFd.cGreenBits = 8;
	pFd.cBlueBits = 8;
	pFd.cAlphaBits = 8;
	pFd.cDepthBits = 32;

	//get dc
	ghdc = GetDC(ghwnd); // device chi attachi awastha sangnara structure - Device context

	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() failed\n");
		return -1;
	}

	//get matching pixel format index using hdc &pFd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pFd);

	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() failed\n");
		return -2;
	}

	//select the pixel format of the found index
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pFd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() failed\n");
		return -3;
	}
	
	// create rendering context using hdc pfd & chosen PixelFormatIndex
	ghrc = wglCreateContext(ghdc);  // windows che bridging api starts with wgl ne suru hota, linux -> glx, mac ->cgl
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() failed\n");
		return -4;
	}

	// make this rendering context as curret context
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() failed\n");
		return -5;
	}

	glShadeModel(GL_SMOOTH);	//smoothness cha wichar kar
	glClearDepth(1.0f);			//glClear() chya opearation kartana depth buffer madhe jaun sagle chi value 1 kar
	glEnable(GL_DEPTH_TEST);	//Enable Depth test in Per-Fragment test
	glDepthFunc(GL_LEQUAL);		//Depth test value is less than or equal to value set in glClearDepth
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);		//when perspective projection mule some shape depth mule wede wakde distil tevha tu tyanna nicest appearance de

	// from here onwards opengl code starts
	// tell opengl to choose the color to clear the screen 
	glClearColor(0.01f, 0.38f, 0.03f, 1.0f);

	//initialize quadric
	quadric = gluNewQuadric();
	// warm up resize
	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
	{
		height = 1;
	}

	//set the viewport
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// set matrix projection mode
	glMatrixMode(GL_PROJECTION);
	//set to Identity Matrix
	glLoadIdentity();
	// do Perspective projection				
	// //glFrustum  H = tan((fovy/2)/180*PI) * near; W = H* Aspect_ratio; glFrustum(-W, W, -H, H, near, far);
	gluPerspective(45.0f, //field of view - y				
		(GLfloat)width / (GLfloat)height, // aspect ratio
		0.1f, //near wall 
		100.0f); // far wall
}

void drawcircleBike(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;

	// Circle
	if (fill == 1)
	{
		glBegin(GL_POLYGON);
	}
	else
	{
		glBegin(GL_POINTS);
	}

	for (ObjAngle = (0.00f); ObjAngle <= (2.0f * M_PI); ObjAngle += 0.01f)
	{
		ObjX = x + radius_hor * sin(ObjAngle);
		ObjY = y + radius_vert * cos(ObjAngle);

		glColor3f(r, g, b);

		glVertex2f(ObjX, ObjY);
	}
	glEnd();
}

void display(void)
{
	void drawBike();
	void drawMan();
	// code
	//clear opengl buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set matrix to Model view mode
	glMatrixMode(GL_MODELVIEW);

	//set to Identity Matrix
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -3.0f);

	glColor3f(1.0f, 0.0f, 0.0f);

	/*glBegin(GL_LINES);
	glVertex2f(5.0f, 0.0f);
	glVertex2f(-5.0f, 0.0f);

	glVertex2f(0.0f, 5.0f);
	glVertex2f(0.0f, -5.0f);
	glEnd();*/

	drawBike();
	drawMan();

	// swap the buffers
	SwapBuffers(ghdc);
}

void drawMan()
{
	void drawLeg();
	void drawTorso();
	void drawHelmet();

	drawLeg();
	drawTorso();
	drawHelmet();
}


void drawHelmet()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.25f, 0.44f);
	glVertex2f(-0.27f, 0.40f);
	glVertex2f(-0.27f, 0.31f);
	glVertex2f(-0.24f, 0.30f);
	glVertex2f(-0.12f, 0.26f);
	glVertex2f(-0.06f, 0.24f);
	glVertex2f(-0.04f, 0.30f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.10f, 0.32f);
	glVertex2f(-0.10f, 0.47f);
	glVertex2f(-0.15f, 0.48f);
	glVertex2f(-0.20f, 0.47f);
	glVertex2f(-0.25f, 0.44f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.10f, 0.38f);
	glVertex2f(0.00f, 0.38f);
	glVertex2f(-0.10f, 0.47f);
	glEnd();

	glColor3f(0.15f, 0.15f, 0.15f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.12f, 0.40f);
	glVertex2f(0.00f, 0.38f);
	glVertex2f(-0.03f, 0.295f);
	glVertex2f(-0.11f, 0.32f);
	glEnd();
}

void drawTorso()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.10f, -0.06f);
	glVertex2f(-0.09f, 0.00f);
	glVertex2f(-0.32f, 0.00f);
	glVertex2f(-0.31f, -0.10f);
	glVertex2f(-0.11f, -0.08f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.08f, 0.15f);
	glVertex2f(-0.09f, 0.00f);
	glVertex2f(-0.32f, 0.00f);
	glVertex2f(-0.33f, 0.15f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.33f, 0.15f);
	glVertex2f(-0.33f, 0.18f);
	glVertex2f(-0.30f, 0.25f);
	glVertex2f(-0.25f, 0.28f);
	glVertex2f(-0.13f, 0.24f);
	glVertex2f(-0.11f, 0.23f);
	glVertex2f(-0.09f, 0.20f);
	glVertex2f(-0.08f, 0.15f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(-0.25f, 0.15f);
	glVertex2f(0.20f, 0.040f);
	glVertex2f(0.22f, 0.080f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.20f, 0.25f);
	glEnd();

	glColor3f(1.0f, 0.8f, 0.7f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.25f, 0.28f);
	glVertex2f(-0.24f, 0.30f);
	glVertex2f(-0.12f, 0.26f);
	glVertex2f(-0.13f, 0.24f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.25f, 0.080f);
	glVertex2f(0.22f, 0.080f);
	glVertex2f(0.20f, 0.040f);
	glVertex2f(0.24f, 0.040f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.25f, 0.080f);
	glVertex2f(0.245f, 0.06f);
	glVertex2f(0.28f, 0.080f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0.25f, 0.065f);
	glVertex2f(0.28f, 0.080f);
	glVertex2f(0.31f, 0.050f);
	glVertex2f(0.25f, 0.025f);
	glEnd();

	drawcircleBike(0.25f, 0.045f, 0.02f, 0.01f, 0.75f, 0.75f, 0.75f, 1);
}

void drawLeg()
{
	glColor3f(0.2f, 0.09f, 0.07f);
	glBegin(GL_POLYGON);
	glVertex2f(0.00f, -0.49f);
	glVertex2f(-0.05f, -0.49f);
	glVertex2f(-0.06f, -0.53f);
	glVertex2f(-0.05f, -0.56f);
	glVertex2f(0.00f, -0.56f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.03f, -0.49f);
	glVertex2f(0.00f, -0.49f);
	glVertex2f(0.00f, -0.54f);
	glVertex2f(0.07f, -0.56f);
	glVertex2f(0.09f, -0.53f);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(0.07f, -0.53f);
	glVertex2f(0.13f, -0.525f);
	glVertex2f(0.15f, -0.54f);
	glVertex2f(0.07f, -0.56f);
	glEnd();

	glColor3f(0.25f, 0.25f, 0.25f);
	glBegin(GL_POLYGON);
	glVertex2f(0.02f, -0.49f);
	glVertex2f(-0.045f, -0.49f);
	glVertex2f(-0.04f, -0.47f);
	glVertex2f(0.03f, -0.47f);
	glEnd();

	glColor3f(0.30f, 0.39f, 0.56f);
	glBegin(GL_POLYGON);
	glVertex2f(0.16f, -0.17f);
	glVertex2f(0.04f, -0.215f);
	glVertex2f(-0.05f, -0.47f);
	glVertex2f(0.05f, -0.47f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.04f, -0.215f);
	glVertex2f(0.16f, -0.17f);
	glVertex2f(0.15f, -0.15f);
	glVertex2f(0.13f, -0.13f);
	glVertex2f(0.115f, -0.12f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(0.04f, -0.215f);
	glVertex2f(-0.15f, -0.21f);
	glVertex2f(-0.10f, -0.06f);
	glVertex2f(0.115f, -0.12f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.09f, -0.08f);
	glVertex2f(-0.31f, -0.10f);
	glVertex2f(-0.30f, -0.17f);
	glVertex2f(-0.29f, -0.20f);
	glVertex2f(-0.28f, -0.21f);
	glVertex2f(-0.15f, -0.21f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.15f, -0.21f);
	glVertex2f(-0.28f, -0.21f);
	glVertex2f(-0.235f, -0.2175f);
	glVertex2f(-0.195f, -0.2125f);
	glEnd();
}


void drawBike()
{
	void drawWheel(float x, float y);
	void drawMudGard(float x, float y, float radius, float startAngle, float endAngle, int bIsFront);
	void drawHeadLight();
	void drawHandle();
	void drawChassi();
	void drawSilencer();
	void drawEngine();
	void drawSeat();
	void drawPetrolTank();

	glColor3f(0.51f, 0.73f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(10.0f, 10.0f);
	glVertex2f(-10.0f, 10.0f);
	glVertex2f(-10.0f, 0.0f);
	glVertex2f(10.0f, 0.0f);
	glEnd();
	//front wheel
	drawWheel(0.65f, -0.5f);
	drawMudGard(0.65f, -0.5f, 0.25f, 4.4f, (2.0f * M_PI) + 0.75f, 1);

	//back wheel
	drawWheel(-0.55f, -0.5f);
	drawMudGard(-0.55f, -0.5f, 0.3f, 4.8f, (2.0f * M_PI) + 1.0f, 0);

	drawChassi();
	drawHeadLight();
	drawHandle();

	glColor3f(0.5f, 0.5f, 0.5f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex2f(0.65f, -0.5f);
	glVertex2f(0.4f, 0.0f);
	glEnd();
	glLineWidth(1.0f);

	drawEngine();
	drawSilencer();
	
	drawPetrolTank();
	drawSeat();
}

void drawPetrolTank()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.080f, -0.14f);
	glVertex2f(-0.080f, -0.17f);
	glVertex2f(-0.070f, -0.18f);
	glVertex2f(-0.060f, -0.19f);
	
	glVertex2f(0.26f, -0.19f);
	glVertex2f(0.31f, -0.16f);
	glVertex2f(0.315f, -0.15f);
	glVertex2f(0.32f, -0.14f);
	glVertex2f(0.325f, -0.13f);
	glVertex2f(0.33f, -0.12f);
	glVertex2f(0.33f, -0.08f);
	glVertex2f(0.325f, -0.07f);
	glVertex2f(0.32f, -0.06f);
	glVertex2f(0.315f, -0.05f);
	glVertex2f(0.30f, -0.03f);
	glEnd();

	glColor3f(0.87f, 0.09f, 0.09f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.075f, -0.14f);
	glVertex2f(-0.065f, -0.17f);
	glVertex2f(-0.060f, -0.175f);
	glVertex2f(-0.050f, -0.18f);
	glVertex2f(0.26f, -0.18f);
	glVertex2f(0.30f, -0.15f);
	glVertex2f(0.305f, -0.15f);
	glVertex2f(0.31f, -0.14f);
	glVertex2f(0.315f, -0.13f);
	glVertex2f(0.32f, -0.12f);
	glVertex2f(0.32f, -0.08f);
	glVertex2f(0.315f, -0.07f);
	glVertex2f(0.31f, -0.06f);
	glVertex2f(0.305f, -0.05f);
	glVertex2f(0.29f, -0.03f);
	glVertex2f(0.28f, -0.025f);
	glVertex2f(0.265f, -0.02f);
	glVertex2f(0.24f, -0.015f);
	glVertex2f(0.21f, -0.01f);
	glVertex2f(0.17f, -0.015f);
	glVertex2f(0.09f, -0.035f);
	glVertex2f(0.01f, -0.075f);
	glVertex2f(-0.075f, -0.14f);
	glEnd();

	glColor3f(0.85f, 0.85f, 0.85f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.050f, -0.14f);
	glVertex2f(-0.045f, -0.16f);
	glVertex2f(-0.040f, -0.165f);
	glVertex2f(-0.028f, -0.17f);
	glVertex2f(0.24f, -0.17f);
	glVertex2f(0.28f, -0.15f);
	glVertex2f(0.285f, -0.15f);
	glVertex2f(0.29f, -0.14f);
	glVertex2f(0.295f, -0.13f);
	glVertex2f(0.30f, -0.12f);
	glVertex2f(0.30f, -0.08f);
	glVertex2f(0.295f, -0.07f);
	glVertex2f(0.29f, -0.06f);
	glVertex2f(0.285f, -0.05f);
	glVertex2f(0.27f, -0.04f);
	glVertex2f(0.26f, -0.035f);
	glVertex2f(0.255f, -0.03f);
	glVertex2f(0.24f, -0.025f);
	glVertex2f(0.21f, -0.02f);
	glVertex2f(0.17f, -0.025f);
	glVertex2f(0.09f, -0.045f);
	glVertex2f(0.01f, -0.085f);
	glVertex2f(-0.050f, -0.15f);
	glEnd();
}

void drawSeat()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.63f, -0.08f);
	glVertex2f(-0.68f, -0.12f);
	glVertex2f(-0.70f, -0.17f);
	glVertex2f(-0.69f, -0.18f);
	glVertex2f(-0.40f, -0.20f);
	glVertex2f(-0.40f, -0.15f);
	glVertex2f(-0.42f, -0.10f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.23f, -0.13f);
	glVertex2f(-0.38f, -0.11f);
	glVertex2f(-0.405f, -0.14f);
	glVertex2f(-0.405f, -0.19f);
	glVertex2f(-0.32f, -0.22f);
	glVertex2f(-0.23f, -0.25f);
	glVertex2f(-0.15f, -0.22f);
	glVertex2f(-0.085f, -0.18f);
	glVertex2f(-0.070f, -0.14f);
	glVertex2f(-0.080f, -0.12f);
	glEnd();
	

	glColor3f(0.15f, 0.15f, 0.15f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.63f, -0.08f);
	glVertex2f(-0.59f, -0.10f);
	glVertex2f(-0.45f, -0.12f);
	glVertex2f(-0.42f, -0.10f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.23f, -0.13f);
	glVertex2f(-0.38f, -0.11f);
	glVertex2f(-0.26f, -0.16f);
	glVertex2f(-0.08f, -0.12f);
	glEnd();

	glColor3f(0.85f, 0.85f, 0.85f);
	glBegin(GL_QUADS);
	glVertex2f(-0.60f, -0.155f);
	glVertex2f(-0.60f, -0.165f);
	glVertex2f(-0.68f, -0.16f);
	glVertex2f(-0.68f, -0.15f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(-0.715f, -0.05f);
	glVertex2f(-0.72f, -0.07f);
	glVertex2f(-0.68f, -0.165f);
	glVertex2f(-0.67f, -0.15f);
	glEnd();
}

void drawChassi()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.2f, -0.6f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.4f, -0.47f);
	glVertex2f(-0.35f, -0.30f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(-0.4f, -0.47f);
	glVertex2f(-0.75f, -0.30f);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.2f, -0.6f);
	glEnd();

	glLineWidth(15.0f);
	glBegin(GL_LINES);
	glVertex2f(-0.64f, -0.53f);
	glVertex2f(-0.08f, -0.40f);
	glEnd();
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex2f(-0.55f, -0.5f);
	glVertex2f(-0.45f, -0.22f);
	glEnd();

	glLineWidth(1.0f);

	glColor3f(0.8f, 0.8f, 0.8f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.48f, -0.245f);
	glVertex2f(-0.44f, -0.255f);
	glVertex2f(-0.53f, -0.385f);
	glVertex2f(-0.49f, -0.395f);
	glEnd();

	

	drawcircleBike(-0.55f, -0.5f, 0.015f, 0.015f, 0.8f, 0.8f, 0.8f, 1);
	drawcircleBike(-0.45f, -0.22f, 0.015f, 0.015f, 0.8f, 0.8f, 0.8f, 1);

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.4f, 0.0f);
	glVertex2f(0.25f, -0.08f);
	glVertex2f(0.30f, -0.3f);
	glEnd();
}

void drawSilencer()
{
	glLineWidth(10.0f);
	glColor3f(0.85f, 0.85f, 0.85f);

	glBegin(GL_QUADS);
	glVertex2f(0.195f, -0.245f);
	glVertex2f(0.19f, -0.27f);
	glVertex2f(0.26f, -0.27f);
	glVertex2f(0.26f, -0.245f);
	
	glVertex2f(0.26f, -0.245f);
	glVertex2f(0.26f, -0.27f);
	glVertex2f(0.30f, -0.30f);
	glVertex2f(0.33f, -0.30f);

	glVertex2f(0.33f, -0.30f);
	glVertex2f(0.30f, -0.30f);
	glVertex2f(0.205f, -0.58f);
	glVertex2f(0.235f, -0.58f);
	
	
	glVertex2f(0.205f, -0.58f);
	glVertex2f(0.235f, -0.58f);
	glVertex2f(0.225f, -0.595f);
	glVertex2f(0.200f, -0.585f);

	glVertex2f(0.200f, -0.585f);
	glVertex2f(0.225f, -0.595f);
	glVertex2f(0.17f, -0.62f);
	glVertex2f(0.17f, -0.59f);
	
	glVertex2f(0.17f, -0.59f);
	glVertex2f(0.17f, -0.62f);
	glVertex2f(0.13f, -0.63f);
	glVertex2f(0.13f, -0.59f);

	glVertex2f(0.13f, -0.63f);
	glVertex2f(0.13f, -0.59f);
	glVertex2f(-0.34f, -0.59f);
	glVertex2f(-0.34f, -0.63f);

	glVertex2f(-0.34f, -0.59f);
	glVertex2f(-0.34f, -0.63f);
	glVertex2f(-0.35f, -0.65f);
	glVertex2f(-0.35f, -0.57f);

	glVertex2f(-0.35f, -0.57f);
	glVertex2f(-0.35f, -0.65f);
	glVertex2f(-0.75f, -0.65f);
	glVertex2f(-0.75f, -0.57f);

	glVertex2f(-0.75f, -0.57f);
	glVertex2f(-0.75f, -0.65f);
	glVertex2f(-0.76f, -0.63f);
	glVertex2f(-0.76f, -0.59f);
	

	glVertex2f(-0.76f, -0.59f);
	glVertex2f(-0.76f, -0.63f);
	glVertex2f(-0.83f, -0.63f);
	glVertex2f(-0.83f, -0.59f);

	glEnd();

	glLineWidth(1.0f);
}

void drawHandle()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(0.36f, 0.02f);
	glVertex2f(0.36f, -0.03f);
	glVertex2f(0.28f, 0.08f);
	glVertex2f(0.30f, 0.08f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex2f(0.25f, 0.065f);
	glVertex2f(0.28f, 0.080f);
	glVertex2f(0.31f, 0.050f);
	glVertex2f(0.25f, 0.025f);
	glEnd();

	drawcircleBike(0.25f, 0.045f, 0.02f, 0.01f, 0.75f, 0.75f, 0.75f, 1);
}

void drawHeadLight()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(0.36f, 0.02f);
	glVertex2f(0.50f, 0.02f);
	glVertex2f(0.50f, -0.12f);
	glVertex2f(0.36f, -0.12f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(0.36f, 0.02f);
	glVertex2f(0.46f, 0.02f);
	glVertex2f(0.45f, 0.04f);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex2f(0.52f, 0.02f);
	glVertex2f(0.50f, 0.02f);

	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex2f(0.52f, -0.05f);
	glVertex2f(0.50f, -0.05f);
	
	glColor3f(0.25f, 0.25f, 0.25f);
	glVertex2f(0.52f, -0.12f);
	glVertex2f(0.50f, -0.12f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.85f, 0.85f, 0.85f);
	glVertex2f(0.52f, 0.015f);
	glVertex2f(0.55f, 0.015f);
	glColor3f(0.75f, 0.75f, 0.75f);
	glVertex2f(0.52f, -0.05f);
	glEnd();
}

void drawWheel(float x, float y)
{
	glPointSize(15.0f);
	drawcircleBike(x, y, 0.225f, 0.225f, 0.0f, 0.0f, 0.0f, 0);
	glPointSize(3.0f);
	drawcircleBike(x, y, 0.20f, 0.20f, 0.7f, 0.7f, 0.7f, 0);
	
	glColor3f(0.7f, 0.7f, 0.7f);
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;
	
	for (ObjAngle = (0.00f); ObjAngle <= (2.0f * M_PI); ObjAngle += 0.3f)
	{
		ObjX = x + 0.20f * sin(ObjAngle);
		ObjY = y + 0.20f * cos(ObjAngle);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(ObjX, ObjY);
		glEnd();
	}
	
	glPointSize(5.0f);
	drawcircleBike(x, y, 0.085f, 0.085f, 0.7f, 0.7f, 0.7f, 0);

	drawcircleBike(x, y, 0.07f, 0.07f, 0.0f, 0.0f, 0.0f, 1);
}

void drawMudGard(float x, float y, float radius, float startAngle, float endAngle, int bIsFront)
{
	if (bIsFront == 0)
	{
		//tail lamp
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_QUADS);
		glVertex2f(-0.825f, -0.32f);
		glVertex2f(-0.825f, -0.40f);
		glVertex2f(-0.90f, -0.40f);
		glVertex2f(-0.90f, -0.32f);
		glEnd();

		glColor3f(0.80f, 0.80f, 0.80f);
		glBegin(GL_QUADS);
		glVertex2f(-0.92f, -0.32f);
		glVertex2f(-0.92f, -0.40f);
		glVertex2f(-0.90f, -0.40f);
		glVertex2f(-0.90f, -0.32f);
		glEnd();

		glColor3f(1.0f, 0.00f, 0.00f);
		glBegin(GL_QUADS);
		glVertex2f(-0.92f, -0.33f);
		glVertex2f(-0.92f, -0.39f);
		glVertex2f(-0.93f, -0.39f);
		glVertex2f(-0.93f, -0.33f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-0.93f, -0.39f);
		glVertex2f(-0.93f, -0.36f);
		glVertex2f(-0.94f, -0.36f);
		glVertex2f(-0.93f, -0.33f);
		glEnd();
	}


	glPointSize(15.0f);
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;

	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_POINTS);
	for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.01f)
	{
		ObjX = x + radius * sin(ObjAngle);
		ObjY = y + radius * cos(ObjAngle);
		
		glVertex2f(ObjX, ObjY);
		
	}
	glEnd();

	if (bIsFront == 1)
	{
		glLineWidth(3.0f);
		glColor3f(0.5f, 0.5f, 0.5f);
		ObjX = x + (radius - 0.02f) * sin(startAngle);
		ObjY = y + (radius - 0.02f) * cos(startAngle);

		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(ObjX, ObjY);
		glEnd();


		ObjX = x + (radius - 0.02f) * sin(endAngle);
		ObjY = y + (radius - 0.02f) * cos(endAngle);

		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(ObjX, ObjY);
		glEnd();
		glLineWidth(1.0f);
	}
	else
	{
		
	}
}

void drawEngine()
{

	glColor3f(0.65f, 0.65f, 0.65f);
	
	glBegin(GL_QUADS);
	glVertex2f(0.01f, -0.22f);
	glVertex2f(0.01f, -0.25f);
	glVertex2f(-0.08f, -0.25f);
	glVertex2f(-0.08f, -0.22f);
	glEnd();


	glBegin(GL_POLYGON);
	glVertex2f(0.26f, -0.43f);
	glVertex2f(0.18f, -0.37f);
	glVertex2f(0.04f, -0.37f);
	glVertex2f(-0.07f, -0.40f);
	glVertex2f(-0.04f, -0.59f);
	glVertex2f(0.22f, -0.59f);
	glEnd();

	drawcircleBike(0.02f, -0.57f, 0.03f, 0.02f, 0.0f, 0.0f, 0.0f, 1);
	glLineWidth(1.0f);
	drawcircleBike(0.1f, -0.47f, 0.05f, 0.12f, 0.55f, 0.55f, 0.55f, 0);
	drawcircleBike(0.1f, -0.47f, 0.05f, 0.12f, 0.85f, 0.85f, 0.85f, 1);

	drawcircleBike(0.02f, -0.47f, 0.06f, 0.06f, 0.95f, 0.95f, 0.95f, 1);
	drawcircleBike(0.13f, -0.45f, 0.03f, 0.03f, 0.95f, 0.95f, 0.95f, 1);

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(0.01f, -0.30f);
	glVertex2f(0.02f, -0.37f);
	glVertex2f(0.18f, -0.37f);
	glVertex2f(0.19f, -0.30f);
	glEnd();

	glColor3f(0.75f, 0.75f, 0.75f);
	glBegin(GL_QUADS);
	glVertex2f(0.00f, -0.19f);
	glVertex2f(0.01f, -0.30f);
	glVertex2f(0.19f, -0.30f);
	glVertex2f(0.20f, -0.19f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.105f, -0.19f);
	glVertex2f(0.095f, -0.19f);
	glVertex2f(0.08f, -0.21f);
	glVertex2f(0.09f, -0.27f);
	glVertex2f(0.11f, -0.27f);
	glVertex2f(0.12f, -0.21f);
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.08f, -0.19f);
	glVertex2f(-0.40f, -0.30f);
	glVertex2f(-0.40f, -0.37f);
	glVertex2f(-0.06f, -0.59f);
	glVertex2f(-0.04f, -0.59f);
	glVertex2f(-0.07f, -0.40f);
	glEnd();

	glColor3f(0.15f, 0.15f, 0.15f);
	glBegin(GL_QUADS);
	glVertex2f(-0.20f, -0.26f);
	glVertex2f(-0.34f, -0.30f);
	glVertex2f(-0.34f, -0.38f);
	glVertex2f(-0.20f, -0.46f);
	glEnd();

	drawcircleBike(-0.20f, -0.36f, 0.10f, 0.04f, 0.15f, 0.15f, 0.15f, 1);
	drawcircleBike(-0.34f, -0.34f, 0.04f, 0.04f, 0.15f, 0.15f, 0.15f, 1);
	drawcircleBike(-0.08f, -0.30f, 0.11f, 0.06f, 0.15f, 0.15f, 0.15f, 1);
}

void update(void)
{
	//nothing here
}

void uninitialize(void)
{
	//function declarations
	void toggleFullScreen(void);

	// code
	
	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}
	// if user is exiting in fullscreen then restore the full screen back to normal
	
	if (gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}
	// make hdc as current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	//delete the rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//release the dc
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	// destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close the log file
	if (gpFile)
	{
		fprintf(gpFile, "Program terminated successfully\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}

//void keyboard(unsigned char key, int x, int y)
//void mouse(int button, int state, int x, int y)
