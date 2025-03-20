#include "../common/common.h"
#include "scene1/elephant.c"
#include "scene1/chamelon.c"
#include "scene1/chamelontounge_mov.c"
#include "scene1/butterfly.c"
#include "../common/props/cranes.c"
#include "../common/props/patterendDeers.c"
#include "../common/props/plainDeers.c"
#include "../common/props/peacock.c"
#include "../common/props/fullkrushna.c"
#include "../common/props/horse.c"

/*******************************/
/* TYPE DEFINITIONS AND DECLARATIONS */
/******************************/

// Scene structure definition for Chain of Responsibility pattern
typedef struct Scene
{
    void (*render)(void);                    // Function to render the scene
    void (*update)(void);                    // Function to update the scene
    BOOL (*shouldTransition)(BOOL iSkipped); // Function to check if transition to next scene is needed
    struct Scene *nextScene;                 // Pointer to next scene in the chain
} Scene;

// External scene variables
Scene *currentScene = NULL;

// Scene-specific globals
BOOL bCallTounge = FALSE;
BOOL bCallElephant = FALSE;
BOOL bCallButterfly = FALSE;

// scene 5 specific
bShowRotatingPlants = FALSE;
bShriKrishnaEntry = FALSE;
bShowLake = FALSE;
bShowCranes = FALSE;
bShowPatternedDeers = FALSE;
bShowFlowers = FALSE;
bShowPeacock = FALSE;

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
void scene5Render(void);
void scene5Update(void);
BOOL scene5ShouldTransition(BOOL iSkipped);

/*******************************/
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene scene0 = {scene0Render, scene0Update, scene0ShouldTransition, NULL};
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};
Scene scene5;
Scene scene6_5;

// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

/*******************************/
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

/*******************************/
/* Props update MANAGEMENT function and variable declarations */
/******************************/

TRANSLATION rathTranslation;

void updateRath(void);

// Initialize the scene chain
void initScenes(void)
{
    // function prototypes
    void renderScene6_5(void);
    void updateScene6_5(void);
    BOOL shouldTransitionScene6_5(GLboolean);

    scene5 = (Scene){scene5Render, scene5Update, scene5ShouldTransition, NULL};
    scene6_5 = (Scene){
        renderScene6_5,
        updateScene6_5,
        shouldTransitionScene6_5,
        NULL};

    scene0.nextScene = &scene1;
    scene1.nextScene = &scene5;
    // scene2.nextScene = &scene5;
    scene5.nextScene = &scene6_5; // End of chain
    scene6_5.nextScene = NULL;
    currentScene = &scene0; // Start with scene 1

    rathTranslation = (TRANSLATION){0.0f, 0.0f, 0.0f};
}

// Update the current scene
void updateCurrentScene(UINT timeElapsed)
{
    if (currentScene)
    {
        // Call the current scene's update function
        if (currentScene->update)
        {
            currentScene->update();
        }

        if (currentScene->shouldTransition && currentScene->shouldTransition(FALSE))
        {
            if (currentScene->nextScene)
            {
                logSceneTransition(timeElapsed);
                currentScene = currentScene->nextScene;
            }
        }
    }
}

// Render the current scene
void renderCurrentScene(void)
{
    if (currentScene && currentScene->render)
    {
        currentScene->render();
    }
}

// Log scene transition
void logSceneTransition(UINT timeElapsed)
{
    if (gpFile)
    {
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
    if (iSkipped || iTimeElapsed >= iThresholdTime)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
        flag = TRUE;
    }
    if (flag == TRUE)
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
    // drawDenseForrest();
    // drawFrontTrees();
    elephant();
    drawButterfly(butterflyX, butterflyY, 0.3f, butterflyRotation);
    toungeMovement();
    chamelon(0.5f, -0.35f, 0.2);
}

void scene1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    case 50:
        bCallElephant = TRUE;
        break;
    case 60:
        bCallTounge = TRUE;
        break;
    case 70:
        bCallButterfly = TRUE;
        break;
    }
    // Update specific elements
    if (bCallTounge == TRUE)
        updateTounge();

    if (bCallElephant == TRUE)
        updateElephant();

    if (bCallButterfly)
        updateButterfly();
}

