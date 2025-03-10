// customer header files
#include "../common.h"

extern FILE *gpFile;

// Function to generate a random float between 0 and 1
float getRandomFloat()
{
    return (float)rand() / (float)RAND_MAX;
}

// sets co-ordinates to draw circular curve
void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.01f)
    {
        ObjX = centerX + radiusH * cos(ObjAngle);
        ObjY = centerY + radiusV * sin(ObjAngle);
        glVertex3f(ObjX, ObjY * WINDOW_ASPECT, 0.0f);
    }
}
