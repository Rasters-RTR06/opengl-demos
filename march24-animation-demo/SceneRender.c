#include "../common/common.h"
#include "scene1/elephant.c"
#include "scene1/chamelon.c"
#include "scene1/chamelontounge_mov.c"
#include "scene1/butterfly.c"
#include "../common/props/cranes.c"
#include "../common/props/patternedDeers.c"
#include "../common/props/plainDeers.c"
#include "../common/props/peacock.c"
#include "../common/props/fullkrushna.c"
#include "../common/props/horse.c"
#include "../common/props/SandeshText.c"
#include "Scene6_2Render.h"

/*******************************/ 
/* TYPE DEFINITIONS AND DECLARATIONS */
/******************************/

// Scene structure definition for Chain of Responsibility pattern
typedef struct Scene {
    void (*render)(void);        // Function to render the scene
    void (*update)(void);        // Function to update the scene
    BOOL (*shouldTransition)(BOOL iSkipped);  // Function to check if transition to next scene is needed
    struct Scene* nextScene;     // Pointer to next scene in the chain
} Scene;

// External scene variables
Scene* currentScene = NULL;

// Scene-specific globals
BOOL bCallTounge = FALSE;
BOOL bCallElephant = FALSE;
BOOL bCallButterfly = FALSE;

//scene 5 specific
BOOL bShowRotatingPlants = FALSE;
BOOL bShriKrishnaEntry = FALSE;
BOOL bShowLake = FALSE;
BOOL bShowCranes = FALSE;
BOOL bShowPatternedDeers = FALSE;
BOOL bShowFlowers = FALSE;
BOOL bShowPeacock = FALSE;


// Scene management functions declarations
void initScenes(void);
void updateCurrentScene(UINT iTimeElapsed);
void renderCurrentScene(void);
void logSceneTransition(UINT iTimeElapsed);

/*******************************/ 
/* SCENE FUNCTION DECLARATIONS */
/******************************/

// Forward declarations for scene functions
void scene0Render(void);
void scene0Update(void);
BOOL scene0ShouldTransition(BOOL iSkipped);
void scene1Render(void);
void scene1Update(void);
BOOL scene1ShouldTransition(BOOL iSkipped);
void scene2Render(void);
void scene2Update(void);
BOOL scene2ShouldTransition(BOOL iSkipped);
void scene3Render(void);
void scene3Update(void);
BOOL scene3ShouldTransition(BOOL iSkipped);
void scene5Render(void);
void scene5Update(void);
BOOL scene5ShouldTransition(BOOL iSkipped);
void scene6_2Render(void);
void scene6_2Update(void);
BOOL scene6_2ShouldTransition(BOOL iSkipped);

/*******************************/ 
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene scene0 = {scene0Render, scene0Update, scene0ShouldTransition, NULL};
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};
Scene scene3 = {scene3Render, scene3Update, scene3ShouldTransition, NULL};
Scene scene5;
Scene scene6_2 = { scene6_2Render, scene6_2Update, scene6_2ShouldTransition, NULL };
// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

TRANSLATION rathTranslation;

/*******************************/ 
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void) {
    scene5 =(Scene) { scene5Render, scene5Update, scene5ShouldTransition, NULL };

    scene0.nextScene = &scene1;
    scene1.nextScene = &scene2;
    scene2.nextScene = &scene3;
    scene3.nextScene = &scene5;
    scene5.nextScene = &scene6_2;
    scene6_2.nextScene = NULL;// End of chain
    currentScene = &scene0;   // Start with scene 1
}

// Update the current scene
void updateCurrentScene(UINT timeElapsed) {
    if (currentScene) {
        // Call the current scene's update function
        if (currentScene->update) {
            currentScene->update();
        }
        
        if (currentScene->shouldTransition && currentScene->shouldTransition(FALSE)) {
            if (currentScene->nextScene) {
                logSceneTransition(timeElapsed);
                currentScene = currentScene->nextScene;
            }
        }
    }
}

