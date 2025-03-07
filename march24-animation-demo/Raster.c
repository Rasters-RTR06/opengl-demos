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
int x_Bheem = 0;
int y_Bheem = 0;


// Color Structure
typedef struct {
    GLfloat r, g, b;
} Color;

// Predefined Colors
#define SKIN_COLOR (Color){0.9f, 0.7f, 0.6f}
#define PANT_COLOR (Color){0.0f, 1.0f, 0.0f}
#define WHITE_COLOR (Color){1.0f, 1.0f, 1.0f}
#define BLACK_COLOR (Color){0.0f, 0.0f, 0.0f}
#define RED_COLOR (Color){1.0f, 0.0f, 0.0f}
#define GREEN_COLOR (Color){0.0f, 1.0f, 0.0f}
#define WOOD_COLOR (Color){0.6f, 0.4f, 0.2f}
#define HANDLE_COLOR (Color){0.6f, 0.4f, 0.2f}
#define HAIR_COLOR (Color){0.0f, 0.0f, 0.0f}
#define SCALE_FACTOR 0.5f

void drawPolygon(GLfloat vertices[][2], int numVertices, Color color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        glVertex2f((vertices[i][0] + x_Bheem)*SCALE_FACTOR, (vertices[i][1] + y_Bheem)*SCALE_FACTOR);
    }
    glEnd();
}


void drawPoint(GLfloat x, GLfloat y, GLfloat size, Color color) {
    glColor3f(color.r, color.g, color.b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2f((x +x_Bheem)*SCALE_FACTOR, (y + y_Bheem)*SCALE_FACTOR);
    glEnd();
}

void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat lineWidth,Color color) {
    glColor3f(color.r, color.g, color.b);  
    glLineWidth(lineWidth); 
    glBegin(GL_LINES);
        glVertex2f((x1+x_Bheem)*SCALE_FACTOR, (y1+ y_Bheem)*SCALE_FACTOR); 
        glVertex2f((x2+x_Bheem)*SCALE_FACTOR, (y2+ y_Bheem)*SCALE_FACTOR); 
    glEnd();
}

void drawBhimMustache() {
    drawLine(0.035f, 0.542f, -0.015f, 0.554f, 5.0f,BLACK_COLOR);
}

void drawBhimUpper() {
    GLfloat upperBody[][2] = {
        {-0.151f, 0.259f}, {-0.113f, 0.251f}, {-0.079f, 0.243f}, {-0.051f, 0.244f},
        {0.002f, 0.251f}, {0.023f, 0.265f}, {0.035f, 0.216f}, {0.043f, 0.173f},
        {0.05f, 0.123f}, {0.056f, 0.063f}, {0.056f, 0.002f}, {0.043f, -0.076f},
        {0.028f, -0.131f}, {0.002f, -0.155f}, {0.027f, -0.169f}, {0.033f, -0.192f},
        {0.047f, -0.218f}, {0.059f, -0.242f}, {0.057f, -0.26f}, {0.040f, -0.273f},
        {0.025f, -0.281f}, {0.003f, -0.266f}, {-0.011f, -0.245f}, {-0.026f, -0.216f},
        {-0.018f, -0.188f}, {-0.017f, -0.167f}, {-0.018f, -0.119f}, {-0.026f, -0.08f},
        {-0.040f, -0.03f}, {-0.054f, -0.016f}, {-0.058f, -0.05f}, {-0.071f, -0.096f},
        {-0.107f, -0.165f}, {-0.115f, -0.189f}, {-0.115f, -0.203f}, {-0.089f, -0.26f},
        {-0.104f, -0.292f}, {-0.122f, -0.299f}, {-0.185f, -0.229f}, {-0.189f, -0.22f},
        {-0.187f, -0.199f}, {-0.173f, -0.177f}, {-0.166f, -0.152f}, {-0.161f, -0.122f},
        {-0.161f, -0.08f}, {-0.167f, -0.037f}, {-0.174f, -0.019f}, {-0.173f, 0.011f},
        {-0.156f, 0.052f}, {-0.155f, 0.074f}, {-0.171f, 0.114f}, {-0.172f, 0.157f},
        {-0.156f, 0.237f}
    };
    drawPolygon(upperBody, sizeof(upperBody) / sizeof(upperBody[0]), SKIN_COLOR);
}

void drawBhimLower() {
    GLfloat lowerBody[][2] = {
        {-0.151f, 0.259f}, {-0.113f, 0.251f}, {-0.079f, 0.243f}, {-0.051f, 0.244f},
        {0.002f, 0.251f}, {0.023f, 0.265f}, {0.024f, 0.29f}, {0.028f, 0.331f},
        {0.038f, 0.402f}, {0.052f, 0.451f}, {0.026f, 0.478f}, {-0.001f, 0.494f},
        {-0.079f, 0.498f}, {-0.107f, 0.466f}
    };
    drawPolygon(lowerBody, sizeof(lowerBody) / sizeof(lowerBody[0]), SKIN_COLOR);
}

