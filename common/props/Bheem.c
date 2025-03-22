// header files
//#include <GL/freeglut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <math.h>
//#include <stdio.h>
//#include "Nakul.h"
#include "../common.h"

//#define SKIN_COLOR                      \
//	{                                   \
//		glColor3f(0.98f, 0.75f, 0.54f); \
//	}


float x_Bheem = -0.7;
float y_Bheem = -0.35;
//static float SCALE_FACTOR = -0.4f;


// Color Structure
typedef struct {
    GLfloat r, g, b;
} Color;

#define HANDLE_COLOR (Color){0.6f, 0.4f, 0.2f}
#define BHEEM_DHOTI_COLOR { glColor3f(1.0f, 0.0f, 0.0f);}
#define Yudhishthir_DHOTI_COLOR { glColor3f(1.0f, 1.0f, 0.0f);}
#define Nakul_DHOTI_COLOR { glColor3f(0.0f, 1.0f, 0.0f);}
#define Sahadev_DHOTI_COLOR { glColor3f(1.0f, 0.0f, 1.0f);}
#define Arjun_DHOTI_COLOR { glColor3f(0.0f, 1.0f, 1.0f);}

void drawBheemWeapon();

//void changeDhotiColor(float r, float g, float b) {
//    DhotiColor[0] = r;
//    DhotiColor[1] = g;
//    DhotiColor[2] = b;
//}

