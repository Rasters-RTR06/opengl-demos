// Win32 Header files
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>

// OpenGL related Header files
#include<gl/GL.h>
#include<gl/GLU.h>

// Custom Header file
#include "OGL.h"

// OpenGL related libraries
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declaration
// variables related to fullscreen
BOOL gbFullScreen = FALSE;
HWND ghwnd = NULL;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;

// Active window related variables
BOOL gbActiveWindow = FALSE;

// Exit key press related
BOOL gbEscapeKeyIsPressed = FALSE; 

// variables related to FILE IO
char gszLogFileName[] = "Log.txt";
FILE *gpFile = NULL;

// OpenGL related global variables
HDC ghdc = NULL; // Handle device context
HGLRC ghrc = NULL; // Handle to graphics rendering context 

// Rotation angles
float angleCube = -45.0f;
GLuint texture_brick = 0.0f;
GLuint texture_roof = 0.0f;

// Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// function declaration
	int initialize(void);
	void display(void);
	void update(void);
	void uninitialize(void);
	BOOL loadGLTexture(GLuint*, TCHAR[]);

	// variable declaration
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("RTR6");
	BOOL bDone = FALSE;

	int smX = GetSystemMetrics(SM_CXSCREEN);
	int smY = GetSystemMetrics(SM_CYSCREEN);

	int x = smX / 2 - WIN_WIDTH/2;
	int y = smY / 2 - WIN_HEIGHT/2;

	// code
	// Create log file
	gpFile = fopen(gszLogFileName, "w");
	if (gpFile == NULL)
	{
		MessageBox(hwnd, TEXT("Log file creation failed"), TEXT("FILE IO ERROR"), MB_OK);
		exit(0);
	}
	else
	{
		fprintf(gpFile, "Program started successfully\n");
	}
	
	// Window Class Initialization
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

	// Registration of Window Class
	RegisterClassEx(&wndclass);

	// Create Window
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
		TEXT("Radhika Vishwakarma"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		x,  // update as homework
		y,  // update as homework
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	
	ghwnd = hwnd;

	// Show Window
	ShowWindow(hwnd, iCmdShow);

	// Point Background & Window
	UpdateWindow(hwnd);
	
	// initialize
	int result = initialize();
	
	if (result != 0)
	{
		fprintf(gpFile, "Initialized function failed\n");
		DestroyWindow(hwnd);
		hwnd = NULL;
	}
	else
	{
		fprintf(gpFile, "Initialized function completed successfully\n");
	}

	// Set this window as foreground and active window
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	

	// Game Loop
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

	return((int)msg.wParam);
}

// Callback Function
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// function declarations
	void toggleFullScreen(void);
	void resize(int, int);
	void uninitialize(void);

	// code
	switch (iMsg)
	{
		case WM_CREATE:
			ZeroMemory((void*) &wpPrev, sizeof(WINDOWPLACEMENT));
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
					gbEscapeKeyIsPressed = TRUE;
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

	return(DefWindowProc(hWnd, iMsg, wParam, lParam));
}

