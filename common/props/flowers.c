// header files
//#include <GL/GLU.h>
#include <GL/GLUT.h>
#include <math.h>

// The purpose of drawSierpinski() is to display the mathematical
// function y = exp(-x) cos (2 PI x) in the window.
void drawCurve(void){
    int n = 10;                         // 2n is number of petals on flower
	const double PI = 3.14159;          //PI in radians
	double radians;                     //theta in radians
	
	//set the foreground color
	glColor3ub (255, 235, 20);
	//(x, y) is a point on the parametric curve
	double x, y;
	//plot points from the parametric curve
	glBegin (GL_POLYGON);
		glVertex2d(0.0, 0.0);
		for (double theta = 0; theta <= 360.0; theta += 0.5){
			radians = theta * PI/180.0;            //convert PI to radians
			x = 2.0 * cos(n * radians) * cos(radians);
			y = 2.0 * cos(n * radians) * sin(radians);
			//cout << x << " " << y << endl;
			glVertex2d (x, y);
		}
	glEnd();	
}

void drawCircle(void)
{
    // local variables declaration
    const double PI = 3.1459;
    double x, y;
    double radius = 0.25;
    double radian_angle;

    //set the foreground color
	glColor3ub (84, 13, 8);

    glBegin(GL_POLYGON);
    for (double angle = 0; angle <= 360; angle += 0.25)
    {
        radian_angle = angle * PI/180;
        x = radius * cos(radian_angle);
        y = radius * sin(radian_angle);
        glVertex2d(x, y);
    }
     
    glEnd();
}
