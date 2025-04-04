//#define PI 3.14159

//#define SKIN_COLOR { \
//    glColor3f(0.94f, 0.72f, 0.63f); \
//}

#define ARJUN_DHOTI_COLOR {\
    glColor3f(0.125f,0.4f,0.047f);\
}

#define ARJUN_SHOULDER_CLOTH_MAJOR {glColor3f(0.75f, 0.00f, 0.25f);}
#define ARJUN_SHOULDER_CLOTH_MINOR {glColor3f(0.75f, 0.55f, 0.00f);}

// global variable declarations
//float xOrigin_Arjun = 0.0f;
//float yOrigin_Arjun_Arjun = 0.0f;
//float fScaleFactor_Arjun_Arjun = 1.0f;

/// global function declarations
void drawLineArjun(float x1, float y1, float x2, float y2);
void drawRectangleArjun(float LX, float RX, float TY, float BY);
void drawQuadrangleArjun(float x1, float  y1, float  x2, float y2, float x3, float  y3, float x4, float y4);
void drawcircleArjun(float, float, float, float, float, float, float, int);
void drawTriangleArjun(float x1, float y1, float x2, float y2, float x3, float y3);
void drawArrowBoxArjun(float xOrigin, float yOrigin, float scale, int iStanding);
void showDhanushyaArjun(float fOriginX, float fOriginY, float fResize);

void drawEllipseArjun(
    float startX, float startY,
    float startAngle, float endAngle,
    float rColor, float gColor, float bColor,
    float hRadius, float vRadius);


// function declarations
void drawArjun(float xOrigin_Arjun, float yOrigin_Arjun, float scale, int iStanding, int iHandPosition, int iShowBowArrow);

//void display(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    drawNakul(xOrigin_Arjun, yOrigin_Arjun_Arjun, fScaleFactor_Arjun_Arjun, 1);
//
//    // Use SwapBuffers instead of glutSwapBuffers since GLUT is not used.
//    SwapBuffers(ghdc);
//}

// Draw Rectangle 
// Draw Rectangle 
void drawRectangleArjun(float LX, float RX, float TY, float BY)
{
    glBegin(GL_QUADS);
    glVertex2f(LX, TY);
    glVertex2f(RX, TY);
    glVertex2f(RX, BY);
    glVertex2f(LX, BY);
    glEnd();
}

void drawQuadrangleArjun(float x1, float  y1, float  x2, float y2, float x3, float  y3, float x4, float y4)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

// Draw Line
void drawLineArjun(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawcircleArjun(float x, float y, float radius_vert, float radius_hor, float r, float g, float b, int fill)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    // Circle
    if (fill == 1) {
        glBegin(GL_POLYGON);
    }
    else {
        glBegin(GL_POINTS);
    }

    for (ObjAngle = (0.00f); ObjAngle <= (2.0f * PI); ObjAngle += 0.01f)
    {
        ObjX = x + radius_hor * sin(ObjAngle);
        ObjY = y + radius_vert * cos(ObjAngle);

        glColor3f(r, g, b);
        glVertex2f(ObjX, ObjY);
    }
    glEnd();
}

