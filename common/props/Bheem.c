// header files
//#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include "Nakul.h"

float x_Bheem = -0.7;
float y_Bheem = -0.35;
//static float SCALE_FACTOR = -0.4f;


// Color Structure
typedef struct {
    GLfloat r, g, b;
} Color;

#define HANDLE_COLOR (Color){0.6f, 0.4f, 0.2f}

void drawBheemWeapon();

void changeDhotiColor(float r, float g, float b) {
    DhotiColor[0] = r;
    DhotiColor[1] = g;
    DhotiColor[2] = b;
}

void drawBPolygon(GLfloat vertices[][2], int numVertices, Color color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        glVertex2f((vertices[i][0] ) + x_Bheem, (vertices[i][1] ) + y_Bheem);
    }
    glEnd();
}

void drawBheem(float xOrigin, float yOrigin, float scale)
{
    changeDhotiColor(1.0f, 0.0f, 0.0f);
    drawBheemWeapon(xOrigin, yOrigin, scale);
	drawHead(xOrigin, yOrigin, scale);
	drawCommonBody(xOrigin, yOrigin, scale, 1);
	drawHandAndCloth(xOrigin, yOrigin, scale, 1);
}

void drawBheemWeapon(float xOrigin, float yOrigin, float scale) {
    // Weapon handle (shaft)
    scale *=-0.4f;
    GLfloat handle[][2] = {
        {xOrigin + (0.203f * scale), yOrigin + (0.469f * scale)},
        {xOrigin + (0.185f * scale), yOrigin + (0.44f * scale)},
        {xOrigin + (-0.174f * scale), yOrigin + (0.633f * scale)},
        {xOrigin + (-0.141f * scale), yOrigin + (0.656f * scale)}
    };
    drawBPolygon(handle, 4, HANDLE_COLOR);

    // Weapon head (blade)
    GLfloat blade[][2] = {
        {xOrigin + (-0.060f * scale), yOrigin + (0.640f * scale)},
        {xOrigin + (-0.070f * scale), yOrigin + (0.665f * scale)},
        {xOrigin + (-0.090f * scale), yOrigin + (0.680f * scale)},
        {xOrigin + (-0.120f * scale), yOrigin + (0.690f * scale)},
        {xOrigin + (-0.150f * scale), yOrigin + (0.730f * scale)},
        {xOrigin + (-0.180f * scale), yOrigin + (0.690f * scale)},
        {xOrigin + (-0.210f * scale), yOrigin + (0.680f * scale)},
        {xOrigin + (-0.230f * scale), yOrigin + (0.665f * scale)},
        {xOrigin + (-0.240f * scale), yOrigin + (0.640f * scale)},
        {xOrigin + (-0.230f * scale), yOrigin + (0.615f * scale)},
        {xOrigin + (-0.210f * scale), yOrigin + (0.600f * scale)},
        {xOrigin + (-0.180f * scale), yOrigin + (0.590f * scale)},
        {xOrigin + (-0.150f * scale), yOrigin + (0.550f * scale)},
        {xOrigin + (-0.120f * scale), yOrigin + (0.590f * scale)},
        {xOrigin + (-0.090f * scale), yOrigin + (0.600f * scale)},
        {xOrigin + (-0.070f * scale), yOrigin + (0.615f * scale)}
    };
    drawBPolygon(blade, 16, HANDLE_COLOR);
}
