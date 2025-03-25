// header files
#include "../common.h"
//#include "Nakul.h"
// global variable declarations
//float xOriginDrau = 0.0f;
//float yOriginDrau = 0.0f;
//float fScaleFactorDrau = 1.0f;

//int g_iHandPositionDrau = 1;
//int g_iStandingDrau = 1;

// global function declarations
//void drawLineDrau(float x1, float y1, float x2, float y2);
//void drawRectangleDrau(float LX, float RX, float TY, float BY);
//void drawQuadrangleDrau(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
//void drawcircleDrau(float, float, float, float, float, float, float, int);
//void drawTriangleDrau(float x1, float y1, float x2, float y2, float x3, float y3);

// function declarations
//void drawDraupadi(float xOriginDrau, float yOriginDrau, float scale, int iHandPosition, int iStanding);

// Below setting required in init

// int initialize(void)
//{
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glClearColor(0.686f, 0.573f, 0.333f, 1.0f);
//	return(0);
// }

// call to display draupadi

// void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	drawDraupadi(xOriginDrau, yOriginDrau, fScaleFactorDrau);
//
//	glutSwapBuffers();
// }

// Draw Rectangle
void drawRectangleDrau(float LX, float RX, float TY, float BY)
{
	glBegin(GL_QUADS);
	glVertex2f(LX, TY);
	glVertex2f(RX, TY);
	glVertex2f(RX, BY);
	glVertex2f(LX, BY);
	glEnd();
}

