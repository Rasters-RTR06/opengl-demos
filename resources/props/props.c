// win32 headers / standard headerfiles
#include <windows.h>
#include <stdio.h>  // i/o for file
#include <stdlib.h> // exit() call
// OpenGL related header files
#include <gl/GL.h>
#include <math.h>

extern FILE *gpFile;

struct Dots
{
    float x;
    float y;
    float dotColor;
};

void drawBushAt(float centerX, float centerY, float radiusX, float radiusY)
{
    // function prototypes
    float getRandomFloat();

    // variable declarations
    static int setDots = 1;
    int numberOfDots = 200;
    static struct Dots dots[300];
    float bushRadius = 0.05f;

    if (setDots != 0)
    {
        for (int i = 0; i < numberOfDots; i++)
        {
            // Generate random polar coordinates within the bush radius
            float radiusXUpdated = radiusX * sqrt(getRandomFloat()); // sqrt for uniform distribution
            float radiusYUpdated = radiusY * sqrt(getRandomFloat()); // sqrt for uniform distribution
            float angle = 2.0f * 3.14159265358979323846f * getRandomFloat();

            // Convert polar to Cartesian coordinates
            dots[i].x = radiusXUpdated * cos(angle);
            dots[i].y = radiusYUpdated * sin(angle);
            dots[i].dotColor = 0.2f + 0.8f * getRandomFloat();
        }

        // after setting the dots for one time, they should not be changed
        setDots = 0;
    }

    // bush outline curves
    glBegin(GL_LINES);
    for (int i = 0; i < numberOfDots; i++)
    {
        // plot points
    }

    glPointSize(3.0f); // Adjust point size as needed
    glBegin(GL_POINTS);
    for (int i = 0; i < numberOfDots; i++)
    {
        // plot dots
        glColor3f(0.0f, dots[i].dotColor, 0.0f);              // Set the color
        glVertex2f(centerX + dots[i].x, centerY + dots[i].y); // Draw the point
    }
    glEnd();
}

// Function to generate a random float between 0 and 1
float getRandomFloat()
{
    return (float)rand() / (float)RAND_MAX;
}

void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.01f)
    {
        ObjX = centerX + radiusH * cos(ObjAngle);
        ObjY = centerY + radiusV * sin(ObjAngle);
        glVertex2f(ObjX, ObjY);
    }
}
