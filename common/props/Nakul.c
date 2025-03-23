// header files
#include "../common.h"
//#include "Nakul.h"



// Below setting required in init

// int initialize(void)
//{
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glClearColor(0.686f, 0.573f, 0.333f, 1.0f);
//
// }

// call to display Nakul

// void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	drawNakul(xOriginNakul, yOriginNakul, fScaleFactorNakul);
//
//	glutSwapBuffers();
// }

// Draw Rectangle


#define NAKUL_DHOTI_COLOR { glColor3f(0.78f, 0.78f, 0.278f);}

//#define NAKUL_SHOULDER_CLOTH_MAJOR {glColor3f(0.50f, 0.67f, 0.35f);}
#define NAKUL_SHOULDER_CLOTH_MAJOR {glColor3f(0.27f, 0.01f, 0.04f);}
//#define NAKUL_SHOULDER_CLOTH_MINOR {glColor3f(0.87f, 0.40f, 0.44f);}
#define NAKUL_SHOULDER_CLOTH_MINOR {glColor3f(0.75f, 0.55f, 0.00f);}

//void drawNakulDhoti() {
    
//}

void drawRectangleNakul(float LX, float RX, float TY, float BY)
{
	glBegin(GL_QUADS);
	glVertex2f(LX, TY);
	glVertex2f(RX, TY);
	glVertex2f(RX, BY);
	glVertex2f(LX, BY);
	glEnd();
}