void drawQuadrangleDrau(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

// Draw Line
void drawLineDrau(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawcircleDrau(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
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

void drawTriangleDrau(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawRiceGrain(float iX, float iY)
{
	SHAPE riceGrain;
	riceGrain.noOfPoints = 7;


	MY_POINT Origin;
	Origin.x = iX;
	Origin.y = iY;
	Origin.z = 0.0f;

	riceGrain.color.rValue = 0.694f;
	riceGrain.color.gValue = 0.694f;
	riceGrain.color.bValue = 0.694f;

	riceGrain.points[0].x = Origin.x + 0.01f;
	riceGrain.points[0].y = Origin.y + 0.05f;
	riceGrain.points[0].z = Origin.z + 0.00f;

	riceGrain.points[1].x = Origin.x + 0.00f;
	riceGrain.points[1].y = Origin.y + 0.06f;
	riceGrain.points[1].z = Origin.z + 0.00f;

	riceGrain.points[2].x = Origin.x + (-0.005f);
	riceGrain.points[2].y = Origin.y + 0.065f;
	riceGrain.points[2].z = Origin.z + 0.00f;

	riceGrain.points[3].x = Origin.x + (-0.01f);
	riceGrain.points[3].y = Origin.y + 0.05f;
	riceGrain.points[3].z = Origin.z + 0.00f;

	riceGrain.points[4].x = Origin.x + (-0.01f);
	riceGrain.points[4].y = Origin.y + (-0.05f);
	riceGrain.points[4].z = Origin.z + 0.00f;

	riceGrain.points[5].x = Origin.x + 0.009f;
	riceGrain.points[5].y = Origin.y + -0.055f;
	riceGrain.points[5].z = Origin.z + 0.00f;

	riceGrain.points[6].x = Origin.x + 0.01f;
	riceGrain.points[6].y = Origin.y + -0.06f;
	riceGrain.points[6].z = Origin.z + 0.00f;

	glBegin(GL_POLYGON);
	for (int iShape = 0; iShape < riceGrain.noOfPoints; iShape = iShape + 1)
	{

		glColor3f(riceGrain.color.rValue, riceGrain.color.gValue, riceGrain.color.bValue);
		glVertex3f((riceGrain.points[iShape].x), (riceGrain.points[iShape].y), (riceGrain.points[iShape].z)); //Origin 
	}
	glEnd();

	//glColor3f(0.694f, 0.694f, 0.694f);
	//glBegin(GL_POLYGON);
	//glVertex3f(0.01f, 0.05f, 0.0f); //Bottom Left
	//glVertex3f(0.00f, 0.06f, 0.0f); //Bottom Left
	//glVertex3f(-0.005f, 0.065f, 0.0f); //Bottom Left
	//glVertex3f(-0.01f, 0.05f, 0.0f); //Bottom Left
	//glVertex3f(-0.01f, -0.05f, 0.0f); //Bottom Left
	//glVertex3f(0.009f, -0.055f, 0.0f); //Bottom Left
	//glVertex3f(0.01f, -0.06f, 0.0f); //Bottom Left
	//glEnd();

}

void drawDraupadi(float xOriginDrau, float yOriginDrau, float scale, int iHandPosition, int iStanding)
{
	void drawLegs(float, float, float, int);
	void drawGhagraCholi(float, float, float, int);
	void drawFace(float, float, float);
	void drawHands(float, float, float, int);
	void drawOdhani(float, float, float, int, int);

	drawLegs(xOriginDrau, yOriginDrau, scale, iStanding);
	drawGhagraCholi(xOriginDrau, yOriginDrau, scale, iStanding);
	drawFace(xOriginDrau, yOriginDrau, scale);
	drawHands(xOriginDrau, yOriginDrau, scale, iHandPosition);
	drawOdhani(xOriginDrau, yOriginDrau, scale, iHandPosition, iStanding);
}

void drawLegs(float xOriginDrau, float yOriginDrau, float scale, int iStanding)
{
	// glColor3f(0.98f, 0.36f, 0.14f);//saffron
	// glColor3f(0.851f, 0.236f, 0.427f);//pink
	glColor3f(0.502f, 0.216f, 0.306f); // pink

	if (iStanding == 1)
	{
		// Hip area
		drawQuadrangleDrau(
			xOriginDrau + (-0.684f * scale), yOriginDrau + (-0.400f * scale),
			xOriginDrau + (-0.875f * scale), yOriginDrau + (-0.400f * scale),
			xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.250f * scale),
			xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.250f * scale));

		// front leg
		glBegin(GL_QUADS);
		glColor3f(0.502f, 0.216f, 0.306f); // pink
		glVertex2f(xOriginDrau + (-0.780f * scale), yOriginDrau + (-0.400f * scale));
		glVertex2f(xOriginDrau + (-0.684f * scale), yOriginDrau + (-0.400f * scale));
		glColor3f(0.851f, 0.236f, 0.427f); // pink
		glVertex2f(xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.550f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.550f * scale));
		glEnd();

		// back leg
		glBegin(GL_QUADS);
		glColor3f(0.502f, 0.216f, 0.306f); // pink
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.35f * scale));
		glVertex2f(xOriginDrau + (-0.875f * scale), yOriginDrau + (-0.40f * scale));
		glColor3f(0.851f, 0.236f, 0.427f); // pink
		glVertex2f(xOriginDrau + (-0.840f * scale), yOriginDrau + (-0.55f * scale));
		glVertex2f(xOriginDrau + (-0.765f * scale), yOriginDrau + (-0.55f * scale));
		glEnd();

		glColor3f(0.851f, 0.236f, 0.427f); // pink
		// back leg lower
		drawQuadrangleDrau(
			xOriginDrau + (-0.825f * scale), yOriginDrau + (-0.83f * scale),
			xOriginDrau + (-0.785f * scale), yOriginDrau + (-0.83f * scale),
			xOriginDrau + (-0.765f * scale), yOriginDrau + (-0.55f * scale),
			xOriginDrau + (-0.840f * scale), yOriginDrau + (-0.55f * scale));
		// front leg lower
		drawQuadrangleDrau(
			xOriginDrau + (-0.742f * scale), yOriginDrau + (-0.830f * scale),
			xOriginDrau + (-0.695f * scale), yOriginDrau + (-0.825f * scale),
			xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.550f * scale),
			xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.550f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		// Back foot
		drawQuadrangleDrau(
			xOriginDrau + (-0.83f * scale), yOriginDrau + (-0.85f * scale),
			xOriginDrau + (-0.82f * scale), yOriginDrau + (-0.83f * scale),
			xOriginDrau + (-0.79f * scale), yOriginDrau + (-0.83f * scale),
			xOriginDrau + (-0.79f * scale), yOriginDrau + (-0.85f * scale));

		drawQuadrangleDrau(
			xOriginDrau + (-0.83f * scale), yOriginDrau + (-0.85f * scale),
			xOriginDrau + (-0.78f * scale), yOriginDrau + (-0.93f * scale),
			xOriginDrau + (-0.74f * scale), yOriginDrau + (-0.93f * scale),
			xOriginDrau + (-0.79f * scale), yOriginDrau + (-0.85f * scale));

		// front foot
		drawQuadrangleDrau(
			xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.850f * scale),
			xOriginDrau + (-0.740f * scale), yOriginDrau + (-0.830f * scale),
			xOriginDrau + (-0.695f * scale), yOriginDrau + (-0.825f * scale),
			xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.840f * scale));

		drawQuadrangleDrau(
			xOriginDrau + (-0.75f * scale), yOriginDrau + (-0.85f * scale),
			xOriginDrau + (-0.66f * scale), yOriginDrau + (-0.9f * scale),
			xOriginDrau + (-0.63f * scale), yOriginDrau + (-0.875f * scale),
			xOriginDrau + (-0.69f * scale), yOriginDrau + (-0.84f * scale));

		// fingers
		glColor3f(0.6f, 0.6f, 0.6f);
		// back
		drawLineDrau(
			xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.93f * scale),
			xOriginDrau + (-0.765f * scale), yOriginDrau + (-0.91f * scale));
		drawLineDrau(
			xOriginDrau + (-0.758f * scale), yOriginDrau + (-0.93f * scale),
			xOriginDrau + (-0.773f * scale), yOriginDrau + (-0.91f * scale));
		drawLineDrau(
			xOriginDrau + (-0.766f * scale), yOriginDrau + (-0.93f * scale),
			xOriginDrau + (-0.781f * scale), yOriginDrau + (-0.91f * scale));
		drawLineDrau(
			xOriginDrau + (-0.774f * scale), yOriginDrau + (-0.93f * scale),
			xOriginDrau + (-0.789f * scale), yOriginDrau + (-0.91f * scale));

		// front
		drawLineDrau(
			xOriginDrau + (-0.65f * scale), yOriginDrau + (-0.89f * scale),
			xOriginDrau + (-0.67f * scale), yOriginDrau + (-0.878f * scale));
		drawLineDrau(
			xOriginDrau + (-0.645f * scale), yOriginDrau + (-0.885f * scale),
			xOriginDrau + (-0.665f * scale), yOriginDrau + (-0.873f * scale));
		drawLineDrau(
			xOriginDrau + (-0.64f * scale), yOriginDrau + (-0.88f * scale),
			xOriginDrau + (-0.66f * scale), yOriginDrau + (-0.868f * scale));
		drawLineDrau(
			xOriginDrau + (-0.635f * scale), yOriginDrau + (-0.875f * scale),
			xOriginDrau + (-0.655f * scale), yOriginDrau + (-0.863f * scale));
	}
	else
	{
		// Hip area
		drawQuadrangleDrau(
			xOriginDrau + (-0.684f * scale), yOriginDrau + (-0.400f * scale),
			xOriginDrau + (-0.875f * scale), yOriginDrau + (-0.400f * scale),
			xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.250f * scale),
			xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.250f * scale));

		// front leg
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.350f * scale));
		glVertex2f(xOriginDrau + (-0.650f * scale), yOriginDrau + (-0.365f * scale));
		glVertex2f(xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.400f * scale));
		glVertex2f(xOriginDrau + (-0.575f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.555f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.545f * scale));
		glEnd();
		// knee
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.575f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.568f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.560f * scale), yOriginDrau + (-0.475f * scale));
		glVertex2f(xOriginDrau + (-0.561f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.565f * scale), yOriginDrau + (-0.525f * scale));
		glVertex2f(xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.555f * scale));
		glEnd();

		// back leg
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.875f * scale), yOriginDrau + (-0.400f * scale));
		glVertex2f(xOriginDrau + (-0.872f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.871f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.865f * scale), yOriginDrau + (-0.475f * scale));

		glVertex2f(xOriginDrau + (-0.865f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.856f * scale), yOriginDrau + (-0.525f * scale));
		glVertex2f(xOriginDrau + (-0.850f * scale), yOriginDrau + (-0.550f * scale));
		glVertex2f(xOriginDrau + (-0.825f * scale), yOriginDrau + (-0.568f * scale));

		glVertex2f(xOriginDrau + (-0.800f * scale), yOriginDrau + (-0.575f * scale));
		glVertex2f(xOriginDrau + (-0.775f * scale), yOriginDrau + (-0.568f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.545f * scale));
		glEnd();

		drawTriangleDrau(
			xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.545f * scale),
			xOriginDrau + (-0.875f * scale), yOriginDrau + (-0.400f * scale),
			xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.350f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.675f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.663f * scale), yOriginDrau + (-0.350f * scale));
		glVertex2f(xOriginDrau + (-0.658f * scale), yOriginDrau + (-0.325f * scale));
		glVertex2f(xOriginDrau + (-0.655f * scale), yOriginDrau + (-0.300f * scale));
		glVertex2f(xOriginDrau + (-0.655f * scale), yOriginDrau + (-0.250f * scale));
		glVertex2f(xOriginDrau + (-0.670f * scale), yOriginDrau + (-0.200f * scale));
		glVertex2f(xOriginDrau + (-0.660f * scale), yOriginDrau + (-0.200f * scale));

		glVertex2f(xOriginDrau + (-0.685f * scale), yOriginDrau + (-0.270f * scale));
		glVertex2f(xOriginDrau + (-0.710f * scale), yOriginDrau + (-0.275f * scale));
		glVertex2f(xOriginDrau + (-0.730f * scale), yOriginDrau + (-0.300f * scale));
		glVertex2f(xOriginDrau + (-0.760f * scale), yOriginDrau + (-0.250f * scale));
		glEnd();

		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(1.0f);

		drawLineDrau(
			xOriginDrau + (-0.850f * scale), yOriginDrau + (-0.400f * scale),
			xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.250f * scale));

		drawLineDrau(xOriginDrau + (-0.670f * scale), yOriginDrau + (-0.365f * scale),
					 xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.450f * scale));

		drawLineDrau(xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.450f * scale),
					 xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.500f * scale));

		drawLineDrau(xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.500f * scale),
					 xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.545f * scale));

		drawLineDrau(xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.450f * scale),
					 xOriginDrau + (-0.660f * scale), yOriginDrau + (-0.433f * scale));

		drawLineDrau(xOriginDrau + (-0.660f * scale), yOriginDrau + (-0.433f * scale),
					 xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.450f * scale));

		glLineWidth(1.0f);
	}
}

