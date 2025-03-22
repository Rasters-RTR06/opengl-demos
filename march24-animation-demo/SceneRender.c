#include "../common/common.h"
#include "scene1/elephant.c"
#include "scene1/chamelon.c"
#include "scene1/chamelontounge_mov.c"
#include "scene1/butterfly.c"


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

extern float D_cordinate;
 

// External scene variables
Scene* currentScene = NULL;

// Scene-specific globals
BOOL bCallTounge = FALSE;
BOOL bCallElephant = FALSE;
BOOL bCallButterfly = FALSE;

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

/*******************************/ 
/* SCENE MANAGEMENT VARIABLES */
/******************************/

// Scene management variables
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
    scene1.nextScene = &scene2;
    scene2.nextScene = NULL;  // End of chain
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

float D_cordinate = -0.4f;
BOOL move = FALSE;

void updateD_Pos(void)
{
	D_cordinate += 0.0006f;
    if(D_cordinate > 0.6f) 
    {move = FALSE;
    }
}

void scene1Render(void)
{
    drawRoom();
    drawBheem(0.2f ,0.0f,0.6f, 0.0f,0.0f);
    drawYuthishteer(-0.1f,0.0f,0.6,0.0f,1.0f);
    drawYuthishteer(-0.3f,0.0f,0.6,0.0f,1.0f);
    drawYuthishteer(-0.4f,-0.2f,0.6,0.0f,1.0f);
    drawYuthishteer(0.1f,0.0f,0.6,0.0f,1.0f);
    
    sittingkrishna(0.6, -0.1f, 0.3);
    drawDraupadi(D_cordinate, -0.3f, 0.6f, 3.0f, 1.0f);
   // Add plate;
}

void scene1Update(void)
{
    // Check time-based triggers
    switch (iTimeElapsed) {
        case 10:
            move = TRUE;
            break;
    }
    // Update specific elements
    if(move == TRUE)
         updateD_Pos();
}

BOOL scene1ShouldTransition(BOOL iSkipped)
{
    int iThresholdTime = 1500000;
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
