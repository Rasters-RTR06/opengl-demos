// header files
//#include <GL/freeglut.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <math.h>
//#include <stdio.h>

//#define PI 3.14159


//#define SKIN_COLOR                      \
//	{                                   \
//		glColor3f(0.98f, 0.75f, 0.54f); \
//	}

#define YUDHISHTHIR_DHOTI_COLOR        \
	{                                  \
		glColor3f(0.451f, 0.388f, 0.082f); \
}
		//glColor3f(0.9f, 0.8f, 0.278f); 	}

#define YUDHISHTHIR_SHOULDER_CLOTH_MAJOR {glColor3f(0.50f, 0.67f, 0.35f);}
#define YUDHISHTHIR_SHOULDER_CLOTH_MINOR {glColor3f(0.75f, 0.55f, 0.00f);}



void drawLineYu(float x1, float y1, float x2, float y2);
//void drawRectangleYu(float LX, float RX, float TY, float BY);
void drawQuadrangleYu(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void drawcircleYu(float, float, float, float, float, float, float, int);
//void drawcircle_(float, float, float, float, float, float, float, int);
void drawTriangleYu(float x1, float y1, float x2, float y2, float x3, float y3);

void drawYudhishthir(float xOrigin, float yOrigin, float scale, int iStanding, int iHandPosition);



// void display(void)
// {
// 	// Code

// 	// Clear OpenGl buufers
// 	glClear(GL_COLOR_BUFFER_BIT);

// 	drawYudhishthir(xOrigin, yOrigin, fScaleFactor);

// 	// Swap the buffers
// 	SwapBuffers(ghdc);
// }

// Draw Rectangle
//void drawRectangleYu(float LX, float RX, float TY, float BY)
//{
//	glBegin(GL_QUADS);
//	glVertex2f(LX, TY);
//	glVertex2f(RX, TY);
//	glVertex2f(RX, BY);
//	glVertex2f(LX, BY);
//	glEnd();
//}

void drawQuadrangleYu(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

// Draw Line
void drawLineYu(float x1, float y1, float x2, float y2)
{
	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glEnd();
}

void drawcircleYu(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
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

void drawTriangleYu(float x1, float y1, float x2, float y2, float x3, float y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();
}

void drawYudhishthir(float xOrigin, float yOrigin, float scale, int iStanding, int iHandPosition)
{
	void drawHead(float, float, float);
	void drawCommonBody(float, float, float, int);
	void drawHandAndCloth(float, float, float, int);
	void drawClothBackSide(float, float, float);

	drawClothBackSide(xOrigin, yOrigin, scale);
	drawHead(xOrigin, yOrigin, scale);
	drawCommonBody(xOrigin, yOrigin, scale, iStanding);    
	drawHandAndCloth(xOrigin, yOrigin, scale, iHandPosition); 
}

void drawHead(float xOrigin, float yOrigin, float scale)
{
	// hairs
	{
		glColor3f(0.0f, 0.0f, 0.0f);

		drawcircleYu(
			xOrigin + (-0.7850f * scale), yOrigin + (0.2550f * scale),
			(0.030f * scale), (0.020f * scale), 0.0f, 0.0f, 0.0f, 1);

		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.7900f * scale), yOrigin + (0.2650f * scale));
		glVertex2f(xOrigin + (-0.7950f * scale), yOrigin + (0.2200f * scale));
		glVertex2f(xOrigin + (-0.7900f * scale), yOrigin + (0.1800f * scale));
		glVertex2f(xOrigin + (-0.7825f * scale), yOrigin + (0.1500f * scale));
		glVertex2f(xOrigin + (-0.7625f * scale), yOrigin + (0.1900f * scale));
		glVertex2f(xOrigin + (-0.7625f * scale), yOrigin + (0.2200f * scale));
		glVertex2f(xOrigin + (-0.7250f * scale), yOrigin + (0.2600f * scale));
		glEnd();

		glColor3f(0.7f, 0.7f, 0.7f); // hair band
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7950f * scale), yOrigin + (0.2300f * scale));
		glVertex2f(xOrigin + (-0.7800f * scale), yOrigin + (0.2400f * scale));

		glVertex2f(xOrigin + (-0.7800f * scale), yOrigin + (0.2400f * scale));
		glVertex2f(xOrigin + (-0.7600f * scale), yOrigin + (0.2650f * scale));
		glEnd();
	}

	glColor3f(1.0f, 0.73f, 0.50f); // Face Skin 1

	glBegin(GL_POLYGON);
	glVertex2f(xOrigin + (-0.7825f * scale), yOrigin + (0.1500f * scale));
	glVertex2f(xOrigin + (-0.7350f * scale), yOrigin + (0.1000f * scale));
	glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.1200f * scale));
	glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.1450f * scale));
	glVertex2f(xOrigin + (-0.7000f * scale), yOrigin + (0.1450f * scale)); // nose cut
	glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.2000f * scale));
	glVertex2f(xOrigin + (-0.7070f * scale), yOrigin + (0.2050f * scale));
	glVertex2f(xOrigin + (-0.7120f * scale), yOrigin + (0.2500f * scale));
	glVertex2f(xOrigin + (-0.730f * scale), yOrigin + (0.2550f * scale));
	glEnd();
	drawTriangleYu(
		xOrigin + (-0.7300f * scale), yOrigin + (0.2550f * scale),
		xOrigin + (-0.7625f * scale), yOrigin + (0.2200f * scale),
		xOrigin + (-0.7625f * scale), yOrigin + (0.1750f * scale));

	// lips
	{
		glColor3f(0.5f, 0.5f, 0.5f);
		// glLineWidth(0.75f);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.1330f * scale));
		glVertex2f(xOrigin + (-0.7220f * scale), yOrigin + (0.1330f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7220f * scale), yOrigin + (0.1330f * scale));
		glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.1280f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7220f * scale), yOrigin + (0.1330f * scale));
		glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.1380f * scale));
		glEnd();
	}

	// eye
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		drawQuadrangleYu(
			xOrigin + (-0.7130f * scale), yOrigin + (0.2000f * scale),
			xOrigin + (-0.7200f * scale), yOrigin + (0.2080f * scale),
			xOrigin + (-0.7400f * scale), yOrigin + (0.2000f * scale),
			xOrigin + (-0.7200f * scale), yOrigin + (0.1920f * scale));

		glColor3f(0.5f, 0.5f, 0.5f);

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7130f * scale), yOrigin + (0.2000f * scale));
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.2080f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.2080f * scale));
		glVertex2f(xOrigin + (-0.7400f * scale), yOrigin + (0.2000f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7400f * scale), yOrigin + (0.2000f * scale));
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.1920f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.1920f * scale));
		glVertex2f(xOrigin + (-0.7130f * scale), yOrigin + (0.2000f * scale));
		glEnd();

		/*glColor3f(0.0f, 0.0f, 0.0f);
		glPointSize(4.0f);
		glBegin(GL_POINTS);
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.2000f * scale));
		glEnd();
		glPointSize(1.0f);*/
		drawcircleYu(
			xOrigin + (-0.7200f * scale), yOrigin + (0.2000f * scale),
			(0.004f * scale), (0.0035f * scale), 0.0f, 0.0f, 0.0f, 1);

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7130f * scale), yOrigin + (0.2150f * scale));
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.2200f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.2200f * scale));
		glVertex2f(xOrigin + (-0.7400f * scale), yOrigin + (0.2150f * scale));
		glEnd();
		/*glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7400f * scale), yOrigin + (0.2180f * scale));
		glVertex2f(xOrigin + (-0.7200f * scale), yOrigin + (0.2180f * scale));
		glEnd();*/
	}

	{
		glLineWidth(2.0f);
		glColor3f(1.0f, 0.337f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7180f * scale), yOrigin + (0.2400f * scale));
		glVertex2f(xOrigin + (-0.7160f * scale), yOrigin + (0.2300f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7160f * scale), yOrigin + (0.2300f * scale));
		glVertex2f(xOrigin + (-0.7090f * scale), yOrigin + (0.2260f * scale));
		glEnd();
		glLineWidth(1.0f);
	}

	{
		glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7700f * scale), yOrigin + (0.1750f * scale));
		glVertex2f(xOrigin + (-0.7700f * scale), yOrigin + (0.1500f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7700f * scale), yOrigin + (0.1500f * scale));
		glVertex2f(xOrigin + (-0.7650f * scale), yOrigin + (0.1400f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7600f * scale), yOrigin + (0.1500f * scale));
		glVertex2f(xOrigin + (-0.7650f * scale), yOrigin + (0.1400f * scale));
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.7650f * scale), yOrigin + (0.1400f * scale));
		glVertex2f(xOrigin + (-0.7650f * scale), yOrigin + (0.1300f * scale));
		glEnd();

		/*drawcircleYu(
			xOrigin + (-0.7650f * scale), yOrigin + (0.1250f * scale),
			(0.01f * scale), (0.01f * scale), 0.33f, 0.11f, 0.0f, 1);*/
	}
}

