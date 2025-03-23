// Win32 headers
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
//#define PI 3.14159

// OpenGL related header file
#include <gl/GL.h>

// global function declarations
extern float plateResize;
float plateResize = 0.1;
void DrawPlateEP(float fOriginX, float fOriginY, float fResize);

// function declarations
void drawEllipseEP(
	float startX, float startY, 
	float startAngle, float endAngle, 
	float rColor, float gColor, float bColor, 
	float hRadius, float vRadius);

void drawEllipsePolyEP(
	float startX, float startY, 
	float startAngle, float endAngle, 
	float rColor, float gColor, float bColor, 
	float hRadius, float vRadius);

void DrawPlateEP(float fOriginX, float fOriginY, float fResize)
{
	plateResize = fResize;
	fOriginX += 0.1f;
	fOriginY += 0.1f;

	drawEllipsePolyEP(
		fOriginX, fOriginY - 0.03f, 
		0, 360, 	
		0.94f, 0.7f, 0.04f,
		0.2f, 0.15f);

	drawEllipseEP(
		fOriginX, fOriginY, 
		0, 360, 	
		0.68f, 0.27f, 0.04f,
		0.2f, 0.15f);

	drawEllipsePolyEP(
		fOriginX, fOriginY, 
		0, 360, 	
		0.94f, 0.7f, 0.04f,
		0.2f, 0.15f);

	drawEllipseEP(
		fOriginX, fOriginY - 0.03f, 
		0, 360, 	
		0.68f, 0.27f, 0.04f,
		0.2f, 0.15f);


	drawEllipseEP(
		fOriginX, fOriginY - 0.015f, 
		0, 360, 	
		0.3f, 0.28f, 0.27f, 
		0.05f, 0.04f);

	drawEllipseEP(
		fOriginX, fOriginY - 0.015f, 
		0, 360, 	
		0.3f, 0.28f, 0.27f,  
		0.08f, 0.04f);

	drawEllipseEP(
		fOriginX, fOriginY - 0.015f, 
		0, 360, 	
		0.3f, 0.28f, 0.27f, 
		0.008f, 0.006f);

	drawEllipseEP(
		fOriginX, fOriginY - 0.015f, 
		0, 360, 	
		0.3f, 0.28f, 0.27f, 
		0.016f, 0.012f);

	drawEllipseEP(
		fOriginX, fOriginY, 
		0, 360, 	
		0.68f, 0.27f, 0.04f,
		0.2f, 0.15f);
}

void drawEllipseEP(
	float startX, float startY, 
	float startAngle, float endAngle, 
	float rColor, float gColor, float bColor, 
	float hRadius, float vRadius)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;

	glColor4f(rColor, gColor, bColor, 1.0f);

	glLineWidth(1.5f);
	glBegin(GL_LINE_STRIP);

	//vRadius *= plateResize;

	for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.001f)
	{
		ObjX = startX + (hRadius * cos(ObjAngle)) * plateResize;
		ObjY = startY + (vRadius * sin(ObjAngle)) * plateResize;

		glVertex3f(ObjX , ObjY , 1.0f);
	}
	glEnd();
}

void drawEllipsePolyEP(
	float startX, float startY, 
	float startAngle, float endAngle, 
	float rColor, float gColor, float bColor, 
	float hRadius, float vRadius)
{
	float ObjX = 0.0f;
	float ObjY = 0.0f;
	float ObjAngle = 0.0f;
    //vRadius *= plateResize;
	glColor4f(rColor, gColor, bColor, 1.0f);

	//glLineWidth(5.0f);
	glBegin(GL_POLYGON);

	for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.001f)
	{
		ObjX = startX + (hRadius * cos(ObjAngle)) * plateResize;
		ObjY = startY + (vRadius * sin(ObjAngle)) * plateResize;

		glVertex3f(ObjX , ObjY , 1.0f);
	}
	glEnd();
}