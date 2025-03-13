#include "../common.h"

extern FILE *gpFile;

void rath(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy)
{
    // function prototypes
    void wheel(MY_POINT startPosition, RADIUS radius, TRANSLATION translateBy, SCALING scaleBy);
    void rathBody(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy);

    // code
    rathBody(startPosition, translateBy, scaleBy);

    RADIUS wheelRadius = (RADIUS){0.10f, 0.10f, 0.0f};
    wheel(startPosition, wheelRadius, translateBy, scaleBy);
}

void rathBody(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy)
{
    // function prototypes
    void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle);

    // code
    // roof pole
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.776f, 0.557f, 0.490f); // wooden pole color browinsh
    glVertex3f(startPosition.x, startPosition.y, startPosition.x);
    glVertex3f(startPosition.x, startPosition.y + 0.90f * scaleBy.y, startPosition.z);
    glEnd();

    // rath roof
    glBegin(GL_POLYGON);
    glColor3f(0.902, 0.753, 0.416); // gold color
    glVertex3f(startPosition.x + (0.20f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y + (0.35f * scaleBy.y), (0.20 * scaleBy.x), (0.20f * scaleBy.y), (80.0f * (PI / 180)), (115.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.30f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.949, 0.737, 0.239); // red ruby color
    glVertex3f(startPosition.x + (0.20f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y + (0.35f * scaleBy.y), (0.20 * scaleBy.x), (0.20f * scaleBy.y), (80.0f * (PI / 180)), (115.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.30f * scaleBy.x), startPosition.y + (0.80f * scaleBy.y), startPosition.z);
    glEnd();

    // rath deck
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.902, 0.753, 0.416);
    glVertex3f(startPosition.x, startPosition.y, startPosition.z);
    glVertex3f(startPosition.x + (0.15f * scaleBy.x), startPosition.y + (0.10f * scaleBy.y), startPosition.z);
    setCircularCurvePoints(startPosition.x, startPosition.y, 0.25f * scaleBy.x, 0.25f * scaleBy.y, (65.0f * (PI / 180)), (100.0f * (PI / 180)));
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
    setCircularCurvePoints(startPosition.x, startPosition.y, 0.25f * scaleBy.x, 0.25f * scaleBy.y, (65.0f * (PI / 180)), (100.0f * (PI / 180)));
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.45f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.20f * scaleBy.x), startPosition.y + (0.25f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.40f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.50f * scaleBy.x), startPosition.y + (0.05f * scaleBy.y), startPosition.z);
    glVertex3f(startPosition.x - (0.50f * scaleBy.x), startPosition.y, startPosition.z);
    glEnd();

    // rath decors
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.675, 0.071, 0.333);
    fprintf(gpFile, "inside rathBody startPositionX: %f, startPositionY: %f\n", startPosition.x, startPosition.y);
    setCircularCurvePoints(startPosition.x - (0.10f * scaleBy.x), startPosition.y + (0.45f * scaleBy.y), (0.05 * scaleBy.x), (0.05 * scaleBy.y), 0.0f, 2 * PI);
    // setCircularCurvePoints(0, 0, (0.05 * scaleBy.x), (0.05 * scaleBy.y), 0.0f, 2 * PI);
    glEnd();
}

void wheel(MY_POINT startPosition, RADIUS radius, TRANSLATION translateBy, SCALING scaleBy)
{
    // function prototypes
    void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle);

    // Draw outer circle
    glLineWidth(10.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.541, 0.373, 0.204); // brownish color
    setCircularCurvePoints(startPosition.x, startPosition.y, radius.x * scaleBy.x, radius.y * scaleBy.y, 0.0f, 2 * PI);
    glEnd();

    // Draw center shaft circles
    glLineWidth(3.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(0.541, 0.373, 0.204); // brownish color
    // 0.20 is for 20 % of radius
    setCircularCurvePoints(startPosition.x, startPosition.y, radius.x * scaleBy.x * 0.20f, radius.y * scaleBy.y * 0.20f, 0.0f, 2 * PI);
    glEnd();

    glBegin(GL_LINE_STRIP);
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
        float x2 = startPosition.x + radius.x * scaleBy.x * cos(angle);
        float y2 = startPosition.y + radius.y * scaleBy.y * WINDOW_ASPECT * sin(angle);
        float x3 = startPosition.x + radius.x * scaleBy.x * cos(angle + angleStep / 2);
        float y3 = startPosition.y + radius.y * scaleBy.y * WINDOW_ASPECT * sin(angle + angleStep / 2);

        glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glEnd();
    }
}
