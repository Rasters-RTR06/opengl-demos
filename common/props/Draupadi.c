// header files
//#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159

// global variable declarations
float xOrigin = 0.0f;
float yOrigin = 0.0f;
float fScaleFactor = 1.0f;

int g_iHandPosition = 1;
int g_iStanding = 1;

// global function declarations
void drawLine(float x1, float y1, float x2, float y2);
void drawRectangle(float LX, float RX, float TY, float BY);
void drawQuadrangle(float x1, float  y1, float  x2, float y2, float x3, float  y3, float  x4, float y4);
void drawcircle(float, float, float, float, float, float, float, int);
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);

// function declarations
void drawDraupadi(float xOrigin, float yOrigin, float scale, int iHandPosition, int iStanding);


//Below setting required in init

//int initialize(void)
//{
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glClearColor(0.686f, 0.573f, 0.333f, 1.0f);
//	return(0);
//}

// call to display draupadi 

//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	drawDraupadi(xOrigin, yOrigin, fScaleFactor);
//
//	glutSwapBuffers();
//}

// Draw Rectangle 
void drawRectangle(float LX, float RX, float TY, float BY)
{
	glBegin(GL_QUADS);
	glVertex2f(LX, TY);
	glVertex2f(RX, TY);
	glVertex2f(RX, BY);
	glVertex2f(LX, BY);
	glEnd();
}

void drawQuadrangle(float x1, float  y1, float  x2, float y2, float x3, float  y3, float  x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

// Draw Line
void drawLine(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawcircle(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;

	// Circle
	if (fill == 1) {
		glBegin(GL_POLYGON);
	}
	else {
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

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawDraupadi(float xOrigin, float yOrigin, float scale, int iHandPosition, int iStanding)
{
	void drawLegs(float, float, float, int);
	void drawGhagraCholi(float, float, float, int);
	void drawFace(float, float, float);
	void drawHands(float, float, float, int );
	void drawOdhani(float, float, float, int, int );

	drawLegs(xOrigin, yOrigin, scale, iStanding);
	drawGhagraCholi(xOrigin, yOrigin, scale, iStanding);
	drawFace(xOrigin, yOrigin, scale);
	drawHands(xOrigin, yOrigin, scale, iHandPosition);
	drawOdhani(xOrigin, yOrigin, scale, iHandPosition, iStanding);
}

void drawLegs(float xOrigin, float yOrigin, float scale, int iStanding)
{
	//glColor3f(0.98f, 0.36f, 0.14f);//saffron
	//glColor3f(0.851f, 0.236f, 0.427f);//pink
	glColor3f(0.502f, 0.216f, 0.306f);//pink


	if (iStanding == 1)
	{
		//Hip area
		drawQuadrangle(
			xOrigin + (-0.684f * scale), yOrigin + (-0.400f * scale),
			xOrigin + (-0.875f * scale), yOrigin + (-0.400f * scale),
			xOrigin + (-0.855f * scale), yOrigin + (-0.250f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.250f * scale));

		//front leg
		glBegin(GL_QUADS);
		glColor3f(0.502f, 0.216f, 0.306f);//pink
		glVertex2f(xOrigin + (-0.780f * scale), yOrigin + (-0.400f * scale));
		glVertex2f(xOrigin + (-0.684f * scale), yOrigin + (-0.400f * scale));
		glColor3f(0.851f, 0.236f, 0.427f);//pink
		glVertex2f(xOrigin + (-0.690f * scale), yOrigin + (-0.550f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.550f * scale));
		glEnd();

		//back leg
		glBegin(GL_QUADS);
		glColor3f(0.502f, 0.216f, 0.306f);//pink
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.35f * scale));
		glVertex2f(xOrigin + (-0.875f * scale), yOrigin + (-0.40f * scale));
		glColor3f(0.851f, 0.236f, 0.427f);//pink
		glVertex2f(xOrigin + (-0.840f * scale), yOrigin + (-0.55f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.55f * scale));
		glEnd();

		glColor3f(0.851f, 0.236f, 0.427f);//pink
		//back leg lower
		drawQuadrangle(
			xOrigin + (-0.825f * scale), yOrigin + (-0.83f * scale),
			xOrigin + (-0.785f * scale), yOrigin + (-0.83f * scale),
			xOrigin + (-0.765f * scale), yOrigin + (-0.55f * scale),
			xOrigin + (-0.840f * scale), yOrigin + (-0.55f * scale));
		// front leg lower
		drawQuadrangle(
			xOrigin + (-0.742f * scale), yOrigin + (-0.830f * scale),
			xOrigin + (-0.695f * scale), yOrigin + (-0.825f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.550f * scale),
			xOrigin + (-0.750f * scale), yOrigin + (-0.550f * scale));


		glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		//Back foot
		drawQuadrangle(
			xOrigin + (-0.83f * scale), yOrigin + (-0.85f * scale),
			xOrigin + (-0.82f * scale), yOrigin + (-0.83f * scale),
			xOrigin + (-0.79f * scale), yOrigin + (-0.83f * scale),
			xOrigin + (-0.79f * scale), yOrigin + (-0.85f * scale));

		drawQuadrangle(
			xOrigin + (-0.83f * scale), yOrigin + (-0.85f * scale),
			xOrigin + (-0.78f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.74f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.79f * scale), yOrigin + (-0.85f * scale));

		// front foot
		drawQuadrangle(
			xOrigin + (-0.750f * scale), yOrigin + (-0.850f * scale),
			xOrigin + (-0.740f * scale), yOrigin + (-0.830f * scale),
			xOrigin + (-0.695f * scale), yOrigin + (-0.825f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.840f * scale));

		drawQuadrangle(
			xOrigin + (-0.75f * scale), yOrigin + (-0.85f * scale),
			xOrigin + (-0.66f * scale), yOrigin + (-0.9f * scale),
			xOrigin + (-0.63f * scale), yOrigin + (-0.875f * scale),
			xOrigin + (-0.69f * scale), yOrigin + (-0.84f * scale));

		//fingers
		glColor3f(0.6f, 0.6f, 0.6f);
		//back
		drawLine(
			xOrigin + (-0.750f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.765f * scale), yOrigin + (-0.91f * scale));
		drawLine(
			xOrigin + (-0.758f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.773f * scale), yOrigin + (-0.91f * scale));
		drawLine(
			xOrigin + (-0.766f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.781f * scale), yOrigin + (-0.91f * scale));
		drawLine(
			xOrigin + (-0.774f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.789f * scale), yOrigin + (-0.91f * scale));

		//front
		drawLine(
			xOrigin + (-0.65f * scale), yOrigin + (-0.89f * scale),
			xOrigin + (-0.67f * scale), yOrigin + (-0.878f * scale));
		drawLine(
			xOrigin + (-0.645f * scale), yOrigin + (-0.885f * scale),
			xOrigin + (-0.665f * scale), yOrigin + (-0.873f * scale));
		drawLine(
			xOrigin + (-0.64f * scale), yOrigin + (-0.88f * scale),
			xOrigin + (-0.66f * scale), yOrigin + (-0.868f * scale));
		drawLine(
			xOrigin + (-0.635f * scale), yOrigin + (-0.875f * scale),
			xOrigin + (-0.655f * scale), yOrigin + (-0.863f * scale));

	}
	else
	{
		//Hip area
		drawQuadrangle(
			xOrigin + (-0.684f * scale), yOrigin + (-0.400f * scale),
			xOrigin + (-0.875f * scale), yOrigin + (-0.400f * scale),
			xOrigin + (-0.855f * scale), yOrigin + (-0.250f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.250f * scale));

		//front leg
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.700f * scale), yOrigin + (-0.350f * scale));
		glVertex2f(xOrigin + (-0.650f * scale), yOrigin + (-0.365f * scale));
		glVertex2f(xOrigin + (-0.600f * scale), yOrigin + (-0.400f * scale));
		glVertex2f(xOrigin + (-0.575f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.600f * scale), yOrigin + (-0.555f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.545f * scale));
		glEnd();
		//knee
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.575f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.568f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.560f * scale), yOrigin + (-0.475f * scale));
		glVertex2f(xOrigin + (-0.561f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.565f * scale), yOrigin + (-0.525f * scale));
		glVertex2f(xOrigin + (-0.600f * scale), yOrigin + (-0.555f * scale));
		glEnd();

		//back leg
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.875f * scale), yOrigin + (-0.400f * scale));
		glVertex2f(xOrigin + (-0.872f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.871f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.865f * scale), yOrigin + (-0.475f * scale));

		glVertex2f(xOrigin + (-0.865f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.856f * scale), yOrigin + (-0.525f * scale));
		glVertex2f(xOrigin + (-0.850f * scale), yOrigin + (-0.550f * scale));
		glVertex2f(xOrigin + (-0.825f * scale), yOrigin + (-0.568f * scale));

		glVertex2f(xOrigin + (-0.800f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.568f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.545f * scale));
		glEnd();

		drawTriangle(
			xOrigin + (-0.750f * scale), yOrigin + (-0.545f * scale),
			xOrigin + (-0.875f * scale), yOrigin + (-0.400f * scale),
			xOrigin + (-0.700f * scale), yOrigin + (-0.350f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.675f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.663f * scale), yOrigin + (-0.350f * scale));
		glVertex2f(xOrigin + (-0.658f * scale), yOrigin + (-0.325f * scale));
		glVertex2f(xOrigin + (-0.655f * scale), yOrigin + (-0.300f * scale));
		glVertex2f(xOrigin + (-0.655f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.670f * scale), yOrigin + (-0.200f * scale));
		glVertex2f(xOrigin + (-0.660f * scale), yOrigin + (-0.200f * scale));

		glVertex2f(xOrigin + (-0.685f * scale), yOrigin + (-0.270f * scale));
		glVertex2f(xOrigin + (-0.710f * scale), yOrigin + (-0.275f * scale));
		glVertex2f(xOrigin + (-0.730f * scale), yOrigin + (-0.300f * scale));
		glVertex2f(xOrigin + (-0.760f * scale), yOrigin + (-0.250f * scale));
		glEnd();

		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(1.0f);

		drawLine(
			xOrigin + (-0.850f * scale), yOrigin + (-0.400f * scale),
			xOrigin + (-0.750f * scale), yOrigin + (-0.250f * scale));

		drawLine(xOrigin + (-0.670f * scale), yOrigin + (-0.365f * scale),
			xOrigin + (-0.700f * scale), yOrigin + (-0.450f * scale));

		drawLine(xOrigin + (-0.700f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.725f * scale), yOrigin + (-0.500f * scale));

		drawLine(xOrigin + (-0.725f * scale), yOrigin + (-0.500f * scale),
			xOrigin + (-0.750f * scale), yOrigin + (-0.545f * scale));


		drawLine(xOrigin + (-0.700f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.660f * scale), yOrigin + (-0.433f * scale));

		drawLine(xOrigin + (-0.660f * scale), yOrigin + (-0.433f * scale),
			xOrigin + (-0.625f * scale), yOrigin + (-0.450f * scale));

		glLineWidth(1.0f);

	}
}