// Render the current scene
void renderCurrentScene(void) {
    if (currentScene && currentScene->render) {
        currentScene->render();
    }
}

// Log scene transition
void logSceneTransition(UINT timeElapsed) {
    if (gpFile) {
        fprintf(gpFile, "Transitioning to next scene at time %d seconds\n", timeElapsed);
    }
}

/*******************************/ 
/* SCENE 0 IMPLEMENTATION */
/******************************/
void scene0Render(void)
{
    drawIntro();
}

void scene0Update(void)
{
    updateIntro();
}

BOOL scene0ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 200;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if(flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/ 
/* SCENE 1 IMPLEMENTATION */
/******************************/
void scene1Render(void)
{
    drawGround();
    //drawDenseForrest();
    //drawFrontTrees();
    elephant();
    drawButterfly(butterflyX, butterflyY, 0.6f, butterflyRotation);
    toungeMovement();
    chamelon(1.5f, -0.35f, 0.2);
    drawSandesh();
}


void scene1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed) {
        case 50:
            break;
        case 60:
            bCallTounge = TRUE;
            break;
        case 70:
            bCallElephant = TRUE;
            break;
    }
    // Update specific elements
    if(bCallTounge == TRUE)
        updateTounge();
    
    if(bCallElephant == TRUE)
        updateElephant();

    if (bCallButterfly)
        updateButterfly();
}

BOOL scene1ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 100;
    BOOL flag = FALSE;
    if (iSkipped || (iTimeElapsed >= iThresholdTime))
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if(flag)
    {
        iTimeElapsed = 0;
    }
    // Transition to the next scene after 15 seconds
    return (flag);
}

/*******************************/ 
/* SCENE 2 IMPLEMENTATION */
/******************************/

void scene2Render(void)
{
    // Draw scene 2 elements
    //drawGround();
    // Add scene 2 specific rendering

}

void scene2Update(void)
{
    // Update scene 2 elements
}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 460;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

void scene3Render(void)
{
    // Draw scene 3 elements
    // Add scene 3 specific rendering
}

void scene3Update(void)
{
    // Update scene 3 elements
}

BOOL scene3ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 520;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 5 IMPLEMENTATION */
/******************************/

void scene5Render(void)
{
    /*
    Elements' Sequence :
                1. Rotating plants at time 1.13 (73 seconds)
                2. lake and cranes, Bhagvan shrikrishna ki sawari   at time 1.16 (76 seconds)
                3. Patterned deers at time  1.24 (84 seconds)
                4. Flowers  - Jungle me mangal chaaya at time 1.27 (87 seconds)
                5. Peacock at time 1.33 (93 seconds)

    */
    // Draw scene 5 elements
    //drawGround();
    if (bShowRotatingPlants == TRUE)
    {
        drawGround();
        drawDenseForrest();
    }
    if (bShriKrishnaEntry = TRUE && bShowLake == TRUE && bShowCranes == TRUE)
    {
        //lake and cranes
        drawGround();
        drawDenseForrest();

        drawCraneOne(0.4f, -0.2f, 0.9f);
        drawCraneTwo(0.8f, 0.0f, 0.9f);

        //Shri-Krishna
        KrishnaRath(-0.8f, -0.3f, 0.50f);
        //Rath
        MY_POINT startPosition = { 0.2f, -0.5f, 0.8f };
        SCALING scaleBy = { 1.3f, 1.3f, 1.3f };
        rath(startPosition, rathTranslation, scaleBy);
        drawHorse(-0.3f, -0.5f, 0.8f);
        drawFrontTrees();
    }

    if (bShowFlowers == TRUE)
    {
        // flowers funtion
    }
    if (bShowPatternedDeers)
    {
        drawGround();
        drawDenseForrest();
        drawRightPatternedDeer(0.0f, 0.0f, 0.5f);
        drawLeftPatternedDeer(-0.4f, 0.0f, 0.5f);
    }
    if (bShowPeacock)
    {
        drawGround();
        drawDenseForrest();
        drawPeacock(0.0f, 0.0f , 0.3f);
    }
}