// functions which don't have body are called as stub functions
void toggleFullScreen(void)
{
	// Variable declarations
	MONITORINFO mi;
	if(gbFullScreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if(dwStyle & WS_OVERLAPPEDWINDOW)
		{
			ZeroMemory((void*) &mi, sizeof(MONITORINFO));
			mi.cbSize = sizeof(MONITORINFO);

			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				int monitorWidth = mi.rcMonitor.right - mi.rcMonitor.left;
				int monitorHeight = mi.rcMonitor.bottom - mi.rcMonitor.top;
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, monitorWidth, monitorHeight, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
	}
	ShowCursor(TRUE);
}

int initialize(void)
{
	// function declaration
	void resize(int, int);

	// local variable declaration
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;

    // code
	// PixelFormatDescriptor initialization
	ZeroMemory((void*) &pfd, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;

	// Get DC
	ghdc = GetDC(ghwnd);

	if (ghdc == NULL)
	{
		fprintf(gpFile, "Get DC function failed!\n");
		return(-1);
	}

	// Get matching pixel format index using hdc and pfd
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "Choose pixel format failed!\n");
		return(-2);
	}
	
	// Select the pixel format of found index
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "Set pixel format function failed!\n");
		return(-3);
	}
	
	// Create rendering context using hdc, pfd and chosen pixel format index
	ghrc = wglCreateContext(ghdc);	// function from Bridging API
	if (ghdc == NULL)
	{
		fprintf(gpFile, "wglCreateContext function failed!\n");
		return(-4);
	}

	// Make this rendering context as current context
	if (wglMakeCurrent(ghdc,ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent function failed!\n");
		return(-5);
	}
	
	// Depth related code
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// From here OpenGL Code starts
	// Tell OpenGL to choose the color to clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Load Textures
	if(loadGLTexture(&texture_brick, MAKEINTRESOURCE(IDBITMAP_BRICK)) == FALSE)
	{
		fprintf(gpFile, "Loading brick texture failed!\n");
		return(-6);
	}

	if(loadGLTexture(&texture_roof, MAKEINTRESOURCE(IDBITMAP_ROOF)) == FALSE)
	{
		fprintf(gpFile, "Loading roof texture failed!\n");
		return(-7);
	}
	
	// Enable Texturing
	glEnable(GL_TEXTURE_2D);

	
	// warm up resize
	resize(WIN_WIDTH, WIN_HEIGHT);

    return(0);
}

BOOL loadGLTexture(GLuint *texture, TCHAR imageResourceID[])
{
	// variable declarations
	HBITMAP hBitmap = NULL;
	BITMAP bmp;
	BOOL bResult = FALSE;

	// code
	// load the bitmap is image
	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION); // Create Device Independent Bitmap (DIB Section)
	if (hBitmap)
	{
		bResult = TRUE;

		// Get bitmap structure from the loaded bitmap image
		GetObject(hBitmap, sizeof(BITMAP), &bmp);

		// Generate OpenGL Texture Object
		glGenTextures(1, texture);
		// Bind to the newly created empty structure object
		glBindTexture(GL_TEXTURE_2D, *texture);
		// Unpack the image in memory for faster loading
		glPixelStorei(GL_UNPACK_ALIGNMENT, 4); // 4 is for RGBA - 4 channels
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);
		glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture by passing 0
		// delete object
		DeleteObject(hBitmap);
		hBitmap = NULL;
	}
	return bResult;
}

void resize(int width, int height)
{
    // code
	// if height by accident becomes 0 then make height 1
	if (height <= 0)
	{
		height = 1;
	}

	// Set the viewport
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	// set matrix projection mode
	glMatrixMode(GL_PROJECTION);

	// set to identity matrix
	glLoadIdentity();

	// do perspective projection
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
}

