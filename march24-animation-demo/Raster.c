// custom header files
#include "Raster.h"
#include "../common/common.h"

// OpenGL realated libraries
#pragma comment(lib, "opengl32.lib")

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

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

// Opengl related global variable
HDC ghdc = NULL;   // global handle to device context
HGLRC ghrc = NULL; // global handle to rendering context (rc -> rendering context, HGLRC -> handle to openGL rendering context)

void BHIM_Upper() {
    
    
    glColor3f(0.9f, 0.7f, 0.6f);  // Light skin tone
    glBegin(GL_POLYGON);

	glVertex2f(-0.151f, 0.259f);
	glVertex2f(-0.113f, 0.251f);
	glVertex2f(-0.079f, 0.243f);
	glVertex2f(-0.051f, 0.244f);
	glVertex2f(0.002f, 0.251f);
	glVertex2f(0.023f, 0.265f);

	glVertex2f(0.035f, 0.216f);
	glVertex2f(0.043f, 0.173f);
	glVertex2f(0.05f, 0.123f);
	glVertex2f(0.056f, 0.063f);
	glVertex2f(0.056f, 0.002f);
	glVertex2f(0.043f, -0.076f);
	glVertex2f(0.028f, -0.131f);
	glVertex2f(0.002f, -0.155f);
	glVertex2f(0.027f, -0.169f);
	glVertex2f(0.033f, -0.192f);
	glVertex2f(0.047f, -0.218f);
	glVertex2f(0.059f, -0.242f);
	glVertex2f(0.057f, -0.26f);
	glVertex2f(0.04f, -0.273f);
	glVertex2f(0.025f, -0.281f);
	glVertex2f(0.003f, -0.266f);
	glVertex2f(-0.011f, -0.245f);
	glVertex2f(-0.026f, -0.216f);
	glVertex2f(-0.018f, -0.0188f);
	glVertex2f(-0.017f, -0.167f);
	glVertex2f(-0.018f, -0.119f);
	glVertex2f(-0.026f, -0.08f);
	glVertex2f(-0.04f, -0.03f);
	glVertex2f(-0.054f, -0.016f);
	glVertex2f(-0.054f, -0.013f);
	glVertex2f(-0.058f, -0.05f);
	glVertex2f(-0.071f, -0.096f);
	glVertex2f(-0.107f, -0.165f);
	glVertex2f(-0.115f, -0.189f);
	glVertex2f(-0.115f, -0.203f);
	glVertex2f(-0.089f, -0.26f);
	glVertex2f(-0.104f, -0.292f);
	glVertex2f(-0.122f, -0.299f);
	glVertex2f(-0.185f, -0.229f);
	glVertex2f(-0.189f, -0.22f);
	glVertex2f(-0.187f, -0.199f);
	glVertex2f(-0.173f, -0.177f);
	glVertex2f(-0.166f, -0.152f);
	glVertex2f(-0.161f, -0.122f);
	glVertex2f(-0.161f, -0.08f);
	glVertex2f(-0.167f, -0.037f);
	glVertex2f(-0.174f, -0.019f);
	glVertex2f(-0.173f, 0.011f);
	glVertex2f(-0.156f, 0.052f);
	glVertex2f(-0.155f, 0.074f);
	glVertex2f(-0.171f, 0.114f);
	glVertex2f(-0.172f, 0.157f);
	glVertex2f(-0.156f, 0.237f);
    glEnd();
}

void BHIM_Lower() { 
    glColor3f(0.9f, 0.7f, 0.6f); 
    glBegin(GL_POLYGON);

	glVertex2f(-0.151f, 0.259f);
	glVertex2f(-0.113f, 0.251f);
	glVertex2f(-0.079f, 0.243f);
	glVertex2f(-0.051f, 0.244f);
	glVertex2f(0.002f, 0.251f);
	glVertex2f(0.023f, 0.265f);
	glVertex2f(0.024f, 0.29f);
	glVertex2f(0.028f, 0.331f);
	glVertex2f(0.038f, 0.402f);
	glVertex2f(0.052f, 0.451f);
	glVertex2f(0.026f, 0.478f);
	glVertex2f(-0.001f, 0.494f);
	glVertex2f(-0.079f, 0.498f);
	glVertex2f(-0.107f, 0.466f);
    glEnd();
}

