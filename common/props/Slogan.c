
void drawText(float originx, float originy, float resize, int r, int g, int b)
{
    // code
    glColor3ub (r, g, b);

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -1.3*resize, originy + 0.05*resize);
    glVertex2f(originx + -1.25*resize, originy + 0.1*resize);
    glVertex2f(originx + -1.2*resize, originy + 0.05*resize);
    glVertex2f(-1.25, 0);
    glVertex2f(originx + -1.2*resize, originy + -0.05*resize);
    glVertex2f(originx + -1.25*resize, originy + -0.1*resize);
    glVertex2f(originx + -1.3*resize, originy + -0.05*resize);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -1.25*resize, originy + 0.0*resize);
    glVertex2f(originx + -1.15*resize, originy + 0.0*resize);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -1.15*resize, originy + 0.1*resize);
    glVertex2f(originx + -1.15*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -1.05*resize, originy + 0.0*resize);
    glVertex2f(originx + -1.05*resize, originy + -0.05*resize);
    glVertex2f(originx + -1.1*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.95*resize, originy + 0.0*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.95*resize, originy + 0.0*resize);
    glVertex2f(originx + -1.05*resize, originy + -0.075*resize);
    glVertex2f(originx + -1.0*resize, originy + -0.1*resize);
    glVertex2f(originx + -1.01*resize, originy + -0.04*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.95*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.95*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.75*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.8*resize, originy + 0.05*resize);
    glVertex2f(originx + -0.85*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.8*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.75*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.7*resize, originy + 0.05*resize);
    glVertex2f(originx + -0.65*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.7*resize, originy + -0.05*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.75*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.75*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.6*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.6*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.4*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.375*resize, originy + -0.025*resize);
    glVertex2f(originx + -0.4*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.45*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.5*resize, originy + 0.05*resize);
    glVertex2f(originx + -0.45*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.4*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.35*resize, originy + 0.05*resize);
    glVertex2f(originx + -0.4*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.45*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.5*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.45*resize, originy + -0.1*resize);
    glVertex2f(originx + -0.4*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.3*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.25*resize, originy + 0.05*resize);
    glVertex2f(originx + -0.3*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.25*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.1*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.1*resize, originy + 0.05*resize);
    glVertex2f(originx + -0.15*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.1*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.05*resize, originy + 0.0*resize);
    glVertex2f(originx + -0.05*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.1*resize, originy + -0.05*resize);
    glVertex2f(originx + -0.1*resize, originy + -0.15*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.0*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.0*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.1*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.1*resize, originy + -0.05*resize);
    glVertex2f(originx + 0.05*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.1*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.2*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.2*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.2*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.25*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.25*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.45*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.4*resize, originy + 0.05*resize);
    glVertex2f(originx + 0.35*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.4*resize, originy + -0.05*resize);
    glVertex2f(originx + 0.45*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.45*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.45*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.375*resize, originy + 0.025*resize);
    glVertex2f(originx + 0.425*resize, originy + -0.025*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.5*resize, originy + 0.05*resize);
    glVertex2f(originx + 0.55*resize, originy + 0.05*resize);
    glVertex2f(originx + 0.5*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.55*resize, originy + -0.05*resize);
    glVertex2f(originx + 0.6*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.6*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.6*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.65*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.65*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.7*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.75*resize, originy + 0.05*resize);
    glVertex2f(originx + 0.7*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.75*resize, originy + -0.05*resize);
    glVertex2f(originx + 0.8*resize, originy + 0.0*resize);
    glVertex2f(originx + 0.8*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.8*resize, originy + -0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.8*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.7*resize, originy + 0.2*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -1.2*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.9*resize, originy + 0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.8*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.55*resize, originy + 0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.5*resize, originy + 0.1*resize);
    glVertex2f(originx + -0.225*resize, originy + 0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + -0.15*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.3*resize, originy + 0.1*resize);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(originx + 0.4*resize, originy + 0.1*resize);
    glVertex2f(originx + 0.85*resize, originy + 0.1*resize);
    glEnd();

}
