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
    void drawCircle(int, int, int);
    void drawTriangle(int, int, int);
    void drawCardioid(int, int, int);
    void drawSemiCircle(int, int, int);

    // code
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Radhika Vishwakarma - Polygon plate demo");

     initialize();

     glutReshapeFunc(resize);
     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     glutMouseFunc(mouse);
    //  glutWMCloseFunc(uninitialize);
     glutCloseFunc(uninitialize);

    glutMainLoop();

    return(0);
}

int initialize(void) {
    // code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    return(0);
}

void resize(int width, int height) {
    // code
    glViewport(0, 0, width, height);
}

void display(void) {
    // code
    glClear(GL_COLOR_BUFFER_BIT);

    // plate
    glPushMatrix();
    glTranslated(-0.65, 0.0, 0.0);
    glScaled(0.22, 0.22, 0.0);
    drawCardioid(73, 130, 65);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.65, 0.0, 0.0);
    glScaled(0.215, 0.215, 0.0);
    drawCardioid(32, 97, 20);       //function called
    glPopMatrix();

    // yellow bowl
    glPushMatrix();
    glTranslated(-0.50, 0.25, 0.0);
    glScaled(0.085, 0.085, 0.0);
    drawCircle(133, 133, 133);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.50, 0.25, 0.0);
    glScaled(0.08, 0.08, 0.0);
    drawCircle(250, 194, 25);       //function called
    glPopMatrix();

    // red bowl
    // glPushMatrix();
    // glTranslated(-0.18, 0.5, 0.0);
    // glScaled(0.085, 0.085, 0.0);
    // drawCircle(133, 133, 133);       //function called
    // glPopMatrix();

    // glPushMatrix();
    // glTranslated(-0.18, 0.5, 0.0);
    // glScaled(0.08, 0.08, 0.0);
    // drawCircle(171, 2, 33);       //function called
    // glPopMatrix();

    // // green bowl
    // glPushMatrix();
    // glTranslated(0.20, 0.5, 0.0);
    // glScaled(0.085, 0.085, 0.0);
    // drawCircle(133, 133, 133);       //function called
    // glPopMatrix();

    // glPushMatrix();
    // glTranslated(0.20, 0.5, 0.0);
    // glScaled(0.08, 0.08, 0.0);
    // drawCircle(40, 92, 24);       //function called
    // glPopMatrix();

    // // orange bowl
    // glPushMatrix();
    // glTranslated(-0.50, -0.14, 0.0);
    // glScaled(0.085, 0.085, 0.0);
    // drawCircle(133, 133, 133);       //function called
    // glPopMatrix();

    // glPushMatrix();
    // glTranslated(-0.50, -0.14, 0.0);
    // glScaled(0.08, 0.08, 0.0);
    // drawCircle(227, 129, 25);       //function called
    // glPopMatrix();

    // // pink bowl
    // glPushMatrix();
    // glTranslated(0.50, 0.25, 0.0);
    // glScaled(0.085, 0.085, 0.0);
    // drawCircle(133, 133, 133);       //function called
    // glPopMatrix();

    // glPushMatrix();
    // glTranslated(0.50, 0.25, 0.0);
    // glScaled(0.08, 0.08, 0.0);
    // drawCircle(181, 58, 126);       //function called
    // glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawCircle(232, 252, 238);       //function called
    glPopMatrix();

    // glPushMatrix();
    // glTranslated(-0.20, -0.5, 0.0);
    // glScaled(1.99, 1.99, 0.0);
    // drawTriangle(168, 115, 29);       //function called
    // glPopMatrix();

    // glPushMatrix();
    // glTranslated(0.3, -0.4, 0.0);
    // glRotated(200.0, 0.3, -0.4, 0.0);
    // glScaled(1.99, 1.99, 0.0);
    // drawTriangle(168, 115, 29);       //function called
    // glPopMatrix();

    // bowl - 1
    glPushMatrix();
    glTranslated(0.6, 0.6, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawSemiCircle(51, 107, 41);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6, 0.6, 0.0);
    glScaled(0.15, 0.03, 0.0);
    drawCircle(42, 94, 32);       //function called
    glPopMatrix();

    // bowl - 2
    glPushMatrix();
    glTranslated(0.6, -0.5, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawSemiCircle(51, 107, 41);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6, -0.5, 0.0);
    glScaled(0.15, 0.03, 0.0);
    drawCircle(42, 94, 32);       //function called
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

void drawCircle(int r, int g, int b)
{
    // local variables declaration
    const double PI = 3.1459;
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

void drawSemiCircle(int r, int g, int b)
{
    // local variables declaration
    const double PI = 3.1459;
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

void drawTriangle(int r, int g, int b)
{
    // set the foreground color
    glColor3ub (r, g, b);

    glBegin(GL_TRIANGLES);
    glVertex2d(0.0, 0.1);
    glVertex2d(-0.1, 0.0);
    glVertex2d(0.1, -0.1);
    glEnd();   
}

void drawCardioid(int r, int g, int b)
{
    // local variables declaration
    const double PI = 3.1459;
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