void drawTriangleArjun(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawArjun(float xOrigin, float yOrigin_Arjun, float scale, int iStanding, int iHandPosition, int iShowBowArrow)
{
    scale = scale + 0.05f;
    void drawClothBackSideArjun(float, float, float);
    void drawHeadArjun(float, float, float);
    void drawCommonBodyArjun(float, float, float, int);
    void drawHandAndClothArjun(float, float, float, int);

    drawClothBackSideArjun(xOrigin, yOrigin_Arjun, scale);
    drawHeadArjun(xOrigin, yOrigin_Arjun, scale);
    drawArrowBoxArjun(xOrigin, yOrigin_Arjun, scale, iShowBowArrow);
    drawCommonBodyArjun(xOrigin, yOrigin_Arjun, scale, iStanding);
    drawHandAndClothArjun(xOrigin, yOrigin_Arjun, scale, iHandPosition);
    if (iShowBowArrow == 1) showDhanushyaArjun(xOrigin, yOrigin_Arjun, scale);
}

void drawHeadArjun(float xOrigin, float yOrigin_Arjun, float scale)
{
    // hairs
    {
        glColor3f(0.0f, 0.0f, 0.0f);

        drawcircleArjun(
            xOrigin + (-0.7850f * scale), yOrigin_Arjun + (0.2550f * scale),
            (0.030f * scale), (0.020f * scale), 0.0f, 0.0f, 0.0f, 1);

        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.7900f * scale), yOrigin_Arjun + (0.2650f * scale));
        glVertex2f(xOrigin + (-0.7950f * scale), yOrigin_Arjun + (0.2200f * scale));
        glVertex2f(xOrigin + (-0.7900f * scale), yOrigin_Arjun + (0.1800f * scale));
        glVertex2f(xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.1500f * scale));
        glVertex2f(xOrigin + (-0.7625f * scale), yOrigin_Arjun + (0.1900f * scale));
        glVertex2f(xOrigin + (-0.7625f * scale), yOrigin_Arjun + (0.2200f * scale));
        glVertex2f(xOrigin + (-0.7250f * scale), yOrigin_Arjun + (0.2600f * scale));
        glEnd();

        glColor3f(0.7f, 0.7f, 0.7f); //hair band
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7950f * scale), yOrigin_Arjun + (0.2300f * scale));
        glVertex2f(xOrigin + (-0.7800f * scale), yOrigin_Arjun + (0.2400f * scale));

        glVertex2f(xOrigin + (-0.7800f * scale), yOrigin_Arjun + (0.2400f * scale));
        glVertex2f(xOrigin + (-0.7600f * scale), yOrigin_Arjun + (0.2650f * scale));
        glEnd();
    }

    // Use uniform skin color for the face
    SKIN_COLOR
        glBegin(GL_POLYGON);
    glVertex2f(xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.1500f * scale));
    glVertex2f(xOrigin + (-0.7350f * scale), yOrigin_Arjun + (0.1000f * scale));
    glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun + (0.1200f * scale));
    glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun + (0.1450f * scale));
    glVertex2f(xOrigin + (-0.7000f * scale), yOrigin_Arjun + (0.1450f * scale)); //nose cut
    glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun + (0.2000f * scale));
    glVertex2f(xOrigin + (-0.7070f * scale), yOrigin_Arjun + (0.2050f * scale));
    glVertex2f(xOrigin + (-0.7120f * scale), yOrigin_Arjun + (0.2500f * scale));
    glVertex2f(xOrigin + (-0.730f * scale), yOrigin_Arjun + (0.2550f * scale));
    glEnd();
    drawTriangleArjun(
        xOrigin + (-0.7300f * scale), yOrigin_Arjun + (0.2550f * scale),
        xOrigin + (-0.7625f * scale), yOrigin_Arjun + (0.2200f * scale),
        xOrigin + (-0.7625f * scale), yOrigin_Arjun + (0.1750f * scale));

    //lips
    {
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun + (0.1330f * scale));
        glVertex2f(xOrigin + (-0.7220f * scale), yOrigin_Arjun + (0.1330f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7220f * scale), yOrigin_Arjun + (0.1330f * scale));
        glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun + (0.1280f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7220f * scale), yOrigin_Arjun + (0.1330f * scale));
        glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun + (0.1380f * scale));
        glEnd();
    }

    glLineWidth(1.5f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7100f * scale), yOrigin_Arjun+ (0.1420f * scale));
    glVertex2f(xOrigin + (-0.7280f * scale), yOrigin_Arjun + (0.1370f * scale));
    glEnd();
    /*glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7280f * scale), yOrigin_Arjun + (0.1370f * scale));
    glVertex2f(xOrigin + (-0.7370f * scale), yOrigin_Arjun + (0.1450f * scale));
    glEnd();*/

    glLineWidth(1.0f);

    //eye
    {
        glColor3f(1.0f, 1.0f, 1.0f);
        drawQuadrangleArjun(
            xOrigin + (-0.7130f * scale), yOrigin_Arjun + (0.2000f * scale),
            xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2080f * scale),
            xOrigin + (-0.7400f * scale), yOrigin_Arjun + (0.2000f * scale),
            xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.1920f * scale));

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7130f * scale), yOrigin_Arjun + (0.2000f * scale));
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2080f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2080f * scale));
        glVertex2f(xOrigin + (-0.7400f * scale), yOrigin_Arjun + (0.2000f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7400f * scale), yOrigin_Arjun + (0.2000f * scale));
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.1920f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.1920f * scale));
        glVertex2f(xOrigin + (-0.7130f * scale), yOrigin_Arjun + (0.2000f * scale));
        glEnd();

        /*glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(4.0f);
        glBegin(GL_POINTS);
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2000f * scale));
        glEnd();
        glPointSize(1.0f);*/
        drawcircleArjun(
            xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2000f * scale),
            (0.004f * scale), (0.0035f * scale), 0.0f, 0.0f, 0.0f, 1);

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7130f * scale), yOrigin_Arjun + (0.2150f * scale));
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2200f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7200f * scale), yOrigin_Arjun + (0.2200f * scale));
        glVertex2f(xOrigin + (-0.7400f * scale), yOrigin_Arjun + (0.2150f * scale));
        glEnd();
    }

    {
        glLineWidth(2.0f);
        glColor3f(1.0f, 0.337f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7180f * scale), yOrigin_Arjun + (0.2400f * scale));
        glVertex2f(xOrigin + (-0.7160f * scale), yOrigin_Arjun + (0.2300f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7160f * scale), yOrigin_Arjun + (0.2300f * scale));
        glVertex2f(xOrigin + (-0.7090f * scale), yOrigin_Arjun + (0.2260f * scale));
        glEnd();
        glLineWidth(1.0f);
    }

    {
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7700f * scale), yOrigin_Arjun + (0.1750f * scale));
        glVertex2f(xOrigin + (-0.7700f * scale), yOrigin_Arjun + (0.1500f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7700f * scale), yOrigin_Arjun + (0.1500f * scale));
        glVertex2f(xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.1400f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7600f * scale), yOrigin_Arjun + (0.1500f * scale));
        glVertex2f(xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.1400f * scale));
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.1400f * scale));
        glVertex2f(xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.1300f * scale));
        glEnd();
    }
}

