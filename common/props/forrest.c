// customer header files
#include "../common.h"

extern FILE *gpFile;

// array of random floats (50)
float randomFloats[200] =
    {0.000123, 0.048659, 0.008744, 0.056581, 0.070940, 0.077847, 0.086422, 0.085055, 0.029301, 0.086438, 0.064492, 0.074685, 0.082864, 0.076562, 0.087191, 0.090832, 0.091253, 0.052196, 0.044017, 0.010764, 0.035401, 0.082305, 0.042772, 0.016984, 0.000085, 0.065746, 0.077355, 0.006372, 0.008982, 0.038566, 0.068389, 0.080761, 0.015409, 0.014286, 0.004846, 0.034614, 0.001856, 0.097842, 0.064763, 0.005365, 0.091415, 0.063747, 0.043171, 0.002106, 0.024259, 0.039195, 0.065401, 0.078188, 0.002283, 0.082604, 0.000123, 0.048659, 0.008744, 0.056581, 0.070940, 0.077847, 0.086422, 0.085055, 0.029301, 0.086438, 0.064492, 0.074685, 0.082864, 0.076562, 0.087191, 0.090832, 0.091253, 0.052196, 0.044017, 0.010764, 0.035401, 0.082305, 0.042772, 0.016984, 0.000085, 0.065746, 0.077355, 0.006372, 0.008982, 0.038566, 0.068389, 0.080761, 0.015409, 0.014286, 0.004846, 0.034614, 0.001856, 0.097842, 0.064763, 0.005365, 0.091415, 0.063747, 0.043171, 0.002106, 0.024259, 0.039195, 0.065401, 0.078188, 0.002283, 0.082604, 0.000123, 0.048659, 0.008744, 0.056581, 0.070940, 0.077847, 0.086422, 0.085055, 0.029301, 0.086438, 0.064492, 0.074685, 0.082864, 0.076562, 0.087191, 0.090832, 0.091253, 0.052196, 0.044017, 0.010764, 0.035401, 0.082305, 0.042772, 0.016984, 0.000085, 0.065746, 0.077355, 0.006372, 0.008982, 0.038566, 0.068389, 0.080761, 0.015409, 0.014286, 0.004846, 0.034614, 0.001856, 0.097842, 0.064763, 0.005365, 0.091415, 0.063747, 0.043171, 0.002106, 0.024259, 0.039195, 0.065401, 0.078188, 0.002283, 0.082604, 0.000123, 0.048659, 0.008744, 0.056581, 0.070940, 0.077847, 0.086422, 0.085055, 0.029301, 0.086438, 0.064492, 0.074685, 0.082864, 0.076562, 0.087191, 0.090832, 0.091253, 0.052196, 0.044017, 0.010764, 0.035401, 0.082305, 0.042772, 0.016984, 0.000085, 0.065746, 0.077355, 0.006372, 0.008982, 0.038566, 0.068389, 0.080761, 0.015409, 0.014286, 0.004846, 0.034614, 0.001856, 0.097842, 0.064763, 0.005365, 0.091415, 0.063747, 0.043171, 0.002106, 0.024259, 0.039195, 0.065401, 0.078188, 0.002283, 0.082604};

float frontForestMoveX = 0.0f;
GLboolean isFrontForrestMoving = FALSE;

struct Color
{
    float r;
    float g;
    float b;
    float alpha;
};

struct Dots
{
    float x;
    float y;
};

void updateFrontForest()
{
    while (isFrontForrestMoving == TRUE)
    {
        frontForestMoveX = frontForestMoveX - 0.001f;
    }
}

void drawGround()
{
    glBegin(GL_QUADS);
    glColor3f(0.008f, 0.275f, 0.231f);
    glVertex3f(-1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
}

void drawDenseForrest()
{
    // function prototypes
    float getRandomFloat();
    void drawPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor);
    void drawCompactPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor);
    void drawTallNarrowPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor);

    // variable declarations
    float plantStartX = -1.10f;
    float plantStartY = 0.0f;
    float plantSeparation = 0.12f;
    float randomFloat = 0.0f;

    int i, j;

    struct Color plantColorGreen = {0.004, 0.114, 0.165};

    // code
    for (j = 0; j < 10; j++)
    {
        for (i = 0; i < 20; i++)
        {
            randomFloat = randomFloats[i + (j * 20)];
            drawPlant(plantStartX + randomFloat, plantStartY + randomFloat, plantColorGreen, plantColorGreen);
            plantStartX = plantStartX + plantSeparation;
        }
        plantStartX = -1.10f;
        plantStartY = plantStartY + plantSeparation;
    }
}

