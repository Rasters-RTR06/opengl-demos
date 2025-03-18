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
    void drawText(int, int, int);

    // code
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Radhika Vishwakarma - Slogan Text");

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
    glTranslated(0.0, 0.0, 0.0);
    glScaled(0.75, 0.75, 0.75);
    // Text
    drawText(255, 0, 0); //function called
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
    // switch (button) {
    //     case GLUT_LEFT_BUTTON:
    //         glutLeaveMainLoop();
    //         // glutLeaveGameMode();
    //         break;
    //     default:
    //         break;
    // }
}

void uninitialize(void) {
    // code
}

void drawText(int r, int g, int b)
{
    // code
    glColor3ub (r, g, b);

    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.3, 0.05);
    glVertex2f(-1.25, 0.1);
    glVertex2f(-1.2, 0.05);
    glVertex2f(-1.25, 0);
    glVertex2f(-1.2, -0.05);
    glVertex2f(-1.25, -0.1);
    glVertex2f(-1.3, -0.05);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.25, 0.0);
    glVertex2f(-1.15, 0.0);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.15, 0.1);
    glVertex2f(-1.15, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.05, 0.0);
    glVertex2f(-1.05, -0.05);
    glVertex2f(-1.1, 0.0);
    glVertex2f(-0.95, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.95, 0.0);
    glVertex2f(-1.05, -0.075);
    glVertex2f(-1.0, -0.1);
    glVertex2f(-1.01, -0.04);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.95, 0.1);
    glVertex2f(-0.95, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.75, 0.0);
    glVertex2f(-0.8, 0.05);
    glVertex2f(-0.85, 0.0);
    glVertex2f(-0.8, -0.05);
    glVertex2f(-0.75, 0.0);
    glVertex2f(-0.7, 0.05);
    glVertex2f(-0.65, 0.0);
    glVertex2f(-0.7, -0.05);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.75, 0.1);
    glVertex2f(-0.75, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.6, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.4, -0.05);
    glVertex2f(-0.375, -0.025);
    glVertex2f(-0.4, 0.0);
    glVertex2f(-0.45, 0.0);
    glVertex2f(-0.5, 0.05);
    glVertex2f(-0.45, 0.1);
    glVertex2f(-0.4, 0.1);
    glVertex2f(-0.35, 0.05);
    glVertex2f(-0.4, 0.0);
    glVertex2f(-0.45, 0.0);
    glVertex2f(-0.5, -0.05);
    glVertex2f(-0.45, -0.1);
    glVertex2f(-0.4, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.3, 0.1);
    glVertex2f(-0.25, 0.05);
    glVertex2f(-0.3, -0.05);
    glVertex2f(-0.25, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.1, 0.05);
    glVertex2f(-0.15, 0.0);
    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.05, 0.0);
    glVertex2f(-0.05, -0.05);
    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.1, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0, 0.1);
    glVertex2f(0.0, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.1, -0.05);
    glVertex2f(0.05, 0.0);
    glVertex2f(0.1, 0.0);
    glVertex2f(0.2, 0.0);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.25, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.45, 0.0);
    glVertex2f(0.4, 0.05);
    glVertex2f(0.35, 0.0);
    glVertex2f(0.4, -0.05);
    glVertex2f(0.45, 0.0);
    glVertex2f(0.45, 0.1);
    glVertex2f(0.45, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.375, 0.025);
    glVertex2f(0.425, -0.025);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.5, 0.05);
    glVertex2f(0.55, 0.05);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.55, -0.05);
    glVertex2f(0.6, 0.0);
    glVertex2f(0.6, 0.1);
    glVertex2f(0.6, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.65, 0.1);
    glVertex2f(0.65, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.7, 0.1);
    glVertex2f(0.75, 0.05);
    glVertex2f(0.7, 0.0);
    glVertex2f(0.75, -0.05);
    glVertex2f(0.8, 0.0);
    glVertex2f(0.8, 0.1);
    glVertex2f(0.8, -0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.8, 0.1);
    glVertex2f(0.7, 0.2);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-1.2, 0.1);
    glVertex2f(-0.9, 0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, 0.1);
    glVertex2f(-0.55, 0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.5, 0.1);
    glVertex2f(-0.225, 0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.15, 0.1);
    glVertex2f(0.3, 0.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.4, 0.1);
    glVertex2f(0.85, 0.1);
    glEnd();

}