BOOL scene1ShouldTransition(BOOL iSkipped)
{
    // int iThresholdTime = 300;
    int iThresholdTime = 200;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 15 seconds
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 2 IMPLEMENTATION */
/******************************/

void scene2Render(void)
{
    // Draw scene 2 elements
    // drawGround();
    // Add scene 2 specific rendering
}

void scene2Update(void)
{
    // Update scene 2 elements
}

BOOL scene2ShouldTransition(BOOL iSkipped)
{
    // 20 Sec is Temporarily set for testing
    int iThresholdTime = 720;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return (iTimeElapsed >= iThresholdTime);
}

/*******************************/
/* SCENE 6_5 IMPLEMENTATION */
/******************************/
void renderScene6_5()
{
    void drawRoom(void);
    void drawNakul(float xOrigin, float yOrigin, float scale);

    drawRoom();
    drawNakul(0.3f, 0.0f, 0.7f);
}

void updateScene6_5()
{
    static GLboolean zoomOutPandav = FALSE;
    static GLboolean zoomInKrishna = FALSE;
    static GLboolean translateRight = FALSE;
    switch (iTimeElapsed)
    {
    case 1620:
        break;

    case 1650:
        zoomOutPandav = TRUE;
        break;

    case 1700:
        zoomOutPandav = FALSE;
        translateRight = TRUE;
        break;

    case 1750:
        translateRight = FALSE;
        zoomInKrishna = TRUE;

    default:
        break;
    }

    if (zoomOutPandav == TRUE)
    {
    }
}

BOOL shouldTransitionScene6_5(BOOL iSceneSkipped)
{
    int iThresholdTime = 1870;
    if (iSceneSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return TRUE;
}

void updateRath()
{
    rathTranslation.x = rathTranslation.x - 0.0001f;
}
/*******************************/
/* SCENE 5 IMPLEMENTATION */
/******************************/

void scene5Render(void)
{
    if (bShowRotatingPlants == TRUE)
    {
        // fprintf(gpFile, "\nbShowRotatingPlants is true\n");
        drawGround();
        drawDenseForrest();
    }
    if (bShriKrishnaEntry = TRUE && bShowLake == TRUE && bShowCranes == TRUE)
    {

        // lake and cranes
        drawGround();
        drawDenseForrest();

        drawCraneOne(0.4f, -0.2f, 0.9f);
        drawCraneTwo(0.8f, 0.0f, 0.9f);

        // Shri-Krishna
        KrishnaRath(-0.8f, -0.3f, 0.50f);

        // Rath
        MY_POINT startPosition = {0.2f, -0.5f, 0.8f};
        SCALING scaleBy = {1.3f, 1.3f, 1.3f};
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
        fprintf(gpFile, "\bShowPatternedDeers is true\n");
        drawGround();
        drawDenseForrest();
        drawRightPatternedDeer(0.0f, 0.0f, 0.5f);
        drawLeftPatternedDeer(-0.4f, 0.0f, 0.5f);
    }
    // Flowers function
    if (bShowPeacock)
    {
        drawPeacock();
    }
    // Peacock function
}

void scene5Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed)
    {
    // case 700:
    case 205:
        // case 72:
        bShowRotatingPlants = TRUE;
        break;
    case 210:
        // case 76:
        bShowRotatingPlants = FALSE;
        bShriKrishnaEntry = TRUE;
        bShowLake = TRUE;
        bShowCranes = TRUE;
        break;
    case 230:
        // case 84:
        bShriKrishnaEntry = FALSE;
        bShowLake = FALSE;
        bShowCranes = FALSE;
        bShowPatternedDeers = TRUE;
        break;
    case 235:
        // case 87:
        bShowFlowers = TRUE;
        break;
    case 245:
        // case 93:
        bShowPatternedDeers = FALSE;
        bShowPeacock = TRUE;
        break;
    }
    // Update specific elements
    if (bShowRotatingPlants == TRUE)
    {
    }
    if (bShriKrishnaEntry == TRUE)
    {
        // call traslation related function for moving Rath
        updateRath();
    }
    if (bShowFlowers == TRUE)
    {
        // rotating flowers
    }
    if (bShowPeacock == TRUE)
    {
        // dancing peacock
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
    return (iTimeElapsed >= iThresholdTime);
}