void drawGhagraCholi(float xOrigin, float yOrigin, float scale, int iStanding)
{

	//Ghagra
	if (iStanding == 1)
	{
		//glColor4f(0.706f, 0.137f, 0.161f, 1.0f);
		//glColor4f(0.96f, 0.58f, 0.44f, 0.5f);
		//glColor4f(1.0f, 0.927f, 0.788f, 0.0f);
		glColor4f(1.0f, 0.51f, 0.71f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.925f * scale), yOrigin + (-0.80f * scale));
		glVertex2f(xOrigin + (-0.600f * scale), yOrigin + (-0.80f * scale));
		glVertex2f(xOrigin + (-0.640f * scale), yOrigin + (-0.84f * scale));
		glVertex2f(xOrigin + (-0.700f * scale), yOrigin + (-0.85f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.86f * scale));
		glVertex2f(xOrigin + (-0.850f * scale), yOrigin + (-0.85f * scale));
		glEnd();

		drawQuadrangle(
			xOrigin + (-0.690f * scale), yOrigin + (-0.25f * scale),
			xOrigin + (-0.600f * scale), yOrigin + (-0.80f * scale),
			xOrigin + (-0.925f * scale), yOrigin + (-0.80f * scale),
			xOrigin + (-0.855f * scale), yOrigin + (-0.25f * scale)); //waist

		glColor3f(1.0f, 0.0f, 0.0f);
		glColor3f(0.62f, 0.463f, 0.51f);
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.69f * scale), yOrigin + (-0.25f * scale));
		glVertex2f(xOrigin + (-0.60f * scale), yOrigin + (-0.80f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.925f * scale), yOrigin + (-0.80f * scale));
		glVertex2f(xOrigin + (-0.855f * scale), yOrigin + (-0.25f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP); // bottom strips
		glVertex2f(xOrigin + (-0.600f * scale), yOrigin + (-0.80f * scale));
		glVertex2f(xOrigin + (-0.640f * scale), yOrigin + (-0.84f * scale));
		glVertex2f(xOrigin + (-0.700f * scale), yOrigin + (-0.85f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.86f * scale));
		glVertex2f(xOrigin + (-0.850f * scale), yOrigin + (-0.85f * scale));
		glVertex2f(xOrigin + (-0.925f * scale), yOrigin + (-0.80f * scale));
		glEnd();

		// waist band
		glLineWidth(4.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.690f * scale), yOrigin + (-0.255f * scale));
		glVertex2f(xOrigin + (-0.855f * scale), yOrigin + (-0.255f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
	else
	{
		glColor4f(1.0f, 0.51f, 0.71f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.25f * scale));
		glVertex2f(xOrigin + (-0.660f * scale), yOrigin + (-0.200f * scale));
		glVertex2f(xOrigin + (-0.655f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.575f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.550f * scale), yOrigin + (-0.475f * scale));
		glVertex2f(xOrigin + (-0.540f * scale), yOrigin + (-0.580f * scale));

		glEnd();

		drawQuadrangle(
			xOrigin + (-0.750f * scale), yOrigin + (-0.250f * scale),
			xOrigin + (-0.540f * scale), yOrigin + (-0.580f * scale),
			xOrigin + (-0.925f * scale), yOrigin + (-0.600f * scale),
			xOrigin + (-0.855f * scale), yOrigin + (-0.250f * scale)); //waist

		glColor3f(0.62f, 0.463f, 0.51f);
		// waist band
		glLineWidth(4.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.690f * scale), yOrigin + (-0.255f * scale));
		glVertex2f(xOrigin + (-0.855f * scale), yOrigin + (-0.255f * scale));
		glEnd();

		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.855f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.925f * scale), yOrigin + (-0.600f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.540f * scale), yOrigin + (-0.580f * scale));
		glVertex2f(xOrigin + (-0.925f * scale), yOrigin + (-0.600f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.660f * scale), yOrigin + (-0.200f * scale));
		glVertex2f(xOrigin + (-0.655f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.655f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.575f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.575f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.550f * scale), yOrigin + (-0.475f * scale));
		glVertex2f(xOrigin + (-0.550f * scale), yOrigin + (-0.475f * scale));
		glVertex2f(xOrigin + (-0.540f * scale), yOrigin + (-0.580f * scale));
		glEnd();
		glLineWidth(1.0f);
	}




	//Choli
	//glColor3f(0.639f, 0.075f, 0.227f);

	glColor3f(0.98f, 0.36f, 0.14f);//orange
	glColor3f(0.851f, 0.236f, 0.427f);//pink
	drawQuadrangle(
		xOrigin + (-0.855f * scale), yOrigin + (-0.25f * scale),
		xOrigin + (-0.875f * scale), yOrigin + (-0.05f * scale),
		xOrigin + (-0.685f * scale), yOrigin + (-0.15f * scale),
		xOrigin + (-0.690f * scale), yOrigin + (-0.25f * scale));
	drawQuadrangle(xOrigin + (-0.83f * scale), yOrigin + (0.00f * scale),
		xOrigin + (-0.86f * scale), yOrigin + (-0.015f * scale),
		xOrigin + (-0.87f * scale), yOrigin + (-0.025f * scale),
		xOrigin + (-0.875 * scale), yOrigin + (-0.05f * scale));
	drawQuadrangle(xOrigin + (-0.685f * scale), yOrigin + (-0.15f * scale),
		xOrigin + (-0.67f * scale), yOrigin + (-0.10f * scale),
		xOrigin + (-0.67f * scale), yOrigin + (-0.115f * scale),
		xOrigin + (-0.675f * scale), yOrigin + (-0.135f * scale)); //
	drawQuadrangle(xOrigin + (-0.685f * scale), yOrigin + (-0.15f * scale),
		xOrigin + (-0.67f * scale), yOrigin + (-0.10f * scale),
		xOrigin + (-0.83f * scale), yOrigin + (0.00f * scale),
		xOrigin + (-0.875 * scale), yOrigin + (-0.05f * scale));
	drawQuadrangle(xOrigin + (-0.83f * scale), yOrigin + (0.00f * scale),
		xOrigin + (-0.8f * scale), yOrigin + (0.0f * scale),
		xOrigin + (-0.725f * scale), yOrigin + (-0.02f * scale),
		xOrigin + (-0.67f * scale), yOrigin + (-0.10f * scale));

	//necklace
	glColor3f(0.82f, 0.569f, 0.196f);
	drawTriangle(xOrigin + (-0.8f * scale), yOrigin + (0.0f * scale),
		xOrigin + (-0.725f * scale), yOrigin + (-0.075f * scale),
		xOrigin + (-0.718f * scale), yOrigin + (-0.1f * scale));
	drawTriangle(xOrigin + (-0.725f * scale), yOrigin + (-0.02f * scale),
		xOrigin + (-0.725f * scale), yOrigin + (-0.075f * scale),
		xOrigin + (-0.718f * scale), yOrigin + (-0.1f * scale));
}

