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

void drawPolygon(SHAPE, struct MY_POINT, struct MY_POINT, struct MY_POINT);
struct MY_POINT scalePoint(struct MY_POINT, struct MY_POINT);           //  change size of object
struct MY_POINT translatePoint(struct MY_POINT, struct MY_POINT);       //  change origin / position of object
struct MY_POINT reflectPoint(struct MY_POINT point, struct MY_POINT);   //  reflection of object

#include "drawing.c"
#include "geometry_calculations.c"
#include "forrest.c"