void display(void)
{
    // code
	// clear OpenGL buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set Matrix to Model View mode
	glMatrixMode(GL_MODELVIEW);

	// Set it to identity matrix
	glLoadIdentity();

	// translate Cube backwards
	glTranslatef(0.0f, 0.0f, -8.0f);
	glRotatef(angleCube, -0.25f, 1.0f, 0.0f);

	glBindTexture(GL_TEXTURE_2D, texture_brick);

	// Draw Cube here
	glBegin(GL_QUADS);
	// Front face
	// Top Right
	glTexCoord2f(1.0, 1.0);
    glVertex3f(2.0f, 1.0f, 1.0f);

	// Top Left
	glTexCoord2f(0.0, 1.0);
    glVertex3f(-2.0f, 1.0f, 1.0f);

	// Bottom Left
	glTexCoord2f(0.0, 0.0);
    glVertex3f(-2.0f, -1.0f, 1.0f);

	// Bottom Right
	glTexCoord2f(1.0, 0.0);
    glVertex3f(2.0f, -1.0f, 1.0f);

	// Right face
	// Top Right
	glTexCoord2f(1.0, 1.0);
    glVertex3f(2.0f, 1.0f, -1.0f);

	// Top Left
	glTexCoord2f(0.0, 1.0);
    glVertex3f(2.0f, 1.0f, 1.0f);

	// Bottom Left
	glTexCoord2f(0.0, 0.0);
    glVertex3f(2.0f, -1.0f, 1.0f);

	// Bottom Right
	glTexCoord2f(1.0, 0.0);
    glVertex3f(2.0f, -1.0f, -1.0f);

	// Back face
	// Top Right
	glTexCoord2f(1.0, 1.0);
    glVertex3f(-2.0f, 1.0f, -1.0f);

	// Top Left
	glTexCoord2f(0.0, 1.0);
    glVertex3f(2.0f, 1.0f, -1.0f);

	// Bottom Left
	glTexCoord2f(0.0, 0.0);
    glVertex3f(2.0f, -1.0f, -1.0f);

	// Bottom Right
	glTexCoord2f(1.0, 0.0);
    glVertex3f(-2.0f, -1.0f, -1.0f);

	// Left face
	// Top Right
	glTexCoord2f(1.0, 1.0);
    glVertex3f(-2.0f, 1.0f, 1.0f);

	// Top Left
	glTexCoord2f(0.0, 1.0);
    glVertex3f(-2.0f, 1.0f, -1.0f);

	// Bottom Left
	glTexCoord2f(0.0, 0.0);
    glVertex3f(-2.0f, -1.0f, -1.0f);

	// Bottom Right
	glTexCoord2f(1.0, 0.0);
    glVertex3f(-2.0f, -1.0f, 1.0f);

	// Top face
	// Top Right
	glTexCoord2f(1.0, 1.0);
    glVertex3f(-2.0f, 1.0f, -1.0f);

	// Top Left
	glTexCoord2f(0.0, 1.0);
    glVertex3f(-2.0f, 1.0f, 1.0f);

	// Bottom Left
	glTexCoord2f(0.0, 0.0);
    glVertex3f(2.0f, 1.0f, 1.0f);

	// Bottom Right
	glTexCoord2f(1.0, 0.0);
    glVertex3f(2.0f, 1.0f, -1.0f);

	// Bottom face
	// Top Right
	glTexCoord2f(1.0, 1.0);
    glVertex3f(-2.0f, -1.0f, -1.0f);

	// Top Left
	glTexCoord2f(0.0, 1.0);
    glVertex3f(-2.0f, -1.0f, 1.0f);

	// Bottom Left
	glTexCoord2f(0.0, 0.0);
    glVertex3f(2.0f, -1.0f, 1.0f);

	// Bottom Right
	glTexCoord2f(1.0, 0.0);
    glVertex3f(2.0f, -1.0f, -1.0f);

    glEnd();

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture here

	glBindTexture(GL_TEXTURE_2D, texture_roof);
	glBegin(GL_QUADS);
	// extra 2 top Quads for roof
	// Top right
	glTexCoord2f(1.0, 1.0);
	glVertex3f(2.0f, 2.0f, 0.0f);

	// Top left
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-2.0f, 2.0f, 0.0f);

	// Bottom left
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-2.0f, 1.0f, -1.0f);

	// Bottom right
	glTexCoord2f(1.0, 0.0);
	glVertex3f(2.0f, 1.0f, -1.0f);
	
	// Top right
	glTexCoord2f(1.0, 1.0);
	glVertex3f(2.0f, 2.0f, 0.0f);

	// Top left
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-2.0f, 2.0f, 0.0f);

	// Bottom left
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-2.0f, 1.0f, 1.0f);

	// Bottom right
	glTexCoord2f(1.0, 0.0);
	glVertex3f(2.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(2.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(2.0f, 1.0f, -1.0f);

	
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-2.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0, 0.0);
	
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture here

	SwapBuffers(ghdc);
}

void update(void)
{
	// code
	// angleCube += 0.05f;
	// if (angleCube >= 360.0f)
	// {
	// 	angleCube = angleCube - 360.0f;
	// }
		
}

void uninitialize(void) {
	// function declarations
	void toggleFullScreen(void);

    // code
	// If user is exiting in fullscreen then return fullscreen back to normal
	if(gbFullScreen == TRUE)
	{
		toggleFullScreen();
		gbFullScreen = FALSE;
	}
	
	if (texture_brick)
	{
		glDeleteTextures(1, &texture_brick);
		texture_brick = 0;
	}
	
	// Make hdc as current context by releasing rendering context as current context
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}
	
	// Delete the rendering context
	if(ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// Release DC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
	}

	// Destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}
	
	
	// Close the file
	if (gpFile)
	{
		fprintf(gpFile, "Program terminated successfully\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}