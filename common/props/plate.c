void drawPlate(void);
void drawCircleRadhika(int r, int g, int b);
void drawSemiCircleRadhika(int r, int g, int b);
void drawTriangleRadhika(int r, int g, int b);
void drawCardioidRadhika(int r, int g, int b);

void drawPlate(void) {
    // code
    // plate
    glPushMatrix();
    glTranslated(-0.65, 0.0, 0.0);
    glScaled(0.22, 0.22, 0.0);
    drawCardioidRadhika(73, 130, 65);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.65, 0.0, 0.0);
    glScaled(0.215, 0.215, 0.0);
    drawCardioidRadhika(32, 97, 20);       //function called
    glPopMatrix();

    // yellow bowl
    glPushMatrix();
    glTranslated(-0.25, 0.25, 0.0);
    glScaled(0.034, 0.034, 0.0);
    drawCircle(133, 133, 133);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.25, 0.25, 0.0);
    glScaled(0.034, 0.034, 0.0);
    drawCircle(250, 194, 25);       //function called
    glPopMatrix();
 
    glPushMatrix();
    glTranslated(-0.22, 0.0, 0.0);
    glScaled(0.07, 0.07, 0.0);
    drawCircle(232, 252, 238);       //function called
    glPopMatrix();

    // bowl - 1
    glPushMatrix();
    glTranslated(0.6, 0.6, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawSemiCircleRadhika(51, 107, 41);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6, 0.6, 0.0);
    glScaled(0.15, 0.03, 0.0);
    drawCircleRadhika(42, 94, 32);       //function called
    glPopMatrix();

    // bowl - 2
    glPushMatrix();
    glTranslated(0.6, -0.5, 0.0);
    glScaled(0.15, 0.15, 0.0);
    drawSemiCircleRadhika(51, 107, 41);       //function called
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.6, -0.5, 0.0);
    glScaled(0.15, 0.03, 0.0);
    drawCircleRadhika(42, 94, 32);       //function called
    glPopMatrix();

    glBegin(GL_TRIANGLES);
    glColor3f(0.13f, 0.27f, 0.17f);
    glVertex2f(-0.01f, 0.25f);
    glVertex2f(-0.08f, 0.15f);
    glVertex2f(-0.09f, 0.25f);
    glEnd();
}

void drawCircleRadhika(int r, int g, int b)
{
    // local variables declaration
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

void drawSemiCircleRadhika(int r, int g, int b)
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

void drawTriangleRadhika(int r, int g, int b)
{
    // set the foreground color
    glColor3ub (r, g, b);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.01f, 0.25f);
    glVertex2f(-0.08f, 0.15f);
    glVertex2f(-0.09f, 0.25f);
    glEnd();  
}

void drawCardioidRadhika(int r, int g, int b)
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