void drawClothBackSide(float xOrigin, float yOrigin, float scale)
{
	{
		YUDHISHTHIR_SHOULDER_CLOTH_MAJOR
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.844f * scale), yOrigin + (-0.050f * scale));
		glVertex2f(xOrigin + (-0.844f * scale), yOrigin + (-0.200f * scale));
		glVertex2f(xOrigin + (-0.860f * scale), yOrigin + (-0.350f * scale));
		glVertex2f(xOrigin + (-0.835f * scale), yOrigin + (-0.350f * scale));
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.250f * scale));

		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.080f * scale));
		glEnd();

		drawTriangleYu(
			xOrigin + (-0.860f * scale), yOrigin + (-0.350f * scale),
			xOrigin + (-0.835f * scale), yOrigin + (-0.350f * scale),
			xOrigin + (-0.834f * scale), yOrigin + (-0.375f * scale));

		glLineWidth(5.0f);
		YUDHISHTHIR_SHOULDER_CLOTH_MINOR
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.834f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.860f * scale), yOrigin + (-0.350f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.860f * scale), yOrigin + (-0.350f * scale));
		glVertex2f(xOrigin + (-0.850f * scale), yOrigin + (-0.200f * scale));
		glEnd();

		glBegin(GL_LINES);

		glVertex2f(xOrigin + (-0.850f * scale), yOrigin + (-0.200f * scale));
		glVertex2f(xOrigin + (-0.844f * scale), yOrigin + (-0.059f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
}

void drawCommonBody(float xOrigin, float yOrigin, float scale, int iStanding)
{
	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
	// neck
	drawQuadrangleYu(
		xOrigin + (-0.7825f * scale), yOrigin + (0.0800f * scale),
		xOrigin + (-0.7825f * scale), yOrigin + (0.1500f * scale),
		xOrigin + (-0.7350f * scale), yOrigin + (0.1000f * scale),
		xOrigin + (-0.7350f * scale), yOrigin + (0.0800f * scale));

	glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
	// Torso
	glBegin(GL_POLYGON);
	glVertex2f(xOrigin + (-0.835f * scale), yOrigin + (0.050f * scale));
	glVertex2f(xOrigin + (-0.7825f * scale), yOrigin + (0.0800f * scale));
	glVertex2f(xOrigin + (-0.735f * scale), yOrigin + (0.0800f * scale));
	glVertex2f(xOrigin + (-0.680f * scale), yOrigin + (0.050f * scale));
	glVertex2f(xOrigin + (-0.685f * scale), yOrigin + (-0.25f * scale));
	glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.25f * scale));
	glEnd();

	if (iStanding == 1)
	{
		glColor3f(0.98f, 0.75f, 0.54f); // Skin 1
		// glColor3f(0.851f, 0.236f, 0.427f);//pink
		// back leg lower
		drawTriangleYu(
			xOrigin + (-0.820f * scale), yOrigin + (-0.55f * scale),
			xOrigin + (-0.830f * scale), yOrigin + (-0.45f * scale),
			xOrigin + (-0.765f * scale), yOrigin + (-0.55f * scale));
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.65f * scale));
		glVertex2f(xOrigin + (-0.820f * scale), yOrigin + (-0.55f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.55f * scale));
		glVertex2f(xOrigin + (-0.783f * scale), yOrigin + (-0.83f * scale));
		glVertex2f(xOrigin + (-0.818f * scale), yOrigin + (-0.83f * scale));
		glEnd();
		// front leg lower
		drawTriangleYu(
			xOrigin + (-0.747f * scale), yOrigin + (-0.550f * scale),
			xOrigin + (-0.750f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.550f * scale));
		drawQuadrangleYu(
			xOrigin + (-0.740f * scale), yOrigin + (-0.830f * scale),
			xOrigin + (-0.695f * scale), yOrigin + (-0.825f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.550f * scale),
			xOrigin + (-0.747f * scale), yOrigin + (-0.550f * scale));

		// glColor3f(0.98f, 0.75f, 0.54f); //Skin 1
		SKIN_COLOR
			// Back foot
			drawQuadrangleYu(
				xOrigin + (-0.83f * scale), yOrigin + (-0.85f * scale),
				xOrigin + (-0.818f * scale), yOrigin + (-0.83f * scale),
				xOrigin + (-0.783f * scale), yOrigin + (-0.83f * scale),
				xOrigin + (-0.78f * scale), yOrigin + (-0.85f * scale));

		drawQuadrangleYu(
			xOrigin + (-0.83f * scale), yOrigin + (-0.85f * scale),
			xOrigin + (-0.78f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.74f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.78f * scale), yOrigin + (-0.85f * scale));

		// front foot
		drawQuadrangleYu(
			xOrigin + (-0.745f * scale), yOrigin + (-0.850f * scale),
			xOrigin + (-0.740f * scale), yOrigin + (-0.830f * scale),
			xOrigin + (-0.695f * scale), yOrigin + (-0.825f * scale),
			xOrigin + (-0.688f * scale), yOrigin + (-0.837f * scale));

		drawQuadrangleYu(
			xOrigin + (-0.745f * scale), yOrigin + (-0.850f * scale),
			xOrigin + (-0.660f * scale), yOrigin + (-0.900f * scale),
			xOrigin + (-0.628f * scale), yOrigin + (-0.870f * scale),
			xOrigin + (-0.688f * scale), yOrigin + (-0.837f * scale));

		// fingers
		glColor3f(0.6f, 0.6f, 0.6f);
		// back
		drawLineYu(
			xOrigin + (-0.750f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.765f * scale), yOrigin + (-0.91f * scale));
		drawLineYu(
			xOrigin + (-0.758f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.773f * scale), yOrigin + (-0.91f * scale));
		drawLineYu(
			xOrigin + (-0.766f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.781f * scale), yOrigin + (-0.91f * scale));
		drawLineYu(
			xOrigin + (-0.774f * scale), yOrigin + (-0.93f * scale),
			xOrigin + (-0.789f * scale), yOrigin + (-0.91f * scale));

		// front
		drawLineYu(
			xOrigin + (-0.65f * scale), yOrigin + (-0.89f * scale),
			xOrigin + (-0.67f * scale), yOrigin + (-0.878f * scale));
		drawLineYu(
			xOrigin + (-0.645f * scale), yOrigin + (-0.885f * scale),
			xOrigin + (-0.665f * scale), yOrigin + (-0.873f * scale));
		drawLineYu(
			xOrigin + (-0.64f * scale), yOrigin + (-0.88f * scale),
			xOrigin + (-0.66f * scale), yOrigin + (-0.868f * scale));
		drawLineYu(
			xOrigin + (-0.635f * scale), yOrigin + (-0.875f * scale),
			xOrigin + (-0.655f * scale), yOrigin + (-0.863f * scale));

		// Dhoti
		YUDHISHTHIR_DHOTI_COLOR

			glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.835f * scale), yOrigin + (-0.35f * scale));
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.25f * scale));
		glVertex2f(xOrigin + (-0.685f * scale), yOrigin + (-0.25f * scale));
		glVertex2f(xOrigin + (-0.680f * scale), yOrigin + (-0.35f * scale));
		glVertex2f(xOrigin + (-0.683f * scale), yOrigin + (-0.45f * scale));
		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.45f * scale));
		glEnd();

		drawTriangleYu(
			xOrigin + (-0.750f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.683f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.690f * scale), yOrigin + (-0.550f * scale));
		drawTriangleYu(
			xOrigin + (-0.833f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.750f * scale), yOrigin + (-0.450f * scale),
			xOrigin + (-0.765f * scale), yOrigin + (-0.550f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.770f * scale), yOrigin + (-0.400f * scale));
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.755f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.755f * scale), yOrigin + (-0.600f * scale));
		glVertex2f(xOrigin + (-0.730f * scale), yOrigin + (-0.612f * scale));
		glVertex2f(xOrigin + (-0.736f * scale), yOrigin + (-0.425f * scale));
		glEnd();

		// Border Lines
		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.768f * scale), yOrigin + (-0.250f * scale));

		glVertex2f(xOrigin + (-0.730f * scale), yOrigin + (-0.612f * scale));
		glVertex2f(xOrigin + (-0.740f * scale), yOrigin + (-0.250f * scale));

		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.731f * scale), yOrigin + (-0.530f * scale));

		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.731f * scale), yOrigin + (-0.575f * scale));

		glVertex2f(xOrigin + (-0.731f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.755f * scale), yOrigin + (-0.600f * scale));

		glVertex2f(xOrigin + (-0.755f * scale), yOrigin + (-0.600f * scale));
		glVertex2f(xOrigin + (-0.730f * scale), yOrigin + (-0.612f * scale));
		glEnd();

		glLineWidth(3.0f);

		glColor3f(0.63f, 0.53f, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.685f * scale), yOrigin + (-0.250f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.740f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.731f * scale), yOrigin + (-0.530f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.731f * scale), yOrigin + (-0.530f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.731f * scale), yOrigin + (-0.575f * scale));
		glVertex2f(xOrigin + (-0.755f * scale), yOrigin + (-0.600f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.775f * scale), yOrigin + (-0.540f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.735f * scale), yOrigin + (-0.465f * scale));
		glVertex2f(xOrigin + (-0.690f * scale), yOrigin + (-0.550f * scale));
		glEnd();

		glLineWidth(1.0f);
	}
	else
	{
		// Dhoti
		YUDHISHTHIR_DHOTI_COLOR

			glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.930f * scale), yOrigin + (-0.40f * scale));
		glVertex2f(xOrigin + (-0.930f * scale), yOrigin + (-0.32f * scale));
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.25f * scale));
		glVertex2f(xOrigin + (-0.685f * scale), yOrigin + (-0.25f * scale));
		glVertex2f(xOrigin + (-0.565f * scale), yOrigin + (-0.32f * scale));
		glVertex2f(xOrigin + (-0.565f * scale), yOrigin + (-0.40f * scale));
		glVertex2f(xOrigin + (-0.683f * scale), yOrigin + (-0.45f * scale));
		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.45f * scale));
		glEnd();

		// knee1
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.930f * scale), yOrigin + (-0.320f * scale));
		glVertex2f(xOrigin + (-0.945f * scale), yOrigin + (-0.345f * scale));
		glVertex2f(xOrigin + (-0.945f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.930f * scale), yOrigin + (-0.400f * scale));
		glEnd();
		// knee2
		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.565f * scale), yOrigin + (-0.320f * scale));
		glVertex2f(xOrigin + (-0.550f * scale), yOrigin + (-0.345f * scale));
		glVertex2f(xOrigin + (-0.550f * scale), yOrigin + (-0.375f * scale));
		glVertex2f(xOrigin + (-0.565f * scale), yOrigin + (-0.400f * scale));
		glEnd();

		SKIN_COLOR
			drawQuadrangleYu(
				xOrigin + (-0.770f * scale), yOrigin + (-0.450f * scale),
				xOrigin + (-0.770f * scale), yOrigin + (-0.373f * scale),
				xOrigin + (-0.625f * scale), yOrigin + (-0.350f * scale),
				xOrigin + (-0.683f * scale), yOrigin + (-0.450f * scale));

		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.770f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.770f * scale), yOrigin + (-0.373f * scale));
		glVertex2f(xOrigin + (-0.825f * scale), yOrigin + (-0.355f * scale));
		glVertex2f(xOrigin + (-0.885f * scale), yOrigin + (-0.350f * scale));
		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.450f * scale));
		glEnd();

		YUDHISHTHIR_DHOTI_COLOR
			// leg1
			drawQuadrangleYu(
				xOrigin + (-0.625f * scale), yOrigin + (-0.350f * scale),
				xOrigin + (-0.650f * scale), yOrigin + (-0.360f * scale),
				xOrigin + (-0.676f * scale), yOrigin + (-0.410f * scale),
				xOrigin + (-0.683f * scale), yOrigin + (-0.450f * scale));
		// leg2
		drawQuadrangleYu(
			xOrigin + (-0.885f * scale), yOrigin + (-0.350f * scale),
			xOrigin + (-0.860f * scale), yOrigin + (-0.360f * scale),
			xOrigin + (-0.840f * scale), yOrigin + (-0.410f * scale),
			xOrigin + (-0.833f * scale), yOrigin + (-0.450f * scale));

		glLineWidth(3.0f);

		glColor3f(0.63f, 0.53f, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.740f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.735f * scale), yOrigin + (-0.370f * scale));
		glEnd();

		glBegin(GL_LINE_STRIP); // waist
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.685f * scale), yOrigin + (-0.250f * scale));
		glEnd();

		// leg1
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.683f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.676f * scale), yOrigin + (-0.410f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.676f * scale), yOrigin + (-0.410f * scale));
		glVertex2f(xOrigin + (-0.650f * scale), yOrigin + (-0.360f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.650f * scale), yOrigin + (-0.360f * scale));
		glVertex2f(xOrigin + (-0.625f * scale), yOrigin + (-0.350f * scale));
		glEnd();

		// leg2
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.450f * scale));
		glVertex2f(xOrigin + (-0.840f * scale), yOrigin + (-0.410f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.840f * scale), yOrigin + (-0.410f * scale));
		glVertex2f(xOrigin + (-0.860f * scale), yOrigin + (-0.360f * scale));
		glEnd();
		glBegin(GL_LINE_STRIP);
		glVertex2f(xOrigin + (-0.860f * scale), yOrigin + (-0.360f * scale));
		glVertex2f(xOrigin + (-0.885f * scale), yOrigin + (-0.350f * scale));
		glEnd();
		glLineWidth(1.0f);

		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.768f * scale), yOrigin + (-0.250f * scale));
		glVertex2f(xOrigin + (-0.773f * scale), yOrigin + (-0.370f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.770f * scale), yOrigin + (-0.373f * scale));
		glVertex2f(xOrigin + (-0.625f * scale), yOrigin + (-0.350f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.770f * scale), yOrigin + (-0.373f * scale));
		glVertex2f(xOrigin + (-0.825f * scale), yOrigin + (-0.355f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.825f * scale), yOrigin + (-0.355f * scale));
		glVertex2f(xOrigin + (-0.885f * scale), yOrigin + (-0.350f * scale));
		glEnd();
	}
}