void drawArrowBoxArjun(float xOrigin, float yOrigin, float scale, int iShowBowArrow)
{
    if (iShowBowArrow == 1)
    {
        // Arrow carrier
        glColor3f(0.03f, 0.42f, 0.12f);
        drawQuadrangleArjun(
            xOrigin + (-0.8400f * scale), yOrigin + (-0.050f * scale),
            xOrigin + (-0.8600f * scale), yOrigin + (0.090f * scale),
            xOrigin + (-0.7900f * scale), yOrigin + (0.120f * scale),
            xOrigin + (-0.7700f * scale), yOrigin + (-0.020f * scale)
        );

        // Arrow 1
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.5);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.858f * scale), yOrigin + (0.14f * scale));
        glVertex2f(xOrigin + (-0.85f * scale), yOrigin + (0.09f * scale));
        glEnd();

        drawTriangleArjun(
            xOrigin + (-0.858f * scale), yOrigin + (0.140f * scale),
            xOrigin + (-0.862f * scale), yOrigin + (0.125f * scale),
            xOrigin + (-0.850f * scale), yOrigin + (0.125f * scale)
        );

        // Arrow 2
        glLineWidth(1.5);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.835f * scale), yOrigin + (0.15f * scale));
        glVertex2f(xOrigin + (-0.827f * scale), yOrigin + (0.10f * scale));
        glEnd();


        drawTriangleArjun(
            xOrigin + (-0.835f * scale), yOrigin + (0.15f * scale),
            xOrigin + (-0.839f * scale), yOrigin + (0.135f * scale),
            xOrigin + (-0.826f * scale), yOrigin + (0.135f * scale)
        );

        // Arrow 3
        glLineWidth(1.5);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.812f * scale), yOrigin + (0.16f * scale));
        glVertex2f(xOrigin + (-0.804f * scale), yOrigin + (0.11f * scale));
        glEnd();


        drawTriangleArjun(
            xOrigin + (-0.812f * scale), yOrigin + (0.160f * scale),
            xOrigin + (-0.816f * scale), yOrigin + (0.145f * scale),
            xOrigin + (-0.801f * scale), yOrigin + (0.145f * scale)
        );
    }
    else
    {

    }
}

void drawClothBackSideArjun(float xOrigin, float yOrigin_Arjun, float scale)
{
    {
        ARJUN_SHOULDER_CLOTH_MAJOR
        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.844f * scale), yOrigin_Arjun + (-0.050f * scale));
        glVertex2f(xOrigin + (-0.844f * scale), yOrigin_Arjun + (-0.200f * scale));
        glVertex2f(xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.350f * scale));
        glVertex2f(xOrigin + (-0.835f * scale), yOrigin_Arjun + (-0.350f * scale));
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.250f * scale));

        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.080f * scale));
        glEnd();

        drawTriangleArjun(
            xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.350f * scale),
            xOrigin + (-0.835f * scale), yOrigin_Arjun + (-0.350f * scale),
            xOrigin + (-0.834f * scale), yOrigin_Arjun + (-0.375f * scale));

        glLineWidth(5.0f);
        ARJUN_SHOULDER_CLOTH_MINOR
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.834f * scale), yOrigin_Arjun + (-0.375f * scale));
        glVertex2f(xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.350f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.350f * scale));
        glVertex2f(xOrigin + (-0.850f * scale), yOrigin_Arjun + (-0.200f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.850f * scale), yOrigin_Arjun + (-0.200f * scale));
        glVertex2f(xOrigin + (-0.844f * scale), yOrigin_Arjun + (-0.059f * scale));
        glEnd();

        glLineWidth(1.0f);
    }
}

