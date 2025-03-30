#include "../common.h"

extern FILE *gpFile;

/*
 * How to call
 *	drawSudarshanChakra((MY_POINT){-0.5f, 0.0f, 0.0f}, (TRANSLATION){0.0f, 0.0f, 0.0f}, (SCALING){0.2f, 0.2f, 0.2f});
 *	drawSudarshanChakra((MY_POINT){0.5f, 0.0f, 0.0f}, (TRANSLATION){0.0f, 0.0f, 0.0f}, (SCALING){0.2f, 0.2f, 0.2f});
 *
 */

void drawSudarshanChakra(MY_POINT center, TRANSLATION translateBy, SCALING scaleBy)
{

    // variable declarations
    // variables used in loops
    float objX = 0.0f;
    float objY = 0.0f;
    float objAngle = 0.0f;

    // chakra radius
    static ANGLE rotateBy = {0.0f, 0.0f, 0.0f};
    RADIUS unitValue = {0.8f * scaleBy.x, 0.3f * scaleBy.y, 0.3f * scaleBy.z};
    RADIUS outerRadius = {unitValue.x, unitValue.y, unitValue.z};
    RADIUS innerRadius = {outerRadius.x * 0.1f, outerRadius.y * 0.1f, outerRadius.z * 0.1f};
    RADIUS ringOfSmallCircleRadius = {outerRadius.x * 0.7f, outerRadius.y * 0.7f, outerRadius.z * 0.7f};
    RADIUS circleOnTheRingRadius = {outerRadius.x * 0.1f, outerRadius.y * 0.1f, outerRadius.z * 0.1f};
    RADIUS chakraSpikeApexRadius = {outerRadius.x * 1.1f, outerRadius.y * 1.1f, outerRadius.z * 1.1f};

    float ringCircleAngle = 0.0f;

    // spikes
    glColor3f(0.906, 0.804, 0.471);
    glBegin(GL_TRIANGLES);
    for (objAngle = 0.0; objAngle <= (2 * PI); objAngle += (PI / 16))
    {
        objX = center.x + (outerRadius.x * cos(objAngle + rotateBy.y));
        objY = center.y + (outerRadius.y * WINDOW_ASPECT * sin(objAngle + rotateBy.y));
        glVertex3f(objX, objY, 0.0f);

        objAngle += (PI / 16);
        objX = center.x + (chakraSpikeApexRadius.x * cos(objAngle + rotateBy.y));
        objY = center.y + (chakraSpikeApexRadius.y * WINDOW_ASPECT * sin(objAngle + rotateBy.y));
        glVertex3f(objX, objY, 0.0f);

        objAngle += (PI / 16);
        objX = center.x + (outerRadius.x * cos(objAngle + rotateBy.y));
        objY = center.y + (outerRadius.y * WINDOW_ASPECT * sin(objAngle + rotateBy.y));
        glVertex3f(objX, objY, 0.0f);

        objAngle -= (PI / 16);
    }
    glEnd();

    // chakra disk
    glColor3f(0.945, 0.89, 0.643); // gold color
    glBegin(GL_TRIANGLE_STRIP);
    for (objAngle = 0.0; objAngle <= ((2 * PI) + 0.1f); objAngle += 0.01f)
    {
        objX = center.x + (outerRadius.x * cos(objAngle));
        objY = center.y + (outerRadius.y * WINDOW_ASPECT * sin(objAngle));
        glVertex3f(objX, objY, 0.0f);

        objX = center.x + (innerRadius.x * cos(objAngle));
        objY = center.y + (innerRadius.y * WINDOW_ASPECT * sin(objAngle));
        glVertex3f(objX, objY, 0.0f);
    }
    glEnd();

    // smalls circles forming a ring
    ringCircleAngle = 0.0f;
    while (ringCircleAngle < 2 * PI)
    {
        // calculating the center of circle on ring
        MY_POINT ringCircleCenter = {0.0f, 0.0f, 0.0f};
        ringCircleCenter.x = center.x + (ringOfSmallCircleRadius.x * cos(ringCircleAngle + rotateBy.y));
        ringCircleCenter.y = center.y + (ringOfSmallCircleRadius.y * WINDOW_ASPECT * sin(ringCircleAngle + rotateBy.y));

        glColor3f(1.0f, 0.0f, 0.0f); // gold color
        glBegin(GL_TRIANGLE_FAN);
        for (objAngle = 0.0; objAngle <= (2 * PI); objAngle += 0.01f)
        {
            objX = ringCircleCenter.x + (circleOnTheRingRadius.x * cos(objAngle));
            objY = ringCircleCenter.y + (circleOnTheRingRadius.y * WINDOW_ASPECT * sin(objAngle));
            glVertex3f(objX, objY, 0.0f);
        }
        glEnd();

        ringCircleAngle += (PI / 8); // dividing by 16 because of 16 ring circles
    }

    if (rotateBy.y >= 2 * PI)
    {
        rotateBy.y = 0.0f;
    }

    rotateBy.y += 0.05f;
}