void drawQuadrangleNakul(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

// Draw Line
void drawLineNakul(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawcircleNakul(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
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

void drawTriangleNakul(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawNakul(float xOriginNakul, float yOriginNakul, float scale, int iStanding, int iHandPosition)
{
	void drawClothBackSideNakul(float, float, float);
	void drawHeadNakul(float, float, float);
	void drawCommonBodyNakul(float, float, float, int);
	void drawHandAndClothNakul(float, float, float, int);
	
	drawClothBackSideNakul(xOriginNakul, yOriginNakul, scale);
	drawHeadNakul(xOriginNakul, yOriginNakul, scale);
	drawCommonBodyNakul(xOriginNakul, yOriginNakul, scale, iStanding);
	drawHandAndClothNakul(xOriginNakul, yOriginNakul, scale, iHandPosition);
}

void drawHeadNakul(float xOriginNakul, float yOriginNakul, float scale)
{
	// hairs
	{
		glColor3f(0.0f, 0.0f, 0.0f);

		drawcircleNakul(
			xOriginNakul + (-0.7850f * scale), yOriginNakul + (0.2550f * scale),
			(0.030f * scale), (0.020f * scale), 0.0f, 0.0f, 0.0f, 1);

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.7900f * scale), yOriginNakul + (0.2650f * scale));
		glVertex2f(xOriginNakul + (-0.7950f * scale), yOriginNakul + (0.2200f * scale));
		glVertex2f(xOriginNakul + (-0.7900f * scale), yOriginNakul + (0.1800f * scale));
		glVertex2f(xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.1500f * scale));
		glVertex2f(xOriginNakul + (-0.7625f * scale), yOriginNakul + (0.1900f * scale));
		glVertex2f(xOriginNakul + (-0.7625f * scale), yOriginNakul + (0.2200f * scale));
		glVertex2f(xOriginNakul + (-0.7250f * scale), yOriginNakul + (0.2600f * scale));
		glEnd();

		glColor3f(0.7f, 0.7f, 0.7f); // hair band
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7950f * scale), yOriginNakul + (0.2300f * scale));
		glVertex2f(xOriginNakul + (-0.7800f * scale), yOriginNakul + (0.2400f * scale));

		glVertex2f(xOriginNakul + (-0.7800f * scale), yOriginNakul + (0.2400f * scale));
		glVertex2f(xOriginNakul + (-0.7600f * scale), yOriginNakul + (0.2650f * scale));
		glEnd();
	}

	glColor3f(1.0f, 0.73f, 0.50f); // Face Skin 1

	glBegin(GL_POLYGON);
	glVertex2f(xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.1500f * scale));
	glVertex2f(xOriginNakul + (-0.7350f * scale), yOriginNakul + (0.1000f * scale));
	glVertex2f(xOriginNakul + (-0.7100f * scale), yOriginNakul + (0.1200f * scale));
	glVertex2f(xOriginNakul + (-0.7100f * scale), yOriginNakul + (0.1450f * scale));
	glVertex2f(xOriginNakul + (-0.7000f * scale), yOriginNakul + (0.1450f * scale)); // nose cut
	glVertex2f(xOriginNakul + (-0.7100f * scale), yOriginNakul + (0.2000f * scale));
	glVertex2f(xOriginNakul + (-0.7070f * scale), yOriginNakul + (0.2050f * scale));
	glVertex2f(xOriginNakul + (-0.7120f * scale), yOriginNakul + (0.2500f * scale));
	glVertex2f(xOriginNakul + (-0.7300f * scale), yOriginNakul + (0.2550f * scale));
	glEnd();
	drawTriangleNakul(
		xOriginNakul + (-0.7300f * scale), yOriginNakul + (0.2550f * scale),
		xOriginNakul + (-0.7625f * scale), yOriginNakul + (0.2200f * scale),
		xOriginNakul + (-0.7625f * scale), yOriginNakul + (0.1750f * scale));

	// lips
	{
		glColor3f(0.5f, 0.5f, 0.5f);
		// glLineWidth(0.75f);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7100f * scale), yOriginNakul + (0.1330f * scale));
		glVertex2f(xOriginNakul + (-0.7220f * scale), yOriginNakul + (0.1330f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7220f * scale), yOriginNakul + (0.1330f * scale));
		glVertex2f(xOriginNakul + (-0.7100f * scale), yOriginNakul + (0.1280f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7220f * scale), yOriginNakul + (0.1330f * scale));
		glVertex2f(xOriginNakul + (-0.7100f * scale), yOriginNakul + (0.1380f * scale));
		glEnd();
	}

	// eye
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		drawQuadrangleNakul(
			xOriginNakul + (-0.7130f * scale), yOriginNakul + (0.2000f * scale),
			xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2080f * scale),
			xOriginNakul + (-0.7400f * scale), yOriginNakul + (0.2000f * scale),
			xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.1920f * scale));

		glColor3f(0.5f, 0.5f, 0.5f);

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7130f * scale), yOriginNakul + (0.2000f * scale));
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2080f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2080f * scale));
		glVertex2f(xOriginNakul + (-0.7400f * scale), yOriginNakul + (0.2000f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7400f * scale), yOriginNakul + (0.2000f * scale));
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.1920f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.1920f * scale));
		glVertex2f(xOriginNakul + (-0.7130f * scale), yOriginNakul + (0.2000f * scale));
		glEnd();

		glColor3f(0.0f, 0.0f, 0.0f);
		glPointSize(4.0f);
		glBegin(GL_POINTS);
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2000f * scale));
		glEnd();
		glPointSize(1.0f);

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7130f * scale), yOriginNakul + (0.2150f * scale));
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2200f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2200f * scale));
		glVertex2f(xOriginNakul + (-0.7400f * scale), yOriginNakul + (0.2150f * scale));
		glEnd();
		/*glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7400f * scale), yOriginNakul + (0.2180f * scale));
		glVertex2f(xOriginNakul + (-0.7200f * scale), yOriginNakul + (0.2180f * scale));
		glEnd();*/
	}

	{
		glLineWidth(2.0f);
		glColor3f(1.0f, 0.337f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7180f * scale), yOriginNakul + (0.2400f * scale));
		glVertex2f(xOriginNakul + (-0.7160f * scale), yOriginNakul + (0.2300f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7160f * scale), yOriginNakul + (0.2300f * scale));
		glVertex2f(xOriginNakul + (-0.7090f * scale), yOriginNakul + (0.2260f * scale));
		glEnd();
		glLineWidth(1.0f);
	}

	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7700f * scale), yOriginNakul + (0.1750f * scale));
		glVertex2f(xOriginNakul + (-0.7700f * scale), yOriginNakul + (0.1500f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7700f * scale), yOriginNakul + (0.1500f * scale));
		glVertex2f(xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.1400f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7600f * scale), yOriginNakul + (0.1500f * scale));
		glVertex2f(xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.1400f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.1400f * scale));
		glVertex2f(xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.1300f * scale));
		glEnd();

		/*drawcircleNakul(
			xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.1250f * scale),
			(0.01f * scale), (0.01f * scale), 0.33f, 0.11f, 0.0f, 1);*/
	}
}

