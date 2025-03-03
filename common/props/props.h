#define MAX_POINTS 12

typedef struct
{
    float x;
    float y;
    float z;
} MY_POINT, ANGLE, SCALING, TRANSLATION, REFLECTION, RADIUS;

typedef struct
{
    float rValue;
    float gValue;
    float bValue;
    float aValue;
} COLOR;

typedef struct
{
    int noOfPoints;
    MY_POINT points[MAX_POINTS];
    COLOR color;
} SHAPE;


// color             : ellipse / circle color   : color.rValue is red value, color.gValue is green value, color.bValue is blue value and  color.aValue is transperancy
// angle             : x of angle is start angle and y is end angle of ellipse in radian : {0, 2 * PI, 0} means full circle or ellipse
// scalingFactor     : change in size of object : x is scaling along x axis and y is scaling along y axis : {1, 1, 0} means no scaling
// translationFactor : change in size of object : x is translation along x axis and y is translation along y axis : {0, 0, 0} means no translation
// reflectionFactor  : creating image of object : {-1, 1, 0} : refliction along y axis
//                                                {1, -1, 0} : refliction along x axis
// radius            : for ellipse / circle     : x of radius is horizonal radius and y of radius is vertical radius (x == y is circle)
// rotationAngle     : rotate object (tilt )    : how much should rotate object in radian (0 for no rotation)
void drawPolygon(SHAPE shape, SCALING scalingFactor, TRANSLATION translationFactor, REFLECTION reflectionFactor);
void drawEllipse(COLOR color, ANGLE angle, SCALING scalingFactor, TRANSLATION translationFactor,
                REFLECTION reflectionFactor, RADIUS radius, float rotationAngle);


MY_POINT scalePoint(MY_POINT, SCALING);             //  change size of object
MY_POINT translatePoint(MY_POINT, TRANSLATION);     //  change origin / position of object
MY_POINT reflectPoint(MY_POINT, REFLECTION);        //  reflection of object
MY_POINT rotatePoint(MY_POINT, float);              //  rotation of point


#include "drawing.c"
#include "geometry_calculations.c"
#include "forrest.c"