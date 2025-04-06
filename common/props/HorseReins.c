#include "../common.h"

// Reins drawing function
void drawReins(MY_POINT horsePos, MY_POINT handPos)
{
    glLineWidth(3.0f);
    glColor3f(0.5f, 0.3f, 0.1f); // Dark brown for rope

    const int segments = 10; // Number of line segments for rope
    float dx = (handPos.x - horsePos.x) / segments;
    float dy = (handPos.y - horsePos.y) / segments;
    float dz = (handPos.z - horsePos.z) / segments;

    glBegin(GL_LINES);
    for (int i = 0; i < segments; i++)
    {
        float t = (float)i / segments;
        float nextT = (float)(i + 1) / segments;

        // Current and next points
        float x1 = horsePos.x + t * (handPos.x - horsePos.x);
        float y1 = horsePos.y + t * (handPos.y - horsePos.y);
        float z1 = horsePos.z + t * (handPos.z - horsePos.z);
        float x2 = horsePos.x + nextT * (handPos.x - horsePos.x);
        float y2 = horsePos.y + nextT * (handPos.y - horsePos.y);
        float z2 = horsePos.z + nextT * (handPos.z - horsePos.z);

        // Add slight droop using a sine wave
        float droop = 0.05f * sinf(3.14f * t); // Small vertical oscillation
        y1 -= droop;
        y2 -= 0.05f * sinf(3.14f * nextT);

        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y2, z2);
    }
    glEnd();
}