#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define MAX_POINTS 12

struct MY_POINT
{
    float x;
    float y;
    float z;
};

typedef struct SHAPE_ATTRIBUTES
{
    int noOfPoints;
    struct MY_POINT points[MAX_POINTS];
    float rValue;
    float gValue;
    float bValue;
} SHAPE;

void drawElephant(struct MY_POINT, struct MY_POINT, struct MY_POINT);
void drawPolygon(SHAPE, struct MY_POINT, struct MY_POINT, struct MY_POINT);
struct MY_POINT scalePoint(struct MY_POINT, struct MY_POINT);
struct MY_POINT translatePoint(struct MY_POINT, struct MY_POINT);
struct MY_POINT reflectPoint(struct MY_POINT point, struct MY_POINT);

void drawElephant(struct MY_POINT scalingFactor, struct MY_POINT translationFactor, struct MY_POINT reflectionFactor)
{
    SHAPE shapes[] = {
        {5, {{0.32f, 0.65f, 0}, {0.38f, 0.14f, 0}, {0.2f, 0.05f, 0}, {-0.09f, 0.19f, 0}, {-0.09f, 0.62f, 0}},       183.0f, 193.0f, 199.0f},
        {4, {{0.32f, 0.65f, 0}, {0.65f, 0.49f, 0}, {0.75f, 0.0f, 0}, {0.45f, -0.47f, 0}},                           155.0f, 170.0f, 179.0f},
        {3, {{0.6f, 0.26f, 0}, {0.54f, -0.54f, 0}, {0.45f, -0.47f, 0}},                                             155.0f, 170.0f, 179.0f},
        {3, {{0.42f, -0.54f, 0}, {0.54f, -0.54f, 0}, {0.45f, -0.47f, 0}},                                           183.0f, 193.0f, 198.0f},
        {3, {{0.38f, 0.14f, 0}, {0.43f, -0.24f, 0}, {0.2f, 0.05f, 0}},                                              162.0f, 174.0f, 181.0f},
        {3, {{0.65f, 0.49f, 0}, {0.79f, -0.21f, 0}, {0.78f, 0.1f, 0}},                                              184.0f, 193.0f, 199.0f},
        {4, {{0.75f, 0.0f, 0}, {0.74f, -0.1f, 0}, {0.635f, -0.32f, 0}, {0.605f, -0.22f, 0}},                        89.0f, 106.0f, 107.0f},
        {5, {{0.74f, -0.1f, 0}, {0.83f, -0.54f, 0}, {0.78f, -0.54f, 0}, {0.7f, -0.47f, 0},  {0.635f, -0.32f, 0}},   155.0f, 170.0f, 179.0f},
        {3, {{0.78f, -0.54f, 0}, {0.7f, -0.47f, 0}, {0.695f, -0.54f, 0}},                                           183.0f, 193.0f, 198.0f},
        {3, {{0.38f, -0.17f, 0}, {0.2f, 0.05f, 0}, {-0.09f, -0.09f, 0}},                                            147.0f, 157.0f, 163.0f},
        {3, {{-0.09f, -0.09f, 0}, {0.2f, 0.05f, 0}, {-0.09f, 0.19f, 0}},                                            172.0f, 184.0f, 194.0f},
        {7, {{-0.35f, 0.05f, 0}, {-0.32f, -0.16f, 0}, {-0.225f, -0.3f, 0}, {-0.14f, -0.19f, 0}, {-0.09f, -0.09f, 0}, {-0.09f, 0.62f, 0}, {-0.25f, 0.625f, 0}},
                                                                                                                    155.0f, 170.0f, 176.0f},
        {4, {{-0.28f, -0.52f, 0}, {-0.36f, -0.44f, 0}, {-0.32f, -0.16f, 0}, {-0.225f, -0.3f, 0}},                   155.0f, 170.0f, 176.0f},
        {3, {{-0.28f, -0.52f, 0}, {-0.26f, -0.44f, 0}, {-0.26f, -0.54f, 0}},                                        155.0f, 170.0f, 176.0f},
        {3, {{-0.36f, -0.44f, 0}, {-0.39f, -0.54f, 0}, {-0.26f, -0.54f, 0}},                                        184.0f, 194.0f, 200.0f},
        {6, {{-0.09f, -0.09f, 0}, {0.035f, -0.11f, 0}, {0.01f, -0.23f, 0}, {-0.07f, -0.18f, 0}, {-0.13f, -0.25f, 0}, {-0.135f, -0.18f, 0}}, 
                                                                                                                    89.0f, 107.0f, 107.0f},
        {6, {{-0.015f, -0.3f, 0}, {0.01f, -0.23f, 0}, {-0.07f, -0.18f, 0}, {-0.13f, -0.25f, 0}, {-0.12f, -0.45f, 0}, {0.0f, -0.54f, 0}},
                                                                                                                    158.0f, 172.0f, 181.0f},
        {3, {{-0.14f, -0.54f, 0}, {-0.12f, -0.45f, 0}, {0.0f, -0.54f, 0}},                                          184.0f, 194.0f, 200.0f},
        {8, {{-0.42f, 0.12f, 0}, {-0.28f, 0.29f, 0}, {-0.23f, 0.31f, 0}, {-0.165f, 0.43f, 0},
             {-0.135f, 0.405f, 0}, {-0.2f, 0.24f, 0}, {-0.265f, 0.215f, 0}, {-0.35f, 0.05f, 0}},                    106.0f, 131.0f, 131.0f},
        {9, {{-0.28f, 0.29f, 0}, {-0.23f, 0.31f, 0}, {-0.13f, 0.49f, 0}, {-0.25f, 0.62f, 0}, {-0.37f, 0.71f, 0},
             {-0.55f, 0.66f, 0}, {-0.5f, 0.2f, 0}, {-0.48f, 0.11f, 0}, {-0.42f, 0.12f, 0}},                         184.0f, 192.0f, 199.0f},
        {3, {{-0.55f, 0.66f, 0}, {-0.53f, 0.54f, 0}, {-0.715f, 0.65f, 0}},                                          173.0f, 184.0f, 190.0f},
        {3, {{-0.81f, 0.35f, 0}, {-0.53f, 0.54f, 0}, {-0.715f, 0.65f, 0}},                                          182.0f, 194.0f, 198.0f},
        {6, {{-0.53f, 0.54f, 0}, {-0.81f, 0.35f, 0}, {-0.68, 0.09f, 0}, {-0.625f, 0.125f, 0},
             {-0.61f, 0.22f, 0}, {-0.535f, 0.255f, 0}},                                                             156.0f, 171.0f, 180.0f},
        {4, {{-0.81f, 0.35f, 0}, {-0.68, 0.09f, 0}, {-0.75f, -0.29f, 0}, {-0.8f, -0.13f, 0}},                       156.0f, 171.0f, 180.0f},
        {4, {{-0.68, 0.09f, 0}, {-0.66f, -0.54f, 0}, {-0.75f, -0.54f, 0}, {-0.75f, -0.29f, 0}},                     156.0f, 171.0f, 180.0f},
        {3, {{-0.71, 0.335f, 0}, {-0.71f, 0.27f, 0}, {-0.64f, 0.335f, 0}},                                          115.0f, 143.0f, 144.0f},
        {3, {{-0.695, 0.32f, 0}, {-0.695f, 0.295f, 0}, {-0.665f, 0.32f, 0}},                                        94.0f, 64.0f, 24.0f},
        {4, {{-0.72, 0.09f, 0}, {-0.675f, 0.095f, 0}, {-0.735f, 0.025f, 0}, {-0.83f, -0.04f, 0}},                   243.0f, 243.0f, 231.0f},
        {3, {{-0.532, 0.495f, 0}, {-0.50f, 0.21f, 0}, {-0.535f, 0.26f, 0}},                                         105.0f, 130.0f, 130.0f},
        {4, {{-0.50f, 0.21f, 0}, {-0.535f, 0.26f, 0}, {-0.61f, 0.22f, 0}, {-0.59f, 0.195f, 0}},                     105.0f, 130.0f, 130.0f},
        {3, {{-0.625f, 0.12f, 0}, {-0.61f, 0.22f, 0}, {-0.59f, 0.195f, 0}},                                          105.0f, 130.0f, 130.0f},
    };

    for (int i = 0; i < ARRAY_SIZE(shapes); i++) 
        drawPolygon(shapes[i], scalingFactor, translationFactor, reflectionFactor);
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