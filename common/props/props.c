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
    // float ObjX = 0.0f;
    // float ObjY = 0.0f;
    float ObjAngle = 0.0f;
    fprintf(gpFile, "inside setcircularCurvePoint centerX: %f, centerY: %f\n", centerX, centerY);
    fprintf(gpFile, "inside setcircularCurvePoint radiusH: %f, radiusV: %f\n", radiusH, radiusV);

    for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.01f)
    {
        float ObjX = centerX + (radiusH * cos(ObjAngle));
        float ObjY = centerY + (radiusV * WINDOW_ASPECT * sin(ObjAngle));
        glVertex3f(ObjX, ObjY, 0.0f);
    }
}