void drawFrontTrees()
{
    // function prototypes
    void drawPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor);
    void drawCompactPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor);
    void drawTallNarrowPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor);

    // variable declarations
    struct Color plantColorGrayDarkGreen = {0.004, 0.114, 0.165};
    struct Color plantColorKindOfPink = {0.45f, 0.19f, 0.30f};
    struct Color plantColorGreen = {0.004, 0.114, 0.165};
    struct Color plantColorSupposedToBeYellow = {0.735f, 0.625f, 0.455f};

    // code
    drawCompactPlant(-1.30f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(-1.10f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(-0.90f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(-0.80f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);

    drawTallNarrowPlant(-0.70f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);

    drawCompactPlant(-0.60f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(-0.50f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(-0.40f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);

    drawTallNarrowPlant(-0.30f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);
    drawTallNarrowPlant(-0.20f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);

    drawCompactPlant(-0.10f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(0.00f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(0.10f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(0.20f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(0.30f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);

    drawTallNarrowPlant(0.40f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);
    drawTallNarrowPlant(0.50f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);
    drawTallNarrowPlant(0.60f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);

    drawCompactPlant(0.70f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
    drawCompactPlant(0.80f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);

    drawTallNarrowPlant(0.90f, -1.00f, plantColorGrayDarkGreen, plantColorKindOfPink);

    drawCompactPlant(1.00f, -1.00f, plantColorGrayDarkGreen, plantColorSupposedToBeYellow);
}

void drawTallNarrowPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor)
{
    // function prototypes
    void drawBushWith(float centerX, float centerY, float radiusX, float radiusY, int dotsCount, struct Color color);

    // code
    drawBushWith(startX + 0.0f, startY + 0.0f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.050f, startY + 0.0f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + -0.050f, startY + 0.0f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.040f, startY + 0.10f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.040f, startY + 0.10f, 0.10f, 0.10f, 100, petalColor);
    drawBushWith(startX + -0.040f, startY + 0.10f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.010f, startY + 0.10f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.030f, startY + 0.20f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.030f, startY + 0.20f, 0.10f, 0.10f, 100, petalColor);
    drawBushWith(startX + -0.030f, startY + 0.20f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.020f, startY + 0.20f, 0.10f, 0.10f, 5000, leavesColor);
    drawBushWith(startX + 0.025f, startY + 0.30f, 0.10f, 0.30f, 5000, leavesColor);
    drawBushWith(startX + 0.025f, startY + 0.30f, 0.10f, 0.30f, 100, petalColor);
    drawBushWith(startX + -0.025f, startY + 0.30f, 0.10f, 0.30f, 5000, leavesColor);
    drawBushWith(startX + 0.015f, startY + 0.40f, 0.10f, 0.30f, 5000, leavesColor);
    drawBushWith(startX + -0.015f, startY + 0.40f, 0.10f, 0.30f, 5000, leavesColor);
    drawBushWith(startX + 0.005f, startY + 0.50f, 0.10f, 0.30f, 5000, leavesColor);
    drawBushWith(startX + -0.005f, startY + 0.50f, 0.10f, 0.30f, 5000, leavesColor);
    drawBushWith(startX + -0.005f, startY + 0.50f, 0.10f, 0.30f, 100, petalColor);
    drawBushWith(startX + 0.005f, startY + 0.60f, 0.10f, 0.30f, 5000, leavesColor);
}

void drawCompactPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor)
{
    // function prototypes
    void drawBushWith(float centerX, float centerY, float radiusX, float radiusY, int dotsCount, struct Color color);

    // code
    drawBushWith(startX + 0.0f, startY + 0.0f, 0.10f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + 0.05f, startY + 0.00f, 0.10f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + 0.05f, startY + 0.00f, 0.10f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.05f, startY + 0.00f, 0.10f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.05f, startY + 0.00f, 0.10f, 0.10f, 200, petalColor);
    drawBushWith(startX + 0.025f, startY + 0.05f, 0.10f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.025f, startY + 0.05f, 0.10f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.025f, startY + 0.05f, 0.10f, 0.10f, 200, petalColor);
    drawBushWith(startX + -0.025f, startY + 0.10f, 0.05f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + 0.010f, startY + 0.10f, 0.05f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + 0.030f, startY + 0.10f, 0.05f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + 0.030f, startY + 0.10f, 0.05f, 0.10f, 200, petalColor);
    drawBushWith(startX + 0.015f, startY + 0.15f, 0.05f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.015f, startY + 0.15f, 0.05f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.015f, startY + 0.15f, 0.05f, 0.10f, 200, petalColor);
    drawBushWith(startX + 0.020f, startY + 0.20f, 0.05f, 0.10f, 3000, leavesColor);
    drawBushWith(startX + -0.020f, startY + 0.20f, 0.05f, 0.10f, 3000, leavesColor);
}

void drawPlant(float startX, float startY, struct Color leavesColor, struct Color petalColor)
{
    // function prototypes
    void drawBushWith(float centerX, float centerY, float radiusX, float radiusY, int dotsCount, struct Color color);

    // code
    drawBushWith(startX + 0.0f, startY + 0.0f, 0.050f, 0.050f, 1000, leavesColor);
    drawBushWith(startX + 0.05f, startY + 0.00f, 0.050f, 0.050f, 1000, leavesColor);
    drawBushWith(startX + -0.05f, startY + 0.00f, 0.050f, 0.050f, 1000, leavesColor);
    drawBushWith(startX + 0.025f, startY + 0.05f, 0.050f, 0.050f, 1000, leavesColor);
    drawBushWith(startX + -0.025f, startY + 0.05f, 0.050f, 0.050f, 1000, leavesColor);
    drawBushWith(startX + -0.025f, startY + 0.10f, 0.05f, 0.10f, 1000, leavesColor);
}

void drawBushWith(float centerX, float centerY, float radiusX, float radiusY, int dotsCount, struct Color color)
{
    // function prototypes
    float getRandomFloat();
    void setCircularCurvePoints(float centerX, float centerY, float radiusH, float radiusV, float startAngle, float endAngle);

    // variable declarations
    static int setDots = 1;
    int numberOfDots = dotsCount > 5000 ? 5000 : dotsCount;
    static struct Dots dots[5000];

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
        glColor3f(color.r, color.g, color.b);                                 // Set the color
        glVertex2f(centerX + dots[i].x, centerY + dots[i].y * WINDOW_ASPECT); // Draw the point
    }
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
        glVertex2f(ObjX, ObjY * WINDOW_ASPECT);
    }
}