void scene5Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed) 
    {
        case 205:
            bShowRotatingPlants = TRUE;
            break;
        case 210:
            bShowRotatingPlants = FALSE;
            bShriKrishnaEntry = TRUE;
            bShowLake = TRUE;
            bShowCranes = TRUE;
            break;
        case 230:
            bShriKrishnaEntry = FALSE;
            bShowLake = FALSE;
            bShowCranes = FALSE;
            bShowPatternedDeers = TRUE;
            break;
        case 240:
            bShowPatternedDeers = FALSE;
            bShowFlowers = TRUE;
            break;
        case 245:
            bShowFlowers = FALSE;
            bShowPeacock = TRUE;
            break;
    }
    // Update specific elements
    if (bShowRotatingPlants == TRUE)
    {
        //rotate plants
    }
    if (bShriKrishnaEntry == TRUE)
    {
        //call traslation related function for moving Rath
    }
    if (bShowFlowers == TRUE)
    {
       //rotating flowers 
    }
    if (bShowPeacock == TRUE)
    {
        //dancing peacock
    }
}

BOOL scene5ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 950;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 1 min 35 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 6_2 IMPLEMENTATION */
/******************************/

void scene6_2Render()
{

    drawRoom();

    drawArjun(xOriginArjun, yOriginArjun, 0.7f, g_iArjunStanding);
    drawBheem(xOriginBheem, yOriginBheem, 0.7f, g_iBheemStanding);
    //drawYudhishteer(xOriginYudhishteer, yOriginYudhishteer, 0.7f, g_iYudhishteerStanding);

    drawSahadev(xOriginSahadev, yOriginSahadev, 0.7f, g_iSahadevStanding);

    //drawNakul(xOriginNakul, yOriginNakul, 0.7f, g_iNakulStanding);

    sittingkrishna(originxSK, originySK, resizeSK);
    drawNakul(xOriginNakul, yOriginNakul, 0.7f, g_iNakulStanding);
    drawDraupadi(xOriginDraupadi, yOriginDraupadi, 0.8f, g_iHandPositionDraupadi, g_iStandingDraupadi);
}

void scene6_2Update()
{
    fprintf(gpFile, "Scene6_2\n");
    g_iHandPositionDraupadi = 1;
    g_iStandingDraupadi = 1;

    g_iYudhishteerStanding = 0;
    g_iBheemStanding = 0;
    g_iArjunStanding = 0;
    g_iNakulStanding = 0;
    g_iSahadevStanding = 0;


    xOriginArjun = 0.05;yOriginArjun = 0.1;
    xOriginBheem = 0.2;yOriginBheem = 0.0;
    xOriginYudhishteer = 0.4;yOriginYudhishteer = -0.2;

    xOriginSahadev = -0.3;yOriginSahadev = 0.0;
    xOriginNakul = -0.1; yOriginNakul = -0.2;

    xOriginDraupadi = -0.2; yOriginDraupadi = -0.3;

    //fprintf(gpFile, "% d\n", iTimeElapsed);

    originxSK = 0.5f;
    originySK = -0.3f;
    resizeSK = 0.3f;

    switch (iTimeElapsed)
    {
    case 1060:
        //bMoveDraupadi = TRUE;

        break;
    case 1120:
        bMoveDraupadi = FALSE;
        break;
    default:
        break;
    }

    if (bMoveDraupadi)
    {
        if (xOriginDraupadi >= 0.0)
            xOriginDraupadi += 0.001;
        else
            xOriginDraupadi -= 0.01;
    }

}

BOOL scene6_2ShouldTransition(BOOL iSceneSkipped)
{
    int iThresholdTime = 1340;
    if (iSceneSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 2 min 14 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}

