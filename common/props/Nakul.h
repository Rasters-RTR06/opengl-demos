#ifndef NAKUL_H
#define NAKUL_H

// global variable declarations
extern int g_iNakulStanding;
extern float xOriginNakul;
extern float yOriginNakul;
extern float fScaleFactorNakul;
extern float DhotiColor[3];  // Global color array

#define SET_DHOTI_COLOR() glColor3fv(DhotiColor)

// Function declarations (not definitions)
void drawRectangleNakul(float, float, float, float);
void drawQuadrangleNakul(float, float, float, float, float, float, float, float);
void drawLineNakul(float, float, float, float);
void drawcircleNakul(float, float, float, float, float, float, float, int);
void drawTriangleNakul(float, float, float, float, float, float);
void drawNakul(float, float, float, int);
void drawHead(float, float, float);
void drawClothBackSide(float, float, float);
void drawCommonBody(float, float, float, int);
void drawHandAndCloth(float, float, float, int);

#endif // NAKUL_H