void drawFace(float xOrigin, float yOrigin, float scale)
{
	glColor3f(0.98f, 0.75f, 0.54f); //Skin 1

	drawTriangle(
		xOrigin + (-0.800f * scale), yOrigin + (0.0f * scale),
		xOrigin + (-0.725f * scale), yOrigin + (-0.02f * scale),
		xOrigin + (-0.735f * scale), yOrigin + (-0.05f * scale)); // neck lower
	//drawTriangle(-0.8f, 0.0f, -0.81f, 0.04f, -0.815f, 0.0f); //neck back
	drawQuadrangle(
		xOrigin + (-0.800f * scale), yOrigin + (0.0f * scale),
		xOrigin + (-0.725f * scale), yOrigin + (-0.02f * scale),
		xOrigin + (-0.740f * scale), yOrigin + (0.04f * scale),
		xOrigin + (-0.810f * scale), yOrigin + (0.04f * scale)); // neck front

	drawQuadrangle(
		xOrigin + (-0.760f * scale), yOrigin + (0.04f * scale),
		xOrigin + (-0.715f * scale), yOrigin + (0.03f * scale),
		xOrigin + (-0.700f * scale), yOrigin + (0.055f * scale),
		xOrigin + (-0.700f * scale), yOrigin + (0.07f * scale)); //chin n lips

	drawTriangle(
		xOrigin + (-0.81f * scale), yOrigin + (0.04f * scale),
		xOrigin + (-0.76f * scale), yOrigin + (0.04f * scale),
		xOrigin + (-0.70f * scale), yOrigin + (0.07f * scale)); // lips n face connector
	drawQuadrangle(
		xOrigin + (-0.810f * scale), yOrigin + (0.04f * scale),
		xOrigin + (-0.790f * scale), yOrigin + (0.13f * scale),
		xOrigin + (-0.692f * scale), yOrigin + (0.15f * scale),
		xOrigin + (-0.700f * scale), yOrigin + (0.055f * scale)); //face

	drawTriangle(
		xOrigin + (-0.700f * scale), yOrigin + (0.07f * scale),
		xOrigin + (-0.688f * scale), yOrigin + (0.065f * scale),
		xOrigin + (-0.697f * scale), yOrigin + (0.11f * scale)); // nose

	drawTriangle(
		xOrigin + (-0.79f * scale), yOrigin + (0.125f * scale),
		xOrigin + (-0.81f * scale), yOrigin + (0.1f * scale),
		xOrigin + (-0.80f * scale), yOrigin + (0.065f * scale)); // ear

	// hairs
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuadrangle(
		xOrigin + (-0.690f * scale), yOrigin + (0.14f * scale),
		xOrigin + (-0.700f * scale), yOrigin + (0.165f * scale),
		xOrigin + (-0.765f * scale), yOrigin + (0.18f * scale),
		xOrigin + (-0.780f * scale), yOrigin + (0.1f * scale)); //-0.79f, 0.13f
	drawQuadrangle(
		xOrigin + (-0.765f * scale), yOrigin + (0.18f * scale),
		xOrigin + (-0.800f * scale), yOrigin + (0.16f * scale),
		xOrigin + (-0.820f * scale), yOrigin + (0.14f * scale),
		xOrigin + (-0.780f * scale), yOrigin + (0.1f * scale));
	drawQuadrangle(
		xOrigin + (-0.78f * scale), yOrigin + (0.1f * scale),
		xOrigin + (-0.82f * scale), yOrigin + (0.14f * scale),
		xOrigin + (-0.84f * scale), yOrigin + (-0.01f * scale),
		xOrigin + (-0.80f * scale), yOrigin + (0.05f * scale));

	drawQuadrangle(
		xOrigin + (-0.770f * scale), yOrigin + (0.11f * scale),
		xOrigin + (-0.760f * scale), yOrigin + (0.08f * scale),
		xOrigin + (-0.755f * scale), yOrigin + (0.085f * scale),
		xOrigin + (-0.740f * scale), yOrigin + (0.12f * scale));
	drawQuadrangle(
		xOrigin + (-0.800f * scale), yOrigin + (0.0f * scale),
		xOrigin + (-0.840f * scale), yOrigin + (0.0f * scale),
		xOrigin + (-0.778f * scale), yOrigin + (0.11f * scale),
		xOrigin + (-0.775f * scale), yOrigin + (0.06f * scale)); //neck back

	drawTriangle(
		xOrigin + (-0.869f * scale), yOrigin + (-0.3f * scale),
		xOrigin + (-0.860f * scale), yOrigin + (-0.2f * scale),
		xOrigin + (-0.850f * scale), yOrigin + (-0.25f * scale));

	// face features
	glColor3f(0.9f, 0.25f, 0.35f);
	drawTriangle(
		xOrigin + (-0.700f * scale), yOrigin + (0.055f * scale),
		xOrigin + (-0.720f * scale), yOrigin + (0.055f * scale),
		xOrigin + (-0.707f * scale), yOrigin + (0.045f * scale)); //lips

	glColor3f(1.0f, 1.0f, 1.0f);
	drawQuadrangle(
		xOrigin + (-0.7000f * scale), yOrigin + (0.105f * scale),
		xOrigin + (-0.7180f * scale), yOrigin + (0.105f * scale),
		xOrigin + (-0.7020f * scale), yOrigin + (0.09f * scale),
		xOrigin + (-0.6950f * scale), yOrigin + (0.1f * scale)); //eye
	glColor3f(0.0f, 0.0f, 0.0f);
	drawTriangle(
		xOrigin + (-0.7020f * scale), yOrigin + (0.09f * scale),
		xOrigin + (-0.6950f * scale), yOrigin + (0.1f * scale),
		xOrigin + (-0.7040f * scale), yOrigin + (0.1f * scale)); //retina
	drawLine(
		xOrigin + (-0.721f * scale), yOrigin + (0.11f * scale),
		xOrigin + (-0.705f * scale), yOrigin + (0.115f * scale));
	drawLine(
		xOrigin + (-0.705f * scale), yOrigin + (0.115f * scale),
		xOrigin + (-0.695f * scale), yOrigin + (0.11f * scale));

	glColor3f(1.0f, 0.0f, 0.0f);
	drawLine(
		xOrigin + (-0.695f * scale), yOrigin + (0.115f * scale),
		xOrigin + (-0.695f * scale), yOrigin + (0.12f * scale));

	//earring
	drawcircle(
		xOrigin + (-0.7625f * scale), yOrigin + (0.062f * scale),
		xOrigin + (0.008f * scale), yOrigin + (0.008f * scale), 0.82f, 0.569f, 0.196f, 1);
}