void drawClothBackSideNakul(float xOriginNakul, float yOriginNakul, float scale)
{
	{
		NAKUL_SHOULDER_CLOTH_MAJOR
		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.844f * scale), yOriginNakul + (-0.050f * scale));
		glVertex2f(xOriginNakul + (-0.844f * scale), yOriginNakul + (-0.200f * scale));
		glVertex2f(xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.350f * scale));
		glVertex2f(xOriginNakul + (-0.835f * scale), yOriginNakul + (-0.350f * scale));
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.250f * scale));

		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.080f * scale));
		glEnd();

		drawTriangleNakul(
			xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.350f * scale),
			xOriginNakul + (-0.835f * scale), yOriginNakul + (-0.350f * scale),
			xOriginNakul + (-0.834f * scale), yOriginNakul + (-0.375f * scale));

		glLineWidth(5.0f);
		NAKUL_SHOULDER_CLOTH_MINOR
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.834f * scale), yOriginNakul + (-0.375f * scale));
		glVertex2f(xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.350f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.350f * scale));
		glVertex2f(xOriginNakul + (-0.850f * scale), yOriginNakul + (-0.200f * scale));
		glEnd();

		glBegin(GL_LINES);

		glVertex2f(xOriginNakul + (-0.850f * scale), yOriginNakul + (-0.200f * scale));
		glVertex2f(xOriginNakul + (-0.844f * scale), yOriginNakul + (-0.059f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
}

void drawCommonBodyNakul(float xOriginNakul, float yOriginNakul, float scale, int iStanding)
{
	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
	// neck
	drawQuadrangleNakul(
		xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.0800f * scale),
		xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.1500f * scale),
		xOriginNakul + (-0.7350f * scale), yOriginNakul + (0.1000f * scale),
		xOriginNakul + (-0.7350f * scale), yOriginNakul + (0.0800f * scale));

	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
	// Torso
	glBegin(GL_POLYGON);
	glVertex2f(xOriginNakul + (-0.835f * scale), yOriginNakul + (0.050f * scale));
	glVertex2f(xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.0800f * scale));
	glVertex2f(xOriginNakul + (-0.735f * scale), yOriginNakul + (0.0800f * scale));
	glVertex2f(xOriginNakul + (-0.680f * scale), yOriginNakul + (0.050f * scale));
	glVertex2f(xOriginNakul + (-0.685f * scale), yOriginNakul + (-0.25f * scale));
	glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.25f * scale));
	glEnd();

	if (iStanding == 1)
	{
		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		// glColor3f(0.851f, 0.236f, 0.427f);//pink
		// back leg lower
		drawTriangleNakul(
			xOriginNakul + (-0.820f * scale), yOriginNakul + (-0.55f * scale),
			xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.45f * scale),
			xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.55f * scale));
		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.65f * scale));
		glVertex2f(xOriginNakul + (-0.820f * scale), yOriginNakul + (-0.55f * scale));
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.55f * scale));
		glVertex2f(xOriginNakul + (-0.783f * scale), yOriginNakul + (-0.83f * scale));
		glVertex2f(xOriginNakul + (-0.818f * scale), yOriginNakul + (-0.83f * scale));
		glEnd();
		// front leg lower
		drawTriangleNakul(
			xOriginNakul + (-0.747f * scale), yOriginNakul + (-0.550f * scale),
			xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.450f * scale),
			xOriginNakul + (-0.690f * scale), yOriginNakul + (-0.550f * scale));
		drawQuadrangleNakul(
			xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.830f * scale),
			xOriginNakul + (-0.695f * scale), yOriginNakul + (-0.825f * scale),
			xOriginNakul + (-0.690f * scale), yOriginNakul + (-0.550f * scale),
			xOriginNakul + (-0.747f * scale), yOriginNakul + (-0.550f * scale));

		// glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		SKIN_COLOR
		// Back foot
		drawQuadrangleNakul(
			xOriginNakul + (-0.83f * scale), yOriginNakul + (-0.85f * scale),
			xOriginNakul + (-0.818f * scale), yOriginNakul + (-0.83f * scale),
			xOriginNakul + (-0.783f * scale), yOriginNakul + (-0.83f * scale),
			xOriginNakul + (-0.78f * scale), yOriginNakul + (-0.85f * scale));

		drawQuadrangleNakul(
			xOriginNakul + (-0.83f * scale), yOriginNakul + (-0.85f * scale),
			xOriginNakul + (-0.78f * scale), yOriginNakul + (-0.93f * scale),
			xOriginNakul + (-0.74f * scale), yOriginNakul + (-0.93f * scale),
			xOriginNakul + (-0.78f * scale), yOriginNakul + (-0.85f * scale));

		// front foot
		drawQuadrangleNakul(
			xOriginNakul + (-0.745f * scale), yOriginNakul + (-0.850f * scale),
			xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.830f * scale),
			xOriginNakul + (-0.695f * scale), yOriginNakul + (-0.825f * scale),
			xOriginNakul + (-0.688f * scale), yOriginNakul + (-0.837f * scale));

		drawQuadrangleNakul(
			xOriginNakul + (-0.745f * scale), yOriginNakul + (-0.850f * scale),
			xOriginNakul + (-0.660f * scale), yOriginNakul + (-0.900f * scale),
			xOriginNakul + (-0.628f * scale), yOriginNakul + (-0.870f * scale),
			xOriginNakul + (-0.688f * scale), yOriginNakul + (-0.837f * scale));

		// fingers
		glColor3f(0.6f, 0.6f, 0.6f);
		// back
		drawLineNakul(
			xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.93f * scale),
			xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.91f * scale));
		drawLineNakul(
			xOriginNakul + (-0.758f * scale), yOriginNakul + (-0.93f * scale),
			xOriginNakul + (-0.773f * scale), yOriginNakul + (-0.91f * scale));
		drawLineNakul(
			xOriginNakul + (-0.766f * scale), yOriginNakul + (-0.93f * scale),
			xOriginNakul + (-0.781f * scale), yOriginNakul + (-0.91f * scale));
		drawLineNakul(
			xOriginNakul + (-0.774f * scale), yOriginNakul + (-0.93f * scale),
			xOriginNakul + (-0.789f * scale), yOriginNakul + (-0.91f * scale));

		// front
		drawLineNakul(
			xOriginNakul + (-0.65f * scale), yOriginNakul + (-0.89f * scale),
			xOriginNakul + (-0.67f * scale), yOriginNakul + (-0.878f * scale));
		drawLineNakul(
			xOriginNakul + (-0.645f * scale), yOriginNakul + (-0.885f * scale),
			xOriginNakul + (-0.665f * scale), yOriginNakul + (-0.873f * scale));
		drawLineNakul(
			xOriginNakul + (-0.64f * scale), yOriginNakul + (-0.88f * scale),
			xOriginNakul + (-0.66f * scale), yOriginNakul + (-0.868f * scale));
		drawLineNakul(
			xOriginNakul + (-0.635f * scale), yOriginNakul + (-0.875f * scale),
			xOriginNakul + (-0.655f * scale), yOriginNakul + (-0.863f * scale));

		// Dhoti
		NAKUL_DHOTI_COLOR

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.835f * scale), yOriginNakul + (-0.35f * scale));
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.25f * scale));
		glVertex2f(xOriginNakul + (-0.685f * scale), yOriginNakul + (-0.25f * scale));
		glVertex2f(xOriginNakul + (-0.680f * scale), yOriginNakul + (-0.35f * scale));
		glVertex2f(xOriginNakul + (-0.683f * scale), yOriginNakul + (-0.45f * scale));
		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.45f * scale));
		glEnd();

		drawTriangleNakul(
			xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.450f * scale),
			xOriginNakul + (-0.683f * scale), yOriginNakul + (-0.450f * scale),
			xOriginNakul + (-0.690f * scale), yOriginNakul + (-0.550f * scale));
		drawTriangleNakul(
			xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.450f * scale),
			xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.450f * scale),
			xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.550f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.400f * scale));
		glVertex2f(xOriginNakul + (-0.775f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.755f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.755f * scale), yOriginNakul + (-0.600f * scale));
		glVertex2f(xOriginNakul + (-0.730f * scale), yOriginNakul + (-0.612f * scale));
		glVertex2f(xOriginNakul + (-0.736f * scale), yOriginNakul + (-0.425f * scale));
		glEnd();

		// Border Lines
		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.775f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.768f * scale), yOriginNakul + (-0.250f * scale));

		glVertex2f(xOriginNakul + (-0.730f * scale), yOriginNakul + (-0.612f * scale));
		glVertex2f(xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.250f * scale));

		glVertex2f(xOriginNakul + (-0.775f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.731f * scale), yOriginNakul + (-0.530f * scale));

		glVertex2f(xOriginNakul + (-0.775f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.731f * scale), yOriginNakul + (-0.575f * scale));

		glVertex2f(xOriginNakul + (-0.731f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.755f * scale), yOriginNakul + (-0.600f * scale));

		glVertex2f(xOriginNakul + (-0.755f * scale), yOriginNakul + (-0.600f * scale));
		glVertex2f(xOriginNakul + (-0.730f * scale), yOriginNakul + (-0.612f * scale));
		glEnd();

		glLineWidth(3.0f);

		glColor3f(0.63f, 0.53f, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.250f * scale));
		glVertex2f(xOriginNakul + (-0.685f * scale), yOriginNakul + (-0.250f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.250f * scale));
		glVertex2f(xOriginNakul + (-0.731f * scale), yOriginNakul + (-0.530f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.775f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.731f * scale), yOriginNakul + (-0.530f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.731f * scale), yOriginNakul + (-0.575f * scale));
		glVertex2f(xOriginNakul + (-0.755f * scale), yOriginNakul + (-0.600f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.450f * scale));
		glVertex2f(xOriginNakul + (-0.775f * scale), yOriginNakul + (-0.540f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.735f * scale), yOriginNakul + (-0.465f * scale));
		glVertex2f(xOriginNakul + (-0.690f * scale), yOriginNakul + (-0.550f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
	else
	{
		// Dhoti
		NAKUL_DHOTI_COLOR

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.930f * scale), yOriginNakul + (-0.40f * scale));
		glVertex2f(xOriginNakul + (-0.930f * scale), yOriginNakul + (-0.32f * scale));
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.25f * scale));
		glVertex2f(xOriginNakul + (-0.685f * scale), yOriginNakul + (-0.25f * scale));
		glVertex2f(xOriginNakul + (-0.565f * scale), yOriginNakul + (-0.32f * scale));
		glVertex2f(xOriginNakul + (-0.565f * scale), yOriginNakul + (-0.40f * scale));
		glVertex2f(xOriginNakul + (-0.683f * scale), yOriginNakul + (-0.45f * scale));
		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.45f * scale));
		glEnd();

		// knee1
		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.930f * scale), yOriginNakul + (-0.320f * scale));
		glVertex2f(xOriginNakul + (-0.945f * scale), yOriginNakul + (-0.345f * scale));
		glVertex2f(xOriginNakul + (-0.945f * scale), yOriginNakul + (-0.375f * scale));
		glVertex2f(xOriginNakul + (-0.930f * scale), yOriginNakul + (-0.400f * scale));
		glEnd();
		// knee2
		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.565f * scale), yOriginNakul + (-0.320f * scale));
		glVertex2f(xOriginNakul + (-0.550f * scale), yOriginNakul + (-0.345f * scale));
		glVertex2f(xOriginNakul + (-0.550f * scale), yOriginNakul + (-0.375f * scale));
		glVertex2f(xOriginNakul + (-0.565f * scale), yOriginNakul + (-0.400f * scale));
		glEnd();

		SKIN_COLOR
		drawQuadrangleNakul(
			xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.450f * scale),
			xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.373f * scale),
			xOriginNakul + (-0.625f * scale), yOriginNakul + (-0.350f * scale),
			xOriginNakul + (-0.683f * scale), yOriginNakul + (-0.450f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.450f * scale));
		glVertex2f(xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.373f * scale));
		glVertex2f(xOriginNakul + (-0.825f * scale), yOriginNakul + (-0.355f * scale));
		glVertex2f(xOriginNakul + (-0.885f * scale), yOriginNakul + (-0.350f * scale));
		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.450f * scale));
		glEnd();

		NAKUL_DHOTI_COLOR
		// leg1
		drawQuadrangleNakul(
			xOriginNakul + (-0.625f * scale), yOriginNakul + (-0.350f * scale),
			xOriginNakul + (-0.650f * scale), yOriginNakul + (-0.360f * scale),
			xOriginNakul + (-0.676f * scale), yOriginNakul + (-0.410f * scale),
			xOriginNakul + (-0.683f * scale), yOriginNakul + (-0.450f * scale));
		// leg2
		drawQuadrangleNakul(
			xOriginNakul + (-0.885f * scale), yOriginNakul + (-0.350f * scale),
			xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.360f * scale),
			xOriginNakul + (-0.840f * scale), yOriginNakul + (-0.410f * scale),
			xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.450f * scale));

		glLineWidth(3.0f);

		glColor3f(0.63f, 0.53f, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.250f * scale));
		glVertex2f(xOriginNakul + (-0.735f * scale), yOriginNakul + (-0.370f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP); // waist
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (-0.250f * scale));
		glVertex2f(xOriginNakul + (-0.685f * scale), yOriginNakul + (-0.250f * scale));
		glEnd();

		// leg1
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.683f * scale), yOriginNakul + (-0.450f * scale));
		glVertex2f(xOriginNakul + (-0.676f * scale), yOriginNakul + (-0.410f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.676f * scale), yOriginNakul + (-0.410f * scale));
		glVertex2f(xOriginNakul + (-0.650f * scale), yOriginNakul + (-0.360f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.650f * scale), yOriginNakul + (-0.360f * scale));
		glVertex2f(xOriginNakul + (-0.625f * scale), yOriginNakul + (-0.350f * scale));
		glEnd();

		// leg2
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.450f * scale));
		glVertex2f(xOriginNakul + (-0.840f * scale), yOriginNakul + (-0.410f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.840f * scale), yOriginNakul + (-0.410f * scale));
		glVertex2f(xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.360f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginNakul + (-0.860f * scale), yOriginNakul + (-0.360f * scale));
		glVertex2f(xOriginNakul + (-0.885f * scale), yOriginNakul + (-0.350f * scale));
		glEnd();
		glLineWidth(1.0f);

		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.768f * scale), yOriginNakul + (-0.250f * scale));
		glVertex2f(xOriginNakul + (-0.773f * scale), yOriginNakul + (-0.370f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.373f * scale));
		glVertex2f(xOriginNakul + (-0.625f * scale), yOriginNakul + (-0.350f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.770f * scale), yOriginNakul + (-0.373f * scale));
		glVertex2f(xOriginNakul + (-0.825f * scale), yOriginNakul + (-0.355f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.825f * scale), yOriginNakul + (-0.355f * scale));
		glVertex2f(xOriginNakul + (-0.885f * scale), yOriginNakul + (-0.350f * scale));
		glEnd();
	}
}

