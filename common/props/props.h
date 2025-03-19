#define MAX_POINTS 12

typedef struct
{
    float x;
    float y;
    float z;
} MY_POINT, ANGLE, SCALING, TRANSLATION, REFLECTION, RADIUS, SPACING;

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
//                     the z of angle will decide whether you want to draw ouline of ellipse / circle only or waan to draw full circle or ellipse
//                     z = 0  : draw full circle
//                     z != 0 : draw outline only (and value of z will be thickness of outline)
// scalingFactor     : change in size of object : x is scaling along x axis and y is scaling along y axis : {1, 1, 0} means no scaling
// translationFactor : change in size of object : x is translation along x axis and y is translation along y axis : {0, 0, 0} means no translation
// reflectionFactor  : creating image of object : {-1, 1, 0} : refliction along y axis
//                                                {1, -1, 0} : refliction along x axis
// radius            : for ellipse / circle     : x of radius is horizonal radius and y of radius is vertical radius (x == y is circle)
// rotationAngle     : rotate object (tilt )    : how much should rotate object in radian (0 for no rotation)
// spacing           : for draw word            : x is character spacing :
//                                                if word contains '\n' (wants to print some character on next line) then y will be consider as line gap
//                                                and z wil be consider as whther you want to print next line
//                                                          to print in center (z will have value other than from (-1.0f to (1.0f - x)))
//                                                          if z is in range (-1.0f to (1.0f - x)) value of z will be consider as start of next line
void drawPolygon(SHAPE shape, SCALING scalingFactor, TRANSLATION translationFactor, REFLECTION reflectionFactor);
void drawEllipse(COLOR color, ANGLE angle, SCALING scalingFactor, TRANSLATION translationFactor,
                 REFLECTION reflectionFactor, RADIUS radius, float rotationAngle);
void drawLine(COLOR, float, MY_POINT, MY_POINT);

MY_POINT scalePoint(MY_POINT, SCALING);         //  change size of object
MY_POINT translatePoint(MY_POINT, TRANSLATION); //  change origin / position of object
MY_POINT reflectPoint(MY_POINT, REFLECTION);    //  reflection of object
MY_POINT rotatePoint(MY_POINT, float);          //  rotation of point

float getCharacterWidth(char, float);
COLOR getRandomColor();
void drawCharacter(char, float, MY_POINT, COLOR, float);
void drawWord(char *, float, MY_POINT, COLOR, float, float);
float getWordwidth(char *, float, float);

void updateIntro();
void drawIntro();
void drawAstromedicomp();
void drawAstre();
void drawRasters();
void drawRasterGroupPresents();

float getRandomFloat();
void rath(MY_POINT startPosition, TRANSLATION translateBy, SCALING scaleBy);

#include "props.c"
#include "drawing.c"
#include "geometry_calculations.c"
#include "forrest.c"
#include "alphabates.c"
#include "astromedicomp_to_rasters.c"
#include "rath.c"