void drawGhagraCholi(float xOriginDrau, float yOriginDrau, float scale, int iStanding)
{

	// Ghagra
	if (iStanding == 1)
	{
		// glColor4f(0.706f, 0.137f, 0.161f, 1.0f);
		// glColor4f(0.96f, 0.58f, 0.44f, 0.5f);
		// glColor4f(1.0f, 0.927f, 0.788f, 0.0f);
		glColor4f(1.0f, 0.51f, 0.71f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.80f * scale));
		glVertex2f(xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.80f * scale));
		glVertex2f(xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.84f * scale));
		glVertex2f(xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.85f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.86f * scale));
		glVertex2f(xOriginDrau + (-0.850f * scale), yOriginDrau + (-0.85f * scale));
		glEnd();

		drawQuadrangleDrau(
			xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.25f * scale),
			xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.80f * scale),
			xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.80f * scale),
			xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.25f * scale)); // waist

		glColor3f(1.0f, 0.0f, 0.0f);
		glColor3f(0.62f, 0.463f, 0.51f);
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.69f * scale), yOriginDrau + (-0.25f * scale));
		glVertex2f(xOriginDrau + (-0.60f * scale), yOriginDrau + (-0.80f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.80f * scale));
		glVertex2f(xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.25f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP); // bottom strips
		glVertex2f(xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.80f * scale));
		glVertex2f(xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.84f * scale));
		glVertex2f(xOriginDrau + (-0.700f * scale), yOriginDrau + (-0.85f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.86f * scale));
		glVertex2f(xOriginDrau + (-0.850f * scale), yOriginDrau + (-0.85f * scale));
		glVertex2f(xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.80f * scale));
		glEnd();

		// waist band
		glLineWidth(4.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.255f * scale));
		glVertex2f(xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.255f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
	else
	{
		glColor4f(1.0f, 0.51f, 0.71f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.25f * scale));
		glVertex2f(xOriginDrau + (-0.660f * scale), yOriginDrau + (-0.200f * scale));
		glVertex2f(xOriginDrau + (-0.655f * scale), yOriginDrau + (-0.250f * scale));
		glVertex2f(xOriginDrau + (-0.575f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.550f * scale), yOriginDrau + (-0.475f * scale));
		glVertex2f(xOriginDrau + (-0.540f * scale), yOriginDrau + (-0.580f * scale));

		glEnd();

		drawQuadrangleDrau(
			xOriginDrau + (-0.750f * scale), yOriginDrau + (-0.250f * scale),
			xOriginDrau + (-0.540f * scale), yOriginDrau + (-0.580f * scale),
			xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.600f * scale),
			xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.250f * scale)); // waist

		glColor3f(0.62f, 0.463f, 0.51f);
		// waist band
		glLineWidth(4.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.255f * scale));
		glVertex2f(xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.255f * scale));
		glEnd();

		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.250f * scale));
		glVertex2f(xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.600f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.540f * scale), yOriginDrau + (-0.580f * scale));
		glVertex2f(xOriginDrau + (-0.925f * scale), yOriginDrau + (-0.600f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.660f * scale), yOriginDrau + (-0.200f * scale));
		glVertex2f(xOriginDrau + (-0.655f * scale), yOriginDrau + (-0.250f * scale));
		glVertex2f(xOriginDrau + (-0.655f * scale), yOriginDrau + (-0.250f * scale));
		glVertex2f(xOriginDrau + (-0.575f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.575f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.550f * scale), yOriginDrau + (-0.475f * scale));
		glVertex2f(xOriginDrau + (-0.550f * scale), yOriginDrau + (-0.475f * scale));
		glVertex2f(xOriginDrau + (-0.540f * scale), yOriginDrau + (-0.580f * scale));
		glEnd();
		glLineWidth(1.0f);
	}

	// Choli
	// glColor3f(0.639f, 0.075f, 0.227f);

	glColor3f(0.98f, 0.36f, 0.14f);	   // orange
	glColor3f(0.851f, 0.236f, 0.427f); // pink
	drawQuadrangleDrau(
		xOriginDrau + (-0.855f * scale), yOriginDrau + (-0.25f * scale),
		xOriginDrau + (-0.875f * scale), yOriginDrau + (-0.05f * scale),
		xOriginDrau + (-0.685f * scale), yOriginDrau + (-0.15f * scale),
		xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.25f * scale));
	drawQuadrangleDrau(xOriginDrau + (-0.83f * scale), yOriginDrau + (0.00f * scale),
					   xOriginDrau + (-0.86f * scale), yOriginDrau + (-0.015f * scale),
					   xOriginDrau + (-0.87f * scale), yOriginDrau + (-0.025f * scale),
					   xOriginDrau + (-0.875 * scale), yOriginDrau + (-0.05f * scale));
	drawQuadrangleDrau(xOriginDrau + (-0.685f * scale), yOriginDrau + (-0.15f * scale),
					   xOriginDrau + (-0.67f * scale), yOriginDrau + (-0.10f * scale),
					   xOriginDrau + (-0.67f * scale), yOriginDrau + (-0.115f * scale),
					   xOriginDrau + (-0.675f * scale), yOriginDrau + (-0.135f * scale)); //
	drawQuadrangleDrau(xOriginDrau + (-0.685f * scale), yOriginDrau + (-0.15f * scale),
					   xOriginDrau + (-0.67f * scale), yOriginDrau + (-0.10f * scale),
					   xOriginDrau + (-0.83f * scale), yOriginDrau + (0.00f * scale),
					   xOriginDrau + (-0.875 * scale), yOriginDrau + (-0.05f * scale));
	drawQuadrangleDrau(xOriginDrau + (-0.83f * scale), yOriginDrau + (0.00f * scale),
					   xOriginDrau + (-0.8f * scale), yOriginDrau + (0.0f * scale),
					   xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.02f * scale),
					   xOriginDrau + (-0.67f * scale), yOriginDrau + (-0.10f * scale));

	// necklace
	glColor3f(0.82f, 0.569f, 0.196f);
	drawTriangleDrau(xOriginDrau + (-0.8f * scale), yOriginDrau + (0.0f * scale),
					 xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.075f * scale),
					 xOriginDrau + (-0.718f * scale), yOriginDrau + (-0.1f * scale));
	drawTriangleDrau(xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.02f * scale),
					 xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.075f * scale),
					 xOriginDrau + (-0.718f * scale), yOriginDrau + (-0.1f * scale));
}