void BHIM_face() {
    glColor3f(0.9f, 0.7f, 0.6f);  
    glBegin(GL_POLYGON);

	glVertex2f(0.025f, 0.482f);
	glVertex2f(0.002f, 0.489f);
	glVertex2f(0.002f, 0.496f);
	glVertex2f(0.003f, 0.506f);
	glVertex2f(0.013f, 0.521f);
	glVertex2f(0.031f, 0.534f);
	glVertex2f(0.033f, 0.544f);
	glVertex2f(0.028f, 0.551f);

	glVertex2f(0.019f, 0.556f);
	glVertex2f(0.019f, 0.56f);
	glVertex2f(0.024f, 0.56f);
	glVertex2f(0.034f, 0.562f);
	glVertex2f(0.045f, 0.572f);
	glVertex2f(0.035f, 0.621f);
	glVertex2f(0.031f, 0.623f);
	glVertex2f(0.035f, 0.636f);
	glVertex2f(0.033f, 0.653f);

	glVertex2f(0.03f, 0.673f);
	glVertex2f(0.007f, 0.686f);
	glVertex2f(0.01f, 0.693f);
	glVertex2f(-0.027f, 0.694f);
	glVertex2f(-0.054f, 0.682f);
	glVertex2f(-0.068f, 0.667f);
	glVertex2f(-0.077f, 0.647f);
	glVertex2f(-0.077f, 0.6f);
	glVertex2f(-0.075f, 0.564f);
	glVertex2f(-0.075f, 0.508f);
	glVertex2f(-0.082f, 0.495f);
	glVertex2f(-0.082f, 0.479f);
    glEnd();
}

void BHIM_R_Hand() { 
    glColor3f(0.9f, 0.7f, 0.6f);  // Light skin tone
    glBegin(GL_POLYGON);
    glVertex2f(0.054f, 0.449f);
	glVertex2f(0.018f, 0.347f);
	glVertex2f(0.093f, 0.302f);
	glVertex2f(0.115f, 0.351f);
    glEnd();
	
	glColor3f(0.9f, 0.7f, 0.6f);  // Light skin tone
    glBegin(GL_POLYGON);
    glVertex2f(0.093f, 0.302f);
	glVertex2f(0.115f, 0.288f);
	glVertex2f(0.169f, 0.418f);
	glVertex2f(0.136f, 0.438f);
    glEnd();

	glColor3f(0.9f, 0.7f, 0.6f);  // Light skin tone
    glBegin(GL_POLYGON);
    glVertex2f(0.136f, 0.438f);
	glVertex2f(0.14f, 0.461f);
	glVertex2f(0.136f, 0.506f);
	glVertex2f(0.146f, 0.497f);
	glVertex2f(0.144f, 0.465f);
	glVertex2f(0.164f, 0.492f);
	glVertex2f(0.182f, 0.472f);
    glVertex2f(0.169f, 0.418f);
    glEnd();

}

void BHIM_Eye() { 
    glColor3f(1.0f, 0.0f, 0.0f);  // Light skin tone
    glBegin(GL_POLYGON);
    glVertex2f(-0.018f, 0.637f);
	glVertex2f(0.006f, 0.643f);
	glVertex2f(0.024f, 0.622f);
	glVertex2f(0.001f, 0.62f);
	glVertex2f(0.015f, 0.628f);

    glEnd();
}
void BHIM_Mouth() { 
    glColor3f(1.0f, 0.0f, 0.0f);  // Light skin tone
	glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.012f, 0.516f);

    glEnd();
}