void drawQuadrangleBheem(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

// Draw Line
void drawLineBheem(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawcircleBheem(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;

	// Circle
	if (fill == 1)
	{
		glBegin(GL_POLYGON);
	}
	else
	{
		glBegin(GL_POINTS);
	}

	for (ObjAngle = (0.00f); ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)
	{
		ObjX = x + radius_hor * sin(ObjAngle);
		ObjY = y + radius_vert * cos(ObjAngle);

		glColor3f(r, g, b);

		glVertex2f(ObjX, ObjY);
	}
	glEnd();
}

void drawTriangleBheem(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}


void drawBPolygon(GLfloat vertices[][2], int numVertices, Color color) {
    glColor3f(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < numVertices; i++) {
        glVertex2f((vertices[i][0] ) + x_Bheem, (vertices[i][1] ) + y_Bheem);
    }
    glEnd();
}

void drawBheem(float xOrigin, float yOrigin, float scale, int iStanding, float color)
{
	void drawHeadBheem(float, float, float);
	void drawClothBackSideBheem(float, float, float);
	void drawCommonBodyBheem(float, float, float, int, float);
	void drawHandAndClothBheem(float, float, float, int);

    //changeDhotiColor(1.0f, 0.0f, 0.0f);
    //drawBheemWeapon(xOrigin, yOrigin, scale);
	drawHeadBheem(xOrigin, yOrigin, scale);
	drawCommonBodyBheem(xOrigin, yOrigin, scale, iStanding, color);
	drawHandAndClothBheem(xOrigin, yOrigin, scale, iStanding);
}

void drawYuthishteer(float xOrigin, float yOrigin, float scale, int iStanding, float color)
{
	void drawHeadBheem(float, float, float);
	void drawClothBackSideBheem(float, float, float);
	void drawCommonBodyBheem(float, float, float, int, float);
	void drawHandAndClothBheem(float, float, float, int);


	drawHeadBheem(xOrigin, yOrigin, scale);
	drawCommonBodyBheem(xOrigin, yOrigin, scale, iStanding, color);
	drawHandAndClothBheem(xOrigin, yOrigin, scale, iStanding);
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

void drawHeadBheem(float xOriginBheem, float yOriginBheem, float scale)
{
	// hairs
	{
		glColor3f(0.0f, 0.0f, 0.0f);

		drawcircleBheem(
			xOriginBheem + (-0.7850f * scale), yOriginBheem + (0.2550f * scale),
			(0.030f * scale), (0.020f * scale), 0.0f, 0.0f, 0.0f, 1);

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.7900f * scale), yOriginBheem + (0.2650f * scale));
		glVertex2f(xOriginBheem + (-0.7950f * scale), yOriginBheem + (0.2200f * scale));
		glVertex2f(xOriginBheem + (-0.7900f * scale), yOriginBheem + (0.1800f * scale));
		glVertex2f(xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.1500f * scale));
		glVertex2f(xOriginBheem + (-0.7625f * scale), yOriginBheem + (0.1900f * scale));
		glVertex2f(xOriginBheem + (-0.7625f * scale), yOriginBheem + (0.2200f * scale));
		glVertex2f(xOriginBheem + (-0.7250f * scale), yOriginBheem + (0.2600f * scale));
		glEnd();

		glColor3f(0.7f, 0.7f, 0.7f); // hair band
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7950f * scale), yOriginBheem + (0.2300f * scale));
		glVertex2f(xOriginBheem + (-0.7800f * scale), yOriginBheem + (0.2400f * scale));

		glVertex2f(xOriginBheem + (-0.7800f * scale), yOriginBheem + (0.2400f * scale));
		glVertex2f(xOriginBheem + (-0.7600f * scale), yOriginBheem + (0.2650f * scale));
		glEnd();
	}

	glColor3f(1.0f, 0.73f, 0.50f); // Face Skin 1

	glBegin(GL_POLYGON);
	glVertex2f(xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.1500f * scale));
	glVertex2f(xOriginBheem + (-0.7350f * scale), yOriginBheem + (0.1000f * scale));
	glVertex2f(xOriginBheem + (-0.7100f * scale), yOriginBheem + (0.1200f * scale));
	glVertex2f(xOriginBheem + (-0.7100f * scale), yOriginBheem + (0.1450f * scale));
	glVertex2f(xOriginBheem + (-0.7000f * scale), yOriginBheem + (0.1450f * scale)); // nose cut
	glVertex2f(xOriginBheem + (-0.7100f * scale), yOriginBheem + (0.2000f * scale));
	glVertex2f(xOriginBheem + (-0.7070f * scale), yOriginBheem + (0.2050f * scale));
	glVertex2f(xOriginBheem + (-0.7120f * scale), yOriginBheem + (0.2500f * scale));
	glVertex2f(xOriginBheem + (-0.730f * scale), yOriginBheem + (0.2550f * scale));
	glEnd();
	drawTriangleBheem(
		xOriginBheem + (-0.7300f * scale), yOriginBheem + (0.2550f * scale),
		xOriginBheem + (-0.7625f * scale), yOriginBheem + (0.2200f * scale),
		xOriginBheem + (-0.7625f * scale), yOriginBheem + (0.1750f * scale));

	// lips
	{
		glColor3f(0.5f, 0.5f, 0.5f);
		// glLineWidth(0.75f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7100f * scale), yOriginBheem + (0.1330f * scale));
		glVertex2f(xOriginBheem + (-0.7220f * scale), yOriginBheem + (0.1330f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7220f * scale), yOriginBheem + (0.1330f * scale));
		glVertex2f(xOriginBheem + (-0.7100f * scale), yOriginBheem + (0.1280f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7220f * scale), yOriginBheem + (0.1330f * scale));
		glVertex2f(xOriginBheem + (-0.7100f * scale), yOriginBheem + (0.1380f * scale));
		glEnd();
	}

	// eye
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		drawQuadrangleBheem(
			xOriginBheem + (-0.7130f * scale), yOriginBheem + (0.2000f * scale),
			xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2080f * scale),
			xOriginBheem + (-0.7400f * scale), yOriginBheem + (0.2000f * scale),
			xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.1920f * scale));

		glColor3f(0.5f, 0.5f, 0.5f);

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7130f * scale), yOriginBheem + (0.2000f * scale));
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2080f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2080f * scale));
		glVertex2f(xOriginBheem + (-0.7400f * scale), yOriginBheem + (0.2000f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7400f * scale), yOriginBheem + (0.2000f * scale));
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.1920f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.1920f * scale));
		glVertex2f(xOriginBheem + (-0.7130f * scale), yOriginBheem + (0.2000f * scale));
		glEnd();

		glColor3f(0.0f, 0.0f, 0.0f);
		glPointSize(4.0f);
		glBegin(GL_POINTS);
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2000f * scale));
		glEnd();
		glPointSize(1.0f);

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7130f * scale), yOriginBheem + (0.2150f * scale));
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2200f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2200f * scale));
		glVertex2f(xOriginBheem + (-0.7400f * scale), yOriginBheem + (0.2150f * scale));
		glEnd();
		/*glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7400f * scale), yOriginBheem + (0.2180f * scale));
		glVertex2f(xOriginBheem + (-0.7200f * scale), yOriginBheem + (0.2180f * scale));
		glEnd();*/
	}

	{
		glLineWidth(2.0f);
		glColor3f(1.0f, 0.337f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7180f * scale), yOriginBheem + (0.2400f * scale));
		glVertex2f(xOriginBheem + (-0.7160f * scale), yOriginBheem + (0.2300f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7160f * scale), yOriginBheem + (0.2300f * scale));
		glVertex2f(xOriginBheem + (-0.7090f * scale), yOriginBheem + (0.2260f * scale));
		glEnd();
		glLineWidth(1.0f);
	}

	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7700f * scale), yOriginBheem + (0.1750f * scale));
		glVertex2f(xOriginBheem + (-0.7700f * scale), yOriginBheem + (0.1500f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7700f * scale), yOriginBheem + (0.1500f * scale));
		glVertex2f(xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.1400f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7600f * scale), yOriginBheem + (0.1500f * scale));
		glVertex2f(xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.1400f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.1400f * scale));
		glVertex2f(xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.1300f * scale));
		glEnd();

		/*drawcircleBheem(
			xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.1250f * scale),
			(0.01f * scale), (0.01f * scale), 0.33f, 0.11f, 0.0f, 1);*/
	}
}

