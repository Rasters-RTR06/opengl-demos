// header files
//#include <GL/GLU.h>
#include <GL/GLUT.h>
#include <math.h>

// global variable declarations
BOOL bFullScreen = FALSE;

// Entry-point function
int main(int argc, char* argv[])
{
    // local function declarations
    int initialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);
    void uninitialize(void);
    void drawCurve(void);
    void drawCircle(void);

    // code
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Radhika Vishwakarma - Flower Demo");

    initialize();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    // glutWMCloseFunc(uninitialize);
    glutCloseFunc(uninitialize);

    glutMainLoop();

    return(0);
}

int initialize(void) {
    // code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0);
    return(0);
}

void resize(int width, int height) {
    // code
    glViewport(0, 0, width, height);
}

void display(void) {
    // code
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    glTranslated(-2.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 0.0);
    drawCurve();        //function called
    drawCircle();       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-1.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 0.0);
    drawCurve();        //function called
    drawCircle();       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 0.0);
    drawCurve();        //function called
    drawCircle();       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 0.0);
    drawCurve();        //function called
    drawCircle();       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0, 0.0, 0.0);
    glScaled(0.2, 0.2, 0.0);
    drawCurve();        //function called
    drawCircle();       //function called
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    // code
    switch (key) {
    case 27:
        glutLeaveMainLoop();
        //  glutLeaveGameMode();
        break;

    case 'F':
    case 'f':
        if (bFullScreen == FALSE) {
            glutFullScreen();
            bFullScreen = TRUE;
        }
        else {
            glutLeaveFullScreen();
            //  glutLeaveGameMode();
            bFullScreen = FALSE;
        }
        break;
    default:
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    // code
    switch (button) {
        case GLUT_LEFT_BUTTON:
            glutLeaveMainLoop();
            // glutLeaveGameMode();
            break;
        default:
            break;
    }
}

void uninitialize(void) {
    // code
}

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