void drawBhimPant() {
    GLfloat vertices[][2] = {
        {-0.151f, 0.259f}, {-0.113f, 0.251f}, {-0.079f, 0.243f}, {-0.051f, 0.244f},
        {0.002f, 0.251f}, {0.023f, 0.265f}, {0.035f, 0.216f}, {0.043f, 0.173f},
        {0.05f, 0.123f}, {0.056f, 0.063f}, {0.056f, 0.002f}, {0.043f, -0.076f},
        {0.028f, -0.131f}, {0.002f, -0.155f}, {-0.026f, -0.08f}, {-0.04f, -0.03f},
        {-0.054f, -0.016f}, {-0.058f, -0.05f}, {-0.071f, -0.096f}, {-0.107f, -0.165f},
        {-0.161f, -0.122f}, {-0.161f, -0.08f}, {-0.167f, -0.037f}, {-0.174f, -0.019f},
        {-0.173f, 0.011f}, {-0.156f, 0.052f}, {-0.155f, 0.074f}, {-0.171f, 0.114f},
        {-0.172f, 0.157f}, {-0.156f, 0.237f}
    };
    drawPolygon(vertices, 30, PANT_COLOR);
}

void drawBhimFace() {
    GLfloat vertices[][2] = {
        {0.025f, 0.482f}, {0.002f, 0.489f}, {0.002f, 0.496f}, {0.003f, 0.506f},
        {0.013f, 0.521f}, {0.031f, 0.534f}, {0.033f, 0.544f}, {0.028f, 0.551f},
        {0.019f, 0.556f}, {0.019f, 0.56f}, {0.024f, 0.56f}, {0.034f, 0.562f},
        {0.045f, 0.572f}, {0.035f, 0.621f}, {0.031f, 0.623f}, {0.035f, 0.636f},
        {0.033f, 0.653f}, {0.03f, 0.673f}, {0.007f, 0.686f}, {0.01f, 0.693f},
        {-0.027f, 0.694f}, {-0.054f, 0.682f}, {-0.068f, 0.667f}, {-0.077f, 0.647f},
        {-0.077f, 0.6f}, {-0.075f, 0.564f}, {-0.075f, 0.508f}, {-0.082f, 0.495f},
        {-0.082f, 0.479f}
    };
    drawPolygon(vertices, 29, SKIN_COLOR);
}

void drawBhimRightHand() {
    GLfloat hand1[][2] = {{0.054f, 0.449f}, {0.018f, 0.347f}, {0.093f, 0.302f}, {0.115f, 0.351f}};
    GLfloat hand2[][2] = {{0.093f, 0.302f}, {0.115f, 0.288f}, {0.169f, 0.418f}, {0.136f, 0.438f}};
    drawPolygon(hand1, 4, SKIN_COLOR);
    drawPolygon(hand2, 4, SKIN_COLOR);
}

void drawBhimEye() {
    drawPoint(0.0f, 0.625f, 10.0f*SCALE_FACTOR, WHITE_COLOR);
    drawPoint(0.01f, 0.627f, 4.0f*SCALE_FACTOR, BLACK_COLOR);
}

void drawBhimHair() {
    GLfloat vertices[][2] = {
        {-0.086f, 0.615f}, {0.045f, 0.663f}, {0.01f, 0.700f}, 
        {-0.025f, 0.714f}, {-0.066f, 0.685f}, {-0.070f, 0.665f}, {-0.073f, 0.64f}
    };
    drawPolygon(vertices, sizeof(vertices) / sizeof(vertices[0]), HAIR_COLOR);
}

void drawBhimMouth() {
    drawPoint(0.012f, 0.516f, 5.0f*SCALE_FACTOR, RED_COLOR);
}

void drawBhimWeapon() {
    // Weapon handle (shaft)
    GLfloat handle[][2] = {
        {0.203f, 0.469f}, {0.185f, 0.44f}, {-0.174f, 0.633f}, {-0.141f, 0.656f}
    };
    drawPolygon(handle, 4, HANDLE_COLOR);

    // Weapon head (blade)
    GLfloat blade[][2] = {
        {-0.060f, 0.640f}, {-0.070f, 0.665f}, {-0.090f, 0.680f}, {-0.120f, 0.690f},
        {-0.150f, 0.730f}, {-0.180f, 0.690f}, {-0.210f, 0.680f}, {-0.230f, 0.665f},
        {-0.240f, 0.640f}, {-0.230f, 0.615f}, {-0.210f, 0.600f}, {-0.180f, 0.590f},
        {-0.150f, 0.550f}, {-0.120f, 0.590f}, {-0.090f, 0.600f}, {-0.070f, 0.615f}
    };
    drawPolygon(blade, 16, HANDLE_COLOR);
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
	wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
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
    if (height == 0) height = 1; // Prevent division by zero

    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if (aspectRatio > 1.0f) {
        // Maintain fixed coordinate system for character
        glOrtho(-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0, -1.0, 1.0);
    } else {
        glOrtho(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// **Draw Entire Character at Given Position**
void Bhim()
{
 glClear(GL_COLOR_BUFFER_BIT);
 drawBhimWeapon();
 drawBhimUpper();
 drawBhimLower();
 drawBhimPant();
 drawBhimFace();
 drawBhimRightHand();
 drawBhimEye();
 drawBhimMouth();
 drawBhimHair();
 drawBhimMustache();
}

void display(void)
{
	// code
	// clear openGL bufferes
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f); 
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