void drawClothBackSideBheem(float xOriginBheem, float yOriginBheem, float scale)
{
	{
		glColor3f(0.50f, 0.67f, 0.35f);
		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.844f * scale), yOriginBheem + (-0.050f * scale));
		glVertex2f(xOriginBheem + (-0.844f * scale), yOriginBheem + (-0.200f * scale));
		glVertex2f(xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.350f * scale));
		glVertex2f(xOriginBheem + (-0.835f * scale), yOriginBheem + (-0.350f * scale));
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.250f * scale));

		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.080f * scale));
		glEnd();

		drawTriangleBheem(
			xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.350f * scale),
			xOriginBheem + (-0.835f * scale), yOriginBheem + (-0.350f * scale),
			xOriginBheem + (-0.834f * scale), yOriginBheem + (-0.375f * scale));

		glLineWidth(5.0f);
		glColor3f(0.87f, 0.40f, 0.44f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.834f * scale), yOriginBheem + (-0.375f * scale));
		glVertex2f(xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.350f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.350f * scale));
		glVertex2f(xOriginBheem + (-0.850f * scale), yOriginBheem + (-0.200f * scale));
		glEnd();

		glBegin(GL_LINES);

		glVertex2f(xOriginBheem + (-0.850f * scale), yOriginBheem + (-0.200f * scale));
		glVertex2f(xOriginBheem + (-0.844f * scale), yOriginBheem + (-0.059f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
}

void drawCommonBodyBheem(float xOriginBheem, float yOriginBheem, float scale, int iStanding, float color)
{
	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
	// neck
	drawQuadrangleBheem(
		xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.0800f * scale),
		xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.1500f * scale),
		xOriginBheem + (-0.7350f * scale), yOriginBheem + (0.1000f * scale),
		xOriginBheem + (-0.7350f * scale), yOriginBheem + (0.0800f * scale));

	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
	// Torso
	glBegin(GL_POLYGON);
	glVertex2f(xOriginBheem + (-0.835f * scale), yOriginBheem + (0.050f * scale));
	glVertex2f(xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.0800f * scale));
	glVertex2f(xOriginBheem + (-0.735f * scale), yOriginBheem + (0.0800f * scale));
	glVertex2f(xOriginBheem + (-0.680f * scale), yOriginBheem + (0.050f * scale));
	glVertex2f(xOriginBheem + (-0.685f * scale), yOriginBheem + (-0.25f * scale));
	glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.25f * scale));
	glEnd();

	if (iStanding == 1)
	{
		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		// glColor3f(0.851f, 0.236f, 0.427f);//pink
		// back leg lower
		drawTriangleBheem(
			xOriginBheem + (-0.820f * scale), yOriginBheem + (-0.55f * scale),
			xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.45f * scale),
			xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.55f * scale));
		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.65f * scale));
		glVertex2f(xOriginBheem + (-0.820f * scale), yOriginBheem + (-0.55f * scale));
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.55f * scale));
		glVertex2f(xOriginBheem + (-0.783f * scale), yOriginBheem + (-0.83f * scale));
		glVertex2f(xOriginBheem + (-0.818f * scale), yOriginBheem + (-0.83f * scale));
		glEnd();
		// front leg lower
		drawTriangleBheem(
			xOriginBheem + (-0.747f * scale), yOriginBheem + (-0.550f * scale),
			xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.450f * scale),
			xOriginBheem + (-0.690f * scale), yOriginBheem + (-0.550f * scale));
		drawQuadrangleBheem(
			xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.830f * scale),
			xOriginBheem + (-0.695f * scale), yOriginBheem + (-0.825f * scale),
			xOriginBheem + (-0.690f * scale), yOriginBheem + (-0.550f * scale),
			xOriginBheem + (-0.747f * scale), yOriginBheem + (-0.550f * scale));

		// glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		SKIN_COLOR;
			// Back foot
			drawQuadrangleBheem(
				xOriginBheem + (-0.83f * scale), yOriginBheem + (-0.85f * scale),
				xOriginBheem + (-0.818f * scale), yOriginBheem + (-0.83f * scale),
				xOriginBheem + (-0.783f * scale), yOriginBheem + (-0.83f * scale),
				xOriginBheem + (-0.78f * scale), yOriginBheem + (-0.85f * scale));

		drawQuadrangleBheem(
			xOriginBheem + (-0.83f * scale), yOriginBheem + (-0.85f * scale),
			xOriginBheem + (-0.78f * scale), yOriginBheem + (-0.93f * scale),
			xOriginBheem + (-0.74f * scale), yOriginBheem + (-0.93f * scale),
			xOriginBheem + (-0.78f * scale), yOriginBheem + (-0.85f * scale));

		// front foot
		drawQuadrangleBheem(
			xOriginBheem + (-0.745f * scale), yOriginBheem + (-0.850f * scale),
			xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.830f * scale),
			xOriginBheem + (-0.695f * scale), yOriginBheem + (-0.825f * scale),
			xOriginBheem + (-0.688f * scale), yOriginBheem + (-0.837f * scale));

		drawQuadrangleBheem(
			xOriginBheem + (-0.745f * scale), yOriginBheem + (-0.850f * scale),
			xOriginBheem + (-0.660f * scale), yOriginBheem + (-0.900f * scale),
			xOriginBheem + (-0.628f * scale), yOriginBheem + (-0.870f * scale),
			xOriginBheem + (-0.688f * scale), yOriginBheem + (-0.837f * scale));

		// fingers
		glColor3f(0.6f, 0.6f, 0.6f);
		// back
		drawLineBheem(
			xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.93f * scale),
			xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.91f * scale));
		drawLineBheem(
			xOriginBheem + (-0.758f * scale), yOriginBheem + (-0.93f * scale),
			xOriginBheem + (-0.773f * scale), yOriginBheem + (-0.91f * scale));
		drawLineBheem(
			xOriginBheem + (-0.766f * scale), yOriginBheem + (-0.93f * scale),
			xOriginBheem + (-0.781f * scale), yOriginBheem + (-0.91f * scale));
		drawLineBheem(
			xOriginBheem + (-0.774f * scale), yOriginBheem + (-0.93f * scale),
			xOriginBheem + (-0.789f * scale), yOriginBheem + (-0.91f * scale));

		// front
		drawLineBheem(
			xOriginBheem + (-0.65f * scale), yOriginBheem + (-0.89f * scale),
			xOriginBheem + (-0.67f * scale), yOriginBheem + (-0.878f * scale));
		drawLineBheem(
			xOriginBheem + (-0.645f * scale), yOriginBheem + (-0.885f * scale),
			xOriginBheem + (-0.665f * scale), yOriginBheem + (-0.873f * scale));
		drawLineBheem(
			xOriginBheem + (-0.64f * scale), yOriginBheem + (-0.88f * scale),
			xOriginBheem + (-0.66f * scale), yOriginBheem + (-0.868f * scale));
		drawLineBheem(
			xOriginBheem + (-0.635f * scale), yOriginBheem + (-0.875f * scale),
			xOriginBheem + (-0.655f * scale), yOriginBheem + (-0.863f * scale));

		// Dhoti
		if(color == 0){
		  BHEEM_DHOTI_COLOR}
		else if (color == 1)
		{
		  Yudhishthir_DHOTI_COLOR
		} 

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.835f * scale), yOriginBheem + (-0.35f * scale));
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.25f * scale));
		glVertex2f(xOriginBheem + (-0.685f * scale), yOriginBheem + (-0.25f * scale));
		glVertex2f(xOriginBheem + (-0.680f * scale), yOriginBheem + (-0.35f * scale));
		glVertex2f(xOriginBheem + (-0.683f * scale), yOriginBheem + (-0.45f * scale));
		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.45f * scale));
		glEnd();

		drawTriangleBheem(
			xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.450f * scale),
			xOriginBheem + (-0.683f * scale), yOriginBheem + (-0.450f * scale),
			xOriginBheem + (-0.690f * scale), yOriginBheem + (-0.550f * scale));
		drawTriangleBheem(
			xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.450f * scale),
			xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.450f * scale),
			xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.550f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.400f * scale));
		glVertex2f(xOriginBheem + (-0.775f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.755f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.755f * scale), yOriginBheem + (-0.600f * scale));
		glVertex2f(xOriginBheem + (-0.730f * scale), yOriginBheem + (-0.612f * scale));
		glVertex2f(xOriginBheem + (-0.736f * scale), yOriginBheem + (-0.425f * scale));
		glEnd();

		// Border Lines
		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.775f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.768f * scale), yOriginBheem + (-0.250f * scale));

		glVertex2f(xOriginBheem + (-0.730f * scale), yOriginBheem + (-0.612f * scale));
		glVertex2f(xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.250f * scale));

		glVertex2f(xOriginBheem + (-0.775f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.731f * scale), yOriginBheem + (-0.530f * scale));

		glVertex2f(xOriginBheem + (-0.775f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.731f * scale), yOriginBheem + (-0.575f * scale));

		glVertex2f(xOriginBheem + (-0.731f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.755f * scale), yOriginBheem + (-0.600f * scale));

		glVertex2f(xOriginBheem + (-0.755f * scale), yOriginBheem + (-0.600f * scale));
		glVertex2f(xOriginBheem + (-0.730f * scale), yOriginBheem + (-0.612f * scale));
		glEnd();

		glLineWidth(3.0f);

		glColor3f(0.63f, 0.53f, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.250f * scale));
		glVertex2f(xOriginBheem + (-0.685f * scale), yOriginBheem + (-0.250f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.250f * scale));
		glVertex2f(xOriginBheem + (-0.731f * scale), yOriginBheem + (-0.530f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.775f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.731f * scale), yOriginBheem + (-0.530f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.731f * scale), yOriginBheem + (-0.575f * scale));
		glVertex2f(xOriginBheem + (-0.755f * scale), yOriginBheem + (-0.600f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.450f * scale));
		glVertex2f(xOriginBheem + (-0.775f * scale), yOriginBheem + (-0.540f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.735f * scale), yOriginBheem + (-0.465f * scale));
		glVertex2f(xOriginBheem + (-0.690f * scale), yOriginBheem + (-0.550f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
	else
	{
		// Dhoti
		if(color == 0){
			BHEEM_DHOTI_COLOR}
		  else if (color == 1)
		  {
			Yudhishthir_DHOTI_COLOR
		  }

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.930f * scale), yOriginBheem + (-0.40f * scale));
		glVertex2f(xOriginBheem + (-0.930f * scale), yOriginBheem + (-0.32f * scale));
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.25f * scale));
		glVertex2f(xOriginBheem + (-0.685f * scale), yOriginBheem + (-0.25f * scale));
		glVertex2f(xOriginBheem + (-0.565f * scale), yOriginBheem + (-0.32f * scale));
		glVertex2f(xOriginBheem + (-0.565f * scale), yOriginBheem + (-0.40f * scale));
		glVertex2f(xOriginBheem + (-0.683f * scale), yOriginBheem + (-0.45f * scale));
		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.45f * scale));
		glEnd();

		// knee1
		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.930f * scale), yOriginBheem + (-0.320f * scale));
		glVertex2f(xOriginBheem + (-0.945f * scale), yOriginBheem + (-0.345f * scale));
		glVertex2f(xOriginBheem + (-0.945f * scale), yOriginBheem + (-0.375f * scale));
		glVertex2f(xOriginBheem + (-0.930f * scale), yOriginBheem + (-0.400f * scale));
		glEnd();
		// knee2
		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.565f * scale), yOriginBheem + (-0.320f * scale));
		glVertex2f(xOriginBheem + (-0.550f * scale), yOriginBheem + (-0.345f * scale));
		glVertex2f(xOriginBheem + (-0.550f * scale), yOriginBheem + (-0.375f * scale));
		glVertex2f(xOriginBheem + (-0.565f * scale), yOriginBheem + (-0.400f * scale));
		glEnd();

		SKIN_COLOR
			drawQuadrangleBheem(
				xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.450f * scale),
				xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.373f * scale),
				xOriginBheem + (-0.625f * scale), yOriginBheem + (-0.350f * scale),
				xOriginBheem + (-0.683f * scale), yOriginBheem + (-0.450f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.450f * scale));
		glVertex2f(xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.373f * scale));
		glVertex2f(xOriginBheem + (-0.825f * scale), yOriginBheem + (-0.355f * scale));
		glVertex2f(xOriginBheem + (-0.885f * scale), yOriginBheem + (-0.350f * scale));
		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.450f * scale));
		glEnd();

		if(color == 0){
			BHEEM_DHOTI_COLOR}
		  else if (color == 1)
		  {
			Yudhishthir_DHOTI_COLOR
		  }
		// leg1
		drawQuadrangleBheem(
			xOriginBheem + (-0.625f * scale), yOriginBheem + (-0.350f * scale),
			xOriginBheem + (-0.650f * scale), yOriginBheem + (-0.360f * scale),
			xOriginBheem + (-0.676f * scale), yOriginBheem + (-0.410f * scale),
			xOriginBheem + (-0.683f * scale), yOriginBheem + (-0.450f * scale));
		// leg2
		drawQuadrangleBheem(
			xOriginBheem + (-0.885f * scale), yOriginBheem + (-0.350f * scale),
			xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.360f * scale),
			xOriginBheem + (-0.840f * scale), yOriginBheem + (-0.410f * scale),
			xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.450f * scale));

		glLineWidth(3.0f);

		glColor3f(0.63f, 0.53f, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.250f * scale));
		glVertex2f(xOriginBheem + (-0.735f * scale), yOriginBheem + (-0.370f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP); // waist
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (-0.250f * scale));
		glVertex2f(xOriginBheem + (-0.685f * scale), yOriginBheem + (-0.250f * scale));
		glEnd();

		// leg1
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.683f * scale), yOriginBheem + (-0.450f * scale));
		glVertex2f(xOriginBheem + (-0.676f * scale), yOriginBheem + (-0.410f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.676f * scale), yOriginBheem + (-0.410f * scale));
		glVertex2f(xOriginBheem + (-0.650f * scale), yOriginBheem + (-0.360f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.650f * scale), yOriginBheem + (-0.360f * scale));
		glVertex2f(xOriginBheem + (-0.625f * scale), yOriginBheem + (-0.350f * scale));
		glEnd();

		// leg2
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.450f * scale));
		glVertex2f(xOriginBheem + (-0.840f * scale), yOriginBheem + (-0.410f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.840f * scale), yOriginBheem + (-0.410f * scale));
		glVertex2f(xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.360f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginBheem + (-0.860f * scale), yOriginBheem + (-0.360f * scale));
		glVertex2f(xOriginBheem + (-0.885f * scale), yOriginBheem + (-0.350f * scale));
		glEnd();
		glLineWidth(1.0f);

		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.768f * scale), yOriginBheem + (-0.250f * scale));
		glVertex2f(xOriginBheem + (-0.773f * scale), yOriginBheem + (-0.370f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.373f * scale));
		glVertex2f(xOriginBheem + (-0.625f * scale), yOriginBheem + (-0.350f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.770f * scale), yOriginBheem + (-0.373f * scale));
		glVertex2f(xOriginBheem + (-0.825f * scale), yOriginBheem + (-0.355f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.825f * scale), yOriginBheem + (-0.355f * scale));
		glVertex2f(xOriginBheem + (-0.885f * scale), yOriginBheem + (-0.350f * scale));
		glEnd();
	}
}