void drawHands(float xOrigin, float yOrigin, float scale, int iHandPosition)
{
	//choli hand
	//glColor3f(0.98f, 0.36f, 0.14f);
	glColor3f(0.851f, 0.236f, 0.427f);//pink
	drawTriangle(
		xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale),
		xOrigin + (-0.7780f * scale), yOrigin + (-0.25f * scale),
		xOrigin + (-0.6780f * scale), yOrigin + (-0.25f * scale));

	if (iHandPosition == 1)
	{
		//
		glColor3f(0.3f, 0.3f, 0.3f);
		glLineWidth(0.5f);
		drawLine(
			xOrigin + (-0.8700f * scale), yOrigin + (-0.1f * scale),
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale));
		drawLine(
			xOrigin + (-0.80f * scale), yOrigin + (-0.075f * scale),
			xOrigin + (-0.73f * scale), yOrigin + (-0.225f * scale));
		drawLine(
			xOrigin + (-0.73f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.70f * scale), yOrigin + (-0.2f * scale));
		drawLine(
			xOrigin + (-0.7000f * scale), yOrigin + (-0.2f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.2625f * scale));
		drawLine(
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.2625f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		drawQuadrangle(
			xOrigin + (-0.6875f * scale), yOrigin + (-0.259f * scale),
			xOrigin + (-0.7000f * scale), yOrigin + (-0.2f * scale),
			xOrigin + (-0.6500f * scale), yOrigin + (-0.15f * scale),
			xOrigin + (-0.6350f * scale), yOrigin + (-0.195f * scale)); //forearm
		drawQuadrangle(
			xOrigin + (-0.650f * scale), yOrigin + (-0.15f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.15f * scale),
			xOrigin + (-0.625f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.635f * scale), yOrigin + (-0.195f * scale)); //wrist-bottom
		drawQuadrangle(
			xOrigin + (-0.65f * scale), yOrigin + (-0.15f * scale),
			xOrigin + (-0.65f * scale), yOrigin + (-0.125f * scale),
			xOrigin + (-0.64f * scale), yOrigin + (-0.12f * scale),
			xOrigin + (-0.62f * scale), yOrigin + (-0.15f * scale)); //wrist-top eith thumbs base
		drawQuadrangle(
			xOrigin + (-0.650f * scale), yOrigin + (-0.125f * scale),
			xOrigin + (-0.637f * scale), yOrigin + (-0.08f * scale),
			xOrigin + (-0.625f * scale), yOrigin + (-0.08f * scale),
			xOrigin + (-0.640f * scale), yOrigin + (-0.12f * scale)); //thumb

		drawQuadrangle(
			xOrigin + (-0.640f * scale), yOrigin + (-0.120f * scale),
			xOrigin + (-0.625f * scale), yOrigin + (-0.065f * scale),
			xOrigin + (-0.615f * scale), yOrigin + (-0.055f * scale),
			xOrigin + (-0.605f * scale), yOrigin + (-0.09f * scale)); //fingers
		drawTriangle(
			xOrigin + (-0.640f * scale), yOrigin + (-0.12f * scale),
			xOrigin + (-0.605f * scale), yOrigin + (-0.09f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.15f * scale)); //fingers base

		//finger lines
		glColor3f(0.6f, 0.6f, 0.6f);
		drawLine(
			xOrigin + (-0.630f * scale), yOrigin + (-0.08f * scale),
			xOrigin + (-0.643f * scale), yOrigin + (-0.125f * scale));
		drawLine(
			xOrigin + (-0.618f * scale), yOrigin + (-0.056f * scale),
			xOrigin + (-0.630f * scale), yOrigin + (-0.11f * scale));
		drawLine(
			xOrigin + (-0.6120f * scale), yOrigin + (-0.065f * scale),
			xOrigin + (-0.6245f * scale), yOrigin + (-0.12f * scale));
		drawLine(
			xOrigin + (-0.608f * scale), yOrigin + (-0.081f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.125f * scale));

		//back hand
		glColor3f(0.98f, 0.65f, 0.44f); //Skin 1
		drawTriangle(
			xOrigin + (-0.6500f * scale), yOrigin + (-0.15f * scale),
			xOrigin + (-0.6855f * scale), yOrigin + (-0.1625f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.19f * scale));

		//hand bangles
		glColor3f(0.82f, 0.569f, 0.196f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		drawQuadrangle(
			xOrigin + (-0.6750f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.6825f * scale), yOrigin + (-0.1825f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.245f * scale),
			xOrigin + (-0.6625f * scale), yOrigin + (-0.23f * scale));
		drawQuadrangle(
			xOrigin + (-0.6625f * scale), yOrigin + (-0.1625f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.1675f * scale),
			xOrigin + (-0.6575f * scale), yOrigin + (-0.2275f * scale),
			xOrigin + (-0.6500f * scale), yOrigin + (-0.2125f * scale));
	}
	else if (iHandPosition == 2)
	{

		glColor3f(0.98f, 0.65f, 0.44f); //Skin 1
		drawQuadrangle(

			xOrigin + (-0.690f * scale), yOrigin + (-0.275f * scale),
			xOrigin + (-0.660f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.630f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.260f * scale)); //wrist-bottom

		drawQuadrangle(
			xOrigin + (-0.630f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.240f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.260f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.260f * scale)); //wrist-bottom
		drawQuadrangle(
			xOrigin + (-0.590f * scale), yOrigin + (-0.240f * scale),
			xOrigin + (-0.560f * scale), yOrigin + (-0.235f * scale),
			xOrigin + (-0.560f * scale), yOrigin + (-0.245f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.260f * scale)); //wrist-top eith thumbs base
		drawQuadrangle(
			xOrigin + (-0.630f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.220f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.260f * scale)); //thumb

		//
		glColor3f(0.3f, 0.3f, 0.3f);
		glLineWidth(0.5f);
		drawLine(
			xOrigin + (-0.8700f * scale), yOrigin + (-0.1f * scale),
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale));
		drawLine(
			xOrigin + (-0.80f * scale), yOrigin + (-0.075f * scale),
			xOrigin + (-0.73f * scale), yOrigin + (-0.225f * scale));
		drawLine(
			xOrigin + (-0.73f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.70f * scale), yOrigin + (-0.2f * scale));
		drawLine(
			xOrigin + (-0.7000f * scale), yOrigin + (-0.2f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.2625f * scale));
		drawLine(
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.2625f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		drawQuadrangle(
			xOrigin + (-0.6875f * scale), yOrigin + (-0.259f * scale),
			xOrigin + (-0.7000f * scale), yOrigin + (-0.200f * scale),
			xOrigin + (-0.6500f * scale), yOrigin + (-0.150f * scale),
			xOrigin + (-0.6350f * scale), yOrigin + (-0.190f * scale)); //forearm
		drawQuadrangle(
			xOrigin + (-0.650f * scale), yOrigin + (-0.150f * scale),
			xOrigin + (-0.615f * scale), yOrigin + (-0.134f * scale),
			xOrigin + (-0.612f * scale), yOrigin + (-0.185f * scale),
			xOrigin + (-0.635f * scale), yOrigin + (-0.190f * scale)); //wrist-bottom
		drawQuadrangle(
			xOrigin + (-0.615f * scale), yOrigin + (-0.134f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.135f * scale),
			xOrigin + (-0.580f * scale), yOrigin + (-0.155f * scale),
			xOrigin + (-0.614f * scale), yOrigin + (-0.160f * scale)); //first two fingers
		drawQuadrangle(
			xOrigin + (-0.614f * scale), yOrigin + (-0.160f * scale),
			xOrigin + (-0.595f * scale), yOrigin + (-0.168f * scale),
			xOrigin + (-0.599f * scale), yOrigin + (-0.185f * scale),
			xOrigin + (-0.612f * scale), yOrigin + (-0.185f * scale)); //sencond two fingers
		drawQuadrangle(
			xOrigin + (-0.595f * scale), yOrigin + (-0.168f * scale),
			xOrigin + (-0.583f * scale), yOrigin + (-0.180f * scale),
			xOrigin + (-0.589f * scale), yOrigin + (-0.190f * scale),
			xOrigin + (-0.599f * scale), yOrigin + (-0.185f * scale)); //sencond two fingers
		//drawQuadrangle(
		//	xOrigin + (-0.640f * scale), yOrigin + (-0.120f * scale),
		//	xOrigin + (-0.625f * scale), yOrigin + (-0.065f * scale),
		//	xOrigin + (-0.615f * scale), yOrigin + (-0.055f * scale),
		//	xOrigin + (-0.605f * scale), yOrigin + (-0.09f * scale)); //fingers
		//drawTriangle(
		//	xOrigin + (-0.640f * scale), yOrigin + (-0.12f * scale),
		//	xOrigin + (-0.605f * scale), yOrigin + (-0.09f * scale),
		//	xOrigin + (-0.620f * scale), yOrigin + (-0.15f * scale)); //fingers base

		//finger lines
		glColor3f(0.6f, 0.6f, 0.6f);
		drawLine(
			xOrigin + (-0.585f * scale), yOrigin + (-0.145f * scale),
			xOrigin + (-0.600f * scale), yOrigin + (-0.145f * scale));
		drawLine(
			xOrigin + (-0.600f * scale), yOrigin + (-0.145f * scale),
			xOrigin + (-0.618f * scale), yOrigin + (-0.152f * scale));

		drawLine(
			xOrigin + (-0.586f * scale), yOrigin + (-0.185f * scale),
			xOrigin + (-0.597f * scale), yOrigin + (-0.174f * scale));
		drawLine(
			xOrigin + (-0.597f * scale), yOrigin + (-0.174f * scale),
			xOrigin + (-0.613f * scale), yOrigin + (-0.175f * scale));
		//drawLine(
		//	xOrigin + (-0.608f * scale), yOrigin + (-0.081f * scale),
		//	xOrigin + (-0.620f * scale), yOrigin + (-0.125f * scale));

		//hand bangles
		glColor3f(0.82f, 0.569f, 0.196f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		drawQuadrangle(
			xOrigin + (-0.6750f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.6825f * scale), yOrigin + (-0.1825f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.245f * scale),
			xOrigin + (-0.6625f * scale), yOrigin + (-0.23f * scale));
		drawQuadrangle(
			xOrigin + (-0.6625f * scale), yOrigin + (-0.1625f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.1675f * scale),
			xOrigin + (-0.6575f * scale), yOrigin + (-0.2275f * scale),
			xOrigin + (-0.6500f * scale), yOrigin + (-0.2125f * scale));

		drawQuadrangle(
			xOrigin + (-0.640f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.650f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.650f * scale), yOrigin + (-0.285f * scale),
			xOrigin + (-0.640f * scale), yOrigin + (-0.285f * scale));
		drawQuadrangle(
			xOrigin + (-0.625f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.635f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.635f * scale), yOrigin + (-0.285f * scale),
			xOrigin + (-0.625f * scale), yOrigin + (-0.285f * scale));
	}
	else if (iHandPosition == 3)
	{
		//
		glColor3f(0.3f, 0.3f, 0.3f);
		glLineWidth(0.5f);
		drawLine(
			xOrigin + (-0.8700f * scale), yOrigin + (-0.1f * scale),
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale));
		drawLine(
			xOrigin + (-0.80f * scale), yOrigin + (-0.075f * scale),
			xOrigin + (-0.73f * scale), yOrigin + (-0.225f * scale));
		drawLine(
			xOrigin + (-0.73f * scale), yOrigin + (-0.225f * scale),
			xOrigin + (-0.69f * scale), yOrigin + (-0.210f * scale));
		drawLine(
			xOrigin + (-0.6900f * scale), yOrigin + (-0.210f * scale),
			xOrigin + (-0.6800f * scale), yOrigin + (-0.270f * scale));
		drawLine(
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale),
			xOrigin + (-0.6800f * scale), yOrigin + (-0.2700f * scale));

		glColor3f(0.851f, 0.236f, 0.427f);//pink
		drawTriangle(
			xOrigin + (-0.6900f * scale), yOrigin + (-0.2100f * scale),
			xOrigin + (-0.6800f * scale), yOrigin + (-0.2700f * scale),
			xOrigin + (-0.7375f * scale), yOrigin + (-0.3125f * scale));

		glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		drawQuadrangle(
			xOrigin + (-0.6800f * scale), yOrigin + (-0.270f * scale),
			xOrigin + (-0.6900f * scale), yOrigin + (-0.210f * scale),
			xOrigin + (-0.6300f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.6200f * scale), yOrigin + (-0.210f * scale)); //forearm
		drawQuadrangle(
			xOrigin + (-0.630f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.190f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.210f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.210f * scale)); //wrist-bottom
		drawQuadrangle(
			xOrigin + (-0.590f * scale), yOrigin + (-0.190f * scale),
			xOrigin + (-0.560f * scale), yOrigin + (-0.185f * scale),
			xOrigin + (-0.560f * scale), yOrigin + (-0.195f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.210f * scale)); //wrist-top eith thumbs base
		drawQuadrangle(
			xOrigin + (-0.630f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.170f * scale),
			xOrigin + (-0.590f * scale), yOrigin + (-0.175f * scale),
			xOrigin + (-0.620f * scale), yOrigin + (-0.210f * scale)); //thumb

		//back hand
		glColor3f(0.98f, 0.65f, 0.44f); //Skin 1
		drawQuadrangle(
			xOrigin + (-0.6855f * scale), yOrigin + (-0.1625f * scale),
			xOrigin + (-0.6300f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.6255f * scale), yOrigin + (-0.1750f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.2050f * scale));
		drawTriangle(
			xOrigin + (-0.6300f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.6000f * scale), yOrigin + (-0.1300f * scale),
			xOrigin + (-0.6255f * scale), yOrigin + (-0.1750f * scale));

		drawQuadrangle(
			xOrigin + (-0.6300f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.5900f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.5900f * scale), yOrigin + (-0.1650f * scale),
			xOrigin + (-0.6255f * scale), yOrigin + (-0.1750f * scale));

		drawQuadrangle(
			xOrigin + (-0.5650f * scale), yOrigin + (-0.1450f * scale),
			xOrigin + (-0.5900f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.5900f * scale), yOrigin + (-0.1650f * scale),
			xOrigin + (-0.5655f * scale), yOrigin + (-0.1550f * scale));

		//hand bangles
		glColor3f(0.82f, 0.569f, 0.196f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		drawQuadrangle(
			xOrigin + (-0.6750f * scale), yOrigin + (-0.195f * scale),
			xOrigin + (-0.6825f * scale), yOrigin + (-0.2025f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.265f * scale),
			xOrigin + (-0.6625f * scale), yOrigin + (-0.25f * scale));
		drawQuadrangle(
			xOrigin + (-0.6625f * scale), yOrigin + (-0.1925f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.1975f * scale),
			xOrigin + (-0.6575f * scale), yOrigin + (-0.2575f * scale),
			xOrigin + (-0.6500f * scale), yOrigin + (-0.2425f * scale));

		drawQuadrangle(
			xOrigin + (-0.6650f * scale), yOrigin + (-0.155f * scale),
			xOrigin + (-0.6725f * scale), yOrigin + (-0.1600f * scale),
			xOrigin + (-0.6600f * scale), yOrigin + (-0.19f * scale),
			xOrigin + (-0.6525f * scale), yOrigin + (-0.185f * scale));
		drawQuadrangle(
			xOrigin + (-0.6525f * scale), yOrigin + (-0.1525f * scale),
			xOrigin + (-0.6600f * scale), yOrigin + (-0.1550f * scale),
			xOrigin + (-0.6475f * scale), yOrigin + (-0.1825f * scale),
			xOrigin + (-0.6400f * scale), yOrigin + (-0.1800f * scale));
	}
}