void drawCommonBodyArjun(float xOrigin, float yOrigin_Arjun, float scale, int iStanding)
{
    // Use uniform skin color for the neck and torso
    SKIN_COLOR
        //neck
        drawQuadrangleArjun(
            xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.0800f * scale),
            xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.1500f * scale),
            xOrigin + (-0.7350f * scale), yOrigin_Arjun + (0.1000f * scale),
            xOrigin + (-0.7350f * scale), yOrigin_Arjun + (0.0800f * scale));

    SKIN_COLOR
        // Torso
        glBegin(GL_POLYGON);
    glVertex2f(xOrigin + (-0.835f * scale), yOrigin_Arjun + (0.050f * scale));
    glVertex2f(xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.0800f * scale));
    glVertex2f(xOrigin + (-0.735f * scale), yOrigin_Arjun + (0.0800f * scale));
    glVertex2f(xOrigin + (-0.680f * scale), yOrigin_Arjun + (0.050f * scale));
    glVertex2f(xOrigin + (-0.685f * scale), yOrigin_Arjun + (-0.25f * scale));
    glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.25f * scale));
    glEnd();

    if (iStanding == 1)
    {
        SKIN_COLOR
            // back leg lower
            drawTriangleArjun(
                xOrigin + (-0.820f * scale), yOrigin_Arjun + (-0.55f * scale),
                xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.45f * scale),
                xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.55f * scale));
        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.65f * scale));
        glVertex2f(xOrigin + (-0.820f * scale), yOrigin_Arjun + (-0.55f * scale));
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.55f * scale));
        glVertex2f(xOrigin + (-0.783f * scale), yOrigin_Arjun + (-0.83f * scale));
        glVertex2f(xOrigin + (-0.818f * scale), yOrigin_Arjun + (-0.83f * scale));
        glEnd();
        // front leg lower
        drawTriangleArjun(
            xOrigin + (-0.747f * scale), yOrigin_Arjun + (-0.550f * scale),
            xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.450f * scale),
            xOrigin + (-0.690f * scale), yOrigin_Arjun + (-0.550f * scale));
        drawQuadrangleArjun(
            xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.830f * scale),
            xOrigin + (-0.695f * scale), yOrigin_Arjun + (-0.825f * scale),
            xOrigin + (-0.690f * scale), yOrigin_Arjun + (-0.550f * scale),
            xOrigin + (-0.747f * scale), yOrigin_Arjun + (-0.550f * scale));

        SKIN_COLOR
            // Back foot
            drawQuadrangleArjun(
                xOrigin + (-0.83f * scale), yOrigin_Arjun + (-0.85f * scale),
                xOrigin + (-0.818f * scale), yOrigin_Arjun + (-0.83f * scale),
                xOrigin + (-0.783f * scale), yOrigin_Arjun + (-0.83f * scale),
                xOrigin + (-0.78f * scale), yOrigin_Arjun + (-0.85f * scale));

        drawQuadrangleArjun(
            xOrigin + (-0.83f * scale), yOrigin_Arjun + (-0.85f * scale),
            xOrigin + (-0.78f * scale), yOrigin_Arjun + (-0.93f * scale),
            xOrigin + (-0.74f * scale), yOrigin_Arjun + (-0.93f * scale),
            xOrigin + (-0.78f * scale), yOrigin_Arjun + (-0.85f * scale));

        // front foot
        drawQuadrangleArjun(
            xOrigin + (-0.745f * scale), yOrigin_Arjun + (-0.850f * scale),
            xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.830f * scale),
            xOrigin + (-0.695f * scale), yOrigin_Arjun + (-0.825f * scale),
            xOrigin + (-0.688f * scale), yOrigin_Arjun + (-0.837f * scale));

        drawQuadrangleArjun(
            xOrigin + (-0.745f * scale), yOrigin_Arjun + (-0.850f * scale),
            xOrigin + (-0.660f * scale), yOrigin_Arjun + (-0.900f * scale),
            xOrigin + (-0.628f * scale), yOrigin_Arjun + (-0.870f * scale),
            xOrigin + (-0.688f * scale), yOrigin_Arjun + (-0.837f * scale));

        //fingers
        glColor3f(0.6f, 0.6f, 0.6f);
        //back
        drawLineArjun(
            xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.93f * scale),
            xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.91f * scale));
        drawLineArjun(
            xOrigin + (-0.758f * scale), yOrigin_Arjun + (-0.93f * scale),
            xOrigin + (-0.773f * scale), yOrigin_Arjun + (-0.91f * scale));
        drawLineArjun(
            xOrigin + (-0.766f * scale), yOrigin_Arjun + (-0.93f * scale),
            xOrigin + (-0.781f * scale), yOrigin_Arjun + (-0.91f * scale));
        drawLineArjun(
            xOrigin + (-0.774f * scale), yOrigin_Arjun + (-0.93f * scale),
            xOrigin + (-0.789f * scale), yOrigin_Arjun + (-0.91f * scale));

        //front
        drawLineArjun(
            xOrigin + (-0.65f * scale), yOrigin_Arjun + (-0.89f * scale),
            xOrigin + (-0.67f * scale), yOrigin_Arjun + (-0.878f * scale));
        drawLineArjun(
            xOrigin + (-0.645f * scale), yOrigin_Arjun + (-0.885f * scale),
            xOrigin + (-0.665f * scale), yOrigin_Arjun + (-0.873f * scale));
        drawLineArjun(
            xOrigin + (-0.64f * scale), yOrigin_Arjun + (-0.88f * scale),
            xOrigin + (-0.66f * scale), yOrigin_Arjun + (-0.868f * scale));
        drawLineArjun(
            xOrigin + (-0.635f * scale), yOrigin_Arjun + (-0.875f * scale),
            xOrigin + (-0.655f * scale), yOrigin_Arjun + (-0.863f * scale));

        //Dhoti
        ARJUN_DHOTI_COLOR

            glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.835f * scale), yOrigin_Arjun + (-0.35f * scale));
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.25f * scale));
        glVertex2f(xOrigin + (-0.685f * scale), yOrigin_Arjun + (-0.25f * scale));
        glVertex2f(xOrigin + (-0.680f * scale), yOrigin_Arjun + (-0.35f * scale));
        glVertex2f(xOrigin + (-0.683f * scale), yOrigin_Arjun + (-0.45f * scale));
        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.45f * scale));
        glEnd();

        drawTriangleArjun(
            xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.450f * scale),
            xOrigin + (-0.683f * scale), yOrigin_Arjun + (-0.450f * scale),
            xOrigin + (-0.690f * scale), yOrigin_Arjun + (-0.550f * scale));
        drawTriangleArjun(
            xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.450f * scale),
            xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.450f * scale),
            xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.550f * scale));

        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.400f * scale));
        glVertex2f(xOrigin + (-0.775f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.755f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.755f * scale), yOrigin_Arjun + (-0.600f * scale));
        glVertex2f(xOrigin + (-0.730f * scale), yOrigin_Arjun + (-0.612f * scale));
        glVertex2f(xOrigin + (-0.736f * scale), yOrigin_Arjun + (-0.425f * scale));
        glEnd();

        //Border Lines
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.775f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.768f * scale), yOrigin_Arjun + (-0.250f * scale));

        glVertex2f(xOrigin + (-0.730f * scale), yOrigin_Arjun + (-0.612f * scale));
        glVertex2f(xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.250f * scale));

        glVertex2f(xOrigin + (-0.775f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.731f * scale), yOrigin_Arjun + (-0.530f * scale));

        glVertex2f(xOrigin + (-0.775f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.731f * scale), yOrigin_Arjun + (-0.575f * scale));

        glVertex2f(xOrigin + (-0.731f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.755f * scale), yOrigin_Arjun + (-0.600f * scale));

        glVertex2f(xOrigin + (-0.755f * scale), yOrigin_Arjun + (-0.600f * scale));
        glVertex2f(xOrigin + (-0.730f * scale), yOrigin_Arjun + (-0.612f * scale));
        glEnd();

        glLineWidth(3.0f);

        glColor3f(0.63f, 0.53f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.250f * scale));
        glVertex2f(xOrigin + (-0.685f * scale), yOrigin_Arjun + (-0.250f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.250f * scale));
        glVertex2f(xOrigin + (-0.731f * scale), yOrigin_Arjun + (-0.530f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.775f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.731f * scale), yOrigin_Arjun + (-0.530f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.731f * scale), yOrigin_Arjun + (-0.575f * scale));
        glVertex2f(xOrigin + (-0.755f * scale), yOrigin_Arjun + (-0.600f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.450f * scale));
        glVertex2f(xOrigin + (-0.775f * scale), yOrigin_Arjun + (-0.540f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.735f * scale), yOrigin_Arjun + (-0.465f * scale));
        glVertex2f(xOrigin + (-0.690f * scale), yOrigin_Arjun + (-0.550f * scale));
        glEnd();

        glLineWidth(1.0f);
    }
    else
    {
        //Dhoti
        ARJUN_DHOTI_COLOR

            glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.930f * scale), yOrigin_Arjun + (-0.40f * scale));
        glVertex2f(xOrigin + (-0.930f * scale), yOrigin_Arjun + (-0.32f * scale));
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.25f * scale));
        glVertex2f(xOrigin + (-0.685f * scale), yOrigin_Arjun + (-0.25f * scale));
        glVertex2f(xOrigin + (-0.565f * scale), yOrigin_Arjun + (-0.32f * scale));
        glVertex2f(xOrigin + (-0.565f * scale), yOrigin_Arjun + (-0.40f * scale));
        glVertex2f(xOrigin + (-0.683f * scale), yOrigin_Arjun + (-0.45f * scale));
        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.45f * scale));
        glEnd();

        //knee1
        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.930f * scale), yOrigin_Arjun + (-0.320f * scale));
        glVertex2f(xOrigin + (-0.945f * scale), yOrigin_Arjun + (-0.345f * scale));
        glVertex2f(xOrigin + (-0.945f * scale), yOrigin_Arjun + (-0.375f * scale));
        glVertex2f(xOrigin + (-0.930f * scale), yOrigin_Arjun + (-0.400f * scale));
        glEnd();
        //knee2
        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.565f * scale), yOrigin_Arjun + (-0.320f * scale));
        glVertex2f(xOrigin + (-0.550f * scale), yOrigin_Arjun + (-0.345f * scale));
        glVertex2f(xOrigin + (-0.550f * scale), yOrigin_Arjun + (-0.375f * scale));
        glVertex2f(xOrigin + (-0.565f * scale), yOrigin_Arjun + (-0.400f * scale));
        glEnd();

        SKIN_COLOR
            drawQuadrangleArjun(
                xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.450f * scale),
                xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.373f * scale),
                xOrigin + (-0.625f * scale), yOrigin_Arjun + (-0.350f * scale),
                xOrigin + (-0.683f * scale), yOrigin_Arjun + (-0.450f * scale)
            );

        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.450f * scale));
        glVertex2f(xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.373f * scale));
        glVertex2f(xOrigin + (-0.825f * scale), yOrigin_Arjun + (-0.355f * scale));
        glVertex2f(xOrigin + (-0.885f * scale), yOrigin_Arjun + (-0.350f * scale));
        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.450f * scale));
        glEnd();

        ARJUN_DHOTI_COLOR
            //leg1
            drawQuadrangleArjun(
                xOrigin + (-0.625f * scale), yOrigin_Arjun + (-0.350f * scale),
                xOrigin + (-0.650f * scale), yOrigin_Arjun + (-0.360f * scale),
                xOrigin + (-0.676f * scale), yOrigin_Arjun + (-0.410f * scale),
                xOrigin + (-0.683f * scale), yOrigin_Arjun + (-0.450f * scale)
            );
        //leg2
        drawQuadrangleArjun(
            xOrigin + (-0.885f * scale), yOrigin_Arjun + (-0.350f * scale),
            xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.360f * scale),
            xOrigin + (-0.840f * scale), yOrigin_Arjun + (-0.410f * scale),
            xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.450f * scale)
        );

        glLineWidth(3.0f);

        glColor3f(0.63f, 0.53f, 0.0f);
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.250f * scale));
        glVertex2f(xOrigin + (-0.735f * scale), yOrigin_Arjun + (-0.370f * scale));
        glEnd();

        glBegin(GL_LINE_STRIP); //waist
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (-0.250f * scale));
        glVertex2f(xOrigin + (-0.685f * scale), yOrigin_Arjun + (-0.250f * scale));
        glEnd();

        //leg1
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.683f * scale), yOrigin_Arjun + (-0.450f * scale));
        glVertex2f(xOrigin + (-0.676f * scale), yOrigin_Arjun + (-0.410f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.676f * scale), yOrigin_Arjun + (-0.410f * scale));
        glVertex2f(xOrigin + (-0.650f * scale), yOrigin_Arjun + (-0.360f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.650f * scale), yOrigin_Arjun + (-0.360f * scale));
        glVertex2f(xOrigin + (-0.625f * scale), yOrigin_Arjun + (-0.350f * scale));
        glEnd();

        //leg2
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.450f * scale));
        glVertex2f(xOrigin + (-0.840f * scale), yOrigin_Arjun + (-0.410f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.840f * scale), yOrigin_Arjun + (-0.410f * scale));
        glVertex2f(xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.360f * scale));
        glEnd();
        glBegin(GL_LINE_STRIP);
        glVertex2f(xOrigin + (-0.860f * scale), yOrigin_Arjun + (-0.360f * scale));
        glVertex2f(xOrigin + (-0.885f * scale), yOrigin_Arjun + (-0.350f * scale));
        glEnd();
        glLineWidth(1.0f);

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.768f * scale), yOrigin_Arjun + (-0.250f * scale));
        glVertex2f(xOrigin + (-0.773f * scale), yOrigin_Arjun + (-0.370f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.373f * scale));
        glVertex2f(xOrigin + (-0.625f * scale), yOrigin_Arjun + (-0.350f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.770f * scale), yOrigin_Arjun + (-0.373f * scale));
        glVertex2f(xOrigin + (-0.825f * scale), yOrigin_Arjun + (-0.355f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.825f * scale), yOrigin_Arjun + (-0.355f * scale));
        glVertex2f(xOrigin + (-0.885f * scale), yOrigin_Arjun + (-0.350f * scale));
        glEnd();
    }
}