void drawHandAndCloth(float xOrigin, float yOrigin, float scale, int iHandPosition)
{
	// Ear rudraksh
	drawcircleYu(
		xOrigin + (-0.7650f * scale), yOrigin + (0.1300f * scale),
		(0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

	// beard
	glColor3f(0.0f, 0.0f, 0.0f);
	drawQuadrangleYu(
		xOrigin + (-0.775f * scale), yOrigin + (0.20f * scale),
		xOrigin + (-0.765f * scale), yOrigin + (0.20f * scale),
		xOrigin + (-0.740f * scale), yOrigin + (0.10f * scale),
		xOrigin + (-0.710f * scale), yOrigin + (0.12f * scale));

	drawQuadrangleYu(
		xOrigin + (-0.740f * scale), yOrigin + (0.100f * scale),
		xOrigin + (-0.710f * scale), yOrigin + (0.120f * scale),
		xOrigin + (-0.708f * scale), yOrigin + (0.070f * scale),
		xOrigin + (-0.715f * scale), yOrigin + (0.080f * scale));


	glLineWidth(2.5f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7100f * scale), yOrigin + (0.1420f * scale));
	glVertex2f(xOrigin + (-0.7320f * scale), yOrigin + (0.1370f * scale));
	glEnd();

	//neck thread
	glColor3f(0.63f, 0.53f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7825f * scale), yOrigin + (0.0800f * scale));
	glVertex2f(xOrigin + (-0.7650f * scale), yOrigin + (0.0700f * scale));
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7650f * scale), yOrigin + (0.0700f * scale));
	glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (0.0700f * scale));
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (0.0700f * scale));
	glVertex2f(xOrigin + (-0.7350f * scale), yOrigin + (0.0800f * scale));
	glEnd();

	//locket 
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7825f * scale), yOrigin + (0.0800f * scale));
	glVertex2f(xOrigin + (-0.7700f * scale), yOrigin + (0.0000f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7700f * scale), yOrigin + (0.0000f * scale));
	glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (-0.0500f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7500f * scale), yOrigin + (-0.0500f * scale));
	glVertex2f(xOrigin + (-0.7400f * scale), yOrigin + (-0.0200f * scale));
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(xOrigin + (-0.7400f * scale), yOrigin + (-0.0200f * scale));
	glVertex2f(xOrigin + (-0.7350f * scale), yOrigin + (0.0800f * scale));
	glEnd();

	drawcircleYu(
		xOrigin + (-0.750f * scale), yOrigin + (-0.0500f * scale),
		(0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

	{
		//shoulder cloth
		YUDHISHTHIR_SHOULDER_CLOTH_MAJOR

			drawQuadrangleYu(
				xOrigin + (-0.680f * scale), yOrigin + (0.051f * scale),
				xOrigin + (-0.720f * scale), yOrigin + (0.071f * scale),
				xOrigin + (-0.760f * scale), yOrigin + (-0.325f * scale),
				xOrigin + (-0.720f * scale), yOrigin + (-0.345f * scale));


		glLineWidth(5.0f);
		YUDHISHTHIR_SHOULDER_CLOTH_MINOR
			glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (0.071f * scale));
		glVertex2f(xOrigin + (-0.760f * scale), yOrigin + (-0.325f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.760f * scale), yOrigin + (-0.325f * scale));
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (-0.345f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.680f * scale), yOrigin + (0.051f * scale));
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (-0.345f * scale));
		glEnd();

		glLineWidth(1.0f);

		YUDHISHTHIR_SHOULDER_CLOTH_MAJOR

			glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.800f * scale), yOrigin + (0.075f * scale));
		glVertex2f(xOrigin + (-0.830f * scale), yOrigin + (0.060f * scale));
		glVertex2f(xOrigin + (-0.800f * scale), yOrigin + (0.015f * scale));
		glVertex2f(xOrigin + (-0.780f * scale), yOrigin + (-0.035f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.090f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.050f * scale));
		glEnd();

		glBegin(GL_POLYGON);
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.090f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.050f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.090f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.140f * scale));
		glVertex2f(xOrigin + (-0.745f * scale), yOrigin + (-0.160f * scale));
		glVertex2f(xOrigin + (-0.700f * scale), yOrigin + (-0.080f * scale));
		glEnd();

		glLineWidth(5.0f);
		YUDHISHTHIR_SHOULDER_CLOTH_MINOR
			glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.800f * scale), yOrigin + (0.075f * scale));
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.050f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.765f * scale), yOrigin + (-0.050f * scale));
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.090f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.750f * scale), yOrigin + (-0.090f * scale));
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (-0.080f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (-0.080f * scale));
		glVertex2f(xOrigin + (-0.690f * scale), yOrigin + (-0.050f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.749f * scale), yOrigin + (-0.155f * scale));
		glVertex2f(xOrigin + (-0.740f * scale), yOrigin + (-0.150f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.740f * scale), yOrigin + (-0.150f * scale));
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (-0.145f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.720f * scale), yOrigin + (-0.145f * scale));
		glVertex2f(xOrigin + (-0.710f * scale), yOrigin + (-0.135f * scale));
		glEnd();

		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.710f * scale), yOrigin + (-0.135f * scale));
		glVertex2f(xOrigin + (-0.695f * scale), yOrigin + (-0.095f * scale));
		glEnd();

		glLineWidth(1.0f);
	}

	{
		SKIN_COLOR
			//Hands
			drawQuadrangleYu(
				xOrigin + (-0.835f * scale), yOrigin + (0.050f * scale),
				xOrigin + (-0.845f * scale), yOrigin + (0.0166f * scale),
				xOrigin + (-0.844f * scale), yOrigin + (-0.050f * scale),
				xOrigin + (-0.833f * scale), yOrigin + (-0.080f * scale)
			);

		glColor3f(0.5f, 0.5f, 0.5f);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.833f * scale), yOrigin + (-0.080f * scale));
		glVertex2f(xOrigin + (-0.760f * scale), yOrigin + (-0.235f * scale));
		glEnd();


		//Back side hand
		glColor3f(1.0f, 0.73f, 0.50f); //Face Skin 1
		drawQuadrangleYu(
			xOrigin + (-0.6550f * scale), yOrigin + (-0.250f * scale),
			xOrigin + (-0.6875f * scale), yOrigin + (-0.160f * scale),
			xOrigin + (-0.6800f * scale), yOrigin + (0.050f * scale),
			xOrigin + (-0.6550f * scale), yOrigin + (-0.1350f * scale)
		);

		drawQuadrangleYu(
			xOrigin + (-0.6250f * scale), yOrigin + (-0.075f * scale),
			xOrigin + (-0.6550f * scale), yOrigin + (-0.1350f * scale),
			xOrigin + (-0.6550f * scale), yOrigin + (-0.250f * scale),
			xOrigin + (-0.6100f * scale), yOrigin + (-0.095f * scale)
		);

		drawTriangleYu(
			xOrigin + (-0.6250f * scale), yOrigin + (-0.075f * scale),
			xOrigin + (-0.6100f * scale), yOrigin + (-0.095f * scale),
			xOrigin + (-0.6000f * scale), yOrigin + (-0.080f * scale)
		);

		drawQuadrangleYu(
			xOrigin + (-0.6250f * scale), yOrigin + (-0.075f * scale),
			xOrigin + (-0.6000f * scale), yOrigin + (-0.080f * scale),
			xOrigin + (-0.5950f * scale), yOrigin + (-0.010f * scale),
			xOrigin + (-0.6175f * scale), yOrigin + (0.020f * scale));

		drawTriangleYu(
			xOrigin + (-0.5950f * scale), yOrigin + (-0.010f * scale),
			xOrigin + (-0.6175f * scale), yOrigin + (0.020f * scale),
			xOrigin + (-0.6050f * scale), yOrigin + (0.024f * scale)); //finger tips

		if (iHandPosition == 1)
		{
			drawQuadrangleYu(
				xOrigin + (-0.6250f * scale), yOrigin + (-0.075f * scale),
				xOrigin + (-0.6300f * scale), yOrigin + (-0.050f * scale),
				xOrigin + (-0.6275f * scale), yOrigin + (-0.010f * scale),
				xOrigin + (-0.6100f * scale), yOrigin + (-0.010f * scale)); //thumb
		}
		else
		{
			drawQuadrangleYu(
				xOrigin + (-0.6249f * scale), yOrigin + (-0.075f * scale),
				xOrigin + (-0.6400f * scale), yOrigin + (-0.010f * scale),
				xOrigin + (-0.6350f * scale), yOrigin + (-0.010f * scale),
				xOrigin + (-0.6200f * scale), yOrigin + (-0.036f * scale)); //thumb
		}

		//fingers
		{
			glColor3f(0.6f, 0.6f, 0.6f);
			if (iHandPosition == 1)
			{
				glBegin(GL_LINES);
				glVertex2f(xOrigin + (-0.6190f * scale), yOrigin + (-0.006f * scale));
				glVertex2f(xOrigin + (-0.6230f * scale), yOrigin + (-0.036f * scale));
				glEnd();
			}

			glBegin(GL_LINES);
			glVertex2f(xOrigin + (-0.6100f * scale), yOrigin + (0.019f * scale));
			glVertex2f(xOrigin + (-0.6140f * scale), yOrigin + (-0.024f * scale));
			glEnd();

			glBegin(GL_LINES);
			glVertex2f(xOrigin + (-0.6030f * scale), yOrigin + (0.013f * scale));
			glVertex2f(xOrigin + (-0.6070f * scale), yOrigin + (-0.030f * scale));
			glEnd();

			glBegin(GL_LINES);
			glVertex2f(xOrigin + (-0.5980f * scale), yOrigin + (0.001f * scale));
			glVertex2f(xOrigin + (-0.6020f * scale), yOrigin + (-0.036f * scale));
			glEnd();
		}

		if (iHandPosition == 1)
		{
			//front side hand
			SKIN_COLOR

				drawQuadrangleYu(
					xOrigin + (-0.6275f * scale), yOrigin + (-0.075f * scale),
					xOrigin + (-0.7500f * scale), yOrigin + (-0.160f * scale),
					xOrigin + (-0.7600f * scale), yOrigin + (-0.235f * scale),
					xOrigin + (-0.6125f * scale), yOrigin + (-0.100f * scale));

			drawTriangleYu(
				xOrigin + (-0.6275f * scale), yOrigin + (-0.075f * scale),
				xOrigin + (-0.6125f * scale), yOrigin + (-0.100f * scale),
				xOrigin + (-0.6000f * scale), yOrigin + (-0.080f * scale));

			drawQuadrangleYu(
				xOrigin + (-0.6250f * scale), yOrigin + (-0.075f * scale),
				xOrigin + (-0.6000f * scale), yOrigin + (-0.080f * scale),
				xOrigin + (-0.5950f * scale), yOrigin + (-0.010f * scale),
				xOrigin + (-0.6175f * scale), yOrigin + (0.020f * scale));

			drawTriangleYu(
				xOrigin + (-0.5950f * scale), yOrigin + (-0.010f * scale),
				xOrigin + (-0.6175f * scale), yOrigin + (0.020f * scale),
				xOrigin + (-0.6050f * scale), yOrigin + (0.024f * scale)); //finger tips

			drawQuadrangleYu(
				xOrigin + (-0.6250f * scale), yOrigin + (-0.075f * scale),
				xOrigin + (-0.6300f * scale), yOrigin + (-0.050f * scale),
				xOrigin + (-0.6275f * scale), yOrigin + (-0.010f * scale),
				xOrigin + (-0.6100f * scale), yOrigin + (-0.010f * scale)); //thumb

			//fingers
			{
				glColor3f(0.6f, 0.6f, 0.6f);
				glBegin(GL_LINES);
				glVertex2f(xOrigin + (-0.6190f * scale), yOrigin + (-0.006f * scale));
				glVertex2f(xOrigin + (-0.6230f * scale), yOrigin + (-0.036f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOrigin + (-0.6100f * scale), yOrigin + (0.019f * scale));
				glVertex2f(xOrigin + (-0.6140f * scale), yOrigin + (-0.024f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOrigin + (-0.6030f * scale), yOrigin + (0.013f * scale));
				glVertex2f(xOrigin + (-0.6070f * scale), yOrigin + (-0.030f * scale));
				glEnd();

				glBegin(GL_LINES);
				glVertex2f(xOrigin + (-0.5980f * scale), yOrigin + (0.001f * scale));
				glVertex2f(xOrigin + (-0.6020f * scale), yOrigin + (-0.036f * scale));
				glEnd();
			}
		}
		else
		{
			SKIN_COLOR
				drawQuadrangleYu(
					xOrigin + (-0.6275f * scale), yOrigin + (-0.170f * scale),
					xOrigin + (-0.7500f * scale), yOrigin + (-0.160f * scale),
					xOrigin + (-0.7600f * scale), yOrigin + (-0.235f * scale),
					xOrigin + (-0.6275f * scale), yOrigin + (-0.195f * scale));

			drawQuadrangleYu(
				xOrigin + (-0.6275f * scale), yOrigin + (-0.170f * scale),
				xOrigin + (-0.5900f * scale), yOrigin + (-0.180f * scale),
				xOrigin + (-0.5900f * scale), yOrigin + (-0.200f * scale),
				xOrigin + (-0.6275f * scale), yOrigin + (-0.195f * scale));

			drawQuadrangleYu(
				xOrigin + (-0.5900f * scale), yOrigin + (-0.180f * scale),
				xOrigin + (-0.5700f * scale), yOrigin + (-0.170f * scale),
				xOrigin + (-0.5720f * scale), yOrigin + (-0.180f * scale),
				xOrigin + (-0.5900f * scale), yOrigin + (-0.200f * scale));

			drawTriangleYu(
				xOrigin + (-0.6275f * scale), yOrigin + (-0.170f * scale),
				xOrigin + (-0.6000f * scale), yOrigin + (-0.150f * scale),
				xOrigin + (-0.6100f * scale), yOrigin + (-0.195f * scale));
		}
	}

	{

		glColor3f(0.0f, 0.0f, 0.0f);
		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.815f * scale), yOrigin + (-0.12f * scale));
		glVertex2f(xOrigin + (-0.767f * scale), yOrigin + (-0.08f * scale));
		glEnd();

		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.818f * scale), yOrigin + (-0.11f * scale));
		glVertex2f(xOrigin + (-0.768f * scale), yOrigin + (-0.07f * scale));
		glEnd();

		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.68f * scale), yOrigin + (-0.10f * scale));
		glVertex2f(xOrigin + (-0.662f * scale), yOrigin + (-0.08f * scale));
		glEnd();

		glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex2f(xOrigin + (-0.68f * scale), yOrigin + (-0.09f * scale));
		glVertex2f(xOrigin + (-0.663f * scale), yOrigin + (-0.07f * scale));
		glEnd();
	}
}

