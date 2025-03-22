#include "plate.h"


void drawPlate(void) {
    // code
    // plate
    glPushMatrix();
    glTranslated(-0.65, 0.0, 0.0);
    glScaled(0.22, 0.22, 0.0);
    drawCardioidP(73, 130, 65);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.65, 0.0, 0.0);
    glScaled(0.215, 0.215, 0.0);
    drawCardioidP(32, 97, 20);       //function called
    glPopMatrix();

    // yellow bowl
    glPushMatrix();
    glTranslated(-0.50, 0.25, 0.0);
    glScaled(0.085, 0.085, 0.0);
    drawCircleP(133, 133, 133);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.50, 0.25, 0.0);
    glScaled(0.08, 0.08, 0.0);
    drawCircleP(250, 194, 25);       //function called
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawCircleP(232, 252, 238);       //function called
    glPopMatrix();

    // bowl - 1
    glPushMatrix();
    glTranslated(0.6, 0.6, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawSemiCircleP(51, 107, 41);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6, 0.6, 0.0);
    glScaled(0.15, 0.03, 0.0);
    drawCircleP(42, 94, 32);       //function called
    glPopMatrix();

    // bowl - 2
    glPushMatrix();
    glTranslated(0.6, -0.5, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawSemiCircleP(51, 107, 41);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6, -0.5, 0.0);
    glScaled(0.15, 0.03, 0.0);
    drawCircleP(42, 94, 32);       //function called
    glPopMatrix();
}

void drawCircleP(float r, float g, float b)
{
    // local variables declaration
  //  const double PI = 3.1459;
    double x, y;
    double radius = 2.0;
    double radian_angle;

    //set the foreground color
	glColor3ub (r, g, b);

    glBegin(GL_POLYGON);
    for (double angle = 0; angle <= 360; angle += 2.0)
    {
        radian_angle = angle * PI/180;
        x = radius * cos(radian_angle);
        y = radius * sin(radian_angle);
        glVertex2d(x, y);
    }
     
    glEnd();
}

void drawSemiCircleP(float r, float g, float b)
{
    // local variables declaration

    double x, y;
    double radius = 2.0;
    double radian_angle;

    //set the foreground color
	glColor3ub (r, g, b);

    glBegin(GL_POLYGON);
    for (double angle = 180; angle <= 360; angle += 2.0)
    {
        radian_angle = angle * PI/180;
        x = radius * cos(radian_angle);
        y = radius * sin(radian_angle);
        glVertex2d(x, y);
    }
     
    glEnd();
}

void drawTriangleP(float r, float g, float b)
{
    // set the foreground color
    glColor3ub (r, g, b);

    glBegin(GL_TRIANGLES);
    glVertex2d(0.0, 0.1);
    glVertex2d(-0.1, 0.0);
    glVertex2d(0.1, -0.1);
    glEnd();   
}

void drawCardioidP(float r, float g, float b)
{
    // local variables declaration
    
    double x, y;
    double radius = 0.0;
    double radian_angle = 0.0;
    double a = 2.5;

    //set the foreground color
	glColor3ub (r, g, b);

    
    glBegin(GL_POLYGON);
    for (double angle = 0; angle <= 360; angle += 2.0)
    {
        // calculation for cardioid
        radius = a + a * cos(radian_angle);
        radian_angle = angle * PI/180;
        x = radius * cos(radian_angle);
        y = radius * sin(radian_angle);
        glVertex2d(x, y);
    }
     
    glEnd();
}