void drawHandAndClothNakul(float xOriginNakul, float yOriginNakul, float scale, int iHandPosition)
{
	// Ear rudraksh
	drawcircleNakul(
		xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.1300f * scale),
		(0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

	// neck thread
	glColor3f(0.63f, 0.53f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.0800f * scale));
	glVertex2f(xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.0700f * scale));
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7650f * scale), yOriginNakul + (0.0700f * scale));
	glVertex2f(xOriginNakul + (-0.7500f * scale), yOriginNakul + (0.0700f * scale));
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7500f * scale), yOriginNakul + (0.0700f * scale));
	glVertex2f(xOriginNakul + (-0.7350f * scale), yOriginNakul + (0.0800f * scale));
	glEnd();

	// locket
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7825f * scale), yOriginNakul + (0.0800f * scale));
	glVertex2f(xOriginNakul + (-0.7700f * scale), yOriginNakul + (0.0000f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7700f * scale), yOriginNakul + (0.0000f * scale));
	glVertex2f(xOriginNakul + (-0.7500f * scale), yOriginNakul + (-0.0500f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7500f * scale), yOriginNakul + (-0.0500f * scale));
	glVertex2f(xOriginNakul + (-0.7400f * scale), yOriginNakul + (-0.0200f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOriginNakul + (-0.7400f * scale), yOriginNakul + (-0.0200f * scale));
	glVertex2f(xOriginNakul + (-0.7350f * scale), yOriginNakul + (0.0800f * scale));
	glEnd();

	drawcircleNakul(
		xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.0500f * scale),
		(0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

	{
		// shoulder cloth
		NAKUL_SHOULDER_CLOTH_MAJOR

		drawQuadrangleNakul(
			xOriginNakul + (-0.680f * scale), yOriginNakul + (0.051f * scale),
			xOriginNakul + (-0.720f * scale), yOriginNakul + (0.071f * scale),
			xOriginNakul + (-0.760f * scale), yOriginNakul + (-0.325f * scale),
			xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.345f * scale));

		glLineWidth(5.0f);
		NAKUL_SHOULDER_CLOTH_MINOR
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (0.071f * scale));
		glVertex2f(xOriginNakul + (-0.760f * scale), yOriginNakul + (-0.325f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.760f * scale), yOriginNakul + (-0.325f * scale));
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.345f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.680f * scale), yOriginNakul + (0.051f * scale));
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.345f * scale));
		glEnd();

		glLineWidth(1.0f);

		NAKUL_SHOULDER_CLOTH_MAJOR

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.800f * scale), yOriginNakul + (0.075f * scale));
		glVertex2f(xOriginNakul + (-0.830f * scale), yOriginNakul + (0.060f * scale));
		glVertex2f(xOriginNakul + (-0.800f * scale), yOriginNakul + (0.015f * scale));
		glVertex2f(xOriginNakul + (-0.780f * scale), yOriginNakul + (-0.035f * scale));
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.090f * scale));
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.050f * scale));
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.090f * scale));
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.050f * scale));
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.090f * scale));
		glVertex2f(xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.140f * scale));
		glVertex2f(xOriginNakul + (-0.745f * scale), yOriginNakul + (-0.160f * scale));
		glVertex2f(xOriginNakul + (-0.700f * scale), yOriginNakul + (-0.080f * scale));
		glEnd();

		glLineWidth(5.0f);
		NAKUL_SHOULDER_CLOTH_MINOR
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.800f * scale), yOriginNakul + (0.075f * scale));
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.050f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.765f * scale), yOriginNakul + (-0.050f * scale));
		glVertex2f(xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.090f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.750f * scale), yOriginNakul + (-0.090f * scale));
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.080f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.080f * scale));
		glVertex2f(xOriginNakul + (-0.690f * scale), yOriginNakul + (-0.050f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.749f * scale), yOriginNakul + (-0.155f * scale));
		glVertex2f(xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.150f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.740f * scale), yOriginNakul + (-0.150f * scale));
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.145f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.720f * scale), yOriginNakul + (-0.145f * scale));
		glVertex2f(xOriginNakul + (-0.710f * scale), yOriginNakul + (-0.135f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.710f * scale), yOriginNakul + (-0.135f * scale));
		glVertex2f(xOriginNakul + (-0.695f * scale), yOriginNakul + (-0.095f * scale));
		glEnd();

		glLineWidth(1.0f);
	}

	{
		SKIN_COLOR
		// Hands
		drawQuadrangleNakul(
			xOriginNakul + (-0.835f * scale), yOriginNakul + (0.050f * scale),
			xOriginNakul + (-0.845f * scale), yOriginNakul + (0.0166f * scale),
			xOriginNakul + (-0.844f * scale), yOriginNakul + (-0.050f * scale),
			xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.080f * scale));

		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.833f * scale), yOriginNakul + (-0.080f * scale));
		glVertex2f(xOriginNakul + (-0.760f * scale), yOriginNakul + (-0.235f * scale));
		glEnd();

		// Back side hand
		glColor3f(1.0f, 0.73f, 0.50f); // Face Skin 1
		drawQuadrangleNakul(
			xOriginNakul + (-0.6550f * scale), yOriginNakul + (-0.250f * scale),
			xOriginNakul + (-0.6875f * scale), yOriginNakul + (-0.160f * scale),
			xOriginNakul + (-0.6800f * scale), yOriginNakul + (0.050f * scale),
			xOriginNakul + (-0.6550f * scale), yOriginNakul + (-0.1350f * scale));

		drawQuadrangleNakul(
			xOriginNakul + (-0.6250f * scale), yOriginNakul + (-0.075f * scale),
			xOriginNakul + (-0.6550f * scale), yOriginNakul + (-0.1350f * scale),
			xOriginNakul + (-0.6550f * scale), yOriginNakul + (-0.250f * scale),
			xOriginNakul + (-0.6100f * scale), yOriginNakul + (-0.095f * scale));

		drawTriangleNakul(
			xOriginNakul + (-0.6250f * scale), yOriginNakul + (-0.075f * scale),
			xOriginNakul + (-0.6100f * scale), yOriginNakul + (-0.095f * scale),
			xOriginNakul + (-0.6000f * scale), yOriginNakul + (-0.080f * scale));

		drawQuadrangleNakul(
			xOriginNakul + (-0.6250f * scale), yOriginNakul + (-0.075f * scale),
			xOriginNakul + (-0.6000f * scale), yOriginNakul + (-0.080f * scale),
			xOriginNakul + (-0.5950f * scale), yOriginNakul + (-0.010f * scale),
			xOriginNakul + (-0.6175f * scale), yOriginNakul + (0.020f * scale));

		drawTriangleNakul(
			xOriginNakul + (-0.5950f * scale), yOriginNakul + (-0.010f * scale),
			xOriginNakul + (-0.6175f * scale), yOriginNakul + (0.020f * scale),
			xOriginNakul + (-0.6050f * scale), yOriginNakul + (0.024f * scale)); // finger tips

		if (iHandPosition == 1)
		{
			drawQuadrangleNakul(
				xOriginNakul + (-0.6250f * scale), yOriginNakul + (-0.075f * scale),
				xOriginNakul + (-0.6300f * scale), yOriginNakul + (-0.050f * scale),
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.010f * scale),
				xOriginNakul + (-0.6100f * scale), yOriginNakul + (-0.010f * scale)); // thumb
		}
		else
		{
			drawQuadrangleNakul(
				xOriginNakul + (-0.6249f * scale), yOriginNakul + (-0.075f * scale),
				xOriginNakul + (-0.6400f * scale), yOriginNakul + (-0.010f * scale),
				xOriginNakul + (-0.6350f * scale), yOriginNakul + (-0.010f * scale),
				xOriginNakul + (-0.6200f * scale), yOriginNakul + (-0.036f * scale)); // thumb
		}

		// fingers
		{
			glColor3f(0.6f, 0.6f, 0.6f);
			if (iHandPosition == 1)
			{
				glBegin(GL_LINES);
				glVertex2f(xOriginNakul + (-0.6190f * scale), yOriginNakul + (-0.006f * scale));
				glVertex2f(xOriginNakul + (-0.6230f * scale), yOriginNakul + (-0.036f * scale));
				glEnd();
			}

			glBegin(GL_LINES);
			glVertex2f(xOriginNakul + (-0.6100f * scale), yOriginNakul + (0.019f * scale));
			glVertex2f(xOriginNakul + (-0.6140f * scale), yOriginNakul + (-0.024f * scale));
			glEnd();

			glBegin(GL_LINES);
			glVertex2f(xOriginNakul + (-0.6030f * scale), yOriginNakul + (0.013f * scale));
			glVertex2f(xOriginNakul + (-0.6070f * scale), yOriginNakul + (-0.030f * scale));
			glEnd();

			glBegin(GL_LINES);
			glVertex2f(xOriginNakul + (-0.5980f * scale), yOriginNakul + (0.001f * scale));
			glVertex2f(xOriginNakul + (-0.6020f * scale), yOriginNakul + (-0.036f * scale));
			glEnd();
		}

		if (iHandPosition == 1)
		{
			// front side hand
			SKIN_COLOR
			drawQuadrangleNakul(
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.075f * scale),
				xOriginNakul + (-0.7500f * scale), yOriginNakul + (-0.160f * scale),
				xOriginNakul + (-0.7600f * scale), yOriginNakul + (-0.235f * scale),
				xOriginNakul + (-0.6125f * scale), yOriginNakul + (-0.100f * scale));

			drawTriangleNakul(
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.075f * scale),
				xOriginNakul + (-0.6125f * scale), yOriginNakul + (-0.100f * scale),
				xOriginNakul + (-0.6000f * scale), yOriginNakul + (-0.080f * scale));

			drawQuadrangleNakul(
				xOriginNakul + (-0.6250f * scale), yOriginNakul + (-0.075f * scale),
				xOriginNakul + (-0.6000f * scale), yOriginNakul + (-0.080f * scale),
				xOriginNakul + (-0.5950f * scale), yOriginNakul + (-0.010f * scale),
				xOriginNakul + (-0.6175f * scale), yOriginNakul + (0.020f * scale));

			drawTriangleNakul(
				xOriginNakul + (-0.5950f * scale), yOriginNakul + (-0.010f * scale),
				xOriginNakul + (-0.6175f * scale), yOriginNakul + (0.020f * scale),
				xOriginNakul + (-0.6050f * scale), yOriginNakul + (0.024f * scale)); // finger tips

			drawQuadrangleNakul(
				xOriginNakul + (-0.6250f * scale), yOriginNakul + (-0.075f * scale),
				xOriginNakul + (-0.6300f * scale), yOriginNakul + (-0.050f * scale),
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.010f * scale),
				xOriginNakul + (-0.6100f * scale), yOriginNakul + (-0.010f * scale)); // thumb

			// fingers
			{
				glColor3f(0.6f, 0.6f, 0.6f);
				glBegin(GL_LINES);
				glVertex2f(xOriginNakul + (-0.6190f * scale), yOriginNakul + (-0.006f * scale));
				glVertex2f(xOriginNakul + (-0.6230f * scale), yOriginNakul + (-0.036f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOriginNakul + (-0.6100f * scale), yOriginNakul + (0.019f * scale));
				glVertex2f(xOriginNakul + (-0.6140f * scale), yOriginNakul + (-0.024f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOriginNakul + (-0.6030f * scale), yOriginNakul + (0.013f * scale));
				glVertex2f(xOriginNakul + (-0.6070f * scale), yOriginNakul + (-0.030f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOriginNakul + (-0.5980f * scale), yOriginNakul + (0.001f * scale));
				glVertex2f(xOriginNakul + (-0.6020f * scale), yOriginNakul + (-0.036f * scale));
				glEnd();
			}
		}
		else
		{
			SKIN_COLOR
			drawQuadrangleNakul(
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.170f * scale),
				xOriginNakul + (-0.7500f * scale), yOriginNakul + (-0.160f * scale),
				xOriginNakul + (-0.7600f * scale), yOriginNakul + (-0.235f * scale),
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.195f * scale));

			drawQuadrangleNakul(
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.170f * scale),
				xOriginNakul + (-0.5900f * scale), yOriginNakul + (-0.180f * scale),
				xOriginNakul + (-0.5900f * scale), yOriginNakul + (-0.200f * scale),
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.195f * scale));

			drawQuadrangleNakul(
				xOriginNakul + (-0.5900f * scale), yOriginNakul + (-0.180f * scale),
				xOriginNakul + (-0.5700f * scale), yOriginNakul + (-0.170f * scale),
				xOriginNakul + (-0.5720f * scale), yOriginNakul + (-0.180f * scale),
				xOriginNakul + (-0.5900f * scale), yOriginNakul + (-0.200f * scale));

			drawTriangleNakul(
				xOriginNakul + (-0.6275f * scale), yOriginNakul + (-0.170f * scale),
				xOriginNakul + (-0.6000f * scale), yOriginNakul + (-0.150f * scale),
				xOriginNakul + (-0.6100f * scale), yOriginNakul + (-0.195f * scale));
		}
	}
	{

		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.815f * scale), yOriginNakul + (-0.12f * scale));
		glVertex2f(xOriginNakul + (-0.767f * scale), yOriginNakul + (-0.08f * scale));
		glEnd();

		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.818f * scale), yOriginNakul + (-0.11f * scale));
		glVertex2f(xOriginNakul + (-0.768f * scale), yOriginNakul + (-0.07f * scale));
		glEnd();

		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.68f * scale), yOriginNakul + (-0.10f * scale));
		glVertex2f(xOriginNakul + (-0.662f * scale), yOriginNakul + (-0.08f * scale));
		glEnd();

		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOriginNakul + (-0.68f * scale), yOriginNakul + (-0.09f * scale));
		glVertex2f(xOriginNakul + (-0.663f * scale), yOriginNakul + (-0.07f * scale));
		glEnd();
	}
}
