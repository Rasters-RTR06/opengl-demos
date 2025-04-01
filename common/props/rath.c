#include "../common.h"

extern FILE *gpFile;

GLboolean bShowRath = FALSE;
GLboolean bMoveRath = FALSE;

void rath(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy)
{
    // function prototypes
    void wheel(MY_POINT startPosition, RADIUS radius, TRANSLATION translateBy, SCALING scaleBy);
    void rathBody(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy);

    // code
    MY_POINT anchorPoint = (MY_POINT){startPosition.x + translateBy.x, startPosition.y + translateBy.y, startPosition.z + translateBy.z};
    rathBody(anchorPoint, translateBy, scaleBy);

    RADIUS wheelRadius = (RADIUS){0.10f, 0.10f, 0.0f};
    wheel(anchorPoint, wheelRadius, translateBy, scaleBy);
}

void rathBody(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy)
{
    // function prototypes
    void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle);
    void drawOM(float originx, float originy, float resize);

    // variable declaration
    float ObjAngle = 0.0f;
    float ObjX = 0.0f;
    float ObjY = 0.0f;

    // code
    // roof pole
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.776f, 0.557f, 0.490f); // wooden pole color browinsh
    glVertex3f(startPosition.x, startPosition.y, startPosition.x);
    glVertex3f(startPosition.x, startPosition.y + (1.15 * scaleBy.y), startPosition.z);
    glEnd();

    // rath roof
    glBegin(GL_POLYGON);
    glColor3f(0.902, 0.753, 0.416); // gold color
    glVertex3f(startPosition.x + (0.20f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y + (0.65f * scaleBy.y), (0.20 * scaleBy.x), (0.20f * scaleBy.y), (80.0f * (PI / 180)), (115.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.30f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.949, 0.737, 0.239); // red ruby color
    glVertex3f(startPosition.x + (0.20f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y + (0.65f * scaleBy.y), (0.20 * scaleBy.x), (0.20f * scaleBy.y), (80.0f * (PI / 180)), (115.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.30f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    glEnd();

    // rath deck
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.902, 0.753, 0.416);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (0.10f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y, (0.25f * scaleBy.x), (0.25f * scaleBy.y), (65.0f * (PI / 180)), (100.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.45f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.20f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.40f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.50f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.50f * scaleBy.x), startPosition.y, startPosition.z);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.949, 0.737, 0.239);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (0.10f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y, (0.25f * scaleBy.x), (0.25f * scaleBy.y), (65.0f * (PI / 180)), (100.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.45f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.20f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.40f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.50f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.50f * scaleBy.x), startPosition.y, startPosition.z);
    glEnd();

    // rath decors
    // flag on pole
    glBegin(GL_TRIANGLES);
    glColor3f(0.957f, 0.643f, 0.376f); // saffron color
    glVertex3f(startPosition.x, startPosition.y + (1.15f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (1.10f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x, startPosition.y + (1.05f * scaleBy.y), startPosition.z);
    glEnd();

    drawOM(startPosition.x + (0.05f * scaleBy.x), startPosition.y + (1.10f * scaleBy.y), 0.03f);

    // Tassels hanging from roof
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(0.824f, 0.412f, 0.118f); // deep orange
    // Left tassel
    glVertex3f(startPosition.x - (0.25f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.25f * scaleBy.x), startPosition.y + (0.70f * scaleBy.y), startPosition.z);
    // Right tassel
    glVertex3f(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (0.70f * scaleBy.y), startPosition.z);
    glEnd();

    // Tassel ends (small circles)
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.824f, 0.412f, 0.118f);
    setCircularCurvePoints(startPosition.x - (0.25f * scaleBy.x), startPosition.y + (0.70f * scaleBy.y),
                           (0.02f * scaleBy.x), (0.02f * scaleBy.y), 0.0f, 2 * PI);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.824f, 0.412f, 0.118f);
    setCircularCurvePoints(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (0.70f * scaleBy.y),
                           (0.02f * scaleBy.x), (0.02f * scaleBy.y), 0.0f, 2 * PI);
    glEnd();

    // 4. Small decorative studs on roof
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.961f, 0.871f, 0.702f); // light gold
    setCircularCurvePoints(startPosition.x - (0.05f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y),
                           (0.015f * scaleBy.x), (0.015f * scaleBy.y), 0.0f, 2 * PI);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.961f, 0.871f, 0.702f);
    setCircularCurvePoints(startPosition.x + (0.10f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y),
                           (0.015f * scaleBy.x), (0.015f * scaleBy.y), 0.0f, 2 * PI);
    glEnd();

    // lines on corner

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.675, 0.071, 0.333);
    setCircularCurvePoints(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.45f * scaleBy.y), (0.01 * scaleBy.x), (0.01 * scaleBy.y), 0.0f, 2 * PI);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.675, 0.071, 0.333);
    setCircularCurvePoints(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), (0.01 * scaleBy.x), (0.01 * scaleBy.y), 0.0f, 2 * PI);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.675, 0.071, 0.333);
    setCircularCurvePoints(startPosition.x - (0.20f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), (0.01 * scaleBy.x), (0.01 * scaleBy.y), 0.0f, 2 * PI);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.675, 0.071, 0.333);
    setCircularCurvePoints(startPosition.x - (0.40f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), (0.01 * scaleBy.x), (0.01 * scaleBy.y), 0.0f, 2 * PI);
    glEnd();

    glLineWidth(5.0f);
    glColor3f(0.816, 0.58, 0.502);
    glBegin(GL_LINES);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.45f * scaleBy.y), startPosition.z);
    glEnd();

    glLineWidth(5.0f);
    glColor3f(0.816, 0.58, 0.502);
    glBegin(GL_LINES);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glEnd();

    glLineWidth(5.0f);
    glColor3f(0.816, 0.58, 0.502);
    glBegin(GL_LINES);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x - (0.20f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glEnd();

    glLineWidth(5.0f);
    glColor3f(0.816, 0.58, 0.502);
    glBegin(GL_LINES);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x - (0.40f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glEnd();
}

void wheel(MY_POINT startPosition, RADIUS radius, TRANSLATION translateBy, SCALING scaleBy)
{
    // function prototypes
    void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle);

    // variable declaration
    static float rotateBy = 0.0f;
    float ObjAngle = 0.0f;
    float ObjX = 0.0f;
    float ObjY = 0.0f;

    // Draw outer circle
    glLineWidth(10.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.541, 0.373, 0.204); // brownish color
    setCircularCurvePoints(startPosition.x, startPosition.y, radius.x * scaleBy.x, radius.y * scaleBy.y, 0.0f, 2 * PI);
    glEnd();

    // Draw center shaft circles
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.541, 0.373, 0.204); // brownish color
    // 0.20 is for 20 % of radius
    setCircularCurvePoints(startPosition.x, startPosition.y, radius.x * scaleBy.x * 0.20f, radius.y * scaleBy.y * 0.20f, 0.0f, 2 * PI);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.541, 0.373, 0.204);
    // 0.10 is for 10 % of radius
    setCircularCurvePoints(startPosition.x, startPosition.y, radius.x * scaleBy.x * 0.10f, radius.y * scaleBy.y * 0.10f, 0.0f, 2 * PI);
    glEnd();

    // Draw wheel spokes
    // 0.92 specifies spoke length of wheel to be 92% of wheel radius - removed later
    // window aspect to get perfect circle
    glColor3f(0.541, 0.373, 0.204); // brownish color
    int numSpokes = 10;
    float angleStep = 2.0f * PI / numSpokes;
    for (int i = 0; i < numSpokes; i++)
    {
        float angle = i * angleStep;
        float x1 = startPosition.x;
        float y1 = startPosition.y;
        float x2 = startPosition.x + (radius.x * scaleBy.x * cos(angle + rotateBy));
        float y2 = startPosition.y + (radius.y * scaleBy.y * WINDOW_ASPECT * sin(angle + rotateBy));
        float x3 = startPosition.x + (radius.x * scaleBy.x * cos(angle + (angleStep / 2) + rotateBy));
        float y3 = startPosition.y + (radius.y * scaleBy.y * WINDOW_ASPECT * sin(angle + (angleStep / 2) + rotateBy));

        glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glEnd();
    }

    if (bMoveRath == TRUE)
    {
        if (rotateBy >= 2 * PI)
        {
            rotateBy = 0.0f;
        }

        rotateBy += 0.05f;
    }
}
