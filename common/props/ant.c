void drawAnt(float originx, float originy, float resize) 
{
// LINE_STRIP 1
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + -0.057*resize, originy + 0.093*resize);
glVertex2f(originx + -0.024*resize, originy + 0.176*resize);
glVertex2f(originx + 0.113*resize, originy + -0.331*resize);
glEnd();
// LINE_STRIP 2
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + -0.102*resize, originy + 0.058*resize);
glVertex2f(originx + -0.318*resize, originy + -0.288*resize);
glVertex2f(originx + -0.318*resize, originy + -0.288*resize);
glEnd();
// LINE_STRIP 3
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + -0.165*resize, originy + 0.050*resize);
glVertex2f(originx + -0.500*resize, originy + -0.253*resize);
glVertex2f(originx + -0.500*resize, originy + -0.253*resize);
glEnd();
// LINE_STRIP 4
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + 0.047*resize, originy + 0.014*resize);
glVertex2f(originx + 0.111*resize, originy + 0.216*resize);
glVertex2f(originx + 0.281*resize, originy + -0.210*resize);
glEnd();
// LINE_STRIP 5
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + 0.175*resize, originy + 0.045*resize);
glVertex2f(originx + 0.316*resize, originy + 0.200*resize);
glVertex2f(originx + 0.690*resize, originy + -0.246*resize);
glEnd();
// LINE_STRIP 6
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + 0.217*resize, originy + -0.066*resize);
glVertex2f(originx + 0.279*resize, originy + 0.090*resize);
glVertex2f(originx + 0.489*resize, originy + -0.279*resize);
glEnd();

// BODY
glBegin(GL_TRIANGLES);
glColor3f(0.3294, 0.2745, 0.2235);
glVertex2f(originx + -0.470*resize, originy + 0.048*resize);
glVertex2f(originx + -0.330*resize, originy + 0.026*resize);
glVertex2f(originx + -0.278*resize, originy + 0.163*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3176, 0.2627, 0.2157);
glVertex2f(originx + -0.328*resize, originy + 0.091*resize);
glVertex2f(originx + -0.212*resize, originy + 0.133*resize);
glVertex2f(originx + -0.105*resize, originy + 0.045*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3725, 0.3059, 0.2471);
glVertex2f(originx + -0.212*resize, originy + 0.133*resize);
glVertex2f(originx + -0.142*resize, originy + 0.151*resize);
glVertex2f(originx + -0.105*resize, originy + 0.045*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3333, 0.2745, 0.2235);
glVertex2f(originx + -0.142*resize, originy + 0.151*resize);
glVertex2f(originx + 0.040*resize, originy + 0.045*resize);
glVertex2f(originx + -0.105*resize, originy + 0.045*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3098, 0.2549, 0.2078);
glVertex2f(originx + -0.105*resize, originy + 0.045*resize);
glVertex2f(originx + -0.059*resize, originy + -0.004*resize);
glVertex2f(originx + 0.040*resize, originy + 0.045*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3176, 0.2627, 0.2157);
glVertex2f(originx + 0.040*resize, originy + 0.045*resize);
glVertex2f(originx + 0.053*resize, originy + 0.003*resize);
glVertex2f(originx + -0.059*resize, originy + -0.004*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3451, 0.2863, 0.2353);
glVertex2f(originx + 0.053*resize, originy + 0.003*resize);
glVertex2f(originx + 0.105*resize, originy + 0.064*resize);
glVertex2f(originx + 0.111*resize, originy + -0.018*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3098, 0.2549, 0.2078);
glVertex2f(originx + 0.111*resize, originy + -0.018*resize);
glVertex2f(originx + 0.327*resize, originy + 0.094*resize);
glVertex2f(originx + 0.492*resize, originy + -0.126*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.1804, 0.1529, 0.1333);
glVertex2f(originx + 0.111*resize, originy + -0.018*resize);
glVertex2f(originx + 0.254*resize, originy + -0.150*resize);
glVertex2f(originx + 0.492*resize, originy + -0.126*resize);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.3137, 0.2549, 0.2078);
glVertex2f(originx + -0.449*resize, originy + 0.044*resize);
glVertex2f(originx + -0.492*resize, originy + 0.004*resize);
glVertex2f(originx + -0.407*resize, originy + 0.041*resize);
glEnd();

// ANTENAS
glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + -0.374*resize, originy + 0.105*resize);
glVertex2f(originx + -0.485*resize, originy + 0.204*resize);
glVertex2f(originx + -0.718*resize, originy + 0.239*resize);
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.0, 0.0, 0.0);
glVertex2f(originx + -0.374*resize, originy + 0.105*resize);
glVertex2f(originx + -0.448*resize, originy + 0.223*resize);
glVertex2f(originx + -0.633*resize, originy + 0.280*resize);
glEnd();

// EYE
glBegin(GL_TRIANGLES);
glColor3f(0.1451, 0.1294, 0.1098);
glVertex2f(originx + -0.374*resize, originy + 0.105*resize);
glVertex2f(originx + -0.336*resize, originy + 0.124*resize);
glVertex2f(originx + -0.355*resize, originy + 0.088*resize);
glEnd();
}