void drawHandAndClothArjun(float xOrigin, float yOrigin_Arjun, float scale, int iHandPosition)
{
    // Ear rudraksh
    drawcircleArjun(
        xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.1300f * scale),
        (0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

    //neck thread
    glColor3f(0.63f, 0.53f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.0800f * scale));
    glVertex2f(xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.0700f * scale));
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7650f * scale), yOrigin_Arjun + (0.0700f * scale));
    glVertex2f(xOrigin + (-0.7500f * scale), yOrigin_Arjun + (0.0700f * scale));
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7500f * scale), yOrigin_Arjun + (0.0700f * scale));
    glVertex2f(xOrigin + (-0.7350f * scale), yOrigin_Arjun + (0.0800f * scale));
    glEnd();

    //locket 
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7825f * scale), yOrigin_Arjun + (0.0800f * scale));
    glVertex2f(xOrigin + (-0.7700f * scale), yOrigin_Arjun + (0.0000f * scale));
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7700f * scale), yOrigin_Arjun + (0.0000f * scale));
    glVertex2f(xOrigin + (-0.7500f * scale), yOrigin_Arjun + (-0.0500f * scale));
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7500f * scale), yOrigin_Arjun + (-0.0500f * scale));
    glVertex2f(xOrigin + (-0.7400f * scale), yOrigin_Arjun + (-0.0200f * scale));
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(xOrigin + (-0.7400f * scale), yOrigin_Arjun + (-0.0200f * scale));
    glVertex2f(xOrigin + (-0.7350f * scale), yOrigin_Arjun + (0.0800f * scale));
    glEnd();

    drawcircleArjun(
        xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.0500f * scale),
        (0.005f * scale), (0.005f * scale), 0.33f, 0.11f, 0.0f, 1);

    {
        //shoulder cloth
        ARJUN_SHOULDER_CLOTH_MAJOR

        drawQuadrangleArjun(
            xOrigin + (-0.680f * scale), yOrigin_Arjun + (0.051f * scale),
            xOrigin + (-0.720f * scale), yOrigin_Arjun + (0.071f * scale),
            xOrigin + (-0.760f * scale), yOrigin_Arjun + (-0.325f * scale),
            xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.345f * scale));

        glLineWidth(5.0f);
        ARJUN_SHOULDER_CLOTH_MINOR
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (0.071f * scale));
        glVertex2f(xOrigin + (-0.760f * scale), yOrigin_Arjun + (-0.325f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.760f * scale), yOrigin_Arjun + (-0.325f * scale));
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.345f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.680f * scale), yOrigin_Arjun + (0.051f * scale));
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.345f * scale));
        glEnd();

        glLineWidth(1.0f);

        ARJUN_SHOULDER_CLOTH_MAJOR

        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.800f * scale), yOrigin_Arjun + (0.075f * scale));
        glVertex2f(xOrigin + (-0.830f * scale), yOrigin_Arjun + (0.060f * scale));
        glVertex2f(xOrigin + (-0.800f * scale), yOrigin_Arjun + (0.015f * scale));
        glVertex2f(xOrigin + (-0.780f * scale), yOrigin_Arjun + (-0.035f * scale));
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.090f * scale));
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.050f * scale));
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.090f * scale));
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.050f * scale));
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.090f * scale));
        glVertex2f(xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.140f * scale));
        glVertex2f(xOrigin + (-0.745f * scale), yOrigin_Arjun + (-0.160f * scale));
        glVertex2f(xOrigin + (-0.700f * scale), yOrigin_Arjun + (-0.080f * scale));
        glEnd();

        glLineWidth(5.0f);
        ARJUN_SHOULDER_CLOTH_MINOR
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.800f * scale), yOrigin_Arjun + (0.075f * scale));
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.050f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.765f * scale), yOrigin_Arjun + (-0.050f * scale));
        glVertex2f(xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.090f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.750f * scale), yOrigin_Arjun + (-0.090f * scale));
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.080f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.080f * scale));
        glVertex2f(xOrigin + (-0.690f * scale), yOrigin_Arjun + (-0.050f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.749f * scale), yOrigin_Arjun + (-0.155f * scale));
        glVertex2f(xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.150f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.740f * scale), yOrigin_Arjun + (-0.150f * scale));
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.145f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.720f * scale), yOrigin_Arjun + (-0.145f * scale));
        glVertex2f(xOrigin + (-0.710f * scale), yOrigin_Arjun + (-0.135f * scale));
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.710f * scale), yOrigin_Arjun + (-0.135f * scale));
        glVertex2f(xOrigin + (-0.695f * scale), yOrigin_Arjun + (-0.095f * scale));
        glEnd();

        glLineWidth(1.0f);
    }

    {
        SKIN_COLOR
            //Hands
            drawQuadrangleArjun(
                xOrigin + (-0.835f * scale), yOrigin_Arjun + (0.050f * scale),
                xOrigin + (-0.845f * scale), yOrigin_Arjun + (0.0166f * scale),
                xOrigin + (-0.844f * scale), yOrigin_Arjun + (-0.050f * scale),
                xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.080f * scale)
            );

        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.833f * scale), yOrigin_Arjun + (-0.080f * scale));
        glVertex2f(xOrigin + (-0.760f * scale), yOrigin_Arjun + (-0.235f * scale));
        glEnd();

        //Back side hand
        // Using uniform skin color for the hand (for the back side)
        SKIN_COLOR
            drawQuadrangleArjun(
                xOrigin + (-0.6550f * scale), yOrigin_Arjun + (-0.250f * scale),
                xOrigin + (-0.6875f * scale), yOrigin_Arjun + (-0.160f * scale),
                xOrigin + (-0.6800f * scale), yOrigin_Arjun + (0.050f * scale),
                xOrigin + (-0.6550f * scale), yOrigin_Arjun + (-0.1350f * scale)
            );

        drawQuadrangleArjun(
            xOrigin + (-0.6250f * scale), yOrigin_Arjun + (-0.075f * scale),
            xOrigin + (-0.6550f * scale), yOrigin_Arjun + (-0.1350f * scale),
            xOrigin + (-0.6550f * scale), yOrigin_Arjun + (-0.250f * scale),
            xOrigin + (-0.6100f * scale), yOrigin_Arjun + (-0.095f * scale)
        );

        drawTriangleArjun(
            xOrigin + (-0.6250f * scale), yOrigin_Arjun + (-0.075f * scale),
            xOrigin + (-0.6100f * scale), yOrigin_Arjun + (-0.095f * scale),
            xOrigin + (-0.6000f * scale), yOrigin_Arjun + (-0.080f * scale)
        );

        drawQuadrangleArjun(
            xOrigin + (-0.6250f * scale), yOrigin_Arjun + (-0.075f * scale),
            xOrigin + (-0.6000f * scale), yOrigin_Arjun + (-0.080f * scale),
            xOrigin + (-0.5950f * scale), yOrigin_Arjun + (-0.010f * scale),
            xOrigin + (-0.6175f * scale), yOrigin_Arjun + (0.020f * scale)
        );

        drawTriangleArjun(
            xOrigin + (-0.5950f * scale), yOrigin_Arjun + (-0.010f * scale),
            xOrigin + (-0.6175f * scale), yOrigin_Arjun + (0.020f * scale),
            xOrigin + (-0.6050f * scale), yOrigin_Arjun + (0.024f * scale)
        ); //finger tips

        if (iHandPosition == 1)
        {
            drawQuadrangleArjun(
                xOrigin + (-0.6250f * scale), yOrigin_Arjun + (-0.075f * scale),
                xOrigin + (-0.6300f * scale), yOrigin_Arjun + (-0.050f * scale),
                xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.010f * scale),
                xOrigin + (-0.6100f * scale), yOrigin_Arjun + (-0.010f * scale)
            ); //thumb
        }
        else
        {
            drawQuadrangleArjun(
                xOrigin + (-0.6249f * scale), yOrigin_Arjun + (-0.075f * scale),
                xOrigin + (-0.6400f * scale), yOrigin_Arjun + (-0.010f * scale),
                xOrigin + (-0.6350f * scale), yOrigin_Arjun + (-0.010f * scale),
                xOrigin + (-0.6200f * scale), yOrigin_Arjun + (-0.036f * scale)
            ); //thumb
        }

        //fingers
        {
            glColor3f(0.6f, 0.6f, 0.6f);
            if (iHandPosition == 1)
            {
                glBegin(GL_LINES);
                glVertex2f(xOrigin + (-0.6190f * scale), yOrigin_Arjun + (-0.006f * scale));
                glVertex2f(xOrigin + (-0.6230f * scale), yOrigin_Arjun + (-0.036f * scale));
                glEnd();
            }

            glBegin(GL_LINES);
            glVertex2f(xOrigin + (-0.6100f * scale), yOrigin_Arjun + (0.019f * scale));
            glVertex2f(xOrigin + (-0.6140f * scale), yOrigin_Arjun + (-0.024f * scale));
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(xOrigin + (-0.6030f * scale), yOrigin_Arjun + (0.013f * scale));
            glVertex2f(xOrigin + (-0.6070f * scale), yOrigin_Arjun + (-0.030f * scale));
            glEnd();

            glBegin(GL_LINES);
            glVertex2f(xOrigin + (-0.5980f * scale), yOrigin_Arjun + (0.001f * scale));
            glVertex2f(xOrigin + (-0.6020f * scale), yOrigin_Arjun + (-0.036f * scale));
            glEnd();
        }

        if (iHandPosition == 1)
        {
            //front side hand
            SKIN_COLOR
                drawQuadrangleArjun(
                    xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.075f * scale),
                    xOrigin + (-0.7500f * scale), yOrigin_Arjun + (-0.160f * scale),
                    xOrigin + (-0.7600f * scale), yOrigin_Arjun + (-0.235f * scale),
                    xOrigin + (-0.6125f * scale), yOrigin_Arjun + (-0.100f * scale)
                );

            drawTriangleArjun(
                xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.075f * scale),
                xOrigin + (-0.6125f * scale), yOrigin_Arjun + (-0.100f * scale),
                xOrigin + (-0.6000f * scale), yOrigin_Arjun + (-0.080f * scale)
            );

            drawQuadrangleArjun(
                xOrigin + (-0.6250f * scale), yOrigin_Arjun + (-0.075f * scale),
                xOrigin + (-0.6000f * scale), yOrigin_Arjun + (-0.080f * scale),
                xOrigin + (-0.5950f * scale), yOrigin_Arjun + (-0.010f * scale),
                xOrigin + (-0.6175f * scale), yOrigin_Arjun + (0.020f * scale)
            );

            drawTriangleArjun(
                xOrigin + (-0.5950f * scale), yOrigin_Arjun + (-0.010f * scale),
                xOrigin + (-0.6175f * scale), yOrigin_Arjun + (0.020f * scale),
                xOrigin + (-0.6050f * scale), yOrigin_Arjun + (0.024f * scale)
            ); //finger tips

            drawQuadrangleArjun(
                xOrigin + (-0.6250f * scale), yOrigin_Arjun + (-0.075f * scale),
                xOrigin + (-0.6300f * scale), yOrigin_Arjun + (-0.050f * scale),
                xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.010f * scale),
                xOrigin + (-0.6100f * scale), yOrigin_Arjun + (-0.010f * scale)
            ); //thumb

            //fingers
            {
                glColor3f(0.6f, 0.6f, 0.6f);
                glBegin(GL_LINES);
                glVertex2f(xOrigin + (-0.6190f * scale), yOrigin_Arjun + (-0.006f * scale));
                glVertex2f(xOrigin + (-0.6230f * scale), yOrigin_Arjun + (-0.036f * scale));
                glEnd();

                glBegin(GL_LINES);
                glVertex2f(xOrigin + (-0.6100f * scale), yOrigin_Arjun + (0.019f * scale));
                glVertex2f(xOrigin + (-0.6140f * scale), yOrigin_Arjun + (-0.024f * scale));
                glEnd();

                glBegin(GL_LINES);
                glVertex2f(xOrigin + (-0.6030f * scale), yOrigin_Arjun + (0.013f * scale));
                glVertex2f(xOrigin + (-0.6070f * scale), yOrigin_Arjun + (-0.030f * scale));
                glEnd();

                glBegin(GL_LINES);
                glVertex2f(xOrigin + (-0.5980f * scale), yOrigin_Arjun + (0.001f * scale));
                glVertex2f(xOrigin + (-0.6020f * scale), yOrigin_Arjun + (-0.036f * scale));
                glEnd();
            }
        }
        else
        {
            SKIN_COLOR
                drawQuadrangleArjun(
                    xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.170f * scale),
                    xOrigin + (-0.7500f * scale), yOrigin_Arjun + (-0.160f * scale),
                    xOrigin + (-0.7600f * scale), yOrigin_Arjun + (-0.235f * scale),
                    xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.195f * scale)
                );

            drawQuadrangleArjun(
                xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.170f * scale),
                xOrigin + (-0.5900f * scale), yOrigin_Arjun + (-0.180f * scale),
                xOrigin + (-0.5900f * scale), yOrigin_Arjun + (-0.200f * scale),
                xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.195f * scale)
            );

            drawQuadrangleArjun(
                xOrigin + (-0.5900f * scale), yOrigin_Arjun + (-0.180f * scale),
                xOrigin + (-0.5700f * scale), yOrigin_Arjun + (-0.170f * scale),
                xOrigin + (-0.5720f * scale), yOrigin_Arjun + (-0.180f * scale),
                xOrigin + (-0.5900f * scale), yOrigin_Arjun + (-0.200f * scale)
            );

            drawTriangleArjun(
                xOrigin + (-0.6275f * scale), yOrigin_Arjun + (-0.170f * scale),
                xOrigin + (-0.6000f * scale), yOrigin_Arjun + (-0.150f * scale),
                xOrigin + (-0.6100f * scale), yOrigin_Arjun + (-0.195f * scale)
            );
        }
    }

    {

        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.815f * scale), yOrigin_Arjun + (-0.12f * scale));
        glVertex2f(xOrigin + (-0.767f * scale), yOrigin_Arjun + (-0.08f * scale));
        glEnd();

        glLineWidth(1.0);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.818f * scale), yOrigin_Arjun + (-0.11f * scale));
        glVertex2f(xOrigin + (-0.768f * scale), yOrigin_Arjun + (-0.07f * scale));
        glEnd();

        glLineWidth(1.0);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.68f * scale), yOrigin_Arjun + (-0.10f * scale));
        glVertex2f(xOrigin + (-0.662f * scale), yOrigin_Arjun + (-0.08f * scale));
        glEnd();

        glLineWidth(1.0);
        glBegin(GL_LINES);
        glVertex2f(xOrigin + (-0.68f * scale), yOrigin_Arjun + (-0.09f * scale));
        glVertex2f(xOrigin + (-0.663f * scale), yOrigin_Arjun + (-0.07f * scale));
        glEnd();
    }
}