void BHIM_Weapon() { 
    glColor3f(0.6f, 0.4f, 0.2f);  // Light skin tone
	//glPointSize(5.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.203f, 0.469f);
	glVertex2f(0.185f, 0.44f);
    glVertex2f(-0.174f, 0.633f);
	glVertex2f(-0.141f, 0.656f);
    glEnd();

	glColor3f(0.6f, 0.4f, 0.2f); 
	//glPointSize(5.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.150f + 0.09f,  0.640f);   
        glVertex2f(-0.150f + 0.08f,  0.665f);  
        glVertex2f(-0.150f + 0.06f,  0.680f);  
        glVertex2f(-0.150f + 0.03f,  0.690f);   
        glVertex2f(-0.150f,  0.730f);        
        glVertex2f(-0.150f - 0.03f,  0.690f);    
        glVertex2f(-0.150f - 0.06f,  0.680f);    
        glVertex2f(-0.150f - 0.08f,  0.665f);  
        glVertex2f(-0.150f - 0.09f,  0.640f);   
        glVertex2f(-0.150f - 0.08f,  0.615f); 
        glVertex2f(-0.150f - 0.06f,  0.600f);   
        glVertex2f(-0.150f - 0.03f,  0.590f);  
        glVertex2f(-0.150f,  0.550f);         
        glVertex2f(-0.150f + 0.03f,  0.590f);  
        glVertex2f(-0.150f + 0.06f,  0.600f);   
        glVertex2f(-0.150f + 0.08f,  0.615f);    
    glEnd();
}


void BHIM_Pant() {

    glColor3f(0.0f, 1.0f, 0.0f);  // Light skin tone
    glBegin(GL_POLYGON);

	glVertex2f(-0.151f, 0.259f);
	glVertex2f(-0.113f, 0.251f);
	glVertex2f(-0.079f, 0.243f);
	glVertex2f(-0.051f, 0.244f);
	glVertex2f(0.002f, 0.251f);
	glVertex2f(0.023f, 0.265f);

	glVertex2f(0.035f, 0.216f);
	glVertex2f(0.043f, 0.173f);
	glVertex2f(0.05f, 0.123f);
	glVertex2f(0.056f, 0.063f);
	glVertex2f(0.056f, 0.002f);
	glVertex2f(0.043f, -0.076f);
	glVertex2f(0.028f, -0.131f);
	glVertex2f(0.002f, -0.155f);
	
	
	glVertex2f(-0.026f, -0.08f);
	glVertex2f(-0.04f, -0.03f);
	glVertex2f(-0.054f, -0.016f);
	glVertex2f(-0.054f, -0.013f);
	glVertex2f(-0.058f, -0.05f);
	glVertex2f(-0.071f, -0.096f);
	glVertex2f(-0.107f, -0.165f);

	glVertex2f(-0.161f, -0.122f);
	glVertex2f(-0.161f, -0.08f);
	glVertex2f(-0.167f, -0.037f);
	glVertex2f(-0.174f, -0.019f);
	glVertex2f(-0.173f, 0.011f);
	glVertex2f(-0.156f, 0.052f);
	glVertex2f(-0.155f, 0.074f);
	glVertex2f(-0.171f, 0.114f);
	glVertex2f(-0.172f, 0.157f);
	glVertex2f(-0.156f, 0.237f);
    glEnd();
}

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

				// render
				display();

				// update
				update();
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

	return (0);
}

void printGLInfo(void)
{
	// code
	// print openGL info
	fprintf(gpFile, "****** OPENGL INFORMATION ******\n");
	fprintf(gpFile, "--------------------------------\n");
	fprintf(gpFile, "OpenGL vender: %s\n", glGetString(GL_VENDOR));
	fprintf(gpFile, "OpenGL render: %s\n", glGetString(GL_RENDERER));
	fprintf(gpFile, "OpenGL Version: %s\n", glGetString(GL_VERSION));
	fprintf(gpFile, "--------------------------------\n");
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

void Bhim()
{
	glClear(GL_COLOR_BUFFER_BIT);
	BHIM_Weapon();
    BHIM_Upper();
	BHIM_Lower();
	BHIM_face();
	BHIM_R_Hand();
	BHIM_Pant();
	BHIM_Eye();
	BHIM_Mouth();

}

void display(void)
{
	// code
	// clear openGL bufferes
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    Bhim();

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