void drawHandAndClothBheem(float xOriginBheem, float yOriginBheem, float scale, int iStanding)
{
	// Ear rudraksh
	drawcircleBheem(
		xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.1300f * scale),
		(0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

	// neck thread
	glColor3f(0.63f, 0.53f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.0800f * scale));
	glVertex2f(xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.0700f * scale));
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7650f * scale), yOriginBheem + (0.0700f * scale));
	glVertex2f(xOriginBheem + (-0.7500f * scale), yOriginBheem + (0.0700f * scale));
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7500f * scale), yOriginBheem + (0.0700f * scale));
	glVertex2f(xOriginBheem + (-0.7350f * scale), yOriginBheem + (0.0800f * scale));
	glEnd();

	// locket
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7825f * scale), yOriginBheem + (0.0800f * scale));
	glVertex2f(xOriginBheem + (-0.7700f * scale), yOriginBheem + (0.0000f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7700f * scale), yOriginBheem + (0.0000f * scale));
	glVertex2f(xOriginBheem + (-0.7500f * scale), yOriginBheem + (-0.0500f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7500f * scale), yOriginBheem + (-0.0500f * scale));
	glVertex2f(xOriginBheem + (-0.7400f * scale), yOriginBheem + (-0.0200f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOriginBheem + (-0.7400f * scale), yOriginBheem + (-0.0200f * scale));
	glVertex2f(xOriginBheem + (-0.7350f * scale), yOriginBheem + (0.0800f * scale));
	glEnd();

	drawcircleBheem(
		xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.0500f * scale),
		(0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

	{
		// shoulder cloth
		glColor3f(0.50f, 0.67f, 0.35f);

		drawQuadrangleBheem(
			xOriginBheem + (-0.680f * scale), yOriginBheem + (0.051f * scale),
			xOriginBheem + (-0.720f * scale), yOriginBheem + (0.071f * scale),
			xOriginBheem + (-0.760f * scale), yOriginBheem + (-0.325f * scale),
			xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.345f * scale));

		glLineWidth(5.0f);
		glColor3f(0.87f, 0.40f, 0.44f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (0.071f * scale));
		glVertex2f(xOriginBheem + (-0.760f * scale), yOriginBheem + (-0.325f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.760f * scale), yOriginBheem + (-0.325f * scale));
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.345f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.680f * scale), yOriginBheem + (0.051f * scale));
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.345f * scale));
		glEnd();

		glLineWidth(1.0f);

		glColor3f(0.50f, 0.67f, 0.35f);

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.800f * scale), yOriginBheem + (0.075f * scale));
		glVertex2f(xOriginBheem + (-0.830f * scale), yOriginBheem + (0.060f * scale));
		glVertex2f(xOriginBheem + (-0.800f * scale), yOriginBheem + (0.015f * scale));
		glVertex2f(xOriginBheem + (-0.780f * scale), yOriginBheem + (-0.035f * scale));
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.090f * scale));
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.050f * scale));
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.090f * scale));
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.050f * scale));
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.090f * scale));
		glVertex2f(xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.140f * scale));
		glVertex2f(xOriginBheem + (-0.745f * scale), yOriginBheem + (-0.160f * scale));
		glVertex2f(xOriginBheem + (-0.700f * scale), yOriginBheem + (-0.080f * scale));
		glEnd();

		glLineWidth(5.0f);
		glColor3f(0.87f, 0.40f, 0.44f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.800f * scale), yOriginBheem + (0.075f * scale));
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.050f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.765f * scale), yOriginBheem + (-0.050f * scale));
		glVertex2f(xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.090f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.750f * scale), yOriginBheem + (-0.090f * scale));
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.080f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.080f * scale));
		glVertex2f(xOriginBheem + (-0.690f * scale), yOriginBheem + (-0.050f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.749f * scale), yOriginBheem + (-0.155f * scale));
		glVertex2f(xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.150f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.740f * scale), yOriginBheem + (-0.150f * scale));
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.145f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.720f * scale), yOriginBheem + (-0.145f * scale));
		glVertex2f(xOriginBheem + (-0.710f * scale), yOriginBheem + (-0.135f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.710f * scale), yOriginBheem + (-0.135f * scale));
		glVertex2f(xOriginBheem + (-0.695f * scale), yOriginBheem + (-0.095f * scale));
		glEnd();

		glLineWidth(1.0f);
	}

	{
		SKIN_COLOR
			// Hands
			drawQuadrangleBheem(
				xOriginBheem + (-0.835f * scale), yOriginBheem + (0.050f * scale),
				xOriginBheem + (-0.845f * scale), yOriginBheem + (0.0166f * scale),
				xOriginBheem + (-0.844f * scale), yOriginBheem + (-0.050f * scale),
				xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.080f * scale));

		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOriginBheem + (-0.833f * scale), yOriginBheem + (-0.080f * scale));
		glVertex2f(xOriginBheem + (-0.760f * scale), yOriginBheem + (-0.235f * scale));
		glEnd();

		// Back side hand
		glColor3f(1.0f, 0.73f, 0.50f); // Face Skin 1
		drawQuadrangleBheem(
			xOriginBheem + (-0.6550f * scale), yOriginBheem + (-0.250f * scale),
			xOriginBheem + (-0.6875f * scale), yOriginBheem + (-0.160f * scale),
			xOriginBheem + (-0.6800f * scale), yOriginBheem + (0.050f * scale),
			xOriginBheem + (-0.6550f * scale), yOriginBheem + (-0.1350f * scale));

		drawQuadrangleBheem(
			xOriginBheem + (-0.6250f * scale), yOriginBheem + (-0.075f * scale),
			xOriginBheem + (-0.6550f * scale), yOriginBheem + (-0.1350f * scale),
			xOriginBheem + (-0.6550f * scale), yOriginBheem + (-0.250f * scale),
			xOriginBheem + (-0.6100f * scale), yOriginBheem + (-0.095f * scale));

		drawTriangleBheem(
			xOriginBheem + (-0.6250f * scale), yOriginBheem + (-0.075f * scale),
			xOriginBheem + (-0.6100f * scale), yOriginBheem + (-0.095f * scale),
			xOriginBheem + (-0.6000f * scale), yOriginBheem + (-0.080f * scale));

		drawQuadrangleBheem(
			xOriginBheem + (-0.6250f * scale), yOriginBheem + (-0.075f * scale),
			xOriginBheem + (-0.6000f * scale), yOriginBheem + (-0.080f * scale),
			xOriginBheem + (-0.5950f * scale), yOriginBheem + (-0.010f * scale),
			xOriginBheem + (-0.6175f * scale), yOriginBheem + (0.020f * scale));

		drawTriangleBheem(
			xOriginBheem + (-0.5950f * scale), yOriginBheem + (-0.010f * scale),
			xOriginBheem + (-0.6175f * scale), yOriginBheem + (0.020f * scale),
			xOriginBheem + (-0.6050f * scale), yOriginBheem + (0.024f * scale)); // finger tips

		if (iStanding == 1)
		{
			drawQuadrangleBheem(
				xOriginBheem + (-0.6250f * scale), yOriginBheem + (-0.075f * scale),
				xOriginBheem + (-0.6300f * scale), yOriginBheem + (-0.050f * scale),
				xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.010f * scale),
				xOriginBheem + (-0.6100f * scale), yOriginBheem + (-0.010f * scale)); // thumb
		}
		else
		{
			drawQuadrangleBheem(
				xOriginBheem + (-0.6249f * scale), yOriginBheem + (-0.075f * scale),
				xOriginBheem + (-0.6400f * scale), yOriginBheem + (-0.010f * scale),
				xOriginBheem + (-0.6350f * scale), yOriginBheem + (-0.010f * scale),
				xOriginBheem + (-0.6200f * scale), yOriginBheem + (-0.036f * scale)); // thumb
		}

		// fingers
		{
			glColor3f(0.6f, 0.6f, 0.6f);
			if (iStanding == 1)
			{
				glBegin(GL_LINES);
				glVertex2f(xOriginBheem + (-0.6190f * scale), yOriginBheem + (-0.006f * scale));
				glVertex2f(xOriginBheem + (-0.6230f * scale), yOriginBheem + (-0.036f * scale));
				glEnd();
			}

			glBegin(GL_LINES);
			glVertex2f(xOriginBheem + (-0.6100f * scale), yOriginBheem + (0.019f * scale));
			glVertex2f(xOriginBheem + (-0.6140f * scale), yOriginBheem + (-0.024f * scale));
			glEnd();

			glBegin(GL_LINES);
			glVertex2f(xOriginBheem + (-0.6030f * scale), yOriginBheem + (0.013f * scale));
			glVertex2f(xOriginBheem + (-0.6070f * scale), yOriginBheem + (-0.030f * scale));
			glEnd();

			glBegin(GL_LINES);
			glVertex2f(xOriginBheem + (-0.5980f * scale), yOriginBheem + (0.001f * scale));
			glVertex2f(xOriginBheem + (-0.6020f * scale), yOriginBheem + (-0.036f * scale));
			glEnd();
		}

		if (iStanding == 1)
		{
			// front side hand
			SKIN_COLOR
				drawQuadrangleBheem(
					xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.075f * scale),
					xOriginBheem + (-0.7500f * scale), yOriginBheem + (-0.160f * scale),
					xOriginBheem + (-0.7600f * scale), yOriginBheem + (-0.235f * scale),
					xOriginBheem + (-0.6125f * scale), yOriginBheem + (-0.100f * scale));

			drawTriangleBheem(
				xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.075f * scale),
				xOriginBheem + (-0.6125f * scale), yOriginBheem + (-0.100f * scale),
				xOriginBheem + (-0.6000f * scale), yOriginBheem + (-0.080f * scale));

			drawQuadrangleBheem(
				xOriginBheem + (-0.6250f * scale), yOriginBheem + (-0.075f * scale),
				xOriginBheem + (-0.6000f * scale), yOriginBheem + (-0.080f * scale),
				xOriginBheem + (-0.5950f * scale), yOriginBheem + (-0.010f * scale),
				xOriginBheem + (-0.6175f * scale), yOriginBheem + (0.020f * scale));

			drawTriangleBheem(
				xOriginBheem + (-0.5950f * scale), yOriginBheem + (-0.010f * scale),
				xOriginBheem + (-0.6175f * scale), yOriginBheem + (0.020f * scale),
				xOriginBheem + (-0.6050f * scale), yOriginBheem + (0.024f * scale)); // finger tips

			drawQuadrangleBheem(
				xOriginBheem + (-0.6250f * scale), yOriginBheem + (-0.075f * scale),
				xOriginBheem + (-0.6300f * scale), yOriginBheem + (-0.050f * scale),
				xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.010f * scale),
				xOriginBheem + (-0.6100f * scale), yOriginBheem + (-0.010f * scale)); // thumb

			// fingers
			{
				glColor3f(0.6f, 0.6f, 0.6f);
				glBegin(GL_LINES);
				glVertex2f(xOriginBheem + (-0.6190f * scale), yOriginBheem + (-0.006f * scale));
				glVertex2f(xOriginBheem + (-0.6230f * scale), yOriginBheem + (-0.036f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOriginBheem + (-0.6100f * scale), yOriginBheem + (0.019f * scale));
				glVertex2f(xOriginBheem + (-0.6140f * scale), yOriginBheem + (-0.024f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOriginBheem + (-0.6030f * scale), yOriginBheem + (0.013f * scale));
				glVertex2f(xOriginBheem + (-0.6070f * scale), yOriginBheem + (-0.030f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOriginBheem + (-0.5980f * scale), yOriginBheem + (0.001f * scale));
				glVertex2f(xOriginBheem + (-0.6020f * scale), yOriginBheem + (-0.036f * scale));
				glEnd();
			}
		}
		else
		{
			SKIN_COLOR
				drawQuadrangleBheem(
					xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.170f * scale),
					xOriginBheem + (-0.7500f * scale), yOriginBheem + (-0.160f * scale),
					xOriginBheem + (-0.7600f * scale), yOriginBheem + (-0.235f * scale),
					xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.195f * scale));

			drawQuadrangleBheem(
				xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.170f * scale),
				xOriginBheem + (-0.5900f * scale), yOriginBheem + (-0.180f * scale),
				xOriginBheem + (-0.5900f * scale), yOriginBheem + (-0.200f * scale),
				xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.195f * scale));

			drawQuadrangleBheem(
				xOriginBheem + (-0.5900f * scale), yOriginBheem + (-0.180f * scale),
				xOriginBheem + (-0.5700f * scale), yOriginBheem + (-0.170f * scale),
				xOriginBheem + (-0.5720f * scale), yOriginBheem + (-0.180f * scale),
				xOriginBheem + (-0.5900f * scale), yOriginBheem + (-0.200f * scale));

			drawTriangleBheem(
				xOriginBheem + (-0.6275f * scale), yOriginBheem + (-0.170f * scale),
				xOriginBheem + (-0.6000f * scale), yOriginBheem + (-0.150f * scale),
				xOriginBheem + (-0.6100f * scale), yOriginBheem + (-0.195f * scale));
		}
	}
}