void showDhanushyaArjun(float fOriginX, float fOriginY, float fResize)
{
    fOriginX -= 0.62f;
    fOriginY += 0.05f;

    drawEllipseArjun(
        fOriginX, fOriginY + 0.13f,
        (PI / 2.0f), 3.0f * PI / 2.0f,
        0.0f, 0.0f, 0.0f,
        0.02f, 0.03f);

    drawEllipseArjun(
        fOriginX, fOriginY,
        -(PI / 2.0f), PI / 2.0f,
        0.0f, 0.0f, 0.0f,
        0.05f, 0.10f);

    drawEllipseArjun(
        fOriginX, fOriginY - 0.20f,
        -(PI / 2.0f), PI / 2.0f,
        0.0f, 0.0f, 0.0f,
        0.05f, 0.10f);

    drawEllipseArjun(
        fOriginX, fOriginY - 0.20f - 0.13f,
        (PI / 2.0f), 3.0f * PI / 2.0f,
        0.0f, 0.0f, 0.0f,
        0.02f, 0.03f);

    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(fOriginX - 0.02f, fOriginY + 0.13f);
    glVertex2f(fOriginX - 0.02f, fOriginY - 0.20f - 0.13f);
    glEnd();
}

void drawEllipseArjun(
    float startX, float startY,
    float startAngle, float endAngle,
    float rColor, float gColor, float bColor,
    float hRadius, float vRadius)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    glColor4f(rColor, gColor, bColor, 1.0f);

    glLineWidth(5.0f);
    glBegin(GL_LINE_STRIP);

    for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.001f)
    {
        ObjX = startX + hRadius * cos(ObjAngle);
        ObjY = startY + vRadius * sin(ObjAngle);

        glVertex3f(ObjX, ObjY, 1.0f);
    }
    glEnd();
}

