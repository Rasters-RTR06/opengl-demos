#ifndef COMMON_H
#define COMMON_H

// win32 headers / standard headerfiles
#include <windows.h>
#include <stdio.h>  // i/o for file
#include <stdlib.h> // exit() call
#include <math.h>
// OpenGL related header files
#include <gl/GL.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// constants
#define PI 3.14159265358979323846f
#define WINDOW_ASPECT (16.0f / 9.0f)

// custom header files
#include "./props/props.h"

#endif