void drawOdhani(float xOrigin, float yOrigin, float scale, int iHandPosition, int iStanding)
{
	if (iStanding == 1)
	{
		//Front
		//glColor4f(1.0f, 1.0f, 0.5f, 0.837f);
		//glColor4f(0.96f, 0.58f, 0.44f, 0.5f);
		//glColor4f(1.0f, 0.927f, 0.788f, 0.25f);
		glColor4f(1.0f, 0.51f, 0.71f, 0.75f);
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.9450f * scale), yOrigin + (-0.49f * scale));
		glVertex2f(xOrigin + (-0.9350f * scale), yOrigin + (-0.44f * scale));
		glVertex2f(xOrigin + (-0.9100f * scale), yOrigin + (-0.40f * scale));
		glVertex2f(xOrigin + (-0.8950f * scale), yOrigin + (-0.35f * scale));
		glVertex2f(xOrigin + (-0.8850f * scale), yOrigin + (-0.30f * scale));
		glVertex2f(xOrigin + (-0.8750f * scale), yOrigin + (-0.05f * scale));
		glVertex2f(xOrigin + (-0.8625f * scale), yOrigin + (0.050f * scale));
		glVertex2f(xOrigin + (-0.8500f * scale), yOrigin + (0.100f * scale));
		glVertex2f(xOrigin + (-0.8300f * scale), yOrigin + (0.150f * scale));
		glVertex2f(xOrigin + (-0.8100f * scale), yOrigin + (0.175f * scale));
		glVertex2f(xOrigin + (-0.7750f * scale), yOrigin + (0.187f * scale));
		glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (0.187f * scale));
		glVertex2f(xOrigin + (-0.7350f * scale), yOrigin + (0.181f * scale)); //top
		glVertex2f(xOrigin + (-0.7450f * scale), yOrigin + (0.150f * scale));
		glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (0.125f * scale));
		glVertex2f(xOrigin + (-0.7600f * scale), yOrigin + (0.075f * scale));
		glVertex2f(xOrigin + (-0.7750f * scale), yOrigin + (-0.075f * scale));
		glVertex2f(xOrigin + (-0.7800f * scale), yOrigin + (-0.300f * scale));
		glVertex2f(xOrigin + (-0.7900f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.8000f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.8050f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.8250f * scale), yOrigin + (-0.550f * scale));

		glEnd();



	}
	else
	{
		glColor4f(1.0f, 0.51f, 0.71f, 0.5f);
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.9450f * scale), yOrigin + (-0.49f * scale));
		glVertex2f(xOrigin + (-0.9350f * scale), yOrigin + (-0.44f * scale));
		glVertex2f(xOrigin + (-0.9100f * scale), yOrigin + (-0.40f * scale));
		glVertex2f(xOrigin + (-0.8950f * scale), yOrigin + (-0.35f * scale));
		glVertex2f(xOrigin + (-0.8850f * scale), yOrigin + (-0.30f * scale));
		glVertex2f(xOrigin + (-0.8750f * scale), yOrigin + (-0.05f * scale));
		glVertex2f(xOrigin + (-0.8625f * scale), yOrigin + (0.050f * scale));
		glVertex2f(xOrigin + (-0.8500f * scale), yOrigin + (0.100f * scale));
		glVertex2f(xOrigin + (-0.8300f * scale), yOrigin + (0.150f * scale));
		glVertex2f(xOrigin + (-0.8100f * scale), yOrigin + (0.175f * scale));
		glVertex2f(xOrigin + (-0.7750f * scale), yOrigin + (0.187f * scale));
		glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (0.187f * scale));
		glVertex2f(xOrigin + (-0.7350f * scale), yOrigin + (0.181f * scale)); //top
		glVertex2f(xOrigin + (-0.7450f * scale), yOrigin + (0.150f * scale));
		glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (0.125f * scale));
		glVertex2f(xOrigin + (-0.7600f * scale), yOrigin + (0.075f * scale));
		glVertex2f(xOrigin + (-0.7750f * scale), yOrigin + (-0.075f * scale));
		glVertex2f(xOrigin + (-0.7800f * scale), yOrigin + (-0.300f * scale));
		glVertex2f(xOrigin + (-0.7900f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.8000f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.8050f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.8250f * scale), yOrigin + (-0.550f * scale));

		glEnd();


	}

	if (iHandPosition == 3)
	{
		drawQuadrangle(
			xOrigin + (-0.6855f * scale), yOrigin + (-0.1600f * scale),
			xOrigin + (-0.6850f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.6750f * scale), yOrigin + (-0.1300f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.1675f * scale));
	}
	else
	{
		drawQuadrangle(
			xOrigin + (-0.6900f * scale), yOrigin + (-0.1900f * scale),
			xOrigin + (-0.6850f * scale), yOrigin + (-0.1500f * scale),
			xOrigin + (-0.6750f * scale), yOrigin + (-0.1300f * scale),
			xOrigin + (-0.6700f * scale), yOrigin + (-0.1675f * scale));
	}

	//Back
	//glColor4f(1.0f, 1.0f, 0.5f, 0.837f);
	drawQuadrangle(
		xOrigin + (-0.7400f * scale), yOrigin + (0.04f * scale),
		xOrigin + (-0.7150f * scale), yOrigin + (0.03f * scale),
		xOrigin + (-0.6875f * scale), yOrigin + (-0.075f * scale),
		xOrigin + (-0.7250f * scale), yOrigin + (-0.020f * scale));

	if (iStanding == 1)
	{

		glBegin(GL_POLYGON);
		if (iHandPosition == 3)
		{
			glVertex2f(xOrigin + (-0.6850f * scale), yOrigin + (-0.273f * scale)); ///
			glVertex2f(xOrigin + (-0.6535f * scale), yOrigin + (-0.240f * scale));
		}
		else
		{
			glVertex2f(xOrigin + (-0.6900f * scale), yOrigin + (-0.263f * scale)); ///
			glVertex2f(xOrigin + (-0.6575f * scale), yOrigin + (-0.223f * scale));
		}


		glVertex2f(xOrigin + (-0.6500f * scale), yOrigin + (-0.275f * scale));
		glVertex2f(xOrigin + (-0.6400f * scale), yOrigin + (-0.325f * scale));
		glVertex2f(xOrigin + (-0.6330f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.6300f * scale), yOrigin + (-0.400f * scale));
		glVertex2f(xOrigin + (-0.6280f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.6280f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.6350f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.6430f * scale), yOrigin + (-0.525f * scale));
		glEnd();

	}
	//line strips

	//front
	if (iStanding == 1)
	{
		//glColor4f(1.0f, 0.0f, 0.0f, 0.837f);
		glColor3f(0.62f, 0.463f, 0.51f);
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.735f * scale), yOrigin + (0.177f * scale)); //top
		glVertex2f(xOrigin + (-0.745f * scale), yOrigin + (0.150f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (0.125f * scale));
		glVertex2f(xOrigin + (-0.760f * scale), yOrigin + (0.075f * scale));
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.075f * scale));
		glVertex2f(xOrigin + (-0.780f * scale), yOrigin + (-0.300f * scale));
		glVertex2f(xOrigin + (-0.790f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.800f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.805f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.825f * scale), yOrigin + (-0.550f * scale));
		glVertex2f(xOrigin + (-0.945f * scale), yOrigin + (-0.490f * scale));
		glEnd();

	}
	else
	{
		glColor3f(0.62f, 0.463f, 0.51f);
		glLineWidth(2.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.735f * scale), yOrigin + (0.177f * scale)); //top
		glVertex2f(xOrigin + (-0.745f * scale), yOrigin + (0.150f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (0.125f * scale));
		glVertex2f(xOrigin + (-0.760f * scale), yOrigin + (0.075f * scale));
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.075f * scale));
		glVertex2f(xOrigin + (-0.780f * scale), yOrigin + (-0.300f * scale));
		glVertex2f(xOrigin + (-0.790f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.800f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.805f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.825f * scale), yOrigin + (-0.550f * scale));
		glVertex2f(xOrigin + (-0.945f * scale), yOrigin + (-0.490f * scale));
		glEnd();
	}
	//back
	glBegin(GL_LINE_STRIP);
	glVertex2f(xOrigin + (-0.7150f * scale), yOrigin + (0.03f * scale));
	glVertex2f(xOrigin + (-0.6875f * scale), yOrigin + (-0.075f * scale));
	glEnd();

	if (iHandPosition == 3)
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.675f * scale), yOrigin + (-0.1300f * scale));
		glVertex2f(xOrigin + (-0.670f * scale), yOrigin + (-0.1535f * scale));
		glEnd();
	}
	else
	{
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.675f * scale), yOrigin + (-0.1300f * scale));
		glVertex2f(xOrigin + (-0.670f * scale), yOrigin + (-0.1675f * scale));
		glEnd();
	}

	if (iStanding == 1)
	{
		glBegin(GL_LINE_STRIP);
		if (iHandPosition == 3)
		{
			glVertex2f(xOrigin + (-0.6535f * scale), yOrigin + (-0.240f * scale));
		}
		else
		{
			glVertex2f(xOrigin + (-0.6575f * scale), yOrigin + (-0.227f * scale));
		}

		glVertex2f(xOrigin + (-0.6500f * scale), yOrigin + (-0.275f * scale));
		glVertex2f(xOrigin + (-0.6400f * scale), yOrigin + (-0.325f * scale));
		glVertex2f(xOrigin + (-0.6330f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.6300f * scale), yOrigin + (-0.400f * scale));
		glVertex2f(xOrigin + (-0.6280f * scale), yOrigin + (-0.425f * scale));
		glVertex2f(xOrigin + (-0.6280f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.6350f * scale), yOrigin + (-0.500f * scale));
		glVertex2f(xOrigin + (-0.6430f * scale), yOrigin + (-0.525f * scale));
		glEnd();
	}
	else
	{
	}

	glLineWidth(1.0f);
}
