#include "../common.h"

extern FILE *gpFile;

struct Dots
{
    float x;
    float y;
    float dotColor;
};

void drawBushAt(float centerX, float centerY, float radiusX, float radiusY)
{
    // function prototypes
    float getRandomFloat();
    void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle);

    // variable declarations
    static int setDots = 1;
    int numberOfDots = 500;
    static struct Dots dots[500];

    if (setDots != 0)
    {
        for (int i = 0; i < numberOfDots; i++)
        {
            // Generate random polar coordinates within the bush radius
            float radiusXUpdated = radiusX * sqrt(getRandomFloat()); // sqrt for uniform distribution
            float radiusYUpdated = radiusY * sqrt(getRandomFloat()); // sqrt for uniform distribution
            float angle = 2.0f * PI * getRandomFloat();

            // Convert polar to Cartesian coordinates
            dots[i].x = radiusXUpdated * cos(angle);
            dots[i].y = radiusYUpdated * sin(angle);
            dots[i].dotColor = 0.2f + 0.8f * getRandomFloat();
        }

        // after setting the dots for one time, they should not be changed
        setDots = 0;
    }

    // bush filling
    glPointSize(3.0f); // Adjust point size as needed
    glBegin(GL_POINTS);
    for (int i = 0; i < numberOfDots; i++)
    {
        // plot dots
        glColor3f(0.0f, dots[i].dotColor, 0.0f);              // Set the color
        glVertex2f(centerX + dots[i].x, centerY + dots[i].y); // Draw the point
    }
    glEnd();

    // bush outline curves
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    setCircularCurvePoints(centerX, centerY, radiusX, radiusY, 0.0f, 2 * PI);
    glEnd();
}

// Function to generate a random float between 0 and 1
float getRandomFloat()
{
    return (float)rand() / (float)RAND_MAX;
}

void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle)
{
    float ObjX = 0.0f;
    float ObjY = 0.0f;
    float ObjAngle = 0.0f;

    for (ObjAngle = startAngle; ObjAngle <= endAngle; ObjAngle += 0.01f)
    {
        ObjX = centerX + radiusH * cos(ObjAngle);
        ObjY = centerY + radiusV * sin(ObjAngle);
        glVertex2f(ObjX, ObjY);
    }
}


void drawPolygon(SHAPE shape, struct MY_POINT scalingFactor, struct MY_POINT translationFactor, struct MY_POINT reflectionFactor)
{
    glColor3f(shape.rValue > 1 ? (shape.rValue / 255.0f) : shape.rValue,
        shape.gValue > 1 ? (shape.gValue / 255.0f) : shape.gValue,
        shape.bValue > 1 ? (shape.bValue / 255.0f) : shape.bValue);
    glBegin(GL_POLYGON);

    for (int i = 0; i < shape.noOfPoints; i++)
    {
        struct MY_POINT newPoint = { shape.points[i].x, shape.points[i].y, shape.points[i].z };
        newPoint = scalePoint(newPoint, scalingFactor);
        newPoint = translatePoint(newPoint, translationFactor);
        newPoint = reflectPoint(newPoint, reflectionFactor);

        glVertex3f((GLfloat)(newPoint.x), (GLfloat)(newPoint.y), (GLfloat)(newPoint.z));
    }

    glEnd();
}

struct MY_POINT scalePoint(struct MY_POINT point, struct MY_POINT scalingFactor)
{
    struct MY_POINT newPoint = { (scalingFactor.x) * (point.x),
                                 (scalingFactor.y) * (point.y),
                                 (scalingFactor.z) * (point.z) };
    return newPoint;
}

struct MY_POINT translatePoint(struct MY_POINT point, struct MY_POINT translationFactor)
{
    struct MY_POINT newPoint = { translationFactor.x + point.x,
                                 translationFactor.y + point.y,
                                 translationFactor.z + point.z };
    return newPoint;
}

// to reflect by x axis : reflectionFactor = {1, -1, 0}
// to reflect by y axis : reflectionFactor = {-1, 1, 0}
struct MY_POINT reflectPoint(struct MY_POINT point, struct MY_POINT reflectionFactor)
{
    struct MY_POINT newPoint = { reflectionFactor.x * point.x,
                                 reflectionFactor.y * point.y,
                                 reflectionFactor.z * point.z };
    return newPoint;
}