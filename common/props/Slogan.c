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
    glVertex2f(-0.1, -0.15);
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
