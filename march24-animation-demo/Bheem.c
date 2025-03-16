#include "Raster.h"
#include "../common/common.h"

// OpenGL realated libraries
#pragma comment(lib, "opengl32.lib")

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

void drawPolygon(GLfloat vertices[][2], int numVertices, Color color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        glVertex2f(vertices[i][0] + x_Bheem, vertices[i][1] + y_Bheem);
    }
    glEnd();
}

// Function to draw a point with offsets
void drawPoint(GLfloat x, GLfloat y, GLfloat size, Color color) {
    glColor3f(color.r, color.g, color.b);
    glPointSize(size);
    glBegin(GL_POINTS);
    glVertex2f(x +x_Bheem, y + y_Bheem);
    glEnd();
}

void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat lineWidth,Color color) {
    glColor3f(color.r, color.g, color.b);  // Set line color
    glLineWidth(lineWidth); // Set line thickness

    glBegin(GL_LINES);
        glVertex2f(x1+x_Bheem, y1+ y_Bheem); // Start point
        glVertex2f(x2+x_Bheem, y2+ y_Bheem); // End point
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

// Lower body shape
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
    drawPoint(0.0f, 0.625f, 10.0f, WHITE_COLOR);
    drawPoint(0.01f, 0.627f, 4.0f, BLACK_COLOR);
}

void drawBhimHair() {
    GLfloat vertices[][2] = {
        {-0.086f, 0.615f}, {0.045f, 0.663f}, {0.01f, 0.700f},
        {-0.025f, 0.714f}, {-0.066f, 0.685f}, {-0.070f, 0.665f}, {-0.073f, 0.64f}
    };
    drawPolygon(vertices, sizeof(vertices) / sizeof(vertices[0]), HAIR_COLOR);
}

void drawBhimMouth() {
    drawPoint(0.012f, 0.516f, 5.0f, RED_COLOR);
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


void drawBhimFoldLeg() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.151f, 0.259f);
	glVertex2f(0.023f, 0.265f);
	glVertex2f(0.093, 0.065);
	glVertex2f(-0.241, 0.059);
	glEnd();
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

void Bhim_SitDown()
{
 glClear(GL_COLOR_BUFFER_BIT);
 drawBhimWeapon();
 drawBhimLower();
 drawBhimFace();
 drawBhimRightHand();
 drawBhimEye();
 drawBhimMouth();
 drawBhimHair();

 drawBhimFoldLeg();
 drawBhimMustache();
}

void Move_Bheem(void)
{
    x_Bheem += 0.0001f;

   // printf("x_Bheem: %f\n", x_Bheem);

    if (x_Bheem > 1.0f) {
        x_Bheem = -1.0f;
    }
}
