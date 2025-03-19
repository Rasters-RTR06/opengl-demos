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
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};
Scene scene5;
// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

/*******************************/ 
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void) {

    scene5 =(Scene) { scene5Render, scene5Update, scene5ShouldTransition, NULL };

    scene1.nextScene = &scene2;
    scene2.nextScene = &scene5;
    scene5.nextScene = NULL; // End of chain
    currentScene = &scene1;   // Start with scene 1
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
/* SCENE 1 IMPLEMENTATION */
/******************************/

void scene1Render(void)
{
    drawGround();
    drawDenseForrest();
    drawFrontTrees();
    elephant();
    drawButterfly(butterflyX, butterflyY, 0.3f, butterflyRotation);
    toungeMovement();
    chamelon(0.5f, -0.35f, 0.2);
}

void scene1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed) {
        case 5000:
            bCallElephant = TRUE;
            break;
        case 6000:
            bCallTounge = TRUE;
            break;
        case 7000:
            bCallButterfly = TRUE;
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
    int iThresholdTime = 15000;
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
    int iThresholdTime = 20000;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    return TRUE;  
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
        drawDenseForrest();  
    }
    if (bShriKrishnaEntry = TRUE && bShowLake == TRUE && bShowCranes == TRUE)
    {
        //draw lake and cranes
        drawCraneOne(0.4f, -0.2f, 0.9f);
        drawCraneTwo(0.8f, 0.0f, 0.9f);
        drawHorse(-0.6f, -0.6f, 0.5f);
        KrishnaRath(0.0f, 0.0f, 0.2f);
        MY_POINT  startPosition = {0.0f, -0.5f, 0.0f};
        TRANSLATION translateBy = { 0.1f, 0.0f, 0.0f };
        SCALING scaleBy = {1.0f, 1.0f, 1.0f};
        rath(startPosition, translateBy,  scaleBy);
    }

    if (bShowFlowers == TRUE)
    {
        //drawFlower();
    }
    if (bShowPatternedDeers)
    {
         drawGround();
         drawRightPatternedDeer(0.0f, 0.0f, 0.5f);
         drawLeftPatternedDeer(-0.4f, 0.0f, 0.5f);
    }
    //Flowers function
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
        case 73000:
            bShowRotatingPlants = TRUE;
            break;
        case 76000:
            bShriKrishnaEntry = TRUE;
            bShowLake = TRUE;
            bShowCranes = TRUE;
            break;
        case 84000:
            bShowRotatingPlants = FALSE;
            bShriKrishnaEntry = FALSE;
            bShowLake = FALSE;
            bShowCranes = FALSE;
            bShowPatternedDeers = TRUE;
            break;
        case 87000:
            bShowFlowers = TRUE;
            break;
        case 93000:
            bShowPatternedDeers = FALSE;
            bShowPeacock = TRUE;
            break;
    }
    // Update specific elements
    if (bShowRotatingPlants == TRUE)
    {
        drawDenseForrest();
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
    int iThresholdTime = 81000;
    if (iSkipped)
    {
        iTimeElapsed = 0;
        iTimeElapsed += iThresholdTime;
    }
    // Transition to the next scene after 1 min 35 sec seconds
    return (iTimeElapsed >= iThresholdTime);
}
