#pragma once
//#include "Raster.h"
#include <Windows.h>

#define CHARACTER_SITTING		0
#define CHARACTER_STANDING		1

#define CHARACTER_HAND_GESTURE	0
#define CHARACTER_HAND_FOLDED	1

#define DRAUPADI_HAND_FOLDED	1
#define DRAUPADI_HAND_SERVING	2
#define DRAUPADI_HAND_THALI		3

#define HIDE_BOW_ARROW			0
#define SHOW_BOW_ARROW			1



//Draupadi
float xOriginDraupadi = 0.0f;
float yOriginDraupadi = 0.0f;
float fScaleFactorDraupadi = 1.0f;
int g_iHandPositionDraupadi = 1;
int g_iStandingDraupadi = 1;
BOOL bMoveDraupadi = FALSE;

//Yudhishteer
int g_iHandPositionYudhishteer = 1;
int g_iYudhishteerStanding = 1;
float xOriginYudhishteer = 0.0f;
float yOriginYudhishteer = 0.0f;
float fScaleFactorYudhishteer = 1.0f;


//Bheem
int g_iHandPositionBheem = 1;
int g_iBheemStanding = 1;
float xOriginBheem = 0.0f;
float yOriginBheem = 0.0f;
float fScaleFactorBheem = 1.0f;


//Arjun
int g_iHandPositionArjun = 1;
int g_iArjunStanding = 1;
float xOriginArjun = 0.0f;
float yOriginArjun = 0.0f;
float fScaleFactorArjun = 1.0f;

//Nakul
int g_iHandPositionNakul = 1;
int g_iNakulStanding = 1;
float xOriginNakul = 0.0f;
float yOriginNakul = 0.0f;
float fScaleFactorNakul = 1.0f;

//Sahadev
int g_iHandPositionSahadev = 1;
int g_iSahadevStanding = 1;
float xOriginSahadev = 0.0f;
float yOriginSahadev = 0.0f;
float fScaleFactorSahadev = 1.0f;

//Sitting Krishna
float originxSK = 0.0f; 
float originySK = 0.0f; 
float resizeSK = 1.0f;

