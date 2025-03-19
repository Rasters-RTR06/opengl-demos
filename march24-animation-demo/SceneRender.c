#include "../common/common.h"
#include "scene1/elephant.c"
#include "scene1/chamelon.c"
#include "scene1/chamelontounge_mov.c"
#include "scene1/butterfly.c"
#include "../common/props/cranes.c"
#include "../common/props/patternedDeers.c"
#include "../common/props/plainDeers.c"


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
void scene0Render(void);
void scene0Update(void);
BOOL scene0ShouldTransition(BOOL iSkipped);

void scene1Render(void);
void scene1Update(void);
BOOL scene1ShouldTransition(BOOL iSkipped);
void scene2Render(void);
void scene2Update(void);
BOOL scene2ShouldTransition(BOOL iSkipped);

/*******************************/ 
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
Scene scene0 = {scene0Render, scene0Update, scene0ShouldTransition, NULL };
Scene scene1 = {scene1Render, scene1Update, scene1ShouldTransition, NULL};
Scene scene2 = {scene2Render, scene2Update, scene2ShouldTransition, NULL};

// External global variables from Raster.c
extern FILE *gpFile;
extern UINT iTimeElapsed;

/*******************************/ 
/* SCENE MANAGEMENT FUNCTIONS */
/******************************/

// Initialize the scene chain
void initScenes(void) {

    scene0.nextScene = &scene1;
    scene1.nextScene = &scene2;
    scene2.nextScene = NULL;

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
        case 5:
            bCallElephant = TRUE;
            break;
        case 6:
            bCallTounge = TRUE;
            break;
        case 7:
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