void drawFace(float xOriginDrau, float yOriginDrau, float scale)
{
	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1

	drawTriangleDrau(
		xOriginDrau + (-0.800f * scale), yOriginDrau + (0.0f * scale),
		xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.02f * scale),
		xOriginDrau + (-0.735f * scale), yOriginDrau + (-0.05f * scale)); // neck lower
	// drawTriangleDrau(-0.8f, 0.0f, -0.81f, 0.04f, -0.815f, 0.0f); //neck back
	drawQuadrangleDrau(
		xOriginDrau + (-0.800f * scale), yOriginDrau + (0.0f * scale),
		xOriginDrau + (-0.725f * scale), yOriginDrau + (-0.02f * scale),
		xOriginDrau + (-0.740f * scale), yOriginDrau + (0.04f * scale),
		xOriginDrau + (-0.810f * scale), yOriginDrau + (0.04f * scale)); // neck front

	drawQuadrangleDrau(
		xOriginDrau + (-0.760f * scale), yOriginDrau + (0.04f * scale),
		xOriginDrau + (-0.715f * scale), yOriginDrau + (0.03f * scale),
		xOriginDrau + (-0.700f * scale), yOriginDrau + (0.055f * scale),
		xOriginDrau + (-0.700f * scale), yOriginDrau + (0.07f * scale)); // chin n lips

	drawTriangleDrau(
		xOriginDrau + (-0.81f * scale), yOriginDrau + (0.04f * scale),
		xOriginDrau + (-0.76f * scale), yOriginDrau + (0.04f * scale),
		xOriginDrau + (-0.70f * scale), yOriginDrau + (0.07f * scale)); // lips n face connector
	drawQuadrangleDrau(
		xOriginDrau + (-0.810f * scale), yOriginDrau + (0.04f * scale),
		xOriginDrau + (-0.790f * scale), yOriginDrau + (0.13f * scale),
		xOriginDrau + (-0.692f * scale), yOriginDrau + (0.15f * scale),
		xOriginDrau + (-0.700f * scale), yOriginDrau + (0.055f * scale)); // face

	drawTriangleDrau(
		xOriginDrau + (-0.700f * scale), yOriginDrau + (0.07f * scale),
		xOriginDrau + (-0.688f * scale), yOriginDrau + (0.065f * scale),
		xOriginDrau + (-0.697f * scale), yOriginDrau + (0.11f * scale)); // nose

	drawTriangleDrau(
		xOriginDrau + (-0.79f * scale), yOriginDrau + (0.125f * scale),
		xOriginDrau + (-0.81f * scale), yOriginDrau + (0.1f * scale),
		xOriginDrau + (-0.80f * scale), yOriginDrau + (0.065f * scale)); // ear

	// hairs
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuadrangleDrau(
		xOriginDrau + (-0.690f * scale), yOriginDrau + (0.14f * scale),
		xOriginDrau + (-0.700f * scale), yOriginDrau + (0.165f * scale),
		xOriginDrau + (-0.765f * scale), yOriginDrau + (0.18f * scale),
		xOriginDrau + (-0.780f * scale), yOriginDrau + (0.1f * scale)); //-0.79f, 0.13f
	drawQuadrangleDrau(
		xOriginDrau + (-0.765f * scale), yOriginDrau + (0.18f * scale),
		xOriginDrau + (-0.800f * scale), yOriginDrau + (0.16f * scale),
		xOriginDrau + (-0.820f * scale), yOriginDrau + (0.14f * scale),
		xOriginDrau + (-0.780f * scale), yOriginDrau + (0.1f * scale));
	drawQuadrangleDrau(
		xOriginDrau + (-0.78f * scale), yOriginDrau + (0.1f * scale),
		xOriginDrau + (-0.82f * scale), yOriginDrau + (0.14f * scale),
		xOriginDrau + (-0.84f * scale), yOriginDrau + (-0.01f * scale),
		xOriginDrau + (-0.80f * scale), yOriginDrau + (0.05f * scale));

	drawQuadrangleDrau(
		xOriginDrau + (-0.770f * scale), yOriginDrau + (0.11f * scale),
		xOriginDrau + (-0.760f * scale), yOriginDrau + (0.08f * scale),
		xOriginDrau + (-0.755f * scale), yOriginDrau + (0.085f * scale),
		xOriginDrau + (-0.740f * scale), yOriginDrau + (0.12f * scale));
	drawQuadrangleDrau(
		xOriginDrau + (-0.800f * scale), yOriginDrau + (0.0f * scale),
		xOriginDrau + (-0.840f * scale), yOriginDrau + (0.0f * scale),
		xOriginDrau + (-0.778f * scale), yOriginDrau + (0.11f * scale),
		xOriginDrau + (-0.775f * scale), yOriginDrau + (0.06f * scale)); // neck back

	drawTriangleDrau(
		xOriginDrau + (-0.869f * scale), yOriginDrau + (-0.3f * scale),
		xOriginDrau + (-0.860f * scale), yOriginDrau + (-0.2f * scale),
		xOriginDrau + (-0.850f * scale), yOriginDrau + (-0.25f * scale));

	// face features
	glColor3f(0.9f, 0.25f, 0.35f);
	drawTriangleDrau(
		xOriginDrau + (-0.700f * scale), yOriginDrau + (0.055f * scale),
		xOriginDrau + (-0.720f * scale), yOriginDrau + (0.055f * scale),
		xOriginDrau + (-0.707f * scale), yOriginDrau + (0.045f * scale)); // lips

	glColor3f(1.0f, 1.0f, 1.0f);
	drawQuadrangleDrau(
		xOriginDrau + (-0.7000f * scale), yOriginDrau + (0.105f * scale),
		xOriginDrau + (-0.7180f * scale), yOriginDrau + (0.105f * scale),
		xOriginDrau + (-0.7020f * scale), yOriginDrau + (0.09f * scale),
		xOriginDrau + (-0.6950f * scale), yOriginDrau + (0.1f * scale)); // eye
	glColor3f(0.0f, 0.0f, 0.0f);
	drawTriangleDrau(
		xOriginDrau + (-0.7020f * scale), yOriginDrau + (0.09f * scale),
		xOriginDrau + (-0.6950f * scale), yOriginDrau + (0.1f * scale),
		xOriginDrau + (-0.7040f * scale), yOriginDrau + (0.1f * scale)); // retina
	drawLineDrau(
		xOriginDrau + (-0.721f * scale), yOriginDrau + (0.11f * scale),
		xOriginDrau + (-0.705f * scale), yOriginDrau + (0.115f * scale));
	drawLineDrau(
		xOriginDrau + (-0.705f * scale), yOriginDrau + (0.115f * scale),
		xOriginDrau + (-0.695f * scale), yOriginDrau + (0.11f * scale));

	glColor3f(1.0f, 0.0f, 0.0f);
	drawLineDrau(
		xOriginDrau + (-0.695f * scale), yOriginDrau + (0.115f * scale),
		xOriginDrau + (-0.695f * scale), yOriginDrau + (0.12f * scale));

	// earring
	drawcircleDrau(
		xOriginDrau + (-0.7625f * scale), yOriginDrau + (0.062f * scale),
		(0.008f * scale), (0.008f * scale), 0.82f, 0.569f, 0.196f, 1);
}

