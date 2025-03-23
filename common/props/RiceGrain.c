
//Use drawRiceGrain() function to call draw 

// Win32 headers
#include "../common.h"
#include "props.h"

void drawRiceGrain(void);


void drawRiceGrain(void)
{
	SHAPE riceGrain;
	riceGrain.noOfPoints = 7;


	MY_POINT Origin;
	Origin.x = 0.0f;
	Origin.y = 0.0f;
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