void drawHands(float xOriginDrau, float yOriginDrau, float scale, int iHandPosition)
{
	// choli hand
	// glColor3f(0.98f, 0.36f, 0.14f);
	glColor3f(0.851f, 0.236f, 0.427f); // pink
	drawTriangleDrau(
		xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale),
		xOriginDrau + (-0.7780f * scale), yOriginDrau + (-0.25f * scale),
		xOriginDrau + (-0.6780f * scale), yOriginDrau + (-0.25f * scale));

	if (iHandPosition == 1)
	{
		//
		glColor3f(0.3f, 0.3f, 0.3f);
		glLineWidth(0.5f);
		drawLineDrau(
			xOriginDrau + (-0.8700f * scale), yOriginDrau + (-0.1f * scale),
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale));
		drawLineDrau(
			xOriginDrau + (-0.80f * scale), yOriginDrau + (-0.075f * scale),
			xOriginDrau + (-0.73f * scale), yOriginDrau + (-0.225f * scale));
		drawLineDrau(
			xOriginDrau + (-0.73f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.70f * scale), yOriginDrau + (-0.2f * scale));
		drawLineDrau(
			xOriginDrau + (-0.7000f * scale), yOriginDrau + (-0.2f * scale),
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.2625f * scale));
		drawLineDrau(
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale),
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.2625f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		drawQuadrangleDrau(
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.259f * scale),
			xOriginDrau + (-0.7000f * scale), yOriginDrau + (-0.2f * scale),
			xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.15f * scale),
			xOriginDrau + (-0.6350f * scale), yOriginDrau + (-0.195f * scale)); // forearm
		drawQuadrangleDrau(
			xOriginDrau + (-0.650f * scale), yOriginDrau + (-0.15f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.15f * scale),
			xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.635f * scale), yOriginDrau + (-0.195f * scale)); // wrist-bottom
		drawQuadrangleDrau(
			xOriginDrau + (-0.65f * scale), yOriginDrau + (-0.15f * scale),
			xOriginDrau + (-0.65f * scale), yOriginDrau + (-0.125f * scale),
			xOriginDrau + (-0.64f * scale), yOriginDrau + (-0.12f * scale),
			xOriginDrau + (-0.62f * scale), yOriginDrau + (-0.15f * scale)); // wrist-top eith thumbs base
		drawQuadrangleDrau(
			xOriginDrau + (-0.650f * scale), yOriginDrau + (-0.125f * scale),
			xOriginDrau + (-0.637f * scale), yOriginDrau + (-0.08f * scale),
			xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.08f * scale),
			xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.12f * scale)); // thumb

		drawQuadrangleDrau(
			xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.120f * scale),
			xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.065f * scale),
			xOriginDrau + (-0.615f * scale), yOriginDrau + (-0.055f * scale),
			xOriginDrau + (-0.605f * scale), yOriginDrau + (-0.09f * scale)); // fingers
		drawTriangleDrau(
			xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.12f * scale),
			xOriginDrau + (-0.605f * scale), yOriginDrau + (-0.09f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.15f * scale)); // fingers base

		// finger lines
		glColor3f(0.6f, 0.6f, 0.6f);
		drawLineDrau(
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.08f * scale),
			xOriginDrau + (-0.643f * scale), yOriginDrau + (-0.125f * scale));
		drawLineDrau(
			xOriginDrau + (-0.618f * scale), yOriginDrau + (-0.056f * scale),
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.11f * scale));
		drawLineDrau(
			xOriginDrau + (-0.6120f * scale), yOriginDrau + (-0.065f * scale),
			xOriginDrau + (-0.6245f * scale), yOriginDrau + (-0.12f * scale));
		drawLineDrau(
			xOriginDrau + (-0.608f * scale), yOriginDrau + (-0.081f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.125f * scale));

		// back hand
		glColor3f(0.98f, 0.65f, 0.44f); // Skin 1
		drawTriangleDrau(
			xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.15f * scale),
			xOriginDrau + (-0.6855f * scale), yOriginDrau + (-0.1625f * scale),
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.19f * scale));

		// hand bangles
		glColor3f(0.82f, 0.569f, 0.196f);
		// glColor3f(1.0f, 0.0f, 0.0f);
		drawQuadrangleDrau(
			xOriginDrau + (-0.6750f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.6825f * scale), yOriginDrau + (-0.1825f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.245f * scale),
			xOriginDrau + (-0.6625f * scale), yOriginDrau + (-0.23f * scale));
		drawQuadrangleDrau(
			xOriginDrau + (-0.6625f * scale), yOriginDrau + (-0.1625f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.1675f * scale),
			xOriginDrau + (-0.6575f * scale), yOriginDrau + (-0.2275f * scale),
			xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.2125f * scale));
	}
	else if (iHandPosition == 2)
	{

		glColor3f(0.98f, 0.65f, 0.44f); // Skin 1
		drawQuadrangleDrau(

			xOriginDrau + (-0.690f * scale), yOriginDrau + (-0.275f * scale),
			xOriginDrau + (-0.660f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.260f * scale)); // wrist-bottom

		drawQuadrangleDrau(
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.240f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.260f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.260f * scale)); // wrist-bottom
		drawQuadrangleDrau(
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.240f * scale),
			xOriginDrau + (-0.560f * scale), yOriginDrau + (-0.235f * scale),
			xOriginDrau + (-0.560f * scale), yOriginDrau + (-0.245f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.260f * scale)); // wrist-top eith thumbs base
		drawQuadrangleDrau(
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.220f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.260f * scale)); // thumb

		//
		glColor3f(0.3f, 0.3f, 0.3f);
		glLineWidth(0.5f);
		drawLineDrau(
			xOriginDrau + (-0.8700f * scale), yOriginDrau + (-0.1f * scale),
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale));
		drawLineDrau(
			xOriginDrau + (-0.80f * scale), yOriginDrau + (-0.075f * scale),
			xOriginDrau + (-0.73f * scale), yOriginDrau + (-0.225f * scale));
		drawLineDrau(
			xOriginDrau + (-0.73f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.70f * scale), yOriginDrau + (-0.2f * scale));
		drawLineDrau(
			xOriginDrau + (-0.7000f * scale), yOriginDrau + (-0.2f * scale),
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.2625f * scale));
		drawLineDrau(
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale),
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.2625f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		drawQuadrangleDrau(
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.259f * scale),
			xOriginDrau + (-0.7000f * scale), yOriginDrau + (-0.200f * scale),
			xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.150f * scale),
			xOriginDrau + (-0.6350f * scale), yOriginDrau + (-0.190f * scale)); // forearm
		drawQuadrangleDrau(
			xOriginDrau + (-0.650f * scale), yOriginDrau + (-0.150f * scale),
			xOriginDrau + (-0.615f * scale), yOriginDrau + (-0.134f * scale),
			xOriginDrau + (-0.612f * scale), yOriginDrau + (-0.185f * scale),
			xOriginDrau + (-0.635f * scale), yOriginDrau + (-0.190f * scale)); // wrist-bottom
		drawQuadrangleDrau(
			xOriginDrau + (-0.615f * scale), yOriginDrau + (-0.134f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.135f * scale),
			xOriginDrau + (-0.580f * scale), yOriginDrau + (-0.155f * scale),
			xOriginDrau + (-0.614f * scale), yOriginDrau + (-0.160f * scale)); // first two fingers
		drawQuadrangleDrau(
			xOriginDrau + (-0.614f * scale), yOriginDrau + (-0.160f * scale),
			xOriginDrau + (-0.595f * scale), yOriginDrau + (-0.168f * scale),
			xOriginDrau + (-0.599f * scale), yOriginDrau + (-0.185f * scale),
			xOriginDrau + (-0.612f * scale), yOriginDrau + (-0.185f * scale)); // sencond two fingers
		drawQuadrangleDrau(
			xOriginDrau + (-0.595f * scale), yOriginDrau + (-0.168f * scale),
			xOriginDrau + (-0.583f * scale), yOriginDrau + (-0.180f * scale),
			xOriginDrau + (-0.589f * scale), yOriginDrau + (-0.190f * scale),
			xOriginDrau + (-0.599f * scale), yOriginDrau + (-0.185f * scale)); // sencond two fingers
		// drawQuadrangleDrau(
		//	xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.120f * scale),
		//	xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.065f * scale),
		//	xOriginDrau + (-0.615f * scale), yOriginDrau + (-0.055f * scale),
		//	xOriginDrau + (-0.605f * scale), yOriginDrau + (-0.09f * scale)); //fingers
		// drawTriangleDrau(
		//	xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.12f * scale),
		//	xOriginDrau + (-0.605f * scale), yOriginDrau + (-0.09f * scale),
		//	xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.15f * scale)); //fingers base

		// finger lines
		glColor3f(0.6f, 0.6f, 0.6f);
		drawLineDrau(
			xOriginDrau + (-0.585f * scale), yOriginDrau + (-0.145f * scale),
			xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.145f * scale));
		drawLineDrau(
			xOriginDrau + (-0.600f * scale), yOriginDrau + (-0.145f * scale),
			xOriginDrau + (-0.618f * scale), yOriginDrau + (-0.152f * scale));

		drawLineDrau(
			xOriginDrau + (-0.586f * scale), yOriginDrau + (-0.185f * scale),
			xOriginDrau + (-0.597f * scale), yOriginDrau + (-0.174f * scale));
		drawLineDrau(
			xOriginDrau + (-0.597f * scale), yOriginDrau + (-0.174f * scale),
			xOriginDrau + (-0.613f * scale), yOriginDrau + (-0.175f * scale));
		// drawLineDrau(
		//	xOriginDrau + (-0.608f * scale), yOriginDrau + (-0.081f * scale),
		//	xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.125f * scale));

		// hand bangles
		glColor3f(0.82f, 0.569f, 0.196f);
		// glColor3f(1.0f, 0.0f, 0.0f);
		drawQuadrangleDrau(
			xOriginDrau + (-0.6750f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.6825f * scale), yOriginDrau + (-0.1825f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.245f * scale),
			xOriginDrau + (-0.6625f * scale), yOriginDrau + (-0.23f * scale));
		drawQuadrangleDrau(
			xOriginDrau + (-0.6625f * scale), yOriginDrau + (-0.1625f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.1675f * scale),
			xOriginDrau + (-0.6575f * scale), yOriginDrau + (-0.2275f * scale),
			xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.2125f * scale));

		drawQuadrangleDrau(
			xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.650f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.650f * scale), yOriginDrau + (-0.285f * scale),
			xOriginDrau + (-0.640f * scale), yOriginDrau + (-0.285f * scale));
		drawQuadrangleDrau(
			xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.635f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.635f * scale), yOriginDrau + (-0.285f * scale),
			xOriginDrau + (-0.625f * scale), yOriginDrau + (-0.285f * scale));
	}
	else if (iHandPosition == 3)
	{
		//
		glColor3f(0.3f, 0.3f, 0.3f);
		glLineWidth(0.5f);
		drawLineDrau(
			xOriginDrau + (-0.8700f * scale), yOriginDrau + (-0.1f * scale),
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale));
		drawLineDrau(
			xOriginDrau + (-0.80f * scale), yOriginDrau + (-0.075f * scale),
			xOriginDrau + (-0.73f * scale), yOriginDrau + (-0.225f * scale));
		drawLineDrau(
			xOriginDrau + (-0.73f * scale), yOriginDrau + (-0.225f * scale),
			xOriginDrau + (-0.69f * scale), yOriginDrau + (-0.210f * scale));
		drawLineDrau(
			xOriginDrau + (-0.6900f * scale), yOriginDrau + (-0.210f * scale),
			xOriginDrau + (-0.6800f * scale), yOriginDrau + (-0.270f * scale));
		drawLineDrau(
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale),
			xOriginDrau + (-0.6800f * scale), yOriginDrau + (-0.2700f * scale));

		glColor3f(0.851f, 0.236f, 0.427f); // pink
		drawTriangleDrau(
			xOriginDrau + (-0.6900f * scale), yOriginDrau + (-0.2100f * scale),
			xOriginDrau + (-0.6800f * scale), yOriginDrau + (-0.2700f * scale),
			xOriginDrau + (-0.7375f * scale), yOriginDrau + (-0.3125f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		drawQuadrangleDrau(
			xOriginDrau + (-0.6800f * scale), yOriginDrau + (-0.270f * scale),
			xOriginDrau + (-0.6900f * scale), yOriginDrau + (-0.210f * scale),
			xOriginDrau + (-0.6300f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.6200f * scale), yOriginDrau + (-0.210f * scale)); // forearm
		drawQuadrangleDrau(
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.190f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.210f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.210f * scale)); // wrist-bottom
		drawQuadrangleDrau(
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.190f * scale),
			xOriginDrau + (-0.560f * scale), yOriginDrau + (-0.185f * scale),
			xOriginDrau + (-0.560f * scale), yOriginDrau + (-0.195f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.210f * scale)); // wrist-top eith thumbs base
		drawQuadrangleDrau(
			xOriginDrau + (-0.630f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.170f * scale),
			xOriginDrau + (-0.590f * scale), yOriginDrau + (-0.175f * scale),
			xOriginDrau + (-0.620f * scale), yOriginDrau + (-0.210f * scale)); // thumb

		// back hand
		glColor3f(0.98f, 0.65f, 0.44f); // Skin 1
		drawQuadrangleDrau(
			xOriginDrau + (-0.6855f * scale), yOriginDrau + (-0.1625f * scale),
			xOriginDrau + (-0.6300f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.6255f * scale), yOriginDrau + (-0.1750f * scale),
			xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.2050f * scale));
		drawTriangleDrau(
			xOriginDrau + (-0.6300f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.6000f * scale), yOriginDrau + (-0.1300f * scale),
			xOriginDrau + (-0.6255f * scale), yOriginDrau + (-0.1750f * scale));

		drawQuadrangleDrau(
			xOriginDrau + (-0.6300f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.5900f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.5900f * scale), yOriginDrau + (-0.1650f * scale),
			xOriginDrau + (-0.6255f * scale), yOriginDrau + (-0.1750f * scale));

		drawQuadrangleDrau(
			xOriginDrau + (-0.5650f * scale), yOriginDrau + (-0.1450f * scale),
			xOriginDrau + (-0.5900f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.5900f * scale), yOriginDrau + (-0.1650f * scale),
			xOriginDrau + (-0.5655f * scale), yOriginDrau + (-0.1550f * scale));

		// hand bangles
		glColor3f(0.82f, 0.569f, 0.196f);
		// glColor3f(1.0f, 0.0f, 0.0f);
		drawQuadrangleDrau(
			xOriginDrau + (-0.6750f * scale), yOriginDrau + (-0.195f * scale),
			xOriginDrau + (-0.6825f * scale), yOriginDrau + (-0.2025f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.265f * scale),
			xOriginDrau + (-0.6625f * scale), yOriginDrau + (-0.25f * scale));
		drawQuadrangleDrau(
			xOriginDrau + (-0.6625f * scale), yOriginDrau + (-0.1925f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.1975f * scale),
			xOriginDrau + (-0.6575f * scale), yOriginDrau + (-0.2575f * scale),
			xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.2425f * scale));

		drawQuadrangleDrau(
			xOriginDrau + (-0.6650f * scale), yOriginDrau + (-0.155f * scale),
			xOriginDrau + (-0.6725f * scale), yOriginDrau + (-0.1600f * scale),
			xOriginDrau + (-0.6600f * scale), yOriginDrau + (-0.19f * scale),
			xOriginDrau + (-0.6525f * scale), yOriginDrau + (-0.185f * scale));
		drawQuadrangleDrau(
			xOriginDrau + (-0.6525f * scale), yOriginDrau + (-0.1525f * scale),
			xOriginDrau + (-0.6600f * scale), yOriginDrau + (-0.1550f * scale),
			xOriginDrau + (-0.6475f * scale), yOriginDrau + (-0.1825f * scale),
			xOriginDrau + (-0.6400f * scale), yOriginDrau + (-0.1800f * scale));
	}
}

void drawOdhani(float xOriginDrau, float yOriginDrau, float scale, int iHandPosition, int iStanding)
{
	if (iStanding == 1)
	{
		// Front
		// glColor4f(1.0f, 1.0f, 0.5f, 0.837f);
		// glColor4f(0.96f, 0.58f, 0.44f, 0.5f);
		// glColor4f(1.0f, 0.927f, 0.788f, 0.25f);
		glColor4f(1.0f, 0.51f, 0.71f, 0.75f);
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.9450f * scale), yOriginDrau + (-0.49f * scale));
		glVertex2f(xOriginDrau + (-0.9350f * scale), yOriginDrau + (-0.44f * scale));
		glVertex2f(xOriginDrau + (-0.9100f * scale), yOriginDrau + (-0.40f * scale));
		glVertex2f(xOriginDrau + (-0.8950f * scale), yOriginDrau + (-0.35f * scale));
		glVertex2f(xOriginDrau + (-0.8850f * scale), yOriginDrau + (-0.30f * scale));
		glVertex2f(xOriginDrau + (-0.8750f * scale), yOriginDrau + (-0.05f * scale));
		glVertex2f(xOriginDrau + (-0.8625f * scale), yOriginDrau + (0.050f * scale));
		glVertex2f(xOriginDrau + (-0.8500f * scale), yOriginDrau + (0.100f * scale));
		glVertex2f(xOriginDrau + (-0.8300f * scale), yOriginDrau + (0.150f * scale));
		glVertex2f(xOriginDrau + (-0.8100f * scale), yOriginDrau + (0.175f * scale));
		glVertex2f(xOriginDrau + (-0.7750f * scale), yOriginDrau + (0.187f * scale));
		glVertex2f(xOriginDrau + (-0.7500f * scale), yOriginDrau + (0.187f * scale));
		glVertex2f(xOriginDrau + (-0.7350f * scale), yOriginDrau + (0.181f * scale)); // top
		glVertex2f(xOriginDrau + (-0.7450f * scale), yOriginDrau + (0.150f * scale));
		glVertex2f(xOriginDrau + (-0.7500f * scale), yOriginDrau + (0.125f * scale));
		glVertex2f(xOriginDrau + (-0.7600f * scale), yOriginDrau + (0.075f * scale));
		glVertex2f(xOriginDrau + (-0.7750f * scale), yOriginDrau + (-0.075f * scale));
		glVertex2f(xOriginDrau + (-0.7800f * scale), yOriginDrau + (-0.300f * scale));
		glVertex2f(xOriginDrau + (-0.7900f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.8000f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.8050f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.8250f * scale), yOriginDrau + (-0.550f * scale));

		glEnd();
	}
	else
	{
		glColor4f(1.0f, 0.51f, 0.71f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(xOriginDrau + (-0.9450f * scale), yOriginDrau + (-0.49f * scale));
		glVertex2f(xOriginDrau + (-0.9350f * scale), yOriginDrau + (-0.44f * scale));
		glVertex2f(xOriginDrau + (-0.9100f * scale), yOriginDrau + (-0.40f * scale));
		glVertex2f(xOriginDrau + (-0.8950f * scale), yOriginDrau + (-0.35f * scale));
		glVertex2f(xOriginDrau + (-0.8850f * scale), yOriginDrau + (-0.30f * scale));
		glVertex2f(xOriginDrau + (-0.8750f * scale), yOriginDrau + (-0.05f * scale));
		glVertex2f(xOriginDrau + (-0.8625f * scale), yOriginDrau + (0.050f * scale));
		glVertex2f(xOriginDrau + (-0.8500f * scale), yOriginDrau + (0.100f * scale));
		glVertex2f(xOriginDrau + (-0.8300f * scale), yOriginDrau + (0.150f * scale));
		glVertex2f(xOriginDrau + (-0.8100f * scale), yOriginDrau + (0.175f * scale));
		glVertex2f(xOriginDrau + (-0.7750f * scale), yOriginDrau + (0.187f * scale));
		glVertex2f(xOriginDrau + (-0.7500f * scale), yOriginDrau + (0.187f * scale));
		glVertex2f(xOriginDrau + (-0.7350f * scale), yOriginDrau + (0.181f * scale)); // top
		glVertex2f(xOriginDrau + (-0.7450f * scale), yOriginDrau + (0.150f * scale));
		glVertex2f(xOriginDrau + (-0.7500f * scale), yOriginDrau + (0.125f * scale));
		glVertex2f(xOriginDrau + (-0.7600f * scale), yOriginDrau + (0.075f * scale));
		glVertex2f(xOriginDrau + (-0.7750f * scale), yOriginDrau + (-0.075f * scale));
		glVertex2f(xOriginDrau + (-0.7800f * scale), yOriginDrau + (-0.300f * scale));
		glVertex2f(xOriginDrau + (-0.7900f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.8000f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.8050f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.8250f * scale), yOriginDrau + (-0.550f * scale));

		glEnd();
	}

	if (iHandPosition == 3)
	{
		drawQuadrangleDrau(
			xOriginDrau + (-0.6855f * scale), yOriginDrau + (-0.1600f * scale),
			xOriginDrau + (-0.6850f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.6750f * scale), yOriginDrau + (-0.1300f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.1675f * scale));
	}
	else
	{
		drawQuadrangleDrau(
			xOriginDrau + (-0.6900f * scale), yOriginDrau + (-0.1900f * scale),
			xOriginDrau + (-0.6850f * scale), yOriginDrau + (-0.1500f * scale),
			xOriginDrau + (-0.6750f * scale), yOriginDrau + (-0.1300f * scale),
			xOriginDrau + (-0.6700f * scale), yOriginDrau + (-0.1675f * scale));
	}

	// Back
	// glColor4f(1.0f, 1.0f, 0.5f, 0.837f);
	drawQuadrangleDrau(
		xOriginDrau + (-0.7400f * scale), yOriginDrau + (0.04f * scale),
		xOriginDrau + (-0.7150f * scale), yOriginDrau + (0.03f * scale),
		xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.075f * scale),
		xOriginDrau + (-0.7250f * scale), yOriginDrau + (-0.020f * scale));

	if (iStanding == 1)
	{

		glBegin(GL_POLYGON);
		if (iHandPosition == 3)
		{
			glVertex2f(xOriginDrau + (-0.6850f * scale), yOriginDrau + (-0.273f * scale)); ///
			glVertex2f(xOriginDrau + (-0.6535f * scale), yOriginDrau + (-0.240f * scale));
		}
		else
		{
			glVertex2f(xOriginDrau + (-0.6900f * scale), yOriginDrau + (-0.263f * scale)); ///
			glVertex2f(xOriginDrau + (-0.6575f * scale), yOriginDrau + (-0.223f * scale));
		}

		glVertex2f(xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.275f * scale));
		glVertex2f(xOriginDrau + (-0.6400f * scale), yOriginDrau + (-0.325f * scale));
		glVertex2f(xOriginDrau + (-0.6330f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.6300f * scale), yOriginDrau + (-0.400f * scale));
		glVertex2f(xOriginDrau + (-0.6280f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.6280f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.6350f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.6430f * scale), yOriginDrau + (-0.525f * scale));
		glEnd();
	}
	// line strips

	// front
	if (iStanding == 1)
	{
		// glColor4f(1.0f, 0.0f, 0.0f, 0.837f);
		glColor3f(0.62f, 0.463f, 0.51f);
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.735f * scale), yOriginDrau + (0.177f * scale)); // top
		glVertex2f(xOriginDrau + (-0.745f * scale), yOriginDrau + (0.150f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (0.125f * scale));
		glVertex2f(xOriginDrau + (-0.760f * scale), yOriginDrau + (0.075f * scale));
		glVertex2f(xOriginDrau + (-0.775f * scale), yOriginDrau + (-0.075f * scale));
		glVertex2f(xOriginDrau + (-0.780f * scale), yOriginDrau + (-0.300f * scale));
		glVertex2f(xOriginDrau + (-0.790f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.800f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.805f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.825f * scale), yOriginDrau + (-0.550f * scale));
		glVertex2f(xOriginDrau + (-0.945f * scale), yOriginDrau + (-0.490f * scale));
		glEnd();
	}
	else
	{
		glColor3f(0.62f, 0.463f, 0.51f);
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.735f * scale), yOriginDrau + (0.177f * scale)); // top
		glVertex2f(xOriginDrau + (-0.745f * scale), yOriginDrau + (0.150f * scale));
		glVertex2f(xOriginDrau + (-0.750f * scale), yOriginDrau + (0.125f * scale));
		glVertex2f(xOriginDrau + (-0.760f * scale), yOriginDrau + (0.075f * scale));
		glVertex2f(xOriginDrau + (-0.775f * scale), yOriginDrau + (-0.075f * scale));
		glVertex2f(xOriginDrau + (-0.780f * scale), yOriginDrau + (-0.300f * scale));
		glVertex2f(xOriginDrau + (-0.790f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.800f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.805f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.825f * scale), yOriginDrau + (-0.550f * scale));
		glVertex2f(xOriginDrau + (-0.945f * scale), yOriginDrau + (-0.490f * scale));
		glEnd();
	}
	// back
	glBegin(GL_LINE_STRIP);
	glVertex2f(xOriginDrau + (-0.7150f * scale), yOriginDrau + (0.03f * scale));
	glVertex2f(xOriginDrau + (-0.6875f * scale), yOriginDrau + (-0.075f * scale));
	glEnd();

	if (iHandPosition == 3)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.675f * scale), yOriginDrau + (-0.1300f * scale));
		glVertex2f(xOriginDrau + (-0.670f * scale), yOriginDrau + (-0.1535f * scale));
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOriginDrau + (-0.675f * scale), yOriginDrau + (-0.1300f * scale));
		glVertex2f(xOriginDrau + (-0.670f * scale), yOriginDrau + (-0.1675f * scale));
		glEnd();
	}

	if (iStanding == 1)
	{
		glBegin(GL_LINE_STRIP);
		if (iHandPosition == 3)
		{
			glVertex2f(xOriginDrau + (-0.6535f * scale), yOriginDrau + (-0.240f * scale));
		}
		else
		{
			glVertex2f(xOriginDrau + (-0.6575f * scale), yOriginDrau + (-0.227f * scale));
		}

		glVertex2f(xOriginDrau + (-0.6500f * scale), yOriginDrau + (-0.275f * scale));
		glVertex2f(xOriginDrau + (-0.6400f * scale), yOriginDrau + (-0.325f * scale));
		glVertex2f(xOriginDrau + (-0.6330f * scale), yOriginDrau + (-0.375f * scale));
		glVertex2f(xOriginDrau + (-0.6300f * scale), yOriginDrau + (-0.400f * scale));
		glVertex2f(xOriginDrau + (-0.6280f * scale), yOriginDrau + (-0.425f * scale));
		glVertex2f(xOriginDrau + (-0.6280f * scale), yOriginDrau + (-0.450f * scale));
		glVertex2f(xOriginDrau + (-0.6350f * scale), yOriginDrau + (-0.500f * scale));
		glVertex2f(xOriginDrau + (-0.6430f * scale), yOriginDrau + (-0.525f * scale));
		glEnd();
	}
	else
	{
	}

	glLineWidth(1.